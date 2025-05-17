#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"data.h"
#define max 10000
void expense()
{
    FILE *fpd = fopen("debit.csv","r");
    if(fpd == NULL)
    {
        printf("Could not open the file\n");
        return;
    }
    char a[max];
    char *tok;
    fgets(a,max,fpd);
    double ex=0.0,ef=0.0,hi=0.0,rc=0.0,si=0.0;
    while(fgets(a,max,fpd))
    {
        tok = strtok(a,",");
        if(!tok) break;
        tok = strtok(NULL,",");
        if(!tok) break;
        if(strcmp(tok,"Emergency Fund")==0)
        {
            tok = strtok(NULL,",");
            ef = ef+ atof(tok);
        }
        else if(strcmp(tok,"Insurance")==0||strcmp(tok,"Health Insurance")==0)
        {
            tok = strtok(NULL,",");
            hi = hi+ atof(tok);
        }
        else if(strcmp(tok,"Retirement Contribution")==0)
        {
            tok = strtok(NULL,",");
            rc = rc+ atof(tok);
        }
        else if(strcmp(tok,"Stock Investment")==0)
        {
            tok = strtok(NULL,",");
            si = si+ atof(tok);
        }
        else
        {
            tok = strtok(NULL,",");
            ex = ex+ atof(tok);
        }
    }
    fclose(fpd);
    FILE *exp = fopen("expenses.csv","a");
    fprintf(exp,"DEBIT INFO\n");
    fprintf(exp,"Emergency Fund,%.2f\n",ef);
    fprintf(exp,"Insurance,%.2f\n",hi);
    fprintf(exp,"Retirement Contribution,%.2f\n",rc);
    fprintf(exp,"Stock Investment,%.2f\n",si);
    fprintf(exp,"Expenses,%.2f\n",ex);
    fclose(exp);
}
