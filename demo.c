#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BUFF_LEN 500
#define CCN_LEN 16+3+1+1
#define EXP_LEN 9+1+4+1+1
#define ZIP_LEN 5+1+4+1+1

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

    printf("Enter your name: ");
    fgets(buff, BUFF_LEN, stdin);
    cleanInput(buff);
    return 0;
}


int getCCN(char *buff)
{
    printf("Enter your credit card number: ");
    fgets(buff, CCN_LEN, stdin);
    cleanInput(buff);
    return 0;
}


int getExp(char *buff)
{
    printf("Enter your expiration date: ");
    fgets(buff, EXP_LEN, stdin);
    cleanInput(buff);
    return 0;
}


int getZip(char *buff)
{
    printf("Enter your zip code: ");
    fgets(buff, ZIP_LEN, stdin);
    cleanInput(buff);
    return 0;
}

int getPrice(char *buff)
{
    printf("Enter the purchase amount: ");
    fgets(buff, BUFF_LEN, stdin);
    cleanInput(buff);
    return 0;
}

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

int main(void)
{
    // Allocate all the buffers for the information
    char *name = calloc(sizeof(char), BUFF_LEN);
    char *ccn = calloc(sizeof(char), CCN_LEN);
    char *exp = calloc(sizeof(char), EXP_LEN);
    char *zip = calloc(sizeof(char), ZIP_LEN);
    char *price = calloc(sizeof(char), BUFF_LEN);
    char *email = calloc(sizeof(char), BUFF_LEN);



    printf("Enter your name: ");
    getInput(name,BUFF_LEN);
    printf("Enter your Credit Card Number: ");
    getInput(ccn,CCN_LEN);
    printf("Enter your Expiration month and year: ");
    getInput(exp,EXP_LEN);
    printf("Enter your zip code: ");
    getInput(zip,ZIP_LEN);
    printf("Enter your purchase amount: ");
    getInput(price,BUFF_LEN);
    printf("Enter your email: ");
    getInput(email,BUFF_LEN);

    printf("Name: %s\n", name);
    printf("Credit card number: %s\n", ccn);
    printf("Expiration month and year: %s\n", exp);
    printf("Zip Code: %s\n", zip);
    printf("Purchase Amount: %s\n", price);
    printf("Email Address: %s\n", email);
    
    // Free all the buffers
    free(name);
    free(ccn);
    free(exp);
    free(zip);
    free(price);
    free(email);
    
    return 0;
}
