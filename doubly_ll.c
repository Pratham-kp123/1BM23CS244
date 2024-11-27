#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *prev;
    struct node *next;
} *start = NULL;

struct node *create_ll(struct node *start) {
    struct node *ptr, *newnode;
    int num;
    printf("Enter -1 to end:");
    printf("\n Enter a value: ");
    scanf("%d", &num);
    while (num != -1) {
        if (start == NULL) {
            newnode = (struct node *)malloc(sizeof(struct node));
            newnode->prev = NULL;
            newnode->data = num;
            newnode->next = NULL;
            start = newnode;
        } else {
            ptr = start;
            newnode = (struct node *)malloc(sizeof(struct node));
            newnode->data = num;
            while (ptr->next != NULL) {
                ptr = ptr->next;
            }
            ptr->next = newnode;
            newnode->prev = ptr;
            newnode->next = NULL;
        }
        printf("\n Enter a value: ");
        scanf("%d", &num);
    }
    return start;
}

struct node *display(struct node *start) {
    if (start == NULL) {
        printf("List is empty.\n");
        return start;
    }
    struct node *ptr = start;
    printf("The list is:");
    while (ptr != NULL) {
        printf("\t%d", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
    return start;
}

struct node *insert_before(struct node *start) {
    struct node *ptr, *newnode;
    int num, val;
    if (start == NULL) {
        printf("List is empty.\n");
        return start;
    }
    printf("Enter the data: ");
    scanf("%d", &num);
    printf("Enter the value before which the data has to be inserted: ");
    scanf("%d", &val);
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = num;
    ptr = start;
    while (ptr != NULL && ptr->data != val) {
        ptr = ptr->next;
    }
    if (ptr == NULL) {
        printf("Value not found in the list.\n");
        free(newnode);
        return start;
    }
    if (ptr == start) {
        newnode->next = start;
        newnode->prev = NULL;
        start->prev = newnode;
        start = newnode;
    } else {
        newnode->next = ptr;
        newnode->prev = ptr->prev;
        ptr->prev->next = newnode;
        ptr->prev = newnode;
    }
    return start;
}

struct node *delete_value(struct node *start) {
    struct node *ptr, *temp;
    int val;
    if (start == NULL) {
        printf("List is empty.\n");
        return start;
    }
    printf("Enter the data to be deleted: ");
    scanf("%d", &val);
    ptr = start;
    while (ptr != NULL && ptr->data != val) {
        ptr = ptr->next;
    }
    if (ptr == NULL) {
        printf("Value not found in the list.\n");
        return start;
    }
    if (ptr == start) {
        start = start->next;
        if (start != NULL) start->prev = NULL;
        free(ptr);
    } else {
        ptr->prev->next = ptr->next;
        if (ptr->next != NULL) ptr->next->prev = ptr->prev;
        free(ptr);
    }
    return start;
}

void main() {
    int op;
    while (1) {
        printf("\nEnter the choice: ");
        printf("\n 1.Create ll \t 2.Display \t 3.Insert Before \t 4.Delete Value \t 5.Exit\n");
        scanf("%d", &op);
        switch (op) {
            case 1:
                start = create_ll(start);
                break;
            case 2:
                start = display(start);
                break;
            case 3:
                start = insert_before(start);
                break;
            case 4:
                start = delete_value(start);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
}
/* Output: Enter the choice:
 1.Create ll     2.Display       3.Insert Before         4.Delete Value          5.Exit
1
Enter -1 to end:
 Enter a value: 1

 Enter a value:
2

 Enter a value: 3

 Enter a value: 4

 Enter a value: 5

 Enter a value: -1

Enter the choice:
 1.Create ll     2.Display       3.Insert Before         4.Delete Value          5.Exit
2
The list is:    1       2       3       4       5

Enter the choice:
 1.Create ll     2.Display       3.Insert Before         4.Delete Value          5.Exit
4
Enter the data to be deleted: 1

Enter the choice:
 1.Create ll     2.Display       3.Insert Before         4.Delete Value          5.Exit
2
The list is:    2       3       4       5

Enter the choice:
 1.Create ll     2.Display       3.Insert Before         4.Delete Value          5.Exit
4
Enter the data to be deleted: 5

Enter the choice:
 1.Create ll     2.Display       3.Insert Before         4.Delete Value          5.Exit
2
The list is:    2       3       4

Enter the choice:
 1.Create ll     2.Display       3.Insert Before         4.Delete Value          5.Exit
3
Enter the data: 6
Enter the value before which the data has to be inserted: 3

Enter the choice:
 1.Create ll     2.Display       3.Insert Before         4.Delete Value          5.Exit
2
The list is:    2       6       3       4

Enter the choice:
 1.Create ll     2.Display       3.Insert Before         4.Delete Value          5.Exit
5
*/
