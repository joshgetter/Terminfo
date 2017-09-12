//
//  main.c
//  Terminfo
//
//  Created by Josh Getter on 9/11/17.
//  Copyright © 2017 Josh Getter. All rights reserved.
//

#include <stdio.h>
#include <curses.h>
#include <term.h>
#include <unistd.h>
#include <strings.h>
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
    sleep(2);
    
    //init ncurses
    initscr();
    
    //3 Clear screen/Home cursor
    clear();
    
    //4 Prompt user
    puts("Enter a coordinate (ex: \"x,y\"):\n");
    refresh();
    
    //5 Get user input
    char input[40];
    fgets(input, 10, stdin);
    char *xIn;
    char *yIn;
    xIn = strtok(input, ",");
    //int x = atoi(xIn);
    yIn = strtok(NULL, ",");
    //int y = atoi(yIn);
    
    //6 Move cursor
    move(y, x);
    refresh();
    
    sleep(2);
    endwin();
    return 0;
}
