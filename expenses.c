#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"data.h"
#define max 10000
extern float deductible1;
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
    double ex=0.0,ef=0.0,hi=0.0,rc=0.0,si=0.0,loan=0.0;
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
        else if(strcmp(tok,"Home Loan")==0||strcmp(tok,"Loan")==0)
        {
            tok = strtok(NULL,",");
            loan = loan + atof(tok);
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
    fprintf(exp,"Loan,%.2f,%s\n",loan,"200000(80C & 80EEA)");
    deductible1 = deductible1 + 200000.0;
    printf("Have you invested your emergency fund and Retirement Contribution in a tax saving instrument(PPF,ELSS,NPS)? (y/n)\n");
    char ch;
    scanf(" %c",&ch);
    if(ch == 'y' || ch == 'Y')
    {
        fprintf(exp,"Emergency Fund,%.2f,%s\n",ef,"Exempt in entireity under 80C & 80CCD");
        fprintf(exp,"Retirement Contribution,%.2f,%s\n",rc,"Exempt in entireity under 80C & 80CCD");
        deductible1 = deductible1 + ef + rc;
    }
    else
    {
        fprintf(exp,"Emergency Fund,%.2f,%.2f\n",ef,0.0);
        fprintf(exp,"Retirement Contribution,%.2f,%.2f\n",rc,0.0);
    }
    printf("Does your insuranceinclude your entire family? (y/n)\n");
    scanf(" %c",&ch);
    if(ch == 'y' || ch == 'Y')
    {
        fprintf(exp,"Insurance,%.2f,%s\n",hi,"50000.00(80D)");
        deductible1 = deductible1 + 50000.0;
    }
    else
    {
        fprintf(exp,"Insurance,%.2f,%s\n",hi,"25000.00(80D)");
        deductible1 = deductible1 + 25000.0;
    }
    fprintf(exp,"Stock Investment,%.2f,%.2f\n",si,100000.0);
    deductible1 = deductible1 + 100000.0;
    fprintf(exp,"Expenses,%.2f\n",ex);
    fclose(exp);
}
