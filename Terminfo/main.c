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
int main(int argc, const char * argv[]) {
    int err = 0;
    //Setup the terminfo instance (null defaults to TERM environment variable).
    int retVal = setupterm(NULL, 1, &err);
    printf("Output is : %d, error is: %d \n", retVal,err); //DEBUGGING
    int numLines = tigetnum("lines");
    int numCols = tigetnum("cols");
    printf("There are: %d lines and %d columns\n",numLines,numCols);
    return 0;
}
