#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"data.h"
#define n 1024
acc p[n];
int input()
{
    FILE *fp = fopen("transactions.csv","r");
    if(fp == NULL)
    {
        printf("Could not open the file\n");
        return 0;
    }
    char a[n];
    char *tok;
    int i=0;
    fgets(a,n,fp);
    while(fgets(a,n,fp))
    {
        //printf("%s",a);
        tok = strtok(a,",");
        if (!tok) break;
        strcpy(p[i].date,tok);
        tok = strtok(NULL,",");
        if (!tok) break;
        strcpy(p[i].description,tok);
        tok = strtok(NULL,",");
        if (!tok) break;
        p[i].credit = atof(tok);
        tok = strtok(NULL,",");
        if (!tok) break;
        p[i].debit = atof(tok);
        tok = strtok(NULL,",");
        if (!tok) break;
        p[i].balance = atof(tok);
        i++;
    }
    fclose(fp);
    return i;
}