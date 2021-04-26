#include<ncurses.h>
#include "../lib/cli_helpler.h"
#include "../lib/win_manager.h"
#include <stdio.h>
#include <string>
#define CLIPS (char *)"sudo /usr/bin/docker ps | awk 'FNR > 1 {print tolower($1 \" \" $2 )}'"
#define CLIIMAGES (char *)"sudo docker images | awk 'FNR>1{print $1\" \"$3}'"
#define CLINETWORKS (char *)"sudo docker network ls | awk 'FNR>1 {print $1 \" \" $2 \" \" $3}'"
void loop();

int main(int argc, char *argv[])
{	
	initscr();		//start "in terminal ncurses context"
	cbreak();		//Exit in <ctr-z>	
	while(1) {		//infite loop ""render"";
		loop();
	}
	
	endwin();		//end
	return 0;
}

void loop() 
{
	Cli_helpler cli;
	Win_Manager win_manage;
	initscr();
	cbreak();
	clear();
	refresh();
	mvaddstr(cli.getLines()-1,0,"Press any key to refresh and ctrl-c to exit ");
	win_manage.handlePs("Docker Processes", cli.dockerSendCommand(CLIPS), LINES/2, COLS/2 , 0, 0);
	win_manage.handlePs("Docker Images",cli.dockerSendCommand(CLIIMAGES), LINES/2, COLS/2 -1, 0, COLS/2+1);
	win_manage.handlePs("Docker Networks",cli.dockerSendCommand(CLINETWORKS), LINES/2-1, COLS/2 , LINES/2, 0);
	clrtoeol();
	getch();
}