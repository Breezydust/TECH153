#include "stringmanip.h"

int len;
int encryptornah;
int stringornah;

void TestStrings(const char* teststring)
{
	static char wordlist[MAXCHARS];
	char operation;
	int key = 0xFACA;
	
	//Menu
	printf("\n\nTest String Functions\n");
	
	printf("Enter 'P' or 'p' to Print Strings\n");
	printf("Enter 'G' or 'g' to Get Strings\n");
	printf("Enter 'E' or 'e' to Encrypt Strings\n");
	printf("Enter 'D' or 'd' to Decrypt Strings\n");
	printf("Enter 'S' or 's' to Sort Strings\n");
	printf("Enter 'Q' or 'q' to Quit\n");
	printf("Any other character will be invalid\n");


	while(1)
	{
		operation = getchar();
		switch(operation)
		{
			case 'P' : case 'p':
			if (stringornah == 1)
			{
				printStrings(wordlist);
				break;
			}
			else 
			{
				printf("You have not entered a string. Please select Get Strings first.\n");
				break;
			}
			case 'G' : case 'g':
				getStrings(wordlist);
				break;
			case 'E' : case 'e':
			if (stringornah == 1)
			{
				encrypt(wordlist,key);
				break;
			}
			else
			{
				printf("You have not entered a string. Please select Get Strings first.\n");
				break;
			}
			case 'D' : case 'd':
			if (stringornah == 1)
			{
				decrypt(wordlist,key);
				break;
			}
			else
			{
				printf("You have not entered a string. Please select Get Strings first.\n");
				break;
			}
			case 'S' : case 's':
				sortStrings(wordlist);
				break;
			case 'Q' : case 'q':
				exit(0);
			default:
				printf("\nPick another function\n");
		}
		operation = '\0';
	}
}

int getStrings(char str[MAXCHARS])
{
	int i=0;
	for(i=0;i<MAXCHARS;i++)
	{
		str[i]='\0';
	}	
	getchar();
	printf("Enter a string: ");
	fgets(str, MAXCHARS, stdin);
	if (str[0] == '\0')
	{
		printf("String is empty, enter a different one!\n");
	}
	else
	{
		len = strlen(str);
		printf("Your string is %s",str);
		stringornah = 1;
	}
}

void printStrings(char str[MAXCHARS])
{
	int i;
	printf("String with commas in between:\n");
	for (i=0;i<len-1;i++)
	{
		if (i < len-2)
		{
			printf("%c,",str[i]);
		}
		else
		{
			printf("%c",str[i]);
		}
	}
	printf("\nString reversed with commas in between:");
	for (i=len-1;i>=0;i--)
	{
		if (i > 0 && i != len-1)
		{
			printf("%c,",str[i]);
		}
		else
		{
			printf("%c",str[i]);
		}
	}
	printf("\nString with no spaces: \n");
	for (i=0;i<len-1;i++)
	{
		if (str[i] != ' ')
		{
			printf("%c",str[i]);
		}
	}
}

void encrypt(char str[MAXCHARS],int key)
{
	int j;
	printf("legnth is %d",len);
	for (j=0; j < len; j++)
	{
		str[j] -= key;
		printf("%c\n",str[j]);
	}

	printf("Encrypted string is: %s\n",str);
	encryptornah = 1;
}	

void decrypt(char str[MAXCHARS],int key)
{
	if (encryptornah == 1)
	{
		int h;
		for (h=0;h<len;h++)
		{
			str[h] += key;
			printf("%c\n",str[h]);
		}
		printf("Decrypted string is: %s",str);
	}
	else
	{
		printf("String is not encrypted, built by Thomas Aziz!\n");
	}
}

void sortStrings(char str[MAXCHARS])
{
	//fgets causes a newline at the end of string input, and the new line carries into str functions. using scanf would not allow capturing spacebar.
	//To maintain the integrity of the user's original string, a copy is made and applied after each function.
	char thecoolerstring[12] = "holy smokes";
	char original[MAXCHARS];
	strcpy(original,str);
	char *ret;
	char search = 'h';
	int rlen;
	
	//Concatenate
	strcat(str,thecoolerstring);
	printf("The concatenated string is: %s\n",str);
	strcpy(str,original);
	
	//Search
	ret = strchr(str,search);
	printf("String after |%c| is - |%s|\n",search,ret);
	strcpy(str,original);

	//Compare
	ret = strcmp(str,thecoolerstring);
	
	if (ret < 0)
	{
		printf("String 1 is less than string 2.\n");
	}
	else if (ret > 0)
	{
		printf("String 2 is less than string 1.\n");
	}
	else
	{
		printf("String 1 equals string 2.\n");
	}
	strcpy(str,original);

	//Copy
	str = strcpy(str,thecoolerstring);
	printf("The string 'holy smokes' has been copied to your string. Your string is now %s.\n",str);
	strcpy(str,original);
	
	//Length
	rlen = strlen(str);
	printf("The length of your string is: %d\n",rlen);
	
	//Partial concatenate
	strncat(str,thecoolerstring,5);
	printf("The partially concatenated string is: %s\n",str);
	strcpy(str,original);

	//Partial compare
	ret = strncmp(str,thecoolerstring,3);
	
	if (ret < 0)
	{
		printf("String 1 is less than string 2.\n");
	}
	else if (ret > 0)
	{
		printf("String 2 is less than string 1.\n");
	}
	else
	{
		printf("String 1 equals string 2.\n");
	}
	strcpy(str,original);

	//Partial copy
	str = strncpy(str,thecoolerstring,5);
	printf("The string 'holy smokes' has been partially copied to your string. Your string is now %s\n",str);
	strcpy(str,original);
	
	//Search for last occurance
	ret = strrchr(str,search);
	printf("String after |%c| is - |%s|\n",search,ret);
	strcpy(str,original);
}
