#pragma once

#include <cstdint>

#define i8  int8_t
#define i16 int16_t
#define i32 int32_t
#define i64 int64_t
#define u8  uint8_t
#define u16 uint16_t
#define u32 uint32_t
#define u64 uint64_t
#define f32 float
#define f64 double

#define SCREEN_HEIGHT 480
#define SCREEN_WIDTH 640

#define MAX(X,Y) ((X>=Y) ? X : Y)
#define MIN(X,Y) ((X<=Y) ? X : Y)

#define ABS(X) ((X < 0) ? -X : X)
#define SIGN(X) ((X < 0) ? -1 : 1)

#define SQ(X) ((X) * (X))
