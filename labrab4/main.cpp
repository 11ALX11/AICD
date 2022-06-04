#include <iostream>
#include <fstream>
#include <string>
#include "bstree.h"
#include "hashtab.h"

using namespace std;

int main()
{
    for (int i=1; i<=1; i++) {
        struct bstree* bstree;
        struct listnode* hashtab[HASHTAB_SIZE];

        fstream dictionary;
        dictionary.open("dictionary.txt", ios::in);

        for (int j = 1; j <= i*10000; j++) {
            string in;
            getline(dictionary, in);
            char* input = &in[0];
            
            if (j == 1) {
                bstree = bstree_create(input, 0);
                hashtab_init(hashtab);
            }
            else {
                bstree_add(bstree, input, j);
                hashtab_add(hashtab, input, j);
            }
        }
        
        char* key = "password";
        struct bstree* treenode = bstree_lookup(bstree, key);
        struct listnode* listnode = hashtab_lookup(hashtab, key);
        
        if (treenode != NULL) {
            cout << treenode->key << endl;
        }
        if (listnode != NULL) {
            cout << listnode->key << " 1" << endl;
        }
    }

    return 0;
}
