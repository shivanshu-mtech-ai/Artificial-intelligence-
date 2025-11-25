#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Simple queue for level-order insertion
struct Queue {
    int front, rear, size;
    struct Node** arr;
};

struct Queue* createQueue(int size) {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = -1;
    q->size = size;
    q->arr = (struct Node**)malloc(sizeof(struct Node*) * size);
    return q;
}

int isEmpty(struct Queue* q) {
    return q->front == -1;
}

void enqueue(struct Queue* q, struct Node* node) {
    if (q->rear == q->size - 1) {
        printf("Queue Overflow\n");
        return;
    }
    q->arr[++q->rear] = node;
    if (q->front == -1) q->front = 0;
}

struct Node* dequeue(struct Queue* q) {
    if (isEmpty(q)) return NULL;

    struct Node* temp = q->arr[q->front];

    if (q->front == q->rear)
        q->front = q->rear = -1;
    else
        q->front++;

    return temp;
}

// Build tree using level-order user input
void buildFromLevelOrder(struct Node** root) {
    int data;
    printf("Enter root data (-1 for NULL): ");
    scanf("%d", &data);

    if (data == -1) {
        *root = NULL;
        return;
    }

    *root = createNode(data);

    struct Queue* q = createQueue(100);
    enqueue(q, *root);

    while (!isEmpty(q)) {
        struct Node* temp = dequeue(q);

        int leftData, rightData;

        printf("Enter left child of %d (-1 for NULL): ", temp->data);
        scanf("%d", &leftData);

        if (leftData != -1) {
            temp->left = createNode(leftData);
            enqueue(q, temp->left);
        }

        printf("Enter right child of %d (-1 for NULL): ", temp->data);
        scanf("%d", &rightData);

        if (rightData != -1) {
            temp->right = createNode(rightData);
            enqueue(q, temp->right);
        }
    }
}

// Traversals
void preorder(struct Node* root) {
    if (root == NULL) return;

    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void inorder(struct Node* root) {
    if (root == NULL) return;

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void postorder(struct Node* root) {
    if (root == NULL) return;

    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

int main() {
    struct Node* root = NULL;

    buildFromLevelOrder(&root);

    printf("\nPreorder Traversal: ");
    preorder(root);

    printf("\nInorder Traversal: ");
    inorder(root);

    printf("\nPostorder Traversal: ");
    postorder(root);

    return 0;
}
