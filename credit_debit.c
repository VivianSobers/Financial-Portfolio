#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"data.h"
extern acc p[1024];
void credit_debit()
{
    FILE *fpc = fopen("credit.csv","w");
    FILE *fpd = fopen("debit.csv","w");
    int n = input();
    if(fpc == NULL || fpd == NULL)
    {
        printf("Could not open the file\n");
        return;
    }
    fprintf(fpc,"Date,Description,Amount\n");
    fprintf(fpd,"Date,Description,Amount\n");
    for(int i=0; i<n;i++)
    {
        if(p[i].credit > 0)
        {
            fprintf(fpc,"%s,%s,%.2f\n",p[i].date,p[i].description,p[i].credit);
        }
        if(p[i].debit > 0)
        {
            fprintf(fpd,"%s,%s,%.2f\n",p[i].date,p[i].description,p[i].debit);
        }
    }
}