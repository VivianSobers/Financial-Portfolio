typedef struct Account_info
{
    char date[11];
    char description[100];
    float credit;
    float debit;
    float balance;
}acc;
int input();
void credit_debit();
void expense();
void income();
void tax();
void advice();