#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#include "demo.h"
#include "getPrice.h"

int getPrice(char *buff)
{
    printf("Enter the Purchase Amount: ");
    getInput(buff,BUFF_LEN);
    
    if(strchr(buff,'$') == NULL)
    {
	printf("Invalid Format, try using the following format \"$1234.56\"\n");
	return 1;
    }
    char *ch = strchr(buff,'.');
    if(ch != NULL)
    {
	if(isdigit(*(ch+1)) == 0 || isdigit(*(ch+2)) == 0 || isdigit(*(ch+3)) != 0 )
	{
	    printf("Invalid Format, try using the following format \"$1234.56\"\n");
	    return 1;
	}
    }

    

    for(unsigned int i = 0; i < strlen(buff); i++)
    {
	char ch = buff[i];
	if(ch != '0' && ch != '1' && ch != '2' && ch != '3' && ch != '4' &&
	    ch != '5' && ch != '6' && ch != '7' && ch != '8' && ch != '9' &&
	    ch != '$' && ch != '.')
	{
	    printf("Invalid character [%c]\n",ch);
	    return 1;
	}

    }

    return 0;
}
