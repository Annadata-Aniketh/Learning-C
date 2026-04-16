#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<stdbool.h>
int getUserChoice()
{
    int choice = 0;
    while(choice<1 || choice>3)
    {
        printf("1. Rock\n");
        printf("2. Paper\n");
        printf("3. Scissors\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
    }
    return(choice);
}
int getComputerChoice()
{
    srand(time(NULL));
    int computerChoice = (rand() % (3-1+1)) + 1;
    return(computerChoice);
}
void checkWinner(int uc, int cc)
{
    if(uc == cc)
        printf("Tie!!\n");
    else if((uc == 1 && cc == 3) || (uc == 2 && cc == 1) || (uc == 3 && cc == 2))
        printf("You Win!!\n");
    else
        printf("You Lost!!\n");
}

int main()
{   
    char playAgain = '\0';
    bool play = true;
    while (play)
    {
        printf("-----Rock Paper Scissors-----\n");
        int computerChoice = getComputerChoice();
        int userChoice = getUserChoice();
        switch (userChoice)
        {
        case 1:
            printf("You chose Rock!\n");
            break;
        case 2:
            printf("You chose Paper!\n");
            break;
        case 3:
            printf("You chose Scissors!\n");
            break;
        
        }
        switch (computerChoice)
        {
        case 1:
            printf("Computer chose Rock!\n");
            break;
        case 2:
            printf("Computer chose Paper!\n");
            break;
        case 3:
            printf("Computer chose Scissors!\n");
            break;
        
        }
        checkWinner(userChoice, computerChoice);
        printf("Do you want to play again? (Y/N): ");
        scanf(" %c", &playAgain);
        if(!(playAgain == 'Y' || playAgain == 'y'))
        {
            play = false;
            printf("-----Thank you playing-----\n");
        }
            
    }   

    return 0;
}