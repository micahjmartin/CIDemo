#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "demo.h"
#include "getExp.h"


int cToi(char a, char b)
{
    //printf("Input Values: [%c] [%c]\nOutput [%i]\n",a,b,retval);
    return (a - '0')*10+(b-'0');
}

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

    int month = cToi(buff[0],buff[1]);

    if(cToi(buff[3],buff[4]) > 31)
    {
	printf("Invalid: There can only be 31 days\n");
	return 1;
    }
    
    switch(month)
    {
	case 1:
	    sprintf(buff,"January %c%c",buff[8],buff[9]);
	    break;
	case 2:
	    sprintf(buff,"February %c%c",buff[8],buff[9]);
	    break;
	case 3:
	    sprintf(buff,"March %c%c",buff[8],buff[9]);
	    break;
	case 4:
	    sprintf(buff,"April %c%c",buff[8],buff[9]);
	    break;
	case 5:
	    sprintf(buff,"May %c%c",buff[8],buff[9]);
	    break;
	case 6:
	    sprintf(buff,"June %c%c",buff[8],buff[9]);
	    break;
	case 7:
	    sprintf(buff,"July %c%c",buff[8],buff[9]);
	    break;
	case 8:
	    sprintf(buff,"August %c%c",buff[8],buff[9]);
	    break;
	case 9:
	    sprintf(buff,"September %c%c",buff[8],buff[9]);
	    break;
	case 10:
	    sprintf(buff,"October %c%c",buff[8],buff[9]);
	    break;
	case 11:
	    sprintf(buff,"November %c%c",buff[8],buff[9]);
	    break;
	case 12:
	    sprintf(buff,"December %c%c",buff[8],buff[9]);
	    break;
	default:
	    printf("Invalid: There are only 12 months\n");
	    return 1;
    }

    return 0;
}
