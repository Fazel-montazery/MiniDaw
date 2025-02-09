#include "state.h"

void printResult(Result r)
{
	switch (r) {
	case SUCCESS:
		printMsg("SUCCESS!\n");

	case FAIL:
		printError("FAIL!\n");

	case ERROR_PW_LOOP_CREATION:
		printError("Couldn't create pipewire main loop!\n");

	case ERROR_PW_CONTEXT_CREATION:
		printError("Couldn't create pipewire main loop context!\n");

	case ERROR_PW_CONTEXT_CONNECTION:
		printError("Couldn't connect to pipewire daemon!\n");

	default:
		printError("Unknown Result!\n");
	}
}
