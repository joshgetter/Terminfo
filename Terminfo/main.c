//
//  main.c
//  Terminfo
//
//  Josh Getter
//  CIS 452 Terminfo
//
//

#include <stdio.h>
#include <curses.h>
#include <term.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
int main(int argc, const char * argv[]) {
    int err = 0;
    //Setup the terminfo instance (null defaults to TERM environment variable).
    setupterm(NULL, 1, &err);
    
    //1 Output term lines/cols
    int numLines = tigetnum("lines");
    int numCols = tigetnum("cols");
    printf("There are: %d lines and %d columns\n",numLines,numCols);
    
    //2 Sleep
    sleep(5);
    
    //init ncurses
    initscr();
    
    //3 Clear screen/Home cursor
    clear();
    
    bool running = true;
    while(running){
        //4 Prompt user
        printw("Please enter a coordinate ex: \"x,y\" or \"q\" to quit. ");
        
        //5 Get user input
        char input[40];
        getstr(input);
        running = strcmp(input, "q");
        if(running){
            char *xIn;
            char *yIn;
            xIn = strtok(input, ",");
            yIn = strtok(NULL, ",");
            int x = atoi(xIn);
            int y = atoi(yIn);
            
            //6 Move cursor
            move(y, x);
        }
    }
    //Exit
    endwin();
    return 0;
}
