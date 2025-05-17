#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"data.h"
void advice()
{
    FILE *fp = fopen("advice.txt","w");
    if(fp == NULL)
    {
        printf("Could not open the file\n");
        return;
    }
    fprintf(fp,"ADVICE\n");
    fprintf(fp,"1. Please reduce your expenditure by 15%%.\n");
    fprintf(fp,"2. Save at least 20%% of your income for retirement.\n");
    fprintf(fp,"3. Invest in a diversified portfolio of stocks and bonds.\n");
    fprintf(fp,"4. Build an emergency fund of 3-6 months of expenses.\n");
    fprintf(fp,"5. Pay off high-interest debt as soon as possible.\n");
    fprintf(fp,"6. Review your budget regularly and adjust as needed.\n");
    fprintf(fp,"7. Liquidate your assets to pay bad debts.\n");
    fprintf(fp,"8. Invest in tax-saving instruments such as PPF, ELSS, NPS to reduce taxable income.\n");
    fprintf(fp,"9. Consider tax-saving fixed deposits for guaranteed returns.\n");
    fprintf(fp,"10.Use tax-saving mutual funds to grow your wealth.\n");
    fprintf(fp,"11.Buy property in a good location to ensure appreciation.\n");
    fprintf(fp,"12. Invest in gold or silver as a hedge against inflation.\n");
    fprintf(fp,"**13.Don't consider investing in stock options or futures**\n");

    fprintf(fp,"\nThank you so much for using our software.\n");
    fprintf(fp,"We are happy that we could be of service to you.\n");
    fprintf(fp,"We hope you have a great Financial year head.\n");
    fprintf(fp,"We are always here to help you.\n");
    fprintf(fp,"Please don't forget to download your Income Tax returns.\n");
    fprintf(fp,"Please feel free to reach out to us for any queries.\n");
    fclose(fp);
}