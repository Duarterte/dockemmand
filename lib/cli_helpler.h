#ifndef CLI_HELPLER_H
#define CLI_HELPLER_H
#include <stdlib.h>
#include <iostream>
#include <string>

class Cli_helpler {
    private:
        FILE *fp;
    public:
        int getLines(); //terminal number of rows
        int getCols (); // terminal number of cols
        char * dockerSendCommand(char *);
};

#endif