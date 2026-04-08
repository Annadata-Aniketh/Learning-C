#include <stdio.h>
#include <string.h>
int main()
{
    char item[30] = "";
    int quantity = 0;
    float price =0.0f, total = 0.0f;
    printf("Enter the item: ");
    fgets(item, sizeof(item),stdin);
    item[strlen(item)-1] = '\0';
    printf("Enter the quatity: ");
    scanf("%d", &quantity);
    printf("Enter the price of each item: ");
    scanf("%f", &price);

    total = price * quantity;
    printf("You bought %d %s/s\n",quantity,item);
    printf("The total cost is $%.2f", total);

    return(0);
}
