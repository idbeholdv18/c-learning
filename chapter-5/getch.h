#ifndef GETCH
#define GETCH
#include <stdio.h>

#define BUF_SIZE 100
int buf[BUF_SIZE];
int buf_p = 0;

int getch(void);
void ungetch(int c);

#endif