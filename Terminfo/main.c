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
    int retVal = setupterm(NULL, 1, &err);
    printf("Output is : %d, error is: %d \n", retVal,err);
    int numLines = tigetnum("lines");
    printf("Number of lines is: %d \n",numLines);
    return 0;
}
