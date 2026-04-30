#include<stdio.h>
#include<string.h>
int main()
{
    printf("Enter a text message - \n");
    char text[100];
    fgets(text, sizeof(text), stdin);
    text[strlen(text)-1] = '\0';
    FILE *pFile = fopen("test.txt", "w");
    
    if(pFile == NULL)
    {
        printf("File not found.");
        return 1;
    }
    fprintf(pFile, "%s", text);
    printf("File successfully edited.\n");
    fclose(pFile);

    
    
    FILE *pFile1 = fopen("test.txt", "r");
    char buffer[1024] = {0};
    if(pFile1 == NULL)
    {
        printf("File not found.");
        return 1;
    }
    while(fgets(buffer, sizeof(buffer), pFile1) != NULL)
    {    
        printf("%s", buffer);
    }
    fclose(pFile1);
    return 0;
}