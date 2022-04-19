//C Program uses to take in an input (amount of elements in linked list)
//Then use Bubble Sort, to sort them
#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node* next;
};

struct Node* head = NULL;
void insert(struct Node** head, int data) {
  // allocate memory for newNode
  struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
  // assign data to newNode
  newNode->data = data;
  // make newNode as a head
  newNode->next = (*head);
  // head points to newNode
  (*head) = newNode;
}

// print the doubly linked list
void displayList(struct Node* node) {
  struct Node* last;

  while (node != NULL) {
    printf("%d->", node->data);
    last = node;
    node = node->next;
  }
if (node == NULL)
    printf("NULL\n");
}
///////Bubble Sort/////////
void bubbleSort(struct Node *start)
{
    int swapped, i;
    struct Node *half1;
    struct Node *half2 = NULL;
  
    do
    {
        swapped = 0;
        half1 = start;
  
        while (half1->next != half2)
        {
            if (half1->data > half1->next->data)
            { 
                swap(half1, half1->next);
                swapped = 1;
            }
            half1 = half1->next;
        }
        half2 = half1;
    }
    while (swapped);
}

void swap(struct Node *a, struct Node *b)
{
    int temp = a->data;
    a->data = b->data;
    b->data = temp;
}


int main() {
// initialize an empty node

int n;
printf("How many random numbers between 1-10000 would you like to enter: ");
    scanf("%d", &n);
for(int i = 1; i < n; ++i){
    int ranint = (rand() % (10000 - 1 + 1)) + 1;
    insert(&head, ranint);
}


bubbleSort(head);
displayList(head);


}
