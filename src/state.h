#pragma once

#include "log.h"

// Return states
typedef enum {
        SUCCESS = 0,
        FAIL
} Result;

void printResult(Result r);

#define CHECK_RESULT(state) do {        \
        if (state != SUCCESS) {         \
                printResult(state);     \
                return state;           \
        }                               \
} while(0)
