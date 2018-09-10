#ifndef UTILITIES_H_  
#define UTILITIES_H_
#define clear() printf("\033[H\033[J")

void dbError();
int takeChoice(int start, int end);
FILE* loadFile(char fName);
void dbSetup();
int wantsToChange(char question[]);
int isIdUnique(int newID);
int getIDInput(char mode);

#endif