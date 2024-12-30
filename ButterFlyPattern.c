#include <stdio.h>

// 1        1
// 12      21
// 123    321
// 1234  4321
// 1234554321
// 1234  4321
// 123    321
// 12      21
// 1        1


int main()
{

    int n = 5;
    printf("The Number is :--");
    scanf("%d",&n);

    int space = 2*n - 2;
    
    for(int i = 1;i<n;i++){

            for(int j = 1;j<=i;j++){


                printf("%d",j);

            }
            for(int k = 0;k<space;k++){ 

                printf(" ");

            }

            for(int k = i;k > 0;k--){

                printf("%d",k);

            }

            printf("\n");
            space = space - 2;


    }

    space = 0;

    for(int i = n;i > 0; i--){


        for(int j = 1;j<=i;j++){

            printf("%d",j);
        }

        for(int k = 0; k< space;k++){

            printf(" ");
        }

        for(int k = i;k > 0;k--){

            printf("%d",k);

        }

        space = space + 2;
        printf("\n");
    }



    return 0;
}