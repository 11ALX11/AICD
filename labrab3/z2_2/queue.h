#include <string.h>
#include <iostream>
using namespace std;

struct node {
    int value;
    struct node* next;
};

void push(struct node** node, int value);
void pop(struct node** node);
int front(struct node* node);
bool empty(struct node* node);

void push(struct node** head, int value) {
    struct node* tmp = (struct node*)malloc(sizeof(struct node));
    tmp->value = value;
    tmp->next = nullptr;
    
    struct node* node = *head;
    if (node) {
        while (node->next) {
            node = node->next;
        }
        node->next = tmp;
    }
    else {
        (*head) = tmp;
    }
}

void pop(struct node** node) {
    *node = (*node)->next;
}

int front(struct node* node) {
    if (node) return node->value;
    return NULL;
}

bool empty(struct node* node) {
    if (node) return false;
    return true;
}
