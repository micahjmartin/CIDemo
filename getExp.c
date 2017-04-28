#include <stdio.h>
#include <string.h>
#include "demo.h"
#include "getExp.h"

int getExp(char *buff)
{
    printf("Enter your expiration date: ");
    getInput(buff,BUFF_LEN);
    
    char ch;
    int slash = 0; // get the number of slashes in the string. 
    if(strlen(buff) != 10)
    {
	printf("Invalid: Please put in mm/dd/yyyy format\n");
	return 1;
    }
    for(unsigned int i = 0; i < strlen(buff); i++)
    {
	ch = buff[i];
	if(ch == '/')
	    slash++;
	if(ch != '0' && ch != '1' && ch != '2' && ch != '3' && ch != '4' &&
	    ch != '5' && ch != '6' && ch != '7' && ch != '8' && ch != '9' &&
	    ch != '/')
	{
	    printf("Invalid character [%c]\n",ch);
	    return 1;
	}

    }
    if(slash != 2)
    {
	printf("Invalid: Please put in mm/dd/yyyy format\n");
	return 1;
    }
    

    return 0;
}
