#include "employee_records.h"

int main()
{
	//Declarations
	int employeecount;
	int x;
	int index;
    
	do {
	printf("Please enter number of employees, from 5-50: ");
	scanf("%d",&employeecount);
	} while (employeecount < 5 || employeecount > 50);
	Person *entry;
	entry = malloc(sizeof(Person) * employeecount);
	if (entry == 0)
	{
		printf("System cannot allocate required memory. Exiting!");
		exit(0);
	}

	//Function calls
	enter_employees(entry,employeecount);
	print_employees(entry,employeecount);
	index = enter_employee(entry);
	print_employee(entry,index);
	clean_employees(entry);
}

void enter_employees(Person* entry, int employeecount)
{
	int i;
	for (i=0;i<employeecount;i++)
	{
		printf("Enter employee information:\n");
		printf("Employee %d age, in years: ",i+1);
		scanf("\n%d",&entry[i].age);
		getchar();
		printf("Employee %d salary, with two decimal points: ",i+1);
		scanf("\n%f",&entry[i].salary);
		getchar();
		printf("Employee %d department, as a number (Sales = 0, HR = 1, Packing = 2, Engineering = 3, Operations = 4): ",i+1);
		scanf("\n%d",&entry[i].dept);
		getchar();
		printf("Employee %d name: ",i+1);
		entry[i].name = calloc(NAMESIZE,sizeof(char));
		fgets(entry[i].name,NAMESIZE,stdin);
		printf("Employee %d address: ",i+1);
		fgets(entry[i].address,MAXADDR,stdin);
		printf("Employee %d status, as a letter ( A = Active, S = Suspended, L = Leave): ",i+1);
		scanf("\n%c",&entry[i].status);
		getchar();
	}
}

void print_employees(Person* entry, int employeecount)
{
	int i;
	for (i=0;i<employeecount;i++)
	{
		printf("\nEmployee %d age is: %d",i+1,entry[i].age);
		printf("\nEmployee %d salary is: %.2f",i+1,entry[i].salary);
		printf("\nEmployee %d department is: %d ",i+1,entry[i].dept);
		printf("\nEmployee %d name is: %s",i+1,entry[i].name);
		printf("Employee %d address is: %s",i+1,entry[i].address);
		printf("Employee %d status is: %c\n",i+1,entry[i].status);
	}
}

int enter_employee(Person* entry)
{
	int index;
	do {
	printf("Enter an index to view that employee's information: ");
	scanf("\n%d",&index);
	} while (index > sizeof(entry)+1);
	return index;
}	

void print_employee(Person* entry,int index)
{
	printf("\nEmployee you chose was Employee %d.",index);
	printf("\nEmployee %d age is: %d",index,entry[index-1].age);
	printf("\nEmployee %d salary is: %.2f",index,entry[index-1].salary);
	printf("\nEmployee %d department is: %d ",index,entry[index-1].dept);
	printf("\nEmployee %d name is: %s",index,entry[index-1].name);
	printf("Employee %d address is: %s",index,entry[index-1].address);
	printf("Employee %d status is: %c",index,entry[index-1].status);
}

void clean_employees(Person* entry)
{
	printf("\nEmployee list will now be cleaned, and the application will close. Thanks for using!\n");
	memset(&entry[0],0,sizeof(entry));
	free(entry);
	exit(0);
}
