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

Node* enqueue(Node* head,int val){

    if (head == NULL) {
        return createNode(val);
    }
    if(head->data > val){
        Node* newNode =createNode(val);
        newNode->next = head;
        head = newNode;
        return head;
    }

    Node* temp = head;
    while (temp->next != NULL && temp->next->data < val) {
        temp = temp->next;
    }

    Node* newNode = createNode(val);
    newNode->next = temp->next;
    temp->next = newNode;
    return head;

}

Node* arrayToQueue(int arr[],int arrSize){
    Node* head = NULL;
    for(int i = 0;i<arrSize;i++){
        head = enqueue(head,arr[i]);
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


    print(arrayToQueue(arr,idx));


}