#include <iostream>
#include <map>
#include <vector>
#include <regex>
#include "Queue.h"
using namespace std;

class Node {
    public:
        string absolute;
        // Queue<string> * relative;
        Queue<string> * relative;
        bool isTravered;
        Node * prev_;
        Node * next_;

        Node (string abs, Node * prev, Node * next) {
            absolute = abs ;
            isTravered = false;
            relative = new Queue<string>();
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
                // Stack<string> * backStack = new Stack<string>();
                Queue<string> * forwardQueue = new Queue<string>();
                while (cur) {
                    if(cur->absolute== "BACK")
                    {
                      // cout << cur->absolute << endl;
                      // if(backQueue->size() > 0)
                      // { string meh =backQueue->dequeue();
                      //   forwardQueue->enqueue(meh);
                      //   cout << meh<<"\n";
                      // }
                    cur = cur->prev_;
                    }
                    else if(cur->absolute=="FORWARD")
                    {
                      // cout << cur->absolute << endl;
                      // if(forwardQueue->size() > 0)
                      // {
                      //   // backQueue->enqueue(forwardQueue->beginning());
                      //   cout << forwardQueue->dequeue()<<"\n";
                      // }
                      // cur = cur->prev_;
                    }
                   else if(showAbs)
                    {
                    showAbs =false;
                    // backQueue->enqueue(cur->absolute);
                    cout << cur->absolute << "\n";
                    }
                    else if( cur->relative->size() > 0)
                    {

                      // if ( backQueue->is_empty() || (backQueue->end().find(cur->absolute) != string::npos ))
                      // backQueue->debug_queue();
                      // backQueue->enqueue(cur->absolute + cur->relative->be());
                      string current =cur->absolute + cur->relative->dequeue();
                      // backQueue->enqueue(current);
                        cout << current <<"\n";
                        // backQueue->debug_queue();
                        // cur->relative->pop();
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
        if(regex_match(input, isAbsolute) || input =="BACK" || input =="FORWARD")
        {
            //cout << input<< "\n";
            history.insert_node(input);
        }
        else if(input.find("/") == 0)
        {
            history.head_->relative->enqueue(input);

        }
        else
        {
            if(history.head_->relative->size() > 0)
            history.head_->relative->enqueue( history.head_->relative->end() + "/" + input);
            else
            history.head_->relative->enqueue(  "/" + input);

        }

          //cout << history.head_->absolute<< "\n";
    }
    history.print_ll();
    history.head_->relative->debug_queue();
    return 0;
}
