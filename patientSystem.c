#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node
{
    int id;
    char *catg;
    struct Node *next;
};

struct Node *createNode(int id, char *catg)
{

    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->catg = malloc(sizeof(char) * (strlen(catg) + 1));
    newNode->id = id;
    strcpy(newNode->catg, catg);
    newNode->next = NULL;
    return newNode;
}


int print(struct Node* head){

    struct Node *temp = head;

    while (temp != NULL)
    {

        printf("%d -> %s\n", temp->id, temp->catg);
        temp = temp->next;
    }

    printf("\n");

}

struct Node *insert(struct Node *head, int id, char *catg)
{

    struct Node *newNode = createNode(id, catg);
    if (head == NULL)
    {
        head = newNode;
        return head;
    }

    struct Node *temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newNode;
    return head;
}


struct Node* sorttheLinkedList(struct Node* head){

    struct Node* temp = head;
    struct Node* criticalList = createNode(-1,"Nothing");
    struct Node* stableList = createNode(-1,"Nothing");
    struct Node* seriousList = createNode(-1,"Nothing");
    struct Node* critical = criticalList;
    struct Node* stable = stableList;
    struct Node* serious = seriousList;


    while(temp != NULL){



        if(strcmp(temp->catg,"Critical")== 0){
            criticalList->next = temp;
            criticalList = criticalList->next;
        }
        else if(strcmp(temp->catg,"Serious")==0){
            seriousList->next = temp;
            seriousList = seriousList->next;
        }
        else{
            stableList->next = temp;
            stableList = stableList->next;
        }

        temp = temp->next;

    }


    head = critical->next;
    criticalList->next = serious->next;
    seriousList->next = stable->next;
    stableList->next = NULL;
    return head;

}


bool isFalseData(char *str){

    if(strcmp(str,"Critical")==0){
        return false;
    }
    else if(strcmp(str,"Serious")==0){
        return false;
    }
    else if(strcmp(str,"Stable")==0){
        return false;
    }

    return true;
}

int main()
{   
    printf("Enter the Number of Inputs>");
    int input = 0;
    scanf("%d", &input);
    struct Node *head = NULL;
    while (input > 0)
    {
        int id;
        scanf("%d", &id);
        char str[100];
        scanf("%s", str);
        if(isFalseData(str)){
            printf("Enter the Correct String!!\n");
            continue;
        }

        head = insert(head, id, str);
        input--;
    }

    print(head);
    head = sorttheLinkedList(head);
    print(head);

}