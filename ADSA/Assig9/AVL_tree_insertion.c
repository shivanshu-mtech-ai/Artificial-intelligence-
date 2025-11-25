#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
    int height;
};

// Get height
int getHeight(struct Node* n) {
    if (n == NULL)
        return 0;
    return n->height;
}

// Create a node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    newNode->height = 1;
    return newNode;
}

// Get balance factor
int getBalance(struct Node* n) {
    if (n == NULL) return 0;
    return getHeight(n->left) - getHeight(n->right);
}


// Right rotation (LL case)
struct Node* rightRotate(struct Node* y) {
    printf("Rotation: RIGHT (LL Rotation)\n");
    
    struct Node* x = y->left;
    struct Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = 1 + (getHeight(y->left) > getHeight(y->right)
                      ? getHeight(y->left) : getHeight(y->right));
                      
    x->height = 1 + (getHeight(x->left) > getHeight(x->right)
                      ? getHeight(x->left) : getHeight(x->right));

    return x;
}

// Left rotation (RR case)
struct Node* leftRotate(struct Node* x) {
    printf("Rotation: LEFT (RR Rotation)\n");

    struct Node* y = x->right;
    struct Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = 1 + (getHeight(x->left) > getHeight(x->right)
                      ? getHeight(x->left) : getHeight(x->right));
                      
    y->height = 1 + (getHeight(y->left) > getHeight(y->right)
                      ? getHeight(y->left) : getHeight(y->right));

    return y;
}

struct Node* insert(struct Node* root, int key) {

    if (root == NULL)
        return createNode(key);

    // Normal BST insert
    if (key < root->data)
        root->left = insert(root->left, key);

    else if (key > root->data)
        root->right = insert(root->right, key);

    else 
        return root;

    // Update height
    root->height = 1 + (getHeight(root->left) > getHeight(root->right)
                        ? getHeight(root->left) : getHeight(root->right));

    // Get balance factor
    int balance = getBalance(root);
    printf("Inserted %d → Node %d Balance = %d\n", key, root->data, balance);

    // CASE 1: Left Left (LL)
    if (balance > 1 && key < root->left->data)
        return rightRotate(root);

    // CASE 2: Right Right (RR)
    if (balance < -1 && key > root->right->data)
        return leftRotate(root);

    // CASE 3: Left Right (LR)
    if (balance > 1 && key > root->left->data) {
        printf("Rotation: LEFT then RIGHT (LR Rotation)\n");
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // CASE 4: Right Left (RL)
    if (balance < -1 && key < root->right->data) {
        printf("Rotation: RIGHT then LEFT (RL Rotation)\n");
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

void inorder(struct Node* root) {
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main() {
    struct Node* root = NULL;
    int n, value;

    printf("Enter number of nodes to insert: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("\nEnter value to insert: ");
        scanf("%d", &value);
        root = insert(root, value);
        printf("-------------------------------\n");
    }

    printf("\nFinal AVL Tree (Inorder Traversal): ");
    inorder(root);
    printf("\n");

    return 0;
}
