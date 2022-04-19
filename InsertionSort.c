//C Program uses to take in an input (amount of elements in linked list)
//Then use Insertion Sort, to sort them#include <stdio.h>
#include <stdlib.h>
 
struct node {
    int data;
    struct node* next;
};
 
struct node* head = NULL;
struct node* sorted = NULL;
 
void insertNum(int num) {
    // allocate memory for newNode
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = num;
    newNode->next = head;
    head = newNode;
}
 
//Inserted into a node
void sortedInsert(struct node* newnode)
{
    // Special case for the head end //
    if (sorted == NULL || sorted->data >= newnode->data) {
        newnode->next = sorted;
        sorted = newnode;
    }
    else {
        struct node* current = sorted;
        // Locate the node before the point of insertion
        while (current->next != NULL
               && current->next->data < newnode->data) {
            current = current->next;
        }
        newnode->next = current->next;
        current->next = newnode;
    }
}
 
// function to sort a singly linked list
// using insertion sort
void insertionsort()
{
 
    struct node* current = head;
 
    // Traverse the  linked list, inserting every node to sorted
    while (current != NULL) {
 
        // Store next for next iteration
        struct node* next = current->next;
 
        // insert current in sorted linked list
        sortedInsert(current);
 
        // Update current
        current = next;
    }
    // Update head to point to sorted linked list
    head = sorted;
}
 
//Print Linked List
void displayList(struct node* node) {
    struct node* last;

    while (node != NULL) {
        printf("%d->", node->data);
        last = node;
        node = node->next;
    }
    if (node == NULL)
        printf("NULL\n");
}
 
// Test function
int main()
{
    // Generate 17 random numbers
    for(int i = 1; i < 17; ++i){
        int ranint = (rand() % (10000 - 1 + 1)) + 1;
        insertNum(ranint);
        }
    printf("The Unsorted List:\n");
    displayList(head);
    printf("Insertion Sort:\n");
    insertionsort(head);
    displayList(head);
    
}