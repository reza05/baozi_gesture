#include "gesture.h"
#include "gesture_scheme.h"
#include "string.h"


/**
  *  Global data
  */
static gesture_circular_buff g_tuple_buffer;
volatile int    g_sem = 0;

/*
 * Function declare
 */
static int gesture_analyse();
static gesture_tuple* read_tuple(int index);
static bool pop_tuple(gesture_tuple* p_tuple);
static int size_tuple(void);
static void clear_tuple(void);
static void skip_tuple(void);
static bool calc_tuple_transfer(char *pbuff);

int wait_user_input(int timeout) 
{
  if (g_sem > 0) {
    disableInterrupts();
    g_sem --;
    enableInterrupts();
    return (g_sem+1);
  }
  if (timeout == INFINITE) {
    while (1) {
      HAL_Delay(5);
      if (g_sem > 0) {
        disableInterrupts();
        g_sem--;
        enableInterrupts();
        return g_sem+1;
      }
    }
  } else {
    while (timeout) {
      HAL_Delay(5);
      if (g_sem > 0) {
        disableInterrupts();
        g_sem--;
        enableInterrupts();
        return g_sem+1;
      }
      timeout -= 5;
    }
    return 0;
  }
}

int trigger(void)
{
  //disableInterrupts();
  g_sem++;
  //enableInterrupts();
}

/**
  * @brief  This function is executed in case of error occurrence.
  * @param  None
  * @retval None
  */
void Error_Handler(void)
{
  while (1) {
    BSP_LED_Toggle(LED0);
    HAL_Delay(50);
  }
}

static void POP(gesture_tuple *p) 
{
  if (!pop_tuple(p)) {
    if (p) {
      p->state = 0;
    }
  }
}

static bool calc_tuple_transfer(char *pbuff1)
{
  int i,size;
  gesture_tuple cur;
  char tmp = 0;

  if (pbuff1 == NULL) {
    return false;
  }

  //find first none zero tuple
  while ((read_tuple(0)->state ==0) && (size_tuple() > 0)) {
    POP((gesture_tuple*)NULL);
  }
  //check tuple size
  if (size_tuple() < 3) {
    skip_tuple();
    return false;
  }
  size = size_tuple();
  pbuff1[0] = read_tuple(0)->state;
  
  for (i=0; i<size-1; i++) {
    POP(&cur);
    tmp = cur.state ^ read_tuple(0)->state;
    switch (tmp&0x7) {
      case 0x4: //0b100:
        pbuff1[i+2] = 1;
        break;
      case 0x2: //0b010:
        pbuff1[i+2] = 2;
        break;
      case 0x1: //0b001:
        pbuff1[i+2] = 3;
        break;
      case 0x0: //0b000
        POP(0);
        i--;
        break;
      default:
        skip_tuple();
        return true;
    }
    if (read_tuple(0)->state == 0) {
      break;
    }
  }
  
  //set count
  pbuff1[1] = i+1+2;  // +2 mean header size

  return true;
}

static void skip_tuple(void)
{
  while ((size_tuple() > 0) && (read_tuple(0)->state != 0)) {
    pop_tuple((gesture_tuple*)0);
  }
  if (size_tuple()) {
    pop_tuple((gesture_tuple*)0);
  }
}

static int size_tuple(void)
{
  return g_tuple_buffer.size;
}

static void clear_tuple(void)
{
  memset(&g_tuple_buffer, 0, sizeof(g_tuple_buffer));
}

static gesture_tuple* read_tuple(int index)
{
  if (size_tuple() <= 0) {
    return (gesture_tuple*)0;
  }
  if (index == 0) {
    return &g_tuple_buffer.data[g_tuple_buffer.tail];
  } else if (index <= size_tuple()) {
    return &g_tuple_buffer.data[(g_tuple_buffer.tail + index) % CONFIG_SPRING_GESTURE_SEQ_SIZE];
  }
  return (gesture_tuple*)0;
}

static bool pop_tuple(gesture_tuple* p_tuple) 
{
  if (size_tuple() <= 0) {
    return false;
  }
  
  if (p_tuple) {
    memcpy(p_tuple, &g_tuple_buffer.data[g_tuple_buffer.tail], sizeof(gesture_tuple));
  }
  memset(&g_tuple_buffer.data[g_tuple_buffer.tail], 0, sizeof(gesture_tuple));
  --g_tuple_buffer.size;

  g_tuple_buffer.tail = (g_tuple_buffer.tail+1) % CONFIG_SPRING_GESTURE_SEQ_SIZE;
 
  return true;
}

