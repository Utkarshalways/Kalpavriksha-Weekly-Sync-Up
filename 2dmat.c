#include<stdio.h>

void printMat(int mat[][50],int matSize){


    for(int i = 0;i<matSize;i++){


        for(int j = 0;j<matSize;j++){

            printf("%d",mat[i][j]);
        }
        printf("\n");
    }
}


void changeMat(int mat[][50],int matSize){


    for(int r = 0;r<matSize;r++){

        for(int c = 0;c<matSize;c++){

            if(r+c % 2 == 0){

                mat[r][c] = 0;
            }

        }
    }

    printMat(mat,matSize);

}


int main(){

    int arr[50][50];

    int matSize  = 0;
    scanf("%d",&matSize);

    printf("Enter the matrix:--");

    for(int  r = 0;r<matSize;r++){


        for(int c = 0;c<matSize;c++){

            scanf("%d",&arr[r][c]);
        }
    }



    changeMat(arr,matSize);

}