#pragma once

#include "libc/stdint.h"
#include "libc/stdbool.h" // for bool


int putchar(int ic);
int printf(const char* __restrict__ format, ...);
bool print(const char* data, size_t length);

#pragma once

int putchar(int ic);
bool print(const char* data, size_t length);
int printf(const char* __restrict__ format, ...);