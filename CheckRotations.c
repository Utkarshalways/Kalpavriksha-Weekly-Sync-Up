#include <stdio.h>


 int checkRotations(char str1[],char str2[]){



    int len1 = 0,len2 = 0;
    int i = 0;
    
    while (str1[i] != '\0')
    {
        len1++;
        i++;
    }


    i = 0;
    while (str2[i] != '\0')
    {

        len2++;
        i++;
    }


    if(len1 != len2){

        return 0;
    }

    

    for (int i = 0; i < len1; i++)
    {
        int j;
        for (j = 0; j < len1; j++)
        {
            printf("%d %d\n",i,j);
            printf("%c %c\n", str1[(i + j) % len1], str2[j]);
            if (str1[(i + j) % len1] != str2[j])
            {
                break;
            }
        }
        if (j == len1)
        {
            return 1; 
        }
    }

    return 0;
}



int main()
{

    char str1[20];
    scanf("%s", str1);

    char str2[20];
    scanf("%s",str2);

    
    

    if( checkRotations(str1,str2)){


        printf("%s\n" , "Yes");
    }
    else{

        printf("%s\n" , "No");
    }
}