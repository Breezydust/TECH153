//header file containing all function declarations and includes

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Constants

#define MAXCHARS 50

//Function Definitions

void TestStrings(const char* teststring);
int getStrings(char str[MAXCHARS]);
void printStrings(char str[MAXCHARS]);
void encrpyt(char str[MAXCHARS],int key);
void decrypt(char str[MAXCHARS],int key);
void sortStrings(char str[MAXCHARS]);

