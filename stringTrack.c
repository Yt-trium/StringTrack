#include "stringTrack.h"

void voidStringTrack(char *fileName, char *string)
{
	printf("> Searching %s in %s ...\n",string,fileName);
	
	int file = 0;					// File descriptor
	unsigned int readedChar = 0;	// Number of char readed
	unsigned char buffer[SIZEBUF];	// buffer for reading
	unsigned int i = 0;				// counter
	unsigned int stringLen = 0;		// Length of string
	unsigned int validChar = 0;		// Number of actual valid char
	unsigned int lineNumber = 1;	// Number of the actual line
	struct stat fileST; 			// stat structure for file stat
	long int fileSize = 0;			// Length of file
	long int readSize = 0;			// Readed byte
	
	stringLen = strlen(string);
	
	file = open(fileName, O_RDONLY);
	
	if(file == -1)
	{
		fprintf(stderr, "ERROR: open() - %s - %d\n", strerror(errno), errno);
		return;
	}
	
	if (stat(fileName, &fileST) == 0)
        fileSize = fileST.st_size;
	
	
	while((readedChar = read(file, buffer, SIZEBUF)) > 0)
	{
		// NEED TO LIMIT OUTPUT TO 10
		if(1)	// TODO		
			printf("%ld / %ld\n", readSize, fileSize);
		
		readSize += SIZEBUF;
		
		for(i=0;i<readedChar;i++)	// For each character
		{
			if(buffer[i] == '\n')
				lineNumber++;
				
			if(buffer[i] == string[validChar])
			{
				validChar++;
				if(validChar == stringLen)
				{
					printf("Founded line %d !\n", lineNumber);
				}
			}
			else
			{
				validChar = 0;
			}
		}
	}
	
	close(file);	
}
