#include <stdio.h>
#include <stdlib.h>

#define MAX 5

int front = -1, rear = -1;
int queue[MAX];

int dequeue() {
    int num;
    if (front == -1) {
        printf("Queue underflow\n");
        return -1;
    }
    num = queue[front];
    if (front == rear) {  // Reset if only one element was left
        front = -1;
        rear = -1;
    } else {
        front = (front + 1) % MAX;
    }
    return num;
}

void enqueue(int num) {
    if ((rear + 1) % MAX == front) {  // Correct overflow condition
        printf("Queue overflow\n");
        return;
    }
    if (front == -1) {  // First element insertion
        front = 0;
    }
    rear = (rear + 1) % MAX;
    queue[rear] = num;
}

void display() {
    if (front == -1) {
        printf("Queue is Empty\n");
        return;
    }
    int i = front;
    while (i != rear) {
        printf("%d ", queue[i]);
        i = (i + 1) % MAX;
    }
    printf("%d\n", queue[rear]);  // Print the last element at rear
}

void main() {
    int op;
    int ele;
    while (1) {
        printf("\nEnter the operation to perform");
        printf("\n1.Queue Insertion");
        printf("\n2.Queue Deletion");
        printf("\n3.Queue Display\n");
        scanf("%d", &op);

        switch (op) {
            case 1:
                printf("Enter the number to insert: ");
                scanf("%d", &ele);
                enqueue(ele);
                break;
            case 2:
                ele = dequeue();
                if (ele != -1) {
                    printf("%d deleted successfully\n", ele);
                }
                break;
            case 3:
                display();
                break;
            default:
                exit(0);
        }
    }
}
/*Output: 

Enter the operation to perform
1.Queue Insertion
2.Queue Deletion
3.Queue Display
1
Enter the number to insert: 1

Enter the operation to perform
1.Queue Insertion
2.Queue Deletion
3.Queue Display
1
Enter the number to insert: 2

Enter the operation to perform
1.Queue Insertion
2.Queue Deletion
3.Queue Display
1
Enter the number to insert: 3

Enter the operation to perform
1.Queue Insertion
2.Queue Deletion
3.Queue Display
2
1 deleted successfully

Enter the operation to perform
1.Queue Insertion
2.Queue Deletion
3.Queue Display
3
2 3

Enter the operation to perform
1.Queue Insertion
2.Queue Deletion
3.Queue Display
1
Enter the number to insert: 4

Enter the operation to perform
1.Queue Insertion
2.Queue Deletion
3.Queue Display
1
Enter the number to insert: 5

Enter the operation to perform
1.Queue Insertion
2.Queue Deletion
3.Queue Display
1
Enter the number to insert: 6

Enter the operation to perform
1.Queue Insertion
2.Queue Deletion
3.Queue Display
3
6 2 3 4 5 

Enter the operation to perform
1.Queue Insertion
2.Queue Deletion
3.Queue Display
 4 
*/
