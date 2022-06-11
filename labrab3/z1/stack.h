#include <string.h>
using namespace std;

struct node {
    char value[255];
    struct node* next;
};

void push(struct node** node, string value);
void pop(struct node** node);
string top(struct node* node);
bool isStackEmpty(struct node* node);

void push(struct node** node, string value) {
    struct node* tmp = (struct node*)malloc(sizeof(struct node));
    strcpy(tmp->value, value.c_str());
    tmp->next = (*node);
    (*node) = tmp;
}

void pop(struct node** node) {
    if (isStackEmpty(*node)) return;
    
    (*node) = (*node)->next;
}

string top(struct node* node) {
    if (isStackEmpty(node)) return "";
    return string(node->value);
}

bool isStackEmpty(struct node* node) {;
    if (node) return false;
    return true;
}
