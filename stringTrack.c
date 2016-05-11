#include "stringTrack.h"

void voidStringTrack(char *fileName, char *string)
{
	printf("> Searching %s in %s ...\n",string,fileName);
	
	int file;
	unsigned int readedChar;
	unsigned char buffer[SIZEBUF];
	
	file = open(fileName, O_RDONLY);
	
	if(file == -1)
	{
		fprintf(stderr, "ERROR: open() - %s - %d\n", strerror(errno), errno);
		return;
	}
	
	while((readedChar = read(file, buffer, SIZEBUF)) > 0)
	{
		// write(1, buffer, SIZEBUF);
	}
	
	close(file);	
}
