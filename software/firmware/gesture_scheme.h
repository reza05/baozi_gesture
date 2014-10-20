#ifndef _GESTURE_SCHEME_H
#define _GESTURE_SCHEME_H

#include "gesture.h"

//Gesture scheme list
// scheme for 001
static char g_scheme001_1_1[] = {
  5+2,SPRING_GESTURE_UP_RIGHT,
  1,2,1,2,3
};
static char g_scheme001_1_2[] = {
  5+2,SPRING_GESTURE_UP,
  1,2,1,3,2
};
static char g_scheme001_1_3[] = {
  5+2,SPRING_GESTURE_UP_DOWN,
  1,2,2,1,3
};
static char g_scheme001_1_4[] = {
  5+2,SPRING_GESTURE_UP_DOWN,
  1,2,2,3,1
};
static char g_scheme001_1_5[] = {
  5+2,SPRING_GESTURE_UP,
  1,2,3,1,2
};
static char g_scheme001_1_6[] = {
  5+2,SPRING_GESTURE_UP_LEFT,
  1,2,3,2,1
};
static char g_scheme001_1_7[] ={
  7+2,SPRING_GESTURE_UP_RIGHT,
  1,2,1,1,1,2,3
};
static char g_scheme001_1_8[] ={
  7+2,SPRING_GESTURE_UP_LEFT,
  1,2,1,1,3,2,1
};
static char g_scheme001_1_9[] ={
  7+2,SPRING_GESTURE_UP_RIGHT,
  1,2,2,2,1,2,3
};
static char g_scheme001_1_10[] = {
  7+2,SPRING_GESTURE_UP_LEFT,
  1,2,2,2,3,2,1
};
static char g_scheme001_1_11[] = {
  7+2,SPRING_GESTURE_UP_RIGHT,
  1,2,3,3,1,2,3
};
static char g_scheme001_1_12[] = {
  7+2,SPRING_GESTURE_UP_LEFT,
  1,2,3,3,3,2,1
};
static char g_scheme001_2_1[] = {
  7+2,SPRING_GESTURE_LEFT_UP,
  2,1,1,1,1,3,2
};
static char g_scheme001_2_2[] = {
  7+2,SPRING_GESTURE_LEFT_UP,
  2,1,1,1,3,1,2
};
static char g_scheme001_2_3[] = {
  5+2,SPRING_GESTURE_LEFT_RIGHT,
  2,1,1,2,3
};
static char g_scheme001_2_4[] = {
  5+2,SPRING_GESTURE_LEFT_UP,
  2,1,1,3,2
};
static char g_scheme001_2_5[] = {
  5+2,SPRING_GESTURE_LEFT_DOWN,
  2,1,2,1,3
};
static char g_scheme001_2_6[] = {
  5+2,SPRING_GESTURE_LEFT_DOWN,
  2,1,2,3,1
};
static char g_scheme001_2_7[] = {
  5+2,SPRING_GESTURE_LEFT_UP,
  2,1,3,1,2
};
static char g_scheme001_2_8[] = {
  5+2,SPRING_GESTURE_LEFT,
  2,1,3,2,1
};
static char g_scheme001_2_9[] = {
  7+2,SPRING_GESTURE_LEFT_UP,
  2,1,3,3,1,3,2
};
static char g_scheme001_2_10[] = {
  7+2,SPRING_GESTURE_LEFT_UP,
  2,1,3,3,3,1,2
};
static char g_scheme001_2_11[] = {
  5+2,SPRING_GESTURE_LEFT,
  2,3,1,2,1
};
static char g_scheme001_2_12[] = {
  7+2,SPRING_GESTURE_LEFT_DOWN,
  2,1,1,1,2,1,3
};
static char g_scheme001_2_13[] = {
  7+2,SPRING_GESTURE_LEFT_DOWN,
  2,1,1,1,2,3,1
};
static char g_scheme001_2_14[] = {
  7+2,SPRING_GESTURE_LEFT_UP,
  2,1,2,2,1,3,2
};
static char g_scheme001_2_15[] = {
  7+2,SPRING_GESTURE_LEFT_DOWN,
  2,1,2,2,2,1,3
};
static char g_scheme001_2_16[] = {
  7+2,SPRING_GESTURE_LEFT_DOWN,
  2,1,2,2,2,3,1
};
static char g_scheme001_2_17[] = {
  7+2,SPRING_GESTURE_LEFT_UP,
  2,1,2,2,3,1,2
};
static char g_scheme001_2_18[] = {
  7+2,SPRING_GESTURE_LEFT_DOWN,
  2,1,3,3,2,1,3
};
static char g_scheme001_2_19[] = {
  7+2,SPRING_GESTURE_LEFT_DOWN,
  2,1,3,3,2,3,1
};
static char* g_scheme001[] = {
  g_scheme001_1_1,
  g_scheme001_1_2,
  g_scheme001_1_3,
  g_scheme001_1_4,
  g_scheme001_1_5,
  g_scheme001_1_6,
  g_scheme001_1_7,
  g_scheme001_1_8,
  g_scheme001_1_9,
  g_scheme001_1_10,
  g_scheme001_1_11,
  g_scheme001_1_12,
  g_scheme001_2_1,
  g_scheme001_2_2,
  g_scheme001_2_3,
  g_scheme001_2_4,
  g_scheme001_2_5,
  g_scheme001_2_6,
  g_scheme001_2_7,
  g_scheme001_2_8,
  g_scheme001_2_9,
  g_scheme001_2_10,
  g_scheme001_2_11,
  g_scheme001_2_12,
  g_scheme001_2_13,
  g_scheme001_2_14,
  g_scheme001_2_15,
  g_scheme001_2_16,
  g_scheme001_2_17,
  g_scheme001_2_18,
  g_scheme001_2_19
};

