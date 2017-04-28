#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#include "demo.h"
#include "getPrice.h"

int getEmail(char *buff)
{
    printf("Enter Email Address: ");
    getInput(buff,BUFF_LEN);
    
    if(strchr(buff,'@') == NULL)
    {
	printf("Invalid Format: Enter a valid email\n");
	return 1;
    }
    if(strchr(buff,' ') != NULL )
    {
	printf("Invalid Format: Enter a valid email\n");
	return 1;
    }
    if(strchr(buff,'.') == NULL )
    {
	printf("Invalid Format: Enter a valid email\n");
	return 1;
    }
    
    return 0;
}
