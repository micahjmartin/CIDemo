#ifndef demo_H
#define demo_H

#define FINISH {retval = 1; goto CLEANUP;}
#define BUFF_LEN 500
#define CCN_LEN 16+3+1+1
#define EXP_LEN 8+3+1+1
#define ZIP_LEN 5+1+4+1+1

int getInput(char *buff, int len);

void cleanInput(char *buff);

int getName(char *buff);

int getCCN(char *buff);

int getZip(char *buff);

int getPrice(char *buff);

void cleanup(int i);

int main(void);

#endif
