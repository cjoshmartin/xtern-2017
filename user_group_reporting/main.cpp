#include <iostream>
#include <map>
#include <algorithm> 
#include <vector>
#include <regex>

using namespace std;
int main()
{
    string input;
    regex isAlphabet("[A-Za-z ]+");
    std::map<string, vector<string> > groups;

    while(getline(cin, input))
    {
        size_t split = input.find(" "); 
        string memberName = input.substr(0,split);
        string groupName  = input.substr(split+1,input.length());
        
        if(regex_match(memberName, isAlphabet) && regex_match(groupName, isAlphabet))
            groups[groupName].push_back(memberName);
    }


    for(map<string,vector<string> >::iterator it = groups.begin(); it != groups.end(); ++it) {
        string name = it->first;
        string output ="";
        cout << name << ',';
        sort(groups[name].begin(), groups[name].end());
        for (std::vector<string>::iterator memberIterator=groups[name].begin(); memberIterator!=groups[name].end(); ++memberIterator)
                output +=*memberIterator +',';
        cout << output.substr(0, output.length()-1) << endl;
    }
    return 0;
}
