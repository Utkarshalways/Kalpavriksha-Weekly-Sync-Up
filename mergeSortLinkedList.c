#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to print the linked list
void printLinkedList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n"); // Indicate the end of the list
}

// Function to insert a node at the end of the linked list
Node* insertIntoLinkedList(Node* head, Node* newNode) {
    if (head == NULL) {
        return newNode;
    }

    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

// Function to get the middle of the linked list
Node* getMiddle(Node* head) {
    if (head == NULL) return NULL;
    Node* slow = head;
    Node* fast = head;

    while (fast->next != NULL && fast->next->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

// Function to merge two sorted linked lists
Node* mergeSortedLists(Node* left, Node* right) {
    if (left == NULL) return right;
    if (right == NULL) return left;

    Node* result = NULL;
    if (left->data <= right->data) {
        result = left;
        result->next = mergeSortedLists(left->next, right);
    } else {
        result = right;
        result->next = mergeSortedLists(left, right->next);
    }
    return result;
}

// Function to sort the linked list using merge sort
Node* mergeSort(Node* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }

    Node* middle = getMiddle(head);
    Node* right = middle->next;
    middle->next = NULL;
    Node* left = head;

    left = mergeSort(left);
    right = mergeSort(right);

    return mergeSortedLists(left, right);
}

// Function to convert an array to a linked list
Node* arrayToLinkedList(int arr[], int arrSize) {
    Node* head = NULL;
    for (int i = 0; i < arrSize; i++) {
        Node* newNode = createNode(arr[i]);
        head = insertIntoLinkedList(head, newNode);
    }
    return head;
}

int main() {
    int arr[] = {38, 27, 43, 3, 9, 82, 10};
    int arrSize = sizeof(arr) / sizeof(arr[0]);

    Node* head = arrayToLinkedList(arr, arrSize);
    printf("Original Linked List:\n");
    printLinkedList(head);

    head = mergeSort(head);
    printf("Sorted Linked List:\n");
    printLinkedList(head);

    return 0;
}