bool write_tuple(gesture_tuple *p_tuple)
{
  if (p_tuple == NULL) {
    return false;
  }
  if (size_tuple() >= CONFIG_SPRING_GESTURE_SEQ_SIZE) {
    clear_tuple();
  }

  memcpy(&g_tuple_buffer.data[g_tuple_buffer.head], p_tuple, sizeof(gesture_tuple));

  ++g_tuple_buffer.size;
  
  g_tuple_buffer.head = (g_tuple_buffer.head + 1) % CONFIG_SPRING_GESTURE_SEQ_SIZE;

  return true;
}

static char scheme_comp(char *pbuf)
{
  char gesture = SPRING_GESTURE_NONE;
  scheme_list *p_scheme_list = NULL;
  char *scheme = NULL;
  int i;

  if (pbuf == NULL) {
    return gesture;
  }

  p_scheme_list = &g_gesture_scheme[(unsigned char)pbuf[0]];
  for (i=0; i<p_scheme_list->count; i++) {
    scheme = p_scheme_list->seqlist[i];
    //scheme size same as buf size
    if (scheme[0] == pbuf[1]) {
      if (memcmp(&scheme[2], &pbuf[2], pbuf[1]-2) == 0) {
        gesture = scheme[1];
        break;
      }
    }
  }
  return gesture;
}

static int gesture_analyse(void)
{
  char  state1[50];
  char  state2[50];
  bool  b_comp = false;
  char  first_gesture  = SPRING_GESTURE_NONE;
  char  second_gesture = SPRING_GESTURE_NONE;
  char  gesture        = SPRING_GESTURE_NONE;
  int   i,size;
  uint32_t   time = 0;
  
  memset(state1, 0, sizeof(state1));
  memset(state2, 0, sizeof(state2));
  
  while (1) {
    time = HAL_GetTick();
    wait_user_input(INFINITE);
    if (HAL_GetTick() - time > CONFIG_SPRING_GESTURE_TIMEOUT) {
      clear_tuple();
      continue;
    }
    memset(state1, 0, sizeof(state1));
    memset(state2, 0, sizeof(state2));
    if (calc_tuple_transfer(state1) == false) {
      continue;
    }
    gesture_uart_sendbyte(0xF2);
    gesture_uart_senddata(10,state1);
    gesture_uart_sendbyte(0xF3);
    //gesture_uart_sendstr("\r\n");
    if (state1[0] > NUM_SCHEME) {
      continue;
    }
    // check whether a component gesture occured
    size = size_tuple();
    HAL_Delay(T); // sleep
    if (size_tuple() != size) {
      //component gesture, wait for user input finish
      time = HAL_GetTick();
      wait_user_input(INFINITE);
      if (HAL_GetTick() - time > CONFIG_SPRING_GESTURE_TIMEOUT) {
        clear_tuple();
        continue;
      }
      if (calc_tuple_transfer(state2) == FALSE) {
        continue;;
      }
      gesture_uart_sendbyte(0xF4);
      gesture_uart_senddata(10,state2);
      gesture_uart_sendbyte(0xF5);
      b_comp = TRUE;
    }
    //find first gesture
    first_gesture = scheme_comp(state1);
    if (b_comp) {
      second_gesture = scheme_comp(state2);
    }

    if (b_comp) {
      //gesture_uart_sendstr("COMP\r\n");
      gesture = ((first_gesture&SPRING_GESTURE_MASK)<<SPRING_GESTURE_SHIFT | 
              (second_gesture&SPRING_GESTURE_MASK));
    } else {
      //gesture_uart_sendstr("ONLY\r\n");
      gesture = first_gesture;
    }
    b_comp = FALSE;
    if (gesture) {
      gesture_uart_sendbyte(0xF6);
      gesture_uart_sendbyte(gesture);
      gesture_uart_sendbyte(0xF7);
    }
  }

}

int main(int argc, char **argv)
{
  HAL_Init(); 
  BSP_LED_Init(LED0);
  gesture_uart_init();
  gesture_init();
 
  
  while (1) {
    gesture_analyse();
  }
  
  return 0;
}
