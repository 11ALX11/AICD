#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <chrono>
//#include <windows.h>
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

        std::chrono::time_point<std::chrono::system_clock> start, finish;

        start = chrono::system_clock::now();
        //start
        struct bstree* treenode = bstree_lookup(bstree, key);
        //finish
        finish = chrono::system_clock::now();
        std::chrono::duration<double> timer_tree = finish - start;

        start = chrono::system_clock::now();
        //start
        struct listnode* listnode = hashtab_lookup(hashtab, key);
        //finish
        finish = chrono::system_clock::now();
        std::chrono::duration<double> timer_hashtab = finish - start;

        cout << i*10000 << " " << timer_tree.count() << " " << timer_hashtab.count() << endl;
    }

    return 0;
}
