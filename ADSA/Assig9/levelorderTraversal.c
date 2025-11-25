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

// Queue Implementation in C
struct Queue {
    int front, rear, size;
    struct Node** arr;
};

// Create queue
struct Queue* createQueue(int capacity) {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = -1;
    q->size = capacity;
    q->arr = (struct Node**)malloc(sizeof(struct Node*) * capacity);
    return q;
}

// Check if queue is empty
int isEmpty(struct Queue* q) {
    return q->front == -1;
}

// Enqueue
void enqueue(struct Queue* q, struct Node* node) {
    if (q->rear == q->size - 1) {
        printf("Queue Overflow!\n");
        return;
    }
    q->arr[++q->rear] = node;
    if (q->front == -1) q->front = 0;
}

// Dequeue
struct Node* dequeue(struct Queue* q) {
    if (isEmpty(q)) {
        return NULL;
    }
    struct Node* temp = q->arr[q->front];

    if (q->front == q->rear)
        q->front = q->rear = -1;
    else
        q->front++;

    return temp;
}

// Level-order Traversal
void levelOrder(struct Node* root) {
    if (root == NULL) return;

    struct Queue* q = createQueue(100);

    enqueue(q, root);

    while (!isEmpty(q)) {
        struct Node* current = dequeue(q);
        printf("%d ", current->data);

        if (current->left)
            enqueue(q, current->left);

        if (current->right)
            enqueue(q, current->right);
    }
}

int main() {

    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);

    printf("Level Order Traversal:\n");
    levelOrder(root);

    return 0;
}
