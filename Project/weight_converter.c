#include<stdio.h>
int main()
{
    int choice = 0;
    float pounds = 0.0f, kilograms = 0.0f;
    printf("---Weight Converter Program---\n");
    printf("1.Kilograms to pounds.\n2.Pounds to Kilograms\nEnter your choice (1 or 2): ");
    scanf("%d", &choice);
    if(choice == 1)
    {
        printf("Enter the weight : ");
        scanf("%f", &kilograms);
        printf("%.2f kgs in pounds is - %.2f lbs.", kilograms, (kilograms*2.20462));
    }
    else if(choice == 2)
    {
        printf("Enter the weight : ");
        scanf("%f", &pounds);
        printf("%.2f lbs in kilograms is - %.2ff kgs.", pounds, (pounds/2.20462));
    }
    else
    {
        printf("Invalid option.");
    }
    return 0;
}