#include"cli_helpler.h"
#include <stdlib.h>
#include <cstring>
#include <iostream>

int Cli_helpler::getLines() {

	FILE *fp;
	char path[255] ,bufferVal[255], *lines;
	bufferVal[0] = '\0';

	fp = popen("/usr/bin/tput lines", "r");
	if (fp == NULL) {
		exit(1);
	}

	while (fgets(path, sizeof(path), fp));
	{
		strcat(bufferVal, path);
	}

	lines = bufferVal;

	pclose(fp);
    return atoi(lines);
}