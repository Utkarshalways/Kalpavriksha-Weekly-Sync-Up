#include<stdio.h>


void Pattern1(int n){

// A 
// A B
// A B C
// A B C D
// A B C D E
// A B C D E F

    for(int i = 0;i<n;i++){

        char alpha = 'A';
        for(int j = 0;j<=i;j++){

            printf("%c ",alpha++);

        }

        printf("\n");

    }

}


void Pattern2(int n){

// ABCDE
// ABCD
// ABC
// AB
// A

    for(int i = 0;i<n;i++){

        char alpha = 'A';

        for(int j = n - i;j > 0;j--){

            printf("%c",alpha++);
        }

        printf("\n");

    }


}


void Pattern3(int n){


//Enter N:-- 7
// A 
// B B
// C C C
// D D D D
// E E E E E
// F F F F F F
// G G G G G G G

    char alpha = 'A';
    for(int i = 0;i<n;i++){


        for(int j = 0;j<=i;j++){

            printf("%c ",alpha);
        }

        printf("\n");
        alpha++;

    }
}


void Pattern4(int n){


//     Enter N:-- 5
//                            A
//                           ABA
//                          ABCBA
//                         ABCDCBA
//                        ABCDEDCBA

    for(int i = 0;i<n;i++){

            char alpha = 'A';

            //spaces
            for(int j = 0;j< n-i+1;j++){

                printf(" ");
            }


            //alphabet
            for(int j = 0;j<=i;j++){

                printf("%c",alpha++);

            }
            alpha -= 2;

            //alphabets
            for(int j = 0;j<i;j++){

                printf("%c",alpha--);

            }

            //spaces
            for (int j = 0; j < n - i + 1; j++)
            {

                printf(" ");
            }


            printf("\n");
    }

}


void Pattern5(int n){



        // Enter N:-- 5
        // E
        // DE
        // CDE
        // BCDE
        // ABCDE

    for(int i = 0;i<n;i++){
        char alpha = 'A';


        for(int j = 0;j <= i;j++){

            printf("%c",alpha+n-i-1);
            alpha++;
        }

        printf("\n");

        
    }


}

int main(){


    int n = 5;
    printf("Enter N:-- ");
    scanf("%d",&n);

    // Pattern1(n);
    // Pattern2(n);
    // Pattern3(n);
    // Pattern4(n);
    Pattern5(n);

}