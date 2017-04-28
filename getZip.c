#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "demo.h"
#include "getZip.h"

int getZip(char *buff)
{
    printf("Enter Zip Code: ");
    getInput(buff,ZIP_LEN);
    unsigned int dlen; // How long it should be

    
    if(strchr(buff,'-') == NULL)
    {
	dlen = 5;
    }
    else
    {
	dlen = 10;
    }

    if(strlen(buff) != dlen)
    {
	printf("Invalid Zip Code Format\n");
	return 1;
    }

    for(unsigned int i = 0; i < strlen(buff); i++)
    {
	char ch = buff[i];
	if(ch != '0' && ch != '1' && ch != '2' && ch != '3' && ch != '4' &&
	    ch != '5' && ch != '6' && ch != '7' && ch != '8' && ch != '9' &&
	    ch != '/')
	{
	    printf("Invalid character [%c]\n",ch);
	    return 1;
	}

    }

    return 0;
}
