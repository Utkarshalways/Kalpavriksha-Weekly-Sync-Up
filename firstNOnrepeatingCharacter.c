#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node{
    char ch;
    struct Node* next;

}Node;

Node* createNode(char ch){

    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->ch = ch;
    newNode->next = NULL;

}

Node* print(Node* head){
    Node* temp = head;
    while(temp != NULL){

        printf("%c -> ",temp->ch);
        temp = temp->next;
        
    }
    
}

Node* push(Node* head, char ch){

    Node* newNode = createNode(ch);
    if(head == NULL){
        return newNode;
    }

    Node* temp =  head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next =  newNode;
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
bool isEmpty(Node* head){
    if(head==NULL){
        return true;
    }
    return false;
}


void operations(char * str){
    char temp;
    Node* head = NULL;
    for(int i =0;i<strlen(str);i++){

        
        if(!isEmpty(head) && str[i] == peek(head)){

          temp = pop(&head);

        }
        else{
                    
            head  = push(head,str[i]);
            // print(head);
        }
        isEmpty(head)?printf("-1"):printf("%c",peek(head));


    }

}

int main(){

    char str[100];
    scanf("%s",str);

    operations(str);
}