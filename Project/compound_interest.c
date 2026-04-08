#include<stdio.h>
#include<math.h>
int main()
{
    double principal, rate, times_compunded, total = 0.0, time;
    printf("Enter the pricipal amount : "); 
    scanf("%lf", &principal);
    printf("Enter the rate : ");
    scanf("%lf", &rate);
    rate /= 100;
    printf("Enter the time period : ");
    scanf("%lf", &time);
    printf("Enter the number of times the interest is compunded : ");
    scanf("%lf", &times_compunded);

    total = principal * pow((1 + (rate/times_compunded)),(times_compunded * time));
    printf("The final amount after maturity is : %.2lf", total);
    return 0;
}