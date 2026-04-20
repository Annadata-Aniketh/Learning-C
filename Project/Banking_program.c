#include<stdio.h>
void checkBalance(float balance)
{
    printf("The account balance is: $%.2f\n\n", balance);
}
float deposit()
{
    float amount = 0.0f;
    printf("Enter the amount to deposit: $");
    scanf("%f", &amount);
    if(amount < 0)
    {
        printf("Invalid amount entered for depositing money.\n\n");
        return 0.0f;
    }
    else
    {
        printf("Successfully deposited the amount.\n\n");
        return amount;
    }
}
float withdraw(float balance)
{
    float amount = 0.0f;
    printf("Enter the amount to withdraw: $");
    scanf("%f", &amount);
    if(amount < 0)
    {
        printf("Invalid amount entered for withdrawing money.\n\n");
        return 0.0f;
    }
    else if(amount > balance)
    {
        printf("Invalid amount entered for withdrawing money. Your balance is: $%.2f\n\n", balance);
        return 0.0f;
    }
    else
    {
        printf("Successfully withdrew the amount.\n\n");
        return amount;
    }
}

int main()
{
    int choice = 0;
    float balance = 0.0f;
    printf("-------Welcome to our bank-------\n");
    while(choice != 4)
    {
        printf("1. Check Account Balance.\n");
        printf("2. Deposit Amount.\n");
        printf("3. Withdraw Amount.\n");
        printf("4. Exit our services.\n");
        printf("\nEnter your choice - ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                checkBalance(balance);
                break;
            case 2:
                balance += deposit();
                break;
            case 3:
                balance -= withdraw(balance);
                break;
            case 4:
                printf("-------Thank You for using our services-------\n");
                break;
            default:
                printf("Invalid Choice. Please select a choice between 1 and 4.\n");

        }

    }
    return 0;
}