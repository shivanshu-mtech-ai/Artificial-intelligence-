#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Tree Node structure
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create new node
struct Node* newNode(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

// Insert nodes like a normal binary tree (not BST insertion)
struct Node* insertLevelOrder(int arr[], struct Node* root, int i, int n) {
    if (i < n) {
        root = newNode(arr[i]);
        root->left = insertLevelOrder(arr, root->left, 2*i + 1, n);
        root->right = insertLevelOrder(arr, root->right, 2*i + 2, n);
    }
    return root;
}

// MIN-MAX method to check if tree is BST
int isBSTUtil(struct Node* root, int min, int max) {
    if (root == NULL)
        return 1;   // Empty tree is BST

    // Check current node
    if (root->data <= min || root->data >= max)
        return 0;

    // Left subtree must be in range (min, root->data)
    // Right subtree must be in range (root->data, max)
    return isBSTUtil(root->left, min, root->data) &&
           isBSTUtil(root->right, root->data, max);
}

// Wrapper function
int isBST(struct Node* root) {
    return isBSTUtil(root, INT_MIN, INT_MAX);
}

// Driver Code
int main() {
    int n;
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter nodes in level order (-1 for null):\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    // Build tree from array (level order)
    struct Node* root = insertLevelOrder(arr, NULL, 0, n);

    if (isBST(root))
        printf("The tree is a VALID BST\n");
    else
        printf("The tree is NOT a BST\n");

    return 0;
}
