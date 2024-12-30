#include<stdio.h>
#include<ctype.h>



int main(){


    char string[20];
    scanf("%s",string);



    for(int idx = 0;string[idx] != '\0' ;idx++){

        char ch = string[idx];

        if(isdigit(ch)){
            continue;
        }

        if(isspace(ch)){

            continue;
        }


        if(ch >= 'A' && ch <= 'Z'){

            string[idx] += 32;


        } 

        else if (ch >= 'a' && ch <=  'z'){

            string[idx] -=  32;
        }



    }


    printf("%s\n" , string);



}