// scheme for 010
static char g_scheme010_1_1[] = {
  5+2,SPRING_GESTURE_DOWN_RIGHT,
  1,3,1,2,3
};
static char g_scheme010_1_2[] = {
  5+2,SPRING_GESTURE_DOWN_UP,
  1,3,1,3,2
};
static char g_scheme010_1_3[] = {
  5+2,SPRING_GESTURE_DOWN,
  1,3,2,1,3
};
static char g_scheme010_1_4[] = {
  5+2,SPRING_GESTURE_DOWN,
  1,3,2,3,1
};
static char g_scheme010_1_5[] = {
  5+2,SPRING_GESTURE_DOWN_UP,
  1,3,3,1,2
};
static char g_scheme010_1_6[] = {
  5+2,SPRING_GESTURE_DOWN_LEFT,
  1,3,3,2,1
};
static char g_scheme010_3_1[] = {
  5+2,SPRING_GESTURE_DOWN_UP,
  3,1,1,3,2
};
static char g_scheme010_3_2[] = {
  5+2,SPRING_GESTURE_DOWN,
  3,1,2,1,3
};
static char g_scheme010_3_3[] = {
  5+2,SPRING_GESTURE_DOWN,
  3,1,2,3,1
};
static char g_scheme010_3_4[] = {
  5+2,SPRING_GESTURE_DOWN_UP,
  3,1,3,1,2
};
static char g_scheme010_3_5[] = {
  5+2,SPRING_GESTURE_DOWN_LEFT,
  3,1,3,2,1
};
static char* g_scheme010[] = {
  g_scheme010_1_1,
  g_scheme010_1_2,
  g_scheme010_1_3,
  g_scheme010_1_4,
  g_scheme010_1_5,
  g_scheme010_1_6,
  g_scheme010_3_1,
  g_scheme010_3_2,
  g_scheme010_3_3,
  g_scheme010_3_4,
  g_scheme010_3_5
};

//scheme for 011
static char g_scheme011_1_1[] = {
  4+2,SPRING_GESTURE_LEFT,
  1,3,2,1
};
static char g_scheme011_2_1[] = {
  2+2,SPRING_GESTURE_RIGHT,
  2,3
};
static char g_scheme011_3_1[] = {
  2+2,SPRING_GESTURE_UP,
  3,2
};
static char* g_scheme011[] = {
  g_scheme011_1_1,
  g_scheme011_2_1,
  g_scheme011_3_1
};

