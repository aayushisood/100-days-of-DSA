#include <stdio.h>
#define MAX 100

int dq[MAX];
int front = -1, rear = -1;

// Check empty
int empty() {
    return (front == -1);
}

// Check full
int full() {
    return ((front == 0 && rear == MAX - 1) || (front == rear + 1));
}

// Push front
void push_front(int x) {
    if (full()) {
        printf("Overflow\n");
        return;
    }

    if (empty()) {
        front = rear = 0;
    } else if (front == 0) {
        front = MAX - 1;
    } else {
        front--;
    }

    dq[front] = x;
}

// Push back
void push_back(int x) {
    if (full()) {
        printf("Overflow\n");
        return;
    }

    if (empty()) {
        front = rear = 0;
    } else if (rear == MAX - 1) {
        rear = 0;
    } else {
        rear++;
    }

    dq[rear] = x;
}

// Pop front
void pop_front() {
    if (empty()) {
        printf("Underflow\n");
        return;
    }

    if (front == rear) {
        front = rear = -1;
    } else if (front == MAX - 1) {
        front = 0;
    } else {
        front++;
    }
}

// Pop back
void pop_back() {
    if (empty()) {
        printf("Underflow\n");
        return;
    }

    if (front == rear) {
        front = rear = -1;
    } else if (rear == 0) {
        rear = MAX - 1;
    } else {
        rear--;
    }
}

// Front element
void get_front() {
    if (empty()) printf("-1\n");
    else printf("%d\n", dq[front]);
}

// Back element
void get_back() {
    if (empty()) printf("-1\n");
    else printf("%d\n", dq[rear]);
}

// Size
int size() {
    if (empty()) return 0;
    if (rear >= front) return rear - front + 1;
    return MAX - front + rear + 1;
}

// Display
void display() {
    if (empty()) {
        printf("Deque is empty\n");
        return;
    }

    int i = front;
    while (1) {
        printf("%d ", dq[i]);
        if (i == rear) break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main() {
    // Example usage (you can modify input style as needed)

    push_back(10);
    push_back(20);
    push_front(5);
    display();      // 5 10 20

    pop_front();
    display();      // 10 20

    pop_back();
    display();      // 10

    get_front();    // 10
    get_back();     // 10

    printf("%d\n", size()); // 1

    return 0;
}
