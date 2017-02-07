#ifndef MAIN_H
#define MAIN_H
  #include <stdio.h>
	#include <string.h>
  #include "bits.h"
	#include "seq.h"
	#include "lzw.h"

	#define ANSI_COLOR_RED     "\x1b[31m"
	#define ANSI_COLOR_GREEN   "\x1b[32m"
	#define ANSI_COLOR_YELLOW  "\x1b[33m"
	#define ANSI_COLOR_BLUE    "\x1b[34m"
	#define ANSI_COLOR_MAGENTA "\x1b[35m"
	#define ANSI_COLOR_CYAN    "\x1b[36m"
	#define ANSI_COLOR_RESET   "\x1b[0m"

	void cmdHelp();												// Command line error generator function
	void cmdError();											// Improper use of command line arguments
	void cmdWarning();										// Wrong number of command line arguments


#endif
