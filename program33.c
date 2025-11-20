#include <stdio.h>
#include <stdlib.h>

int mutex = 1;
int full = 0;
int empty = 3;  
int x = 0;    

int wait(int s) {
    return (--s);
}

