#include<Stdio.h>



int PrintPattern(int n){



            // Enter N:-- 5
            // *****
            // *   *
            // *   *
            // *   *
            // *****

    for(int i = 0;i<n;i++){

        for(int j =0;j<n;j++){


                if(j == 0|| j == n-1 || i == 0 || i == n-1){

                    printf("*");
                }
                else{


                    printf(" ");
                }

        }
        printf("\n");
    }

}


int main(){


    int n = 5;
    printf("Enter N:-- ");
    scanf("%d",&n);


    PrintPattern(n);

}