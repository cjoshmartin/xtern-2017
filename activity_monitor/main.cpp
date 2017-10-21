#include <iostream>
#include <map>
#include <vector>
#include <regex>
#include "Stack.h"

using namespace std;

class Node {
public:
	string absolute;
  Stack<string> relative = new Stack<string>();
	Node * prev_;
	Node * next_;

	Node (int id, Node * prev, Node * next) {
		id_ 	= id;
		prev_ 	= prev;
		next_ 	= next;
	}
};

class linked_list {
public:
	Node * head_ = nullptr;
    Node * tail_ = nullptr;

	void insert_node (int id) {
        if (head_) {
            head_ = head_->prev_ = new Node (id, NULL, head_);
        }
        else {
            head_ = new Node (id, NULL, head_);
            tail_ = head_;
        }
	}
};

int main()
{
    string input;
    string output = "";
    std::map<string, bool > processes;

    linked_list history;
    regex isAbs("https:\/\/[A-Za-z0-9]+\.com");

    while(getline(cin, input))
    {
        switch (input) {
          case regex_match(input, isAbs):
          break;
        }
        regex isNumber("[[:digit:]]+");

        if(regex_match(input, isNumber))
            ( processes.find(input) == processes.end() ) ? processes[input] = true : processes[input] = !processes[input];
    }

    for(map<string, bool >::iterator it = processes.begin(); it != processes.end(); ++it) {
        if(processes[it->first])
            output += it->first +"\n";
    }
    (output != "") ? cout << output : cout << "0" << endl;

    return 0;
}
