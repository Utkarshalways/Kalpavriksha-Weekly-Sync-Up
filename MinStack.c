#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct Node{

    int data;
    struct Node* next;

}Node;

Node* createNode(int data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

int print(Node* head){

    Node* temp = head;
    while(temp != NULL){
        printf("%d ->",temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

Node* push(Node* head,int val){

    if (head == NULL) {
        return createNode(val);
    }
    
    if(head->data < val){
        head->next = push(head->next,val);
        return head;
    }
    Node* newNode = createNode(val);
    newNode->next = head;
    head = newNode;
    return head;
    

}
int pop(Node** head){
    if(head == NULL){
        return -1;
    }

    Node* temp = (*head);
    (*head) = (*head)->next;
    int res = temp->data;
    free(temp);
    return res;
}

Node* arrayToStack(int arr[],int arrSize){
    Node* head = NULL;
    for(int i = 0;i<arrSize;i++){
        head = push(head,arr[i]);
    }

    return head;

}

int main(){

    int arr[10];
    int idx = 0;

    while(1){

        scanf("%d",&arr[idx++]);
        char ch = getchar();
        if(ch == EOF || ch == '\n'){
            break;
        }   

    }


    Node* head = arrayToStack(arr,idx);
    print(head);
    printf("%d\n",pop(&head));
    print(head);


}