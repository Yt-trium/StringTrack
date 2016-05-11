#include <stdio.h>
#include <stdlib.h>

#include "stringTrack.h"

int main(int argc, char **argv)
{
	printf("- StringTrack V1.0 -\n");
	
	if(argc < 3)
	{
		printf("usage: %s filename string\n", argv[0]);
		return 1;
	}
	
	voidStringTrack(argv[1], argv[2]);
	
	return 0;
}
