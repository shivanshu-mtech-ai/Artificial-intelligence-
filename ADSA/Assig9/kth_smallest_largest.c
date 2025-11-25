#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Insert into BST
struct Node* insert(struct Node* root, int data) {
    if (root == NULL)
        return createNode(data);

    if (data < root->data)
        root->left = insert(root->left, data);
    else
        root->right = insert(root->right, data);

    return root;
}

/**************** K-th Smallest (Inorder Traversal) ****************/
void kthSmallestUtil(struct Node* root, int k, int* count, int* result) {
    if (root == NULL)
        return;

    kthSmallestUtil(root->left, k, count, result);
    
    (*count)++;
    if (*count == k) {
        *result = root->data;
        return;
    }

    kthSmallestUtil(root->right, k, count, result);
}

int kthSmallest(struct Node* root, int k) {
    int count = 0, result = -1;
    kthSmallestUtil(root, k, &count, &result);
    return result;
}

/**************** K-th Largest (Reverse Inorder Traversal) ****************/
void kthLargestUtil(struct Node* root, int k, int* count, int* result) {
    if (root == NULL)
        return;

    kthLargestUtil(root->right, k, count, result);

    (*count)++;
    if (*count == k) {
        *result = root->data;
        return;
    }

    kthLargestUtil(root->left, k, count, result);
}

int kthLargest(struct Node* root, int k) {
    int count = 0, result = -1;
    kthLargestUtil(root, k, &count, &result);
    return result;
}

/************************ MAIN FUNCTION ************************/
int main() {
    struct Node* root = NULL;
    int n, value, k;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter values to insert into BST:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        root = insert(root, value);
    }

    printf("Enter k for k-th smallest: ");
    scanf("%d", &k);
    int ks = kthSmallest(root, k);
    if (ks != -1)
        printf("%d-th smallest element = %d\n", k, ks);
    else
        printf("Invalid k\n");

    printf("Enter k for k-th largest: ");
    scanf("%d", &k);
    int kl = kthLargest(root, k);
    if (kl != -1)
        printf("%d-th largest element = %d\n", k, kl);
    else
        printf("Invalid k\n");

    return 0;
}
