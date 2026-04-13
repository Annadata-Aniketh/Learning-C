#include<stdio.h>
#include<math.h>
int main()
{
    float operand1 = 0.0f, operand2 = 0.0f;
    char operator = '\0';
    printf("Enter the 1st operand: ");
    scanf("%f", &operand1);
    printf("Enter the 2nd operand: ");
    scanf("%f", &operand2);
    printf("Enter the operator: ");
    getchar();
    scanf("%c", &operator);
    switch(operator)
    {
        case '+': 
            printf("The sum is - %.2f", (operand1+operand2));
            break;
        case '-': 
            printf("The difference is - %.2f", (operand1-operand2));
            break;
        case '*': 
            printf("The multiplication is - %.2f", (operand1*operand2));
            break;
        case '/': 
            if (operand2 != 0)
                printf("The quotient is - %.2f", (operand1/operand2));
            else
                printf("Not defined.");
            break;
        case '%': 
            if (operand2 != 0)
                printf("The remainder is - %d", ((int)operand1%(int)operand2));
            else
                printf("Not defined.");
            break;
        case '^': 
            printf("The sum is - %.2f", (pow(operand1,operand2)));
            break;
        default:
            printf("Invalid Operator Selected.");
    }

    return 0;
}