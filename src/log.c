#include "log.h"

// Simple logging
void printError(const char* format, ...)
{
	va_list args;

	va_start(args, format);
	fprintf(stderr, RED);
	vfprintf(stderr, format, args);
	fprintf(stderr, CRESET);
	va_end(args);
}

void printWarning(const char* format, ...)
{
	va_list args;

	va_start(args, format);
	fprintf(stdout, YEL);
	vfprintf(stdout, format, args);
	fprintf(stdout, CRESET);
	va_end(args);
}

void printMsg(const char* format, ...)
{
	va_list args;

	va_start(args, format);
	fprintf(stdout, GRN);
	vfprintf(stdout, format, args);
	fprintf(stdout, CRESET);
	va_end(args);
}
