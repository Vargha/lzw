#include "main.h"


int main(int argc, char* argv[])
{
	char inpFlg = 'N';																// Flag for input file existence
	char outFlg = 'N';																// Flag for output file existence
	char inputFile[200];
	char outputFile[200];
	char	mode;																				// Encode / Decode flag


  if (argc<2 || 6<argc)															// If wrong number of command line arguments
  {
    cmdWarning();
  } else
  {
		if (strcmp(argv[1],"-help") == 0)								// Help messages
		{
			cmdHelp();
		}
		else if (strcmp(argv[1],"-encode") == 0)					// Compress/Encode the file
    {
			mode = 'E';
		}
		else if (strcmp(argv[1],"-decode") == 0) 				// Decompress/Dencode the file
    {
			mode = 'D';
		}
		else																						// if enything other than -encode or -decode
			cmdWarning();								
	}



	if (argc==2 && strcmp(argv[1],"-help")!=0)				// if encode from command line
	{
    printf (ANSI_COLOR_BLUE  "\tEncoding/Decoding from the command line. Please type your data below:\n\n"  ANSI_COLOR_RESET);
	}
	else if (argc>=4)
	{
		if (strcmp(argv[2],"-input") == 0)
		{
			inpFlg = 'Y';																	// There exist and inputFile
			strcpy(inputFile, argv[3]);
			printf ("\t\tCommand: ./lzw <-encode> <-input> <address>\n\n");
		}else if (strcmp(argv[2],"-output") == 0)
		{
			outFlg = 'Y';																	// There exist and outputFile
			strcpy(outputFile, argv[3]);
			printf ("\t\tCommand: ./lzw <-encode> <-outnput> <address>\n\n");
		}
	}

	if (argc==6)
	{
		if (strcmp(argv[4],"-input") == 0)
		{
			inpFlg = 'Y';																	// There exist and inputFile
			strcpy(inputFile, argv[5]);
			printf ("\t\tCommand: ./lzw <-encode> <-input/-output> <address>  <-input> <address>\n\n");
		}else if (strcmp(argv[4],"-output") == 0)
		{
			outFlg = 'Y';																	// There exist and outputFile
			strcpy(outputFile, argv[5]);
			printf ("\t\tCommand: ./lzw <-encode> <-input/-output> <address>  <-output> <address>\n\n");
		}
	}


//  Bits* b = newBits(stdin);

  return 0;
}




/*****************************************************************************************/
void cmdHelp() 	                            			// If user wants to see the help message
{
	printf("Usage:\t./lzw <option1> <option2>...  <optionN>\n\n");
	printf("\tWhere <option>'s must be one or more of the following (in any order):\n\n");
	printf("\t\t-help\t\t\tprint this message\n\n");
	printf("\t\t-encode\t\t\tcompress the input data\n\n");
	printf("\t\t-decode\t\t\texpand the compressed input\n\n");
	printf("\t\t\t\t\t(exactly one of -encode\n");
	printf("\t\t\t\t\tor -decode must be present)\n\n");
	printf("\t\t-debug <level>\t\twhere <level> is a positive integer\n\n");
	printf("\t\t-input <pathname>\tread data from file specified by <pathname>\n");
	printf("\t\t\t\t\t(if -input is not specified, stdin is used)\n\n");
	printf("\t\t-output <pathname>\twrite output to file specified by <pathname>\n");
	printf("\t\t\t\t\t(if -output is not specified, stdout is used)\n");
	return;
}

void cmdError()																		// Improper use of command line arguments
{
printf (ANSI_COLOR_RED  "ERROR: "  ANSI_COLOR_RESET);
				printf ("\tImproper use of command line arguments.\n\tUse ");
				printf (ANSI_COLOR_GREEN  "./lzw -help"  ANSI_COLOR_RESET);
				printf(" command for help. \n\n");
	return;
}

void cmdWarning()                             		// If wrong number of command line arguments
{
	printf(ANSI_COLOR_YELLOW  "Warning: "  ANSI_COLOR_RESET);
	printf("Nothing to do. Specify either -encode or -decode.\n\n");
	cmdHelp();
	return;
}
