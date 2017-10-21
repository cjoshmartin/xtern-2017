#include <iostream>
#include <map>
#include <vector>
#include <regex>
#include "Stack.h"
using namespace std;

class Node {
    public:
        string absolute;
        Stack<string> * relative;
        Stack<string> * history;
        bool isTravered;
        Node * prev_;
        Node * next_;

        Node (string abs, Node * prev, Node * next) {
            absolute = abs ;
            isTravered = false;
            relative = new Stack<string>();
            prev_ 	= prev;
            next_ 	= next; 
        }
};

class linked_list {

    public:
        Node * head_ = nullptr;
        Node * tail_ = nullptr;

        void insert_node (string id) {
            if (head_) {
                head_ = head_->prev_ = new Node (id, NULL, head_);
            }
            else {
                head_ = new Node (id, NULL, head_);
                tail_ = head_;
            }
        }


        void print_ll (void) {
            if (head_) {
                bool showAbs=true;
                Node * cur = tail_;
                while (cur) {
                    if(cur->absolute== "BACK" || cur->absolute=="FORWARD")
                    {
                     cout << "I WANT TO MOVE A dir\n";
                    cur = cur->prev_;
                    }
                   else if(showAbs)
                    {
                    showAbs =false; 
                    cout << cur->absolute << "\n";
                    }
                    else if( cur->relative->size() > 0)
                    {
                        cout << cur->absolute << cur->relative->top()<<"\n"; 
                        cur->relative->pop();
                    }
                    else
                    {
                        showAbs=true;
                        cur->isTravered = true;
                    cur = cur->prev_;
                    }
                }
            }
        }
};
int main()
{
    string input;
    linked_list history;

    while(getline(cin, input))
    {
        regex isAbsolute("https:\/\/[A-Za-z0-9]+\.com");
        if(regex_match(input, isAbsolute))
            history.insert_node(input);
        else if(input =="BACK" || input =="FORWARD" )
        {}
        else if(input.find("/") == 0)
        {
            history.head_->relative->push(input);
            if(history.head_->relative->size() > 0)
            cout << history.head_->absolute << input << "\n";
        }
        else /*if(history.head_->relative->size() > 0) */
        {
            history.head_->relative->push("/" + input);
            cout << history.head_->absolute << history.head_->relative->top() << "\n";
        }
    }
    //history.print_ll();
    return 0;
}
