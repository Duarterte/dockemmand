#include<ncurses.h>
#include "/home/essi/Documents/clidocTerminal/lib/handle_window.h"
using namespace std;


int main(int argc, char *argv[]) {
	Handle_window h;	
	initscr();
	h.printTest();

	refresh();
	getch();

	endwin();
	

	return 0;
}
