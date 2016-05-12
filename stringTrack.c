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
	long int numberOfPack = 0;		// Number of SIZEBUF buffer to read
	long int j = 0;					// counter for the read loop
	long int tmp_var_1 = 0;			// Variable temporaire 1
	
	stringLen = strlen(string);
	
	file = open(fileName, O_RDONLY);
	
	if(file == -1)
	{
		fprintf(stderr, "ERROR: open() - %s - %d\n", strerror(errno), errno);
		return;
	}
	
	if (stat(fileName, &fileST) == 0)
        fileSize = fileST.st_size;
    
	numberOfPack = fileSize / SIZEBUF;
	
	if(numberOfPack == 0)
		numberOfPack = 1;
	
	while((readedChar = read(file, buffer, SIZEBUF)) > 0)
	{
		readSize += readedChar;
		j++;
		
		/*
		 * - NEED TO LIMIT OUTPUT TO 10 -
		 * 
		 * Si j'ai 50 ou 700 packet a afficher et que je souhaite en afficher uniquement 10 
		 * j*10 / numberOfPack > 0,1,2,3,4,5,6,7,8,9,10
		 * j*100000 / numberOfPack
		 * printf("- %ld\n", (j*10/numberOfPack));
		 */
		
		if(numberOfPack < 10)
			printf("%ld / %ld\n", readSize, fileSize);
		else if((j*10/numberOfPack) == tmp_var_1 && tmp_var_1++)
			printf("%ld / %ld  \t- %ld\%\n", readSize, fileSize, (tmp_var_1-1)*10);
		
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
