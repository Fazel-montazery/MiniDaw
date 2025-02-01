#pragma once

#include <stdio.h>
#include <stdarg.h>

#define RED "\e[0;31m"
#define GRN "\e[0;32m"
#define YEL "\e[0;33m"
#define CRESET "\e[0m"

// Simple logging
void printError(const char* format, ...);
void printWarning(const char* format, ...);
void printMsg(const char* format, ...);
