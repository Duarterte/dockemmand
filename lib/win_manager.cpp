#include "win_manager.h"
#include "ncurses.h"

void Win_Manager::handlePs(char* psTitle, char* psCommand, int sizeRows, int sizeCols, int posRows, int posCols){
    int halfTitleSize = ((sizeof(psTitle)*sizeof(char))/2)+2;

    use_default_colors();
    start_color();

    WINDOW * winps = newwin(sizeRows, sizeCols, posRows, posCols);
    init_pair(1, COLOR_GREEN, -1);
    init_pair(2, COLOR_YELLOW, -1);

    wattron(winps, COLOR_PAIR(2));
    box(winps, 0, 0);
    wattroff(winps, COLOR_PAIR(2));
    wattron(winps, COLOR_PAIR(1));
    mvwprintw(winps, 1, sizeCols/2-(halfTitleSize), psTitle);
    wattroff(winps, COLOR_PAIR(1));
    
    WINDOW * swin = derwin(winps, sizeRows-4, sizeCols-4, 4, 2);
    wprintw(swin, psCommand);
    wrefresh(winps);
    wrefresh(swin);
    delwin(swin);
    delwin(winps);
}