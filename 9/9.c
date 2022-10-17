#include "../geek.h"

int bracesCheck(char* expression) {
    const int TYPES = 3;
    char braces[][2] = {{'(', ')'}, {'{', '}'}, {'[', ']'}}; // <>, "", begin-end
    OneLinkList *st = (OneLinkList*) malloc(sizeof(OneLinkList));
    initOneLinkList(st);
    int countIndex = 0;
    while (*expression != '\0') {
        for (int i = 0; i < TYPES; ++i) {
            if (*expression == braces[i][0])
              pushOneLinkStack(st, i);
        }
        for (int i = 0; i < TYPES; ++i) {
            if (*expression == braces[i][1]) {
                if (st->size == 0)
                  return countIndex;
                if (i == st->head->dat)
                    popOneLinkStack(st);
                else
                    return countIndex;
            }
        }
        expression++;
        countIndex++;
    }
    if (st->size != 0)
        return st->head->dat;
    return -1;
}

void copyList(OneLinkList* from, OneLinkList* to) {
 	OneLinkNode* current = from->head;
 	if (current == NULL) return;

    pushOneLinkStack(to, current->dat);
    OneLinkNode* nodeInNew = to->head;
    while (current->next != NULL) {
        OneLinkNode *tmp = (OneLinkNode*) malloc(sizeof(OneLinkNode));
        if (tmp == NULL) {
            printf("Stack overflow \n");
            return;
        }
        tmp->dat = current->next->dat;
        nodeInNew->next = tmp;
        tmp->next = NULL;

        current = current->next;
        nodeInNew = tmp;
        to->size++;
    }
}

boolean isSorted(OneLinkList *lst) {
    boolean asc = true;
    boolean desc = true;
    OneLinkNode *current = lst->head;
    while (current->next != NULL) {
        if (current->dat > current->next->dat)
            asc = false;
        if (current->dat < current->next->dat)
            desc = false;
        current = current->next;
    }
    return asc || desc;
}

int main() {
    printf("%d \n", bracesCheck(")"));
    printf("%d \n", bracesCheck("{ ( [ {} [] () ] ( }"));
    printf("%d \n", bracesCheck("[2 / {5 * (4 + 7)}]"));

    OneLinkList* first = (OneLinkList*) malloc(sizeof(OneLinkList));
    initOneLinkList(first);
    OneLinkList* second = (OneLinkList*) malloc(sizeof(OneLinkList));
    initOneLinkList(second);
    for (int i = 9; i > 1; --i) {
        pushOneLinkStack(first, i);
    }
    copyList(first, second);
    printOneLinkIntList(first);
    printOneLinkIntList(second);
    printf("%s \n", isSorted(first) ? "true" : "false");
}

