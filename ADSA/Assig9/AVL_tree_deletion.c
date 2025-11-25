#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
    int height;
};

// Utility: get height
int getHeight(struct Node* n) {
    if (n == NULL) return 0;
    return n->height;
}

// Utility: max
int max(int a, int b) {
    return a > b ? a : b;
}

// Utility: create node
struct Node* createNode(int key) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = key;
    newNode->left = newNode->right = NULL;
    newNode->height = 1;
    return newNode;
}

// Utility: get balance factor
int getBalance(struct Node* n) {
    if (n == NULL) return 0;
    return getHeight(n->left) - getHeight(n->right);
}

struct Node* rightRotate(struct Node* y) {
    printf("Rotation: RIGHT (LL Rotation)\n");
    struct Node* x = y->left;
    struct Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

    return x;
}

struct Node* leftRotate(struct Node* x) {
    printf("Rotation: LEFT (RR Rotation)\n");
    struct Node* y = x->right;
    struct Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

    return y;
}

struct Node* insert(struct Node* root, int key) {
    if (root == NULL)
        return createNode(key);

    if (key < root->data)
        root->left = insert(root->left, key);
    else if (key > root->data)
        root->right = insert(root->right, key);
    else
        return root;

    root->height = 1 + max(getHeight(root->left), getHeight(root->right));

    int balance = getBalance(root);

    if (balance > 1 && key < root->left->data)
        return rightRotate(root);

    if (balance < -1 && key > root->right->data)
        return leftRotate(root);

    if (balance > 1 && key > root->left->data) {
        printf("Rotation: LEFT then RIGHT (LR Rotation)\n");
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if (balance < -1 && key < root->right->data) {
        printf("Rotation: RIGHT then LEFT (RL Rotation)\n");
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

struct Node* findMin(struct Node* root) {
    while (root->left != NULL)
        root = root->left;
    return root;
}

struct Node* deleteNode(struct Node* root, int key) {

    if (root == NULL)
        return root;

    // BST DELETE
    if (key < root->data)
        root->left = deleteNode(root->left, key);

    else if (key > root->data)
        root->right = deleteNode(root->right, key);

    else { 
        if (root->left == NULL || root->right == NULL) {
            struct Node* temp = root->left ? root->left : root->right;
            if (temp == NULL) {
                free(root);
                return NULL;
            } else {
                *root = *temp;
                free(temp);
            }
        } else {
            struct Node* temp = findMin(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }

    // Update height
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));

    // Get balance factor
    int balance = getBalance(root);

    printf("After deleting %d → Node %d Balance = %d\n", key, root->data, balance);

    // LL Case
    if (balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);

    // RR Case
    if (balance < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);

    // LR Case
    if (balance > 1 && getBalance(root->left) < 0) {
        printf("Rotation: LEFT then RIGHT (LR Rotation)\n");
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // RL Case
    if (balance < -1 && getBalance(root->right) > 0) {
        printf("Rotation: RIGHT then LEFT (RL Rotation)\n");
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

void inorder(struct Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main() {
    struct Node* root = NULL;
    int n, value;

    printf("Enter number of nodes to insert: ");
    scanf("%d", &n);

    printf("\n-- INSERTING NODES --\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        root = insert(root, value);
    }

    printf("\nInitial Tree Height = %d\n", getHeight(root));

    printf("\nEnter number of nodes to delete: ");
    int d;  scanf("%d", &d);

    printf("\n-- DELETING NODES --\n");
    for (int i = 0; i < d; i++) {
        scanf("%d", &value);
        root = deleteNode(root, value);
        printf("Tree Height after deletion = %d\n", getHeight(root));
        printf("------------------------------------\n");
    }

    printf("\nFinal Tree Inorder: ");
    inorder(root);
    printf("\n");

    return 0;
}
