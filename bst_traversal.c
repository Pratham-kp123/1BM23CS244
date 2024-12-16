#include <stdio.h>
#include <malloc.h>

typedef struct BST {
    int data;
    struct BST *left;
    struct BST *right;
} node;

node *create() {
    node *temp;
    printf("Enter data: ");
    temp = (node *)malloc(sizeof(node));
    scanf("%d", &temp->data);
    temp->left = temp->right = NULL;
    return temp;
}

void insert(node *root, node *temp) {
    if (temp->data < root->data) {
        if (root->left != NULL)
            insert(root->left, temp);
        else
            root->left = temp;
    } else if (temp->data > root->data) {
        if (root->right != NULL)
            insert(root->right, temp);
        else
            root->right = temp;
    }
}

void preorder(node *root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(node *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void postorder(node *root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

int main() {
    char ch;
    int n = 1;
    node *root = NULL, *temp;
    do {
        temp = create();
        if (root == NULL)
            root = temp;
        else
            insert(root, temp);
        printf("\nEnter 0 to exit ");
        scanf("%d",&n);
    } while (n!=0);

    printf("\nPreorder Traversal: ");
    preorder(root);
    printf("\nInorder Traversal: ");
    inorder(root);
    printf("\nPostorder Traversal: ");
    postorder(root);

    return 0;
}

/*Output: 
Enter data: 20

Enter 0 to exit 4
Enter data: 15

Enter 0 to exit 7
Enter data: 25

Enter 0 to exit 8
Enter data: 7

Enter 0 to exit 8
Enter data: 17

Enter 0 to exit 5
Enter data: 22

Enter 0 to exit 8
Enter data: 30

Enter 0 to exit 0

Preorder Traversal: 20 15 7 17 25 22 30 
Inorder Traversal: 7 15 17 20 22 25 30 
Postorder Traversal: 7 17 15 22 30 25 20 

=== Code Execution Successful ===
*/
