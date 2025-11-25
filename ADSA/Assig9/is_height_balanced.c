#include <stdio.h>
#include <stdlib.h>

// Node Structure
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create Node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

/**************** BUILD TREE (using -1 as NULL) ****************/
struct Node* buildTree() {
    int data;
    printf("Enter data (-1 for NULL): ");
    scanf("%d", &data);

    if (data == -1)
        return NULL;

    struct Node* root = createNode(data);

    printf("Enter left child of %d\n", data);
    root->left = buildTree();

    printf("Enter right child of %d\n", data);
    root->right = buildTree();

    return root;
}

/**************** HEIGHT FUNCTION ****************/
int height(struct Node* root) {
    if (!root) return 0;

    int lh = height(root->left);
    int rh = height(root->right);

    return (lh > rh ? lh : rh) + 1;
}

/**************** CHECK BALANCED + PRINT BALANCE FACTOR ************/
int checkBalanced(struct Node* root, int* isBalanced) {
    if (root == NULL) return 0;

    int leftHeight = checkBalanced(root->left, isBalanced);
    int rightHeight = checkBalanced(root->right, isBalanced);

    int balanceFactor = leftHeight - rightHeight;

    // Print balance factor of current node
    printf("Node %d → Balance Factor = %d\n", root->data, balanceFactor);

    // If difference > 1, tree is not balanced
    if (balanceFactor > 1 || balanceFactor < -1)
        *isBalanced = 0;

    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

/**************** MAIN FUNCTION ****************/
int main() {
    struct Node* root = NULL;
    root = buildTree();

    int isBalanced = 1;

    printf("\n--- Balance Factors ---\n");
    checkBalanced(root, &isBalanced);

    printf("\nIs the tree height-balanced? -> ");
    if (isBalanced)
        printf("YES (AVL)\n");
    else
        printf("NO (Not AVL)\n");

    return 0;
}
