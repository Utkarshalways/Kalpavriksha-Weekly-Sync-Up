#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#define SIZE_TABLE 256

typedef struct Node{
    char ch;
    int count;
    struct Node* next;

}Node;



typedef struct Hashmap{
    struct Node* table[SIZE_TABLE];
}Hashmap;

Node* createNode(char ch){

    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->ch = ch;
    newNode->count = 0;
    newNode->next = NULL;

}
Hashmap* createMap(int size){

    Hashmap* map = (Hashmap*)malloc(sizeof(Hashmap));
    for(int idx = 0;idx < size;idx++){
        map->table[idx] = NULL;
    }

    return map;

}

int hashFunction(char ch) {
    return (int)ch % SIZE_TABLE;
}

void insert(Hashmap* map, char ch) {
    int index = hashFunction(ch);
    Node* curr = map->table[index];

    while (curr != NULL) {
        if (curr->ch == ch) {
            curr->count++;
            return;
        }
        curr = curr->next;
    }

    Node* newNode = createNode(ch);
    newNode->next = map->table[index];
    map->table[index] = newNode;
}

int getCount(Hashmap* map, char ch) {
    int index = hashFunction(ch);
    Node* curr = map->table[index];

    while (curr != NULL) {
        if (curr->ch == ch) {
            return curr->count;
        }
        curr = curr->next;
    }
    return 0;
}


Node* push(Node* head, char ch){

    Node* newNode = createNode(ch);
    if(head == NULL){
        return newNode;
    }

    newNode->next = head;
    head = newNode;
    return head;

}

char peek(Node* head){
    return head->ch;
}

char pop(Node** head){

    if((*head) == NULL){
        return '0';
    }
    char temp = (*head)->ch;
    (*head) = (*head)->next;
    return temp;

}


bool isValid(char* str){
    Node* head = NULL;
    for(int i = 0;i<strlen(str);i++){

        
        if(str[i] == '{' || str[i] == '[' || str[i] == '('){
            head = push(head,str[i]);
        }
        else{

            if(str[i] == '}' ){
                
                if(peek(head) != '{'){
                    return false;
                }else{
                    pop(&head);
                }
                
            }
            else if(str[i] == ']'){
                 
                if(peek(head) != '['){
                    return false;
                }else{
                    pop(&head);
                }
                
            }else if(str[i] == ')'){
                 
                if(peek(head) != '('){
                    return false;
                }else{
                    pop(&head);
                }
                
            }
        }

    }

    if(head != NULL){
        return false;
    }
    return true;
    
}


int main(){

    char str[100];
    scanf("%s",str);
    isValid(str)?printf("True\n"):printf("False");

}