#pragma once

#include "log.h"

// Return states
typedef enum {
	SUCCESS = 0,
	FAIL,
	ERROR_PW_LOOP_CREATION,
	ERROR_PW_CONTEXT_CREATION,
	ERROR_PW_CONTEXT_CONNECTION
} Result;

void printResult(Result r);

#define CHECK_RESULT(state) do {	\
	if (state != SUCCESS) {		\
		printResult(state);	\
		return state;		\
	}				\
} while(0)
