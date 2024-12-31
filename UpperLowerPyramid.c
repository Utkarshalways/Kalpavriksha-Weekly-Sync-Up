#include<stdio.h>

int main(){


//     Enter the value:-- 5
//     *    
//    ***   
//   *****  
//  ******* 
// *********
// *********
//  ******* 
//   *****
//    ***
//     *

    int n = 5;
    printf("Enter the value:-- ");
    scanf("%d",&n);


    // upperPyramid

    for(int i = 0;i <n;i++){

        for(int j = i+1;j < n;j++){


            printf(" ");
        }

        for(int j = 0;j< 2*i+1;j++){

            printf("*");
        }

        for (int j = i+1; j < n; j++)
        {

            printf(" ");
        }


        printf("\n");
    }




    //lower pyramid

    for(int i = 0;i<n;i++){

        for(int j = 0;j<i;j++){

            printf(" ");
        }
        
        
        for(int k = 0; k < 2*n - (2*i+ 1);k++){

            printf("*");
        }
        
        
            
        for(int j = 0;j<i;j++){

            printf(" ");
        }


        printf("\n");


    }


    return 0;





}