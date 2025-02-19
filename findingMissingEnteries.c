#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct Node{
    char word[100];
    int value;
}Node;

typedef struct Hashmap{

    Node* table;
    int size;
    int capacity;

}Hashmap;

Node* createNode(char* str){

    Node* newNode =(Node*)malloc(sizeof(Node));
    strcpy(newNode->word,str);
    newNode->value = 1;
    return newNode;
}

Hashmap* createMap(int Size){
    Hashmap* map = (Hashmap*)malloc(sizeof(Hashmap));
    map->table = (Node*)malloc(sizeof(Node)*Size);
    map->capacity = Size;
    map->size = 0;
    return map;
}

void printStringArray(char str[10][50],int size){

    for(int i = 0;i<size;i++){
        printf("%s ",str[i]);
    }
    printf("\n");

}

void printMap(Hashmap* map){

    for(int i = 0;i<map->size;i++){
        printf("%s - > %d\n",map->table[i].word,map->table[i].value);
    }
    printf("\n");

}

void insert(Hashmap* map,char* str){

    for(int i = 0;i<map->size;i++){

        if(strcmp(map->table[i].word,str)==0){

                map->table[i].value++;
                return;
        }

    }
    map->table[map->size].value = 1;
    strcpy(map->table[map->size].word,str);
    map->size++;
    return;

}   


void insertintoMap(Hashmap* map,char str[10][50],int size){

    for(int i = 0;i<size;i++){
        // printf("%s",str[i]);
        insert(map,str[i]);
    }

    printMap(map);

}


int main(){

    char str[10][50];
    int idx = 0;

    while(1){

        scanf("%s",str[idx++]);
        char ch = getchar();
        if(ch == EOF || ch == '\n'){
            break;
        }   

    }
    

    printStringArray(str,idx);
    Hashmap* map = createMap(idx);
    insertintoMap(map,str,idx);

}