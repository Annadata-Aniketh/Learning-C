#include<stdio.h>
#include<string.h>
int main()
{
    char noun[50] = "", adjective[50] = "", verb[50] = "";
    printf("Enter a noun: ");
    fgets(noun,sizeof(noun),stdin);
    noun[strlen(noun) - 1] = '\0';

    printf("Enter an adjective: ");
    fgets(adjective,sizeof(adjective),stdin);
    adjective[strlen(adjective) - 1] = '\0';

    printf("Enter a verb enging with -ing: ");
    fgets(verb,sizeof(verb),stdin);
    verb[strlen(verb) - 1] = '\0';

    printf("The %s %s was %s.", adjective, noun, verb);
    return(0);
}