#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <windows.h>
#include "bstree.h"
#include "hashtab.h"

using namespace std;

int main()
{
    for (int i=1; i<=20; i++) {
        struct bstree* bstree;
        struct listnode* hashtab[HASHTAB_SIZE];

        fstream dictionary;
        dictionary.open("dictionary.txt", ios::in);

        char key[32];
        int random = rand()%(i*10000);

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

            if (j == i*10000) {
                strcpy(key, input);
            }
        }

        dictionary.close();
        
        int tmp = 0;

        unsigned int timer_tree = clock();
        struct bstree* treenode = bstree_lookup(bstree, key);
        timer_tree = clock()-timer_tree;

        unsigned int timer_hashtab = clock();
        struct listnode* listnode = hashtab_lookup(hashtab, key);
        timer_hashtab = clock()-timer_hashtab;

        cout << i*10000 << " " << timer_tree << " " << timer_hashtab << endl;
    }

    return 0;
}
