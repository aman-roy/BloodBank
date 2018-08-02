#ifndef UTILITIES_H_  
#define UTILITIES_H_

// equivalent to clrscr() in unix
#define clear() printf("\033[H\033[J")

// DB ERROR
void dbError();

// Takes an int between start and end
int takeChoice(int start, int end);

FILE* loadFile(char fName);

void dbSetup();

#endif