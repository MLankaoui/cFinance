#include <stdio.h>
#include <stdlib.h>

int transaction_id = 1;
typedef struct Transaction {
    int id;
    char date[10];
    char type[10];
    float amount;
    char category[20];
} Transaction;

// TODO: implementing file opening check
void file_opening_check(FILE* file)
{
    if (file == NULL)
    {
        printf("file doesnt exsist!\n");
        exit(EXIT_FAILURE);
    }
}


// TODO: implementing add transation
void add_transaction(Transaction transaction)
{
    transaction.id = transaction_id;
    // open a file transaction.txt as an example and put transaction id and details there
    FILE *file = fopen("finance.txt", "a+");
    
    // file checking
    file_opening_check(file);

    //TODO: writing to finance.txt

    // incrementing the id each time this function is called.
    transaction_id++;
}


int main(void)
{
    Transaction transaction;
    int user_option = 1;
    printf("1) Add new transaction");

    if (user_option == 1)
    {
        printf("Please enter the date: 2025-04-01");
        scanf("%s", transaction.date);
        printf("Please enter the Type: (INCOME - EXPENSE)");
        scanf("%s", transaction.type);
        printf("Please enter the Amount: 2000");
        scanf("%f", &transaction.amount);
        printf("Please enter the Category: 2000");
        scanf("%s", transaction.category);
        add_transaction(transaction);
    }
    
    return (0);
}