#include<ncurses.h>
using namespace std;

int main(int argc, char *argv[]) {

	initscr();

	printw("test");

	refresh();

	getch();

	endwin();

	return 0;
}
