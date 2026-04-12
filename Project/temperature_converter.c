#include<stdio.h>
int main()
{
    char choice = '\0';
    float celsius = 0.0f, fahrenheit = 0.0f;
    printf("---Temperature Converter Program---\n");
    printf("Enter C or F: ");
    scanf("%c", &choice);
    if(choice == 'C')
    {
        printf("Enter the temperature in Fahrenheit: ");
        scanf("%f", &fahrenheit);
        printf("The temperature in Celsisus is: %.1f", ((fahrenheit-32)*(5.0/9.0)));
    }
    else if(choice == 'F')
    {
        printf("Enter the temperature in Celsisus: ");
        scanf("%f", &celsius);
        printf("The temperature in Fahrenheit is: %.1f", ((celsius*(9.0/5.0))+32));
    }
    else
    {
        printf("Invalid choice.");
    }
    return 0;
}