#include<stdio.h>


void printPattern(int n){


            // Enter N:-- 6
            // ************
            // *****  *****
            // ****    ****
            // ***      ***
            // **        **
            // *          *
            // *          *
            // **        **
            // ***      ***
            // ****    ****
            // *****  *****
            // ************


    for(int i = 0;i<n;i++){


            //stars
            for(int j = 0;j<n-i;j++){

                printf("*");
            }



            //spaces
            for(int k = 0;k<2*i;k++){

                printf(" ");
            }



            //stars
            for (int j = 0; j < n-i; j++)
            {

                printf("*");
            }


            printf("\n");
    }




    for(int i = 0;i<n;i++){

        //stars
        for(int j = 0;j<=i;j++){

            printf("*");

        }

        //spaces    
        for(int k = 0;k<2*(n-i)-2;k++){

            printf(" ");
        }


        //stars
        for (int j = 0; j <= i; j++)
        {
            printf("*");
        }

        printf("\n");
    }

}

int main(){

    int n = 5;
    printf("Enter N:-- ");
    scanf("%d",&n);


    printPattern(n);
}