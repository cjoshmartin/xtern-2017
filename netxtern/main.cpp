#include <iostream>
#include <map>
#include <vector>
#include <regex>
#include "Queue.h"
using namespace std;

int main()
{
    string input;
    string root ="";
    int i = 0;
    vector<string> history;
    while(getline(cin, input))
    {
        regex isAbsolute("https:\/\/[A-Za-z0-9]+\.com");

        if(regex_match(input, isAbsolute) )
        {
            root=input;
            history.insert(history.begin() + i++,root);
       }
        else if(input == "BACK")
           i--; 
        else if(input == "FORWARD")
        {
           if(i < history.size())
              i++; 
        }
        else if(root!= "") {
            if(input.find("/") == 0)
            {
                history.insert(history.begin()  + i++,root + input);
            }
            else
            {
                if(history.size() > 0)
                {
                    history.insert( history.begin() + i, history[i-1] + "/" + input);
                    i++;
                }
                else
                {
                    history.insert(history.begin() + i++,root +  "/" + input);
                }
            }
        }
        
        cout << history[i-1] << "\n";
    }
    return 0;
}
