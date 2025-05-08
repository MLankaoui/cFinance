#include <stdio.h>
#include <stdlib.h>

typedef struct Transaction {
    char date[10];
    char type[10];
    float amount;
    char category[20];
} Transaction;

void add_transaction_details(Transaction *transaction)
{
    printf("Please enter the date: 2025-04-01");
    fflush(stdout);
    scanf("%s", transaction->date);
    fflush(stdout);
    printf("Please enter the Type: (INCOME - EXPENSE) ");
    fflush(stdout);
    scanf("%s", transaction->type);
    printf("Please enter the Amount: 2000 ");
    fflush(stdout);
    scanf("%f", &transaction->amount);
    printf("Please enter the Category: FOOD ");
    fflush(stdout);
    scanf("%s", transaction->category);
}

// TODO: implementing file opening check
void file_opening_check(FILE* file)
{
    if (file == NULL)
    {
        printf("file doesnt exsist!\n");
        exit(EXIT_FAILURE);
    }
}

int auto_increment()
{
    static int transaction_id = 0;
    transaction_id++;
    return transaction_id;
}

void write_to_file(Transaction transaction, int transaction_id, FILE* file)
{
    fprintf(file, "transaction id: %d\n", transaction_id);
    fprintf(file, "transaction date: %s\n", transaction.date);
    fprintf(file, "transaction type: %s\n", transaction.type);
    fprintf(file, "transaction amount: %f\n", transaction.amount);
    fprintf(file, "transaction category: %s\n\n", transaction.category);
}

// TODO: implementing add transation
void add_transaction(Transaction transaction, int transaction_id)
{
    //transaction.id = transaction_id;
    // open a file transaction.txt as an example and put transaction id and details there
    FILE *file = fopen("finance.txt", "a+");
    
    // file checking
    file_opening_check(file);
    
    //TODO: writing to finance.txt
    write_to_file(transaction, transaction_id, file);
    
    //close the file
    fclose(file);
    
}

int main(void)
{
    Transaction transaction;
    int user_option = 1;
    printf("1) Add new transaction");
    while (1)
    {
        if (user_option == 1)
        {
            add_transaction_details(&transaction);
            int transaction_id = auto_increment(); 
            add_transaction(transaction, transaction_id);
        }
    } 

    return (0);
}