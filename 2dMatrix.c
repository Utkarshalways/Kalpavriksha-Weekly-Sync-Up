#include<stdio.h>
#include<stdlib.h>

void printMat(int** mat,int row,int col){

    for(int idx = 0;idx<row;idx++){

        for(int c = 0;c<col;c++){

            printf("%d ",*(*(mat + idx)+c));

        }
        printf("\n");

    }

}


int main(){

    int row;
    printf("Enter the Rows:--");
    scanf("%d",&row);

    int col;
    printf("Enter the Cols:--");
    scanf("%d",&col);


    int** mat = (int**) malloc(row * sizeof(int*));
    
    for(int idx = 0;idx<row;idx++){

        mat[idx] = (int *) malloc(col * sizeof(int));

    }


    printf("Enter the Matrix:--\n");

    for(int r = 0;r<row;r++){

        for(int c = 0;c<col;c++){

            scanf("%d",(*(mat + r)+c));

        }
    }

    printf("Matrix:--\n");

    printMat(mat,row,col);

    return 0;
}