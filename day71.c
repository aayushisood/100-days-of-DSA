#include <stdio.h>
#include <string.h>

#define SIZE 100

int table[SIZE];

// Initialize table
void init(int m) {
    for (int i = 0; i < m; i++)
        table[i] = -1;
}

// Hash function
int hash(int key, int m) {
    return key % m;
}

// Insert using quadratic probing
void insert(int key, int m) {
    int h = hash(key, m);

    for (int i = 0; i < m; i++) {
        int idx = (h + i * i) % m;
        if (table[idx] == -1) {
            table[idx] = key;
            return;
        }
    }
}

// Search using quadratic probing
void search(int key, int m) {
    int h = hash(key, m);

    for (int i = 0; i < m; i++) {
        int idx = (h + i * i) % m;

        if (table[idx] == key) {
            printf("FOUND\n");
            return;
        }

        if (table[idx] == -1) {
            printf("NOT FOUND\n");
            return;
        }
    }

    printf("NOT FOUND\n");
}

int main() {
    int n, m, key;
    char op[10];

    scanf("%d", &n);
    scanf("%d", &m);

    init(m);

    for (int i = 0; i < n; i++) {
        scanf("%s", op);

        if (strcmp(op, "INSERT") == 0) {
            scanf("%d", &key);
            insert(key, m);
        } else if (strcmp(op, "SEARCH") == 0) {
            scanf("%d", &key);
            search(key, m);
        }
    }

    return 0;
}
