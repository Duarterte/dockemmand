#include"cli_helpler.h"
#include <cstring>

int Cli_helpler::getLines() {
	char path[255] ,bufferVal[255], *lines;
	bufferVal[0] = '\0';

	Cli_helpler::fp = popen("/usr/bin/tput lines", "r");
	if (Cli_helpler::fp == NULL) {
		exit(1);
	}
    
	while (fgets(path, sizeof(path), Cli_helpler::fp))
	{
		strcat(bufferVal, path);
	}

	lines = bufferVal;

	pclose(Cli_helpler::fp);
    return atoi(lines);
}

int Cli_helpler::getCols() {

    char path[255] ,bufferVal[255], *cols;
	bufferVal[0] = '\0';

	Cli_helpler::fp = popen("/usr/bin/tput cols", "r");
	if (Cli_helpler::fp == NULL) {
		exit(1);
	}
    
	while (fgets(path, sizeof(path), Cli_helpler::fp))
	{
		strcat(bufferVal, path);
	}

	cols = bufferVal;
	
	pclose(Cli_helpler::fp);
    return atoi(cols);
}

	char * Cli_helpler::dockerSendCommand(char * cmdParam) {
	char path[4095], dokCommand[4095], *psReturn;
	dokCommand[0] = '\0';
	Cli_helpler::fp = popen(cmdParam, "r");

	if(Cli_helpler::fp == NULL) {
		exit(1);
	}

	while (fgets(path,sizeof(path),Cli_helpler::fp))
	{
		strcat(dokCommand, path);
	}
	pclose(fp);
	psReturn = dokCommand;
	return psReturn;	
}

