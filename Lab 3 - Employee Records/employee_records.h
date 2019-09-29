#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Constants

#define MAXADDR 50
#define NAMESIZE 50

// Function Declarations

enum Department {Sales,HR,Packing,Engineering,Operations};
typedef enum Department DEPT;

typedef struct{
int age;
float salary;
DEPT dept;
char* name;
char address[MAXADDR];
char status;
} Person;

void enter_employees(Person* entry, int employeecount);
void print_employees(Person* entry, int employeecount);
int enter_employee(Person* entry);
void print_employee(Person* entry,int index);
void clean_employees(Person* entry);
