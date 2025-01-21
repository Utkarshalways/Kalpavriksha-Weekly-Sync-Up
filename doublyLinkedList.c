#include <stdio.h>
#include <stdlib.h>

struct Node
{

    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node *createNode(int value)
{

    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;
}

struct Node *head = NULL;

int getLength()
{

    struct Node *temp = head;
    int length = 0;
    while (temp != NULL)
    {

        temp = temp->next;
        length++;
    }

    return length;
}

void printLL(struct Node *start)
{

    printf("Linked List :- ");
    struct Node *temp = start;
    while (temp != NULL)
    {

        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL");

    printf("\n");
}

void insertAtbeginning(int value)
{

    if (head == NULL)
    {
        struct Node *newNode = createNode(value);
        head = newNode;
        return;
    }

    struct Node *newNode = createNode(value);
    head->prev = newNode;
    newNode->next = head;
    head = newNode;

    return;
}

void insertAtEnd(int value)
{

    if (head == NULL)
    {
        insertAtbeginning(value);
        return;
    }

    struct Node *temp = head;

    while (temp->next != NULL)
    {

        temp = temp->next;
    }

    struct Node *newNode = createNode(value);
    newNode->prev = temp;
    temp->next = newNode;

    return;
}

void insertAtPosition(int pos, int value)
{

    if (head == NULL)
    {
        insertAtbeginning(value);
        return;
    }

    if (pos == 1)
    {

        insertAtbeginning(value);
        return;
    }
    else
    {
        pos = pos - 1;
    }

    int length = getLength();
    if (length < pos)
    {

        printf("Error Invaild position!!");
        return;
    }

    if (pos == length + 1)
    {

        insertAtEnd(value);
        return;
    }

    struct Node *temp = head;

    int count = 0;
    while (count < pos - 1)
    {

        temp = temp->next;
        count++;
    }

    struct Node *newNode = createNode(value);
    newNode->next = temp->next;
    temp->next = newNode;
    newNode->prev = temp;

    return;
}

void insertAtMiddle(int value)
{

    int len = getLength();

    insertAtPosition((len / 2)+1, value);
    return;
}

int main()
{

    while (1)
    {
        int value = 0;
        int pos;
        printf("Enter Your Choice:--\n");
        printf("1. Insert At Beginning \n");
        printf("2. Insert At End \n");
        printf("3. Insert At Position \n");
        printf("4. Insert At Middle \n");
        printf("Default: Exit the Code.... \n");
        int choice;
        scanf("%d", &choice);

        switch (choice)
        {

        case 1:
            printf("Value? ");
            scanf("%d", &value);
            insertAtbeginning(value);
            printLL(head);
            break;

        case 2:
            printf("Value? ");
            scanf("%d", &value);
            insertAtEnd(value);
            printLL(head);
            break;

        case 3:
            printf("Position?");
            scanf("%d", &pos);
            printf("Value? ");
            scanf("%d", &value);
            insertAtPosition(pos, value);
            printLL(head);
            break;

        case 4:
            printf("Value? ");
            scanf("%d", &value);
            insertAtMiddle(value);
            printLL(head);
            break;

        default:
            printLL(head);
            printf("EXIT..");
            return 0;
        }
    }

    
}