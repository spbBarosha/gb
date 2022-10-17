#include "../geek.h"

typedef struct {
    int pr;
    int dat;
} Node;

#define SZ 20
Node* arr[SZ];
int tail;
int items;

void init() {
    tail = 0;
    items = 0;
    for (int i = 0; i < SZ; ++i) {
        arr[i] = NULL;
    }
}

void insert(int pr, int dat) {
    Node *node = (Node*) malloc(sizeof(Node));
    node->pr = pr;
    node->dat = dat;
    if (items < SZ) {
        arr[tail++] = node;
        items++;
    } else {
        printf("%s \n", "Queue is full!");
    }
}

int rem() {
    if (items == 0) {
        printf("%s \n", "Queue is empty");
        return 0;
    }
    int max = arr[0]->pr;
    int idx = 0;

    for (int i = 1; i < items; ++i) {
        if (arr[i]->pr > max) {
            max = arr[i]->pr;
            idx = i;
        }
    }
    Node *tmp = arr[idx];
    int result = tmp->dat;
     arr[idx] = arr[--tail];

    items--;
    free(tmp);
    return result;
}

#define T char
#define SIZE 1000

int cursor = -1;
T Stack[SIZE];

boolean pushStack(T data) {
    if (cursor < SIZE) {
        Stack[++cursor] = data;
        return true;
    } else {
        printf("%s \n", "Stack overflow");
        return false;
    }
}

T popStack() {
    if (cursor != -1) {
        return Stack[cursor--];
    } else {
        printf("%s \n", "Stack is empty");
        return -1;
    }
}

boolean decToBin(int a, char *result) {
    if (a <= 0) return false;
    while (a >= 1) {
        pushStack(a % 2);
        a /= 2;
    }
    while (cursor != -1) {
        strcat(result, (popStack()) ? "1" : "0");
    }
    strcat(result, "\0");
    return true;
}

int main() {
    init();
    insert(3, 3);
    insert(4, 4);
    insert(2, 2);
    insert(0, 0);
    insert(1, 1);
    printf("%d ", rem());
    printf("%d ", rem());
    printf("%d ", rem());
    printf("%d ", rem());

    char bin[35] = "b'";
    boolean b = decToBin(10, bin);
    if (!b) {
        printf("dec-to-bin failed");
        return 1;
    }
    printf("\nbin\n");
    printf("%s\n", bin);
    return 0;
}