//scheme for 100
static char g_scheme100_2_1[] = {
  5+2,SPRING_GESTURE_RIGHT,
  2,3,1,2,3
};
static char g_scheme100_2_2[] = {
  5+2,SPRING_GESTURE_RIGHT_UP,
  2,3,1,3,2
};
static char g_scheme100_2_3[] = {
  5+2,SPRING_GESTURE_RIGHT_DOWN,
  2,3,2,1,3
};
static char g_scheme100_2_4[] = {
  5+2,SPRING_GESTURE_RIGHT_DOWN,
  2,3,2,3,1
};
static char g_scheme100_2_5[] = {
  5+2,SPRING_GESTURE_RIGHT_UP,
  2,3,3,1,2
};
static char g_scheme100_2_6[] = {
  5+2,SPRING_GESTURE_RIGHT_LEFT,
  2,3,3,2,1
};
static char g_scheme100_2_7[] = {
  7+2,SPRING_GESTURE_RIGHT_UP,
  2,3,1,1,1,3,2
};
static char g_scheme100_2_8[] = {
  7+2,SPRING_GESTURE_RIGHT_DOWN,
  2,3,1,1,2,1,3
};
static char g_scheme100_2_9[] = {
  7+2,SPRING_GESTURE_RIGHT_DOWN,
  2,3,1,1,2,3,1
};
static char g_scheme100_2_10[] = {
  7+2,SPRING_GESTURE_RIGHT_UP,
  2,3,2,2,1,3,2
};
static char g_scheme100_2_11[] = {
  7+2,SPRING_GESTURE_DOWN,
  2,3,2,2,2,1,3
};
static char g_scheme100_2_12[] = {
  7+2,SPRING_GESTURE_DOWN,
  2,3,2,2,2,3,1
};
static char g_scheme100_2_13[] = {
  7+2,SPRING_GESTURE_RIGHT_UP,
  2,3,3,3,1,3,2
};
static char g_scheme100_2_14[] = {
  7+2,SPRING_GESTURE_DOWN,
  2,3,3,3,2,1,3
};
static char g_scheme100_2_15[] = {
  7+2,SPRING_GESTURE_DOWN,
  2,3,3,3,2,3,1
};
static char g_scheme100_3_1[] = {
  5+2,SPRING_GESTURE_UP_RIGHT,
  3,2,1,2,3
};
static char g_scheme100_3_2[] = {
  5+2,SPRING_GESTURE_UP,
  3,2,1,3,2
};
static char g_scheme100_3_3[] = {
  5+2,SPRING_GESTURE_UP_DOWN,
  3,2,2,1,3
};
static char g_scheme100_3_4[] = {
  5+2,SPRING_GESTURE_UP_DOWN,
  3,2,2,3,1
};
static char g_scheme100_3_5[] = {
  5+2,SPRING_GESTURE_UP,
  3,2,3,1,2
};
static char g_scheme100_3_6[] = {
  5+2,SPRING_GESTURE_UP_LEFT,
  3,2,3,2,1
};
static char* g_scheme100[] = {
  g_scheme100_2_1,
  g_scheme100_2_2,
  g_scheme100_2_3,
  g_scheme100_2_4,
  g_scheme100_2_5,
  g_scheme100_2_6,
  g_scheme100_2_7,
  g_scheme100_2_8,
  g_scheme100_2_9,
  g_scheme100_2_10,
  g_scheme100_2_11,
  g_scheme100_2_12,
  g_scheme100_2_13,
  g_scheme100_2_14,
  g_scheme100_2_15,
  g_scheme100_3_1,
  g_scheme100_3_2,
  g_scheme100_3_3,
  g_scheme100_3_4,
  g_scheme100_3_5,
  g_scheme100_3_6
};

//scheme for 101
static char g_scheme101_2_1[] = {
  4+2,SPRING_GESTURE_UP,
  2,1,3,2
};
static char g_scheme101_2_2[] = {
  4+2,SPRING_GESTURE_UP,
  2,3,1,2
};
static char* g_scheme101[] = {
  g_scheme101_2_1,
  g_scheme101_2_2
};

// scheme for 110
static char g_scheme110_1_1[] = {
  2+2,SPRING_GESTURE_UP,
  1,2
};
static char g_scheme110_2_1[] = {
  2+2,SPRING_GESTURE_LEFT,
  2,1
};
static char g_scheme110_3_1[] = {
  4+2,SPRING_GESTURE_RIGHT,
  3,1,2,3
};
static char g_scheme110_3_2[] = {
  4+2,SPRING_GESTURE_DOWN,
  3,2,1,3
};
static char g_scheme110_3_3[] = {
  4+2,SPRING_GESTURE_DOWN,
  3,2,3,1
};
static char* g_scheme110[] = {
  g_scheme110_1_1,
  g_scheme110_2_1,
  g_scheme110_3_1,
  g_scheme110_3_2,
  g_scheme110_3_3
};

//scheme for 111
static char g_scheme111_1_1[] = {
  3+2,SPRING_GESTURE_RIGHT,
  1,2,3
};
static char g_scheme111_1_2[] = {
  3+2,SPRING_GESTURE_UP,
  1,3,2
};
static char g_scheme111_2_1[] = {
  3+2,SPRING_GESTURE_DOWN,
  2,1,3
};
static char g_scheme111_2_2[] = {
  3+2,SPRING_GESTURE_DOWN,
  2,3,1
};
static char g_scheme111_3_1[] = {
  3+2,SPRING_GESTURE_UP,
  3,1,2
};
static char g_scheme111_3_2[] = {
  3+2,SPRING_GESTURE_LEFT,
  3,2,1
};
static char* g_scheme111[] = {
  g_scheme111_1_1,
  g_scheme111_1_2,
  g_scheme111_2_1,
  g_scheme111_2_2,
  g_scheme111_3_1,
  g_scheme111_3_2
};

static scheme_list g_gesture_scheme[8] = {
  //000
  {0,0},
  //001
  {31, g_scheme001},
  //010
  {11,g_scheme010},
  //011
  {3, g_scheme011},
  //100
  {21, g_scheme100},
  //101
  {2, g_scheme101},
  //110
  {5,g_scheme110},
  //111
  {6,g_scheme111},
};

#define NUM_SCHEME  (sizeof(g_gesture_scheme)/sizeof(scheme_list))

#endif
