#include<stdio.h>
#define MAX 5

int front=-1,rear=-1;
int queue[MAX];

int dequeue(){
    int num;
    if(front==-1 || front>rear ){
        printf("Queue underflow");
        return -1;
    }
    if(front==rear){
        num=queue[front];
        front=-1;
        rear=-1;
        return num;
    }
    else{
        num=queue[front];
        front++;
        return num;
    }
}
void enqueue(int num){
    if(rear==MAX-1 || front>rear){
        printf("Queue overflow");
        return;
    }
    if(front==-1 && rear==-1){
        front=0;
        rear=0;
        queue[rear]=num;
    }
    else{
        rear++;
        queue[rear]=num;
    }
    }
void display(){
    if(front==-1 || front>rear){
        printf("Queue is Empty");

    }
    else{
        for(int i=front; i<=rear; i++){
            printf("%d ",queue[i]);
        }
    }
}
void main(){
    int op;
    int ele;
    while(1){
        printf("\n Enter the operation to perform");
        printf("\n 1.Queue Insertion");
        printf("\n 2.Queue Deletion");
        printf("\n 3.Queue Display \n");
        scanf("%d",&op);

        switch(op){
            case 1:
                printf("Enter the number to insert:");
                scanf("%d",&ele);
                enqueue(ele);
                break;
            case 2:
                ele=dequeue();
                printf("%d deleted successfully",ele);
                break;
            case 3:
                display();
                break;
            default:
                exit(0);
                break;
        }
    }
}
/*Output: 
Enter the operation to perform
 1.Queue Insertion
 2.Queue Deletion
 3.Queue Display
1
Enter the number to insert:1

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
Queue is Empty
 Enter the operation to perform
 1.Queue Insertion
 2.Queue Deletion
 3.Queue Display
1
Enter the number to insert:1

 Enter the operation to perform
 1.Queue Insertion
 2.Queue Deletion
 3.Queue Display
1
Enter the number to insert:2

 Enter the operation to perform
 1.Queue Insertion
 2.Queue Deletion
 3.Queue Display 
1
Enter the number to insert:3 

 Enter the operation to perform
 1.Queue Insertion
 2.Queue Deletion
 3.Queue Display
1
Enter the number to insert:4

 Enter the operation to perform
 1.Queue Insertion
 2.Queue Deletion
 3.Queue Display
1
Enter the number to insert:5

 Enter the operation to perform
 1.Queue Insertion
 2.Queue Deletion
 3.Queue Display
1
Enter the number to insert:6
Queue overflow
 Enter the operation to perform
 3.Queue Display
1
Enter the number to insert:6
Queue overflow
 Enter the operation to perform
Enter the number to insert:6
Queue overflow
 Enter the operation to perform
 Enter the operation to perform
 1.Queue Insertion
 2.Queue Deletion
 3.Queue Display
 4
 */
