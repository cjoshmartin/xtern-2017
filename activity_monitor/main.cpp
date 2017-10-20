#include <iostream>
#include <map>
#include <vector>
#include <regex>

using namespace std;
int main()
{
    string input;
    string output = "";
    std::map<string, bool > processes;

    while(getline(cin, input))
    {
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
