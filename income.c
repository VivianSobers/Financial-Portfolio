#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"data.h"
#define max 10000
void income()
{
    FILE *fpc = fopen("credit.csv","r");
    if(fpc == NULL)
    {
        printf("Could not open the file\n");
        return;
    }
    char a[max];
    char *tok;
    fgets(a,max,fpc);
    double fdi=0.0,fp=0.0,lw=0.0,ls=0.0,s=0.0;
    while(fgets(a,max,fpc))
    {
        tok = strtok(a,",");
        tok = strtok(NULL,",");
        if(strcmp(tok,"FD Interest")==0)
        {
            tok = strtok(NULL,",");
            fdi = fdi+ atof(tok);
        }
        else if(strcmp(tok,"Freelance Project")==0)
        {
            tok = strtok(NULL,",");
            fp = fp+ atof(tok);
        }
        else if(strcmp(tok,"Lottery Win")==0)
        {
            tok = strtok(NULL,",");
            lw = lw+ atof(tok);
        }
        else if(strcmp(tok,"Legal Settlement")==0)
        {
            tok = strtok(NULL,",");
            ls = ls+ atof(tok);
        }
        else
        {
            tok = strtok(NULL,",");
            s = s+ atof(tok);
        }
    }
    fclose(fpc);
    FILE *exp = fopen("expenses.csv","w");
    fprintf(exp,"CREDIT INFO\n");
    fprintf(exp,"Salary,%.2f\n",s);
    fprintf(exp,"FD Interest,%.2f\n",fdi);
    fprintf(exp,"Freelance Project,%.2f\n",fp);
    fprintf(exp,"Lottery Win,%.2f\n",lw);
    fprintf(exp,"Legal Settlement,%.2f\n\n",ls);
    fclose(exp);
}