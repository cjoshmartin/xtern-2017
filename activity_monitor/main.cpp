// TODO: sort groups alphabetically
// TODO: sort names in groups alphabetically
//
#include <iostream>
#include <map>
#include <vector>
#include <regex>

using namespace std;
int main()
{
    string test;
    string spliter = " ";
    size_t split = 0;
    regex isNumber("[[:digit:]]+");
    std::map<string, bool > processes;
    while(getline(cin, test))
    {
        if(test!= "" && regex_match(test, isNumber))
            ( processes.find(test) == processes.end() ) ? processes[test] = true : processes[test] = !processes[test];
    }
    string output = "";
    for(map<string, bool >::iterator it = processes.begin(); it != processes.end(); ++it) {
        if(processes[it->first])
            output += it->first +"\n";
    }
            (output != "") ? cout << output: cout << "0" << endl;
    return 0;
}
