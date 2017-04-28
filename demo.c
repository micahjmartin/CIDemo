#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "demo.h"
#include "getExp.h"
#include "getZip.h"
#include "getPrice.h"

int getInput(char *buff, int len)
{
    fgets(buff, len, stdin);
    if(strchr(buff, '\n') == NULL)
    {
	int ex;
	while ((ex = fgetc(stdin)) != '\n' && ex != EOF)
	{
	    ;
	}
    }
    //fflush(stdin);
    cleanInput(buff);
    return 0;
}

void cleanInput(char *buff)
{
    int l = strlen(buff);
    if (buff[l-1] == '\n')
    {
	buff[l-1] = '\0';
    }
}

int getName(char *buff)
{
    printf("Enter your first and last name: ");
    getInput(buff,BUFF_LEN);
    
    if(strchr(buff,' ') == NULL)
    {
	printf("Invalid: Does not contain two names\n");
	return 1;
    }
    return 0;
}


int getCCN(char *buff)
{
    printf("Enter your credit card number: ");
    getInput(buff,CCN_LEN);
    char ch;
    int dashes = 0; // get the number of dashes in the string. 
    if(strlen(buff) != 19)
    {
	printf("Invalid length of credit card number\n");
	return 1;
    }
    for(unsigned int i = 0; i < strlen(buff); i++)
    {
	ch = buff[i];
	if(ch == '-')
	    dashes++;
	if(ch != '0' && ch != '1' && ch != '2' && ch != '3' && ch != '4' &&
	    ch != '5' && ch != '6' && ch != '7' && ch != '8' && ch != '9' &&
	    ch != '-')
	{
	    printf("Invalid character [%c]\n",ch);
	    return 1;
	}

    }
    if(dashes != 3)
    {
	printf("Invalid: Please follow the following format: xxxx-xxxx-xxxx-xxxx\n");
	return 1;
    }
    return 0;
}

void cleanup(int i)
{
    // Free all the buffers
    exit(i);
}

int main(void)
{
    int retval = 0;
    // Allocate all the buffers for the information
    char *name = calloc(sizeof(char), BUFF_LEN);
    char *ccn = calloc(sizeof(char), CCN_LEN);
    char *exp = calloc(sizeof(char), EXP_LEN);
    char *zip = calloc(sizeof(char), ZIP_LEN);
    char *price = calloc(sizeof(char), BUFF_LEN);
    char *email = calloc(sizeof(char), BUFF_LEN);



    if (getName(name) != 0)
	FINISH
    if (getCCN(ccn) != 0)
	FINISH
    if (getExp(exp) != 0)
	FINISH
    if (getZip(zip) != 0)
	FINISH
    if (getPrice(price) != 0)
	FINISH
    

    printf("Enter your email: ");
    getInput(email,BUFF_LEN);

    printf("Name: %s\n", name);
    printf("Credit card number: %s\n", ccn);
    printf("Expiration month and year: %s\n", exp);
    printf("Zip Code: %s\n", zip);
    printf("Purchase Amount: %s\n", price);
    printf("Email Address: %s\n", email);

    CLEANUP: 
    free(name);
    free(ccn);
    free(exp);
    free(zip);
    free(price);
    free(email);
    return retval;
}
