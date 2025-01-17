#include<stdio.h>
#include<string.h>



void changeString(char* str){
    
    char temp[strlen(str)];
    int index = 0;
    
    for(int idx = 0;idx < strlen(str)-1;idx++){

        
        if((str[idx] >= 'a' && str[idx] <= 'z')){
            
            if((idx+1) % 2 == 0){

                str[idx]  = str[idx] -  32;
                temp[index++] = str[idx];

            }
            else{
                temp[index++] = str[idx];
            }
 
        }
        
    }
    
    printf("%s",temp);

}


int main(){

    char str[15];
    printf("Enter the string:- ");
    scanf("%15s",str);
    
    changeString(str);

}