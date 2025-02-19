#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node{

    int userId;
    int transactionId;
    int amount;
    int timeStamp;
    bool isDuplicate;

}Node;

typedef struct Hashmap{
    struct Node* table;
    int size;   
    int capacity;
}Hashmap;

int hash(Hashmap* map,int transactionId){
    return transactionId % map->capacity;
    
}

Hashmap* createMap(int capacity){

    Hashmap* map = (Hashmap*)malloc(sizeof(Hashmap));
    map->table = (Node*)malloc(sizeof(Node)*capacity);
    for(int i = 0;i<capacity;i++){
        map->table[i].amount = 0;
        map->table[i].transactionId = 0;
        map->table[i].userId = 0;
        map->table[i].timeStamp = 0;
        map->table[i].isDuplicate = false;
    }
    map->capacity = capacity;
    map->size = 0;
    return map;

}


void printMap(Hashmap* map){

    for(int i = 0;i<map->capacity;i++){
        if(map->table[i].userId != 0 ){

            printf("Index %d: UserId: %d, TransactionId: %d, Amount: %d, TimeStamp: %d, isDuplicate: %s\n",
                i, map->table[i].userId, map->table[i].transactionId,
                map->table[i].amount, map->table[i].timeStamp,map->table[i].isDuplicate?"true":"false");
     
        }
    }

}

void insert(Hashmap* map, int userId,int amount,int timestamp,int transaction){

        for(int idx = 0;idx<map->size;idx++){

            if(map->table[idx].userId == 0){
                map->table[idx].userId = userId;
                map->table[idx].timeStamp = timestamp;
                map->table[idx].transactionId = transaction;
                map->table[idx].amount = amount;
                return;
            }
            else if(userId == map->table[idx].userId && amount == map->table[idx].amount && abs(map->table[idx].timeStamp - timestamp) <= 60){
                map->table[idx].isDuplicate = true;
                return;
            }
        }

                map->table[map->size].userId = userId;
                map->table[map->size].timeStamp = timestamp;
                map->table[map->size].transactionId = transaction;
                map->table[map->size].amount = amount;
                map->size++;
                return;
    
}

void insertTransaction(Hashmap* map){
    int transaction = 0;
        int userId = 0;
        int amount =0;
        int timeStamp = 0;
        printf("Enter the TransactionId > ");
        scanf("%d",&transaction);

        printf("Enter the UserId > ");
        scanf("%d",&userId);

        printf("Enter the Amount > ");
        scanf("%d",&amount);

        printf("Enter the timeStamp > ");
        scanf("%d",&timeStamp);
        
        
        insert(map,userId,amount,timeStamp,transaction);

}


void detectDuplicates(Hashmap* map){
    printf("Duplicates Are:-- \n");
    for(int i = 0;i<map->capacity;i++){
        if(map->table[i].isDuplicate){

            printf("Index %d: UserId: %d, TransactionId: %d, Amount: %d, TimeStamp: %d, isDuplicate: %s\n",
                i, map->table[i].userId, map->table[i].transactionId,
                map->table[i].amount, map->table[i].timeStamp,map->table[i].isDuplicate?"true":"false");
        }
    }
}

int main(){
    printf("No of Operations:-- "); 
    int noOfOperations;
    scanf("%d",&noOfOperations);
    Hashmap* map = createMap(100);
    while(noOfOperations--){

        

        printf("1. Insert Transaction\n");
        printf("2. Detect Duplicates Transaction\n");
        printf("3. Print Single Transaction\n");
        printf("4. Exit...\n");
        printf("> ");
        int choice;
        scanf("%d",&choice);

        switch(choice){

            case 1: insertTransaction(map);
                    break;

            case 2: detectDuplicates(map);
                    break;

            case 3 : printMap(map);
                    break;

            case 4: return 0;
        }


    }
    // Hashmap* map = createMap(100);
    // insertTransaction(map);
    // insertTransaction(map);
    // printMap(map);
    return 0;

}