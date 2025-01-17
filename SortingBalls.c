#include <stdio.h>



void sortingBalls(int *arr, int n){


        int red = 0;
        int blue = 0;
        int white = 0;

        // printf("This is going in this function");


        for(int i = 0;i<n;i++){

            if(arr[i] == 0){
                red++;
            }
            else if(arr[i] == 1){
                blue++;
            }
            else{

                white++;
            }
        }



        for(int i = 0;i < red;i++){
            arr[i] = 0;
        }
        for(int i = red;i<red+blue;i++){

            arr[i] = 1;

        }
        for(int i = red+blue;i<n;i++){
            arr[i] = 2;
        }

}




void using3Pointer(int *arr,int n){


    int low = 0;
    int mid = 0;
    int high = n-1;


    while(mid < high){

    

        if(arr[mid] == 0){

            int temp = arr[mid];
            arr[mid] = arr[low];
            arr[low] = temp;
            low++;
            mid++;

        }
        else if(arr[mid] == 1){

            mid++;
            
        }
        else{

            int temp = arr[mid];
            arr[mid] = arr[high];
            arr[high] = temp;
            high--;

        }

    }

}



int main(){


    int n = 5;
    printf("Enter Size:--- ");
    scanf("%d",&n);
    int arr[n];

    printf("Enter elements:-- ");

    for(int i = 0;i<n;i++){

        scanf("%d",&arr[i]);
    }

    using3Pointer(arr, n);

    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }


}