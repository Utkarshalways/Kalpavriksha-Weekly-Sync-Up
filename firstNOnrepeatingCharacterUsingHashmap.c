#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define HASH_SIZE 256

typedef struct Node {
    char ch;
    int count;
    struct Node* next;
} Node;

typedef struct {
    Node* table[HASH_SIZE];
} HashMap;

Node* createNode(char ch) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->ch = ch;
    newNode->count = 1;
    newNode->next = NULL;
    return newNode;
}

HashMap* createMap() {
    HashMap* map = (HashMap*)malloc(sizeof(HashMap));
    for (int i = 0; i < HASH_SIZE; i++) {
        map->table[i] = NULL;
    }
    return map;
}

int hashFunction(char ch) {
    return (int)ch % HASH_SIZE;
}

void insert(HashMap* map, char ch) {
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

int getCount(HashMap* map, char ch) {
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

void operations(char* str) {
    HashMap* map = createMap();
    char queue[strlen(str) + 1];
    int front = 0, rear = -1;

    for (int i = 0; i < strlen(str); i++) {
        insert(map, str[i]);

        if (getCount(map, str[i]) == 1) {
            queue[++rear] = str[i];
        }

        while (front <= rear && getCount(map, queue[front]) > 1) {
            front++;
        }

        if (front <= rear) {
            printf("%c", queue[front]);
        } else {
            printf("-1");
        }
    }

    free(map);
}

int main() {
    char str[100001];
    scanf("%s", str);
    operations(str);
    return 0;
}
