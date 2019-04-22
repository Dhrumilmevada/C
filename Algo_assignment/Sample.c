/*
Write a program to "fold" long input lines into two or more shorter lines after the last non-blank character that occurs before the n -th column of input. Make sure your program does something intelligent with very long lines, and if there are no blanks or tabs before the specified column. 
*/

/******************************************************************************
 *
 * @file    exe4_sam.c
 * @author  einfochips
 * @brief   This file folds long input lines in to shorter lines.
 * @date
 *          JUL/16/2018,Created
 *****************************************************************************/
/******************************************************************************
The program works in following manner:

User can pass following 3 arguments:
1. Maximum length of output line - a positive integer number.
2. Name of input file - a character string.
3. Name of output file - a character string.
The max length can be practically anything. We will restrict it to the max size
of uint32 for now. We will also be strict about the location of this #. It has
to be the 1st arg. If user omits the number, we will default to 80 chars.
If user omits the file name, we will default to stdin. There is a constraint
 here. If user specified only 1 filename, we will assume it to be input.
If user omits the 2nd file name, we will default to stdout.

We will parse the command lines first & configure all parameters. The program
will stop if there are invalid parameters.

We will then open the input & output files for reading & writing respectively.
We will do whole processing at a time on 1 input line. Read the line, parse it,
write to output & then read next.

CONSTRAINTS:
1. If the output is stdout, the actual output may wary depending on the size of
 the window.
2. This program will work only on Linux. It won't work on Windows where a new-
  line is done by \n\r.
3. If there is a tab in the input, there is no way to know how many spaces are
  to be considered. So, whenever a tab comes, the program will output those 
  many chars extra in that line.
 *****************************************************************************/

/***************
 * Include Files
 ***************/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


/********
 * MACROS
 ********/
#define DEF_OUT_LEN     80  // Default length of output line

// Error codes
#define ERR_CMD_LINE    -1  // Error in command line
#define ERR_FILE        -2  // Error in processing file

#define ERROR_DISP  printf  // Defines how we will display errors.


/******************
 * Global Variables
 ******************/
unsigned long   maxOutLen;      // Holds the max length of output line.
FILE        *inFilePtr;     // points to the input file for line processing
FILE        *outFilePtr;    // points to the output file for line storing
char        *inputFileName; // Holds the name of input file if user specified.
char        *outputFileName;     // Holds the name of output file if user
                                 // specified.


/*********************
 * Function Prototypes
 *********************/
int parseCmdLine (int, char *argv[]);
int foldLine (char *, unsigned long);
int processLines ();
void printUsage ();
void releaseResources ();


/** Function    main
 * @date        JUL/16/2018
 * @brief       Main function of the program.
 * @param       int: argc: # of command line arguments
 *	        	char *: argv: the char array to hold each command line arg.
 * @return      int: the result of execution.
 *		        0: success
 *		        -ve: on various failures.
 *                  -1: if command line is incorrect.
 */
int main (int argc, char *argv[])
{
    if (parseCmdLine(argc, argv))
    {
        releaseResources();
        return ERR_CMD_LINE;
    }

    if (processLines())
    {
        releaseResources();
        return ERR_FILE;
    }

    releaseResources();
    return 0;
}   // End of main


/** Function    parseCmdLine
 * @date        DEC/11/2008
 * @brief       Parses the commnad line options.
 * @param       int: argc: # of command line arguments
 *	        	char *: argv: the char array to hold each command line arg.
 * @return      int: the result of execution.
 *		        0: success
 *		        -ve: on various failures.
 */
int parseCmdLine (int argc, char *argv[])
{
    int index = 0;    // to loop through argv

    inputFileName = NULL;
    outputFileName = NULL;

    // User wants to go with default i.e. 80 chars, std in & out.
    if (argc <= 1)
    {
        maxOutLen = DEF_OUT_LEN;
        inFilePtr = stdin;
        outFilePtr = stdout;
    }
    else
    {
        // Get the max length of output line
        if ( (maxOutLen = atoi (argv[1]) ) <= 0 )
        {
            ERROR_DISP ("\nERROR: The 1st parameter should be a reasonable positive integer value.");
            ERROR_DISP ("\n       It should specify maximum length of output line.");
            ERROR_DISP ("\n       The value that you provided \"%s\", doesn't seem to be correct.", argv[1]);
            ERROR_DISP ("\n       Re run the program with proper value.\n");

            return ERR_CMD_LINE;
        }

        // Get the name of input file.
        if (argv[2] != NULL )
        {
            if (access (argv[2], F_OK) != 0)
            {
                ERROR_DISP ("\nERROR: The 2nd parameter should be name of an existing text input file.");
                ERROR_DISP ("\n       The value that you provided \"%s\", doesn't seem to be correct.", argv[2]);
                ERROR_DISP ("\n       Re run the program with proper value.\n");
    
                return ERR_CMD_LINE;
            }
            else
            {
                inputFileName = (char *)malloc ( strlen(argv[2]) * sizeof (char) );
                strcpy (inputFileName, argv[2]);
            }
        }
        else    inFilePtr = stdin;

        // Get the name of output file.
        if (argv[3] == NULL )
            outFilePtr = stdout;
        else
        {
            outputFileName = (char *)malloc ( strlen(argv[3]) * sizeof (char) );
            strcpy (outputFileName, argv[3]);
        }

    }

    return 0;
}   // End of parseCmdLine


