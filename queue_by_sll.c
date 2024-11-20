#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *front = NULL, *rear = NULL;


void insertion() {
    struct node *newnode;
    int val;
    printf("Enter the number: ");
    scanf("%d", &val);
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = val;
    newnode->next = NULL;
    if (front == NULL && rear == NULL) {
        front = newnode;
        rear = newnode;
    } else {
        rear->next = newnode;
        rear = newnode;
    }
}

void deletion() {
    if (front == NULL) {
        printf("Queue Underflow\n");
    } else {
        struct node *ptr = front;
        front = front->next;
        printf("Deleted: %d\n", ptr->data);
        free(ptr);
        if (front == NULL) { 
            rear = NULL;
        }
    }
}


void display() {
    if (front == NULL) {
        printf("Queue Underflow\n");
        return;
    } else {
        struct node *ptr = front;
        printf("Queue elements: ");
        while (ptr != NULL) {
            printf("%d\t", ptr->data);
            ptr = ptr->next;
        }
        printf("\n");
    }
}


int main() {
    int op;
    while (1) {
        printf("\n1. Insertion \t2. Deletion \t3. Display \t4. Exit\n");
        printf("Select the operation to perform: ");
        scanf("%d", &op);

        switch (op) {
            case 1:
                insertion();
                break;
            case 2:
                deletion();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
                break;
        }
    }
    return 0;
}
/*Output: 1. Insertion    2. Deletion     3. Display      4. Exit
Select the operation to perform: 1
Enter the number: 1

1. Insertion    2. Deletion     3. Display      4. Exit
Select the operation to perform: 1
Enter the number: 2

1. Insertion    2. Deletion     3. Display      4. Exit
Select the operation to perform: 1
Enter the number: 3

1. Insertion    2. Deletion     3. Display      4. Exit
Select the operation to perform: 1
Enter the number: 4

1. Insertion    2. Deletion     3. Display      4. Exit
Select the operation to perform: 1
Enter the number: 5

1. Insertion    2. Deletion     3. Display      4. Exit
Select the operation to perform: 1
Enter the number: 6

1. Insertion    2. Deletion     3. Display      4. Exit
Select the operation to perform: 2
Deleted: 1

1. Insertion    2. Deletion     3. Display      4. Exit
Select the operation to perform: 3
Queue elements: 2       3       4       5       6

1. Insertion    2. Deletion     3. Display      4. Exit
Select the operation to perform: 1
Enter the number: 1

1. Insertion    2. Deletion     3. Display      4. Exit
Select the operation to perform: 3
Queue elements: 2       3       4       5       6       1

1. Insertion    2. Deletion     3. Display      4. Exit
Select the operation to perform: 2
Deleted: 2

1. Insertion    2. Deletion     3. Display      4. Exit
Select the operation to perform: 2
Deleted: 3

1. Insertion    2. Deletion     3. Display      4. Exit
Select the operation to perform: 2
Deleted: 4

1. Insertion    2. Deletion     3. Display      4. Exit
Select the operation to perform: 3
Queue elements: 5       6       1

1. Insertion    2. Deletion     3. Display      4. Exit
Select the operation to perform: 6
Invalid choice.

1. Insertion    2. Deletion     3. Display      4. Exit
Select the operation to perform: 4*/
