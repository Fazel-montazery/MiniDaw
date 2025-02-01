#include "state.h"

void printResult(Result r)
{
	switch (r) {
        case SUCCESS:
                printMsg("SUCCESS!\n");

        case FAIL:
                printError("FAIL!\n");
                
	default:
                printError("Unknown Result!\n");
        }
}
