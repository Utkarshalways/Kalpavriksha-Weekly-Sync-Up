// Online C compiler to run C program online
#include <stdio.h>

int main() {
    
    char str[100];
    printf("Enter the string:-- ");
    
    scanf("%[^\n]%*c",str);

    printf("%s",str);

    return 0;
}