/** Function    foldLine
 * @date        JUL/16/2018
 * @brief       Folds each line exceeding a certain limit into shorter lines.
 * @param       char *: buffer to process
 *              unsigned long: Bytes to read
 * @return      int: the remaining characters to output from current line.
 */
int foldLine (char *inBuf, unsigned long bytesToRead)
{
    unsigned long bufLen = strlen (inBuf);
    unsigned long index = bufLen;

    // Easy thing 1st: the lines that are shorter than the max output length,
    // just print them.
    if (inBuf[maxOutLen] == '\n' || bufLen < bytesToRead - 1)
    {
        fputs (inBuf, outFilePtr);
        return 0;
    }

    // We need to find the last possible white space in the line.
    while ( !isspace (inBuf[index]) && index != 0 )
        index--;

    // If there is no white space in whole line, we will print whole line but
    // the last char. And then we put a '-' to show that the next line is in
    // continuation of this line. Then we print the last char in next line.
    if (index == 0)
    {
        fwrite (inBuf, sizeof (char), bufLen - 1, outFilePtr);
        fwrite ("-\n", sizeof (char), 2, outFilePtr);
        fwrite (&inBuf[bufLen-1], sizeof (char), 1, outFilePtr);
        index = 1;
    }
    /*
     If we found a white space, we print till that location. Then,
     we print rest of the chars in next line.
    */
    else
    {
        fwrite (inBuf, sizeof (char), index, outFilePtr);
        fwrite ("\n", sizeof (char), 1, outFilePtr);
        fwrite (&inBuf[index], sizeof (char), bufLen - index, outFilePtr);
        index = bufLen - index;
    }


    return index;
}   // End of foldLine


/** Function    processLines
 * @date        JUL/16/2018
 * @brief       Main function of the program.
 * @param       None
 * @return      int: the result of execution.
 *		        0: success
 *		        -ve: on various failures.
 */
int processLines()
{
    char    *inBuffer;   // Buffer to hold input lines. We process lines longer
                         // than max output in next turn.
    unsigned long bytesToRead = 0;

    if (inputFileName != NULL)
        if ( (inFilePtr = fopen (inputFileName, "r") ) == NULL )
        {
            ERROR_DISP ("\nERROR: Could not open the file \"%s\" for reading.", inputFileName);
            ERROR_DISP ("\n       Make sure the file exists.");
            ERROR_DISP ("\n       Program will exit now.\n");
            return ERR_FILE;
        }

    if (outputFileName != NULL)
        if ( (outFilePtr = fopen (outputFileName, "w") ) == NULL )
        {
            ERROR_DISP ("\nERROR: Could not open the file \"%s\" for writing.", outputFileName);
            ERROR_DISP ("\n       Make sure the permissions for writing file on the disk are proper.");
            ERROR_DISP ("\n       Program will exit now.\n");
            return ERR_FILE;
        }

    inBuffer = (char *)calloc (maxOutLen + 1, sizeof (char) );

    // Process whole file line by line now.
    bytesToRead = maxOutLen + 1;
    while ( !feof(inFilePtr) )
    {
        if ( fgets (inBuffer, bytesToRead, inFilePtr) != NULL )
        {
            bytesToRead = maxOutLen - foldLine (inBuffer, bytesToRead) + 1;
        }
    }

    free (inBuffer);
    return 0;
}   // End of processLines


/** Function    printUsage
 * @date        JUL/16/2018
 * @brief       Prints the usage of this program
 * @param       None
 * @return      None
 */
void printUsage()
{
    printf ("\nFold line program");
    printf ("\nUsage: foldline [n] [input_file [output_file] ]");
    printf ("\nWhere,");
    printf ("\n    optinal n: maximum length of output line");
    printf ("\n    optinal input_file: Name of input file (otherwise, standard input)");
    printf ("\n    optinal output_file: Name of output file (otherwise, standard output:");
}   // End of processLines


/** Function    releaseResources
 * @date        JUL/16/2018
 * @brief       Closes all open resources
 * @param       None
 * @return      None
 */
void releaseResources()
{
    if (inFilePtr)
        fclose (inFilePtr);

    if (outFilePtr)
        fclose (outFilePtr);

    if (inputFileName)
        free (inputFileName);

    if (outputFileName)
        free (outputFileName);

}   // End of releaseResources
