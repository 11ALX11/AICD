#include <iostream>
#include "stack.h"

using namespace std;

bool checkHTML();

int main()
{
    string input = "y";
    while (input == "y" || input == "") {
        if (checkHTML()) {
            cout << "HTML tag pairs are valid.\n";
        }
        else {
            cout << "HTML tag pairs are invalid!\n";
        }

        cout << "Continue? (y/n)\n";
        getline(cin, input); getline(cin, input);
    }

    return 0;
}

bool checkHTML() {
    struct node* tags = NULL; //stack
    
    bool result = true;
    cout << "Enter HTML code (to exit input mode, type 'e!'):\n";
    
    char tmp;
    cin >> noskipws >> tmp;

    bool isTag = false;
    bool isClosingTag = false;
    bool isLastChrE = false;
    bool exitCondition = false;

    string tag;
    while (!exitCondition) {
        //request for exit
        if (isLastChrE) {
            if (tmp == '!') {
                exitCondition = true;
                continue;
            }
            isLastChrE = false;
        }
        if (tmp == 'e') {
            isLastChrE = true;
        }

        //closing type of tag
        if (isTag) {
            if (tmp == '/') {
                isClosingTag = true;
            }
        //end creating tag
            else {
                if (!isalpha(tmp) && !isdigit(tmp)) {
                    if (!isClosingTag) {
                        //push into stack if opening tag
                        push(&tags, tag);
                    }
                    else {
                        if (!isStackEmpty(tags) && top(tags) == tag) {
                            //pop from stack if pair matches
                            pop(&tags);
                        }
                        else {
                            result = false;
                        }
                    }
                    
                    isTag = false;
                    isClosingTag = false;
                }
        //reading tag
                else {
                    tag.push_back(tmp);
                }
            }
        }

        //begin creating tag
        if (tmp == '<') {
            isTag = true;
            tag = "";
        }

        cin >> noskipws >> tmp;
    }
    
    if (result && isStackEmpty(tags)) {
        return true;
    }
    return false;
}
