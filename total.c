#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"data.h"
extern acc p[1024];
float deb=0.0,cred=0.0;
int main()
{
    int N;
    N = input();
    for(int i=0; i<N; i++)
    {
        deb = deb + p[i].debit;
        cred = cred + p[i].credit;
    }
    printf("Total Debit: %.2f\n",deb);
    printf("Total Credit: %.2f\n",cred);
    credit_debit();
    income();
    expense();   
    tax();
    advice();
}