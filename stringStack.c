#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct Node
{

    char ch;
    struct Node *next;
};

struct Node *createNode(char ch)
{

    struct Node *newNode = malloc(sizeof(struct Node));

    if (newNode == NULL)
    {
        return NULL;
    }

    newNode->ch = ch;
    newNode->next = NULL;

    return newNode;
}

int print(struct Node *head)
{

    struct Node *temp = head;

    while (temp != NULL)
    {

        printf("%c ", temp->ch);
        temp = temp->next;
    }
    printf("\n");
}

struct Node *createLinkedList(char *str)
{

    struct Node *head = createNode(-1);
    struct Node *temp = head;

    for (int i = 0; i < strlen(str); i++)
    {

        if (str[i + 1] != '#' && str[i] != '#')
        {
            struct Node *newNode = createNode(str[i]);
            temp->next = newNode;
            temp = temp->next;
        }
    }
    print(head->next);
    return head->next;
}

struct Node *removeBackSpaces(struct Node *s1)
{

    struct Node *curr = s1;
    struct Node *prev = curr;
    struct Node *forw = curr;

    while (curr != NULL)
    {

        if (curr->ch == '#')
        {

            prev->next = forw->next;
        }
        curr->next = forw;
        prev = curr;
        curr = curr->next;
    }

    return s1;
}

bool compareLinkedList(struct Node *str, struct Node *str2)
{

    struct Node *temp = str;
    struct Node *temp2 = str2;

    while (temp->next != NULL && temp2->next != NULL)
    {

        if (temp->ch != temp2->ch)
        {
            return false;
        }
        temp = temp->next;
        temp2 = temp2->next;
    }

    return true;
}

bool checkstring(char *str, char *str2)
{

    struct Node *s1 = createLinkedList(str);
    struct Node *s2 = createLinkedList(str2);

    print(s1);
    print(s2);

    return compareLinkedList(s1, s2);
}

int main()
{

    char str[100];
    char str1[100];

    scanf("%s", str);
    scanf("%s", str1);
    checkstring(str, str1) ? printf("True") : printf("false");
}