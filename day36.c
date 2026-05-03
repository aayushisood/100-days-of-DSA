#include <stdio.h>

#define MAX 100

int queue[MAX];
int front = 0, rear = -1;
int size = 0;

// Enqueue
void enqueue(int value) {
    if (size == MAX) {
        printf("Queue Overflow\n");
        return;
    }
    rear = (rear + 1) % MAX;
    queue[rear] = value;
    size++;
}

// Dequeue (returns removed element)
int dequeue() {
    if (size == 0) {
        printf("Queue Underflow\n");
        return -1;
    }
    int value = queue[front];
    front = (front + 1) % MAX;
    size--;
    return value;
}

// Display
void display() {
    int i, count;
    for (i = front, count = 0; count < size; count++) {
        printf("%d ", queue[i]);
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main() {
    int n, m, value;

    scanf("%d", &n);

    // Enqueue elements
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        enqueue(value);
    }

    scanf("%d", &m);

    // Perform m rotations (dequeue + enqueue)
    for (int i = 0; i < m; i++) {
        int temp = dequeue();
        enqueue(temp);
    }

    display();

    return 0;
}
