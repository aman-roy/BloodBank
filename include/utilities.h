#ifndef UTILITIES_H_  
#define UTILITIES_H_

// equivalent to clrscr() in unix
#define clear() printf("\033[H\033[J")

// Takes an int between start and end
int takeChoice(int start, int end);

#endif