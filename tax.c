#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"data.h"
extern float cred;
extern float deductible1;
void tax()
{
    double tax,taxableIncome,tx=0.0;
    FILE *fp = fopen("Income Tax Returns.csv","w");
    if(fp == NULL)
    {
        printf("Could not open the file\n");
        return;
    }
    fprintf(fp,"Component,Amount\n");
    fprintf(fp,"Total Income,%.2f\n",cred);
    fprintf(fp,"Deductible,-%.2f\n",deductible1);
    taxableIncome = cred - deductible1;
    fprintf(fp,"Taxable Income,%.2f\n",taxableIncome);
    fprintf(fp,"Tax Slab,Rate,Tax\n");
    if (taxableIncome <= 300000)
    {   
        tax = 0; fprintf(fp,"0-300000,0%%,0.0\n"); 
        tx=0.0;
    }
    else if (taxableIncome <= 600000) 
    {   
        tax = (taxableIncome - 300000) * 0.05; 
        fprintf(fp,"0-300000,0%%,0.0\n");
        fprintf(fp,"300001-600000,5%%,%.2f\n",tax); 
        tx = tx+tax;
    }
    else if (taxableIncome <= 900000) 
    {   
        tax = (300000 * 0.05) + (taxableIncome - 600000) * 0.10; 
        fprintf(fp,"0-300000,0%%,0.0\n");
        fprintf(fp,"300001-600000,5%%,15000\n");
        fprintf(fp,"600001-900000,10%%,%.2f\n",tax); 
        tx=tx+tax+15000;
    }
    else if (taxableIncome <= 1200000) 
    {   
        tax = (300000 * 0.05) + (300000 * 0.10) + (taxableIncome - 900000) * 0.15; 
        fprintf(fp,"0-300000,0%%,0.0\n");
        fprintf(fp,"300001-600000,5%%,15000\n");
        fprintf(fp,"600001-900000,10%%,30000\n");
        fprintf(fp,"900001-1200000,15%%,%.2f\n",tax); 
        tx=tx+tax+30000+15000;
    }
    else if (taxableIncome <= 1500000) 
    {  
        tax = (300000 * 0.05) + (300000 * 0.10) + (300000 * 0.15) + (taxableIncome - 1200000) * 0.20; 
        fprintf(fp,"0-300000,0%%,0.0\n");
        fprintf(fp,"300001-600000,5%%,15000\n");
        fprintf(fp,"600001-900000,10%%,30000\n");
        fprintf(fp,"900001-1200000,15%%,45000\n"); 
        fprintf(fp,"1200001-1500000,20%%,%.2f\n",tax); 
        tx=tx+tax+45000+30000+15000;
    }
    else 
    {   
        tax = 15000+30000+45000+60000+(taxableIncome - 1500000) * 0.30;
        fprintf(fp,"0-300000,0%%,0.0\n");
        fprintf(fp,"300001-600000,5%%,15000\n");
        fprintf(fp,"600001-900000,10%%,30000\n");
        fprintf(fp,"900001-1200000,15%%,45000\n");  
        fprintf(fp,"1200001-1500000,20%%,60000\n"); 
        fprintf(fp,"Above 1500000,30%%,%.2f\n",tax); 
        tx=tx+tax+60000+45000+30000+15000;
    }
    fprintf(fp,"Total Tax,,%.2f\n",tx);
    if(tx<700000)
    {
        tx = tx - 25000;
        fprintf(fp,"Rebate u/s 87A,-25000\n");
    }
    else
    {
       fprintf(fp,"Rebate u/s 87A,Not eligible\n");
    }
    fprintf(fp,"Cess @ 4%%,+%.2f\n",tx*0.04);
    tx = tx + 0.04 * tx;
    fprintf(fp,"Total Tax Payable,%.2f\n",tx);
    fclose(fp);
}