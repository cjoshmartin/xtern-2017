// TODO: sort groups alphabetically
// TODO: sort names in groups alphabetically
//
#include <iostream>
#include <map>
#include <algorithm> 
#include <vector>
#include <regex>

using namespace std;
int main()
{
    string test;
    string spliter = " ";
    size_t split = 0;
    regex isAlphabet("[A-Za-z ]+");
    std::map<string, vector<string> > groups;
    while(getline(cin, test))
    {
        split = test.find(spliter); 
        string memberName = test.substr(0,split);
        string groupName  = test.substr(split+1,test.length());
        //cout << "Member Name is ='" << memberName<<"' Group name is ='" << groupName << "'" << endl;
        
        if(memberName != "" && regex_match(memberName, isAlphabet) && regex_match(groupName, isAlphabet))
            groups[groupName].push_back(memberName);
    }
    //for(size_t i =0; i <)
    //cout << groupName << ", " << groups[groupName].substr(0,groups[groupName].length()-1) << endl;
    vector<string> groupsName;
    for(map<string,vector<string> >::iterator it = groups.begin(); it != groups.end(); ++it) {
        groupsName.push_back(it->first);
       sort(groups[it->first].begin(), groups[it->first].end());
    }
    string output;
    for(map<string,vector<string> >::iterator it = groups.begin(); it != groups.end(); ++it) {
        string name = it->first;
        output ="";
        cout << name << ',';
        for (std::vector<string>::iterator its=groups[name].begin(); its!=groups[name].end(); ++its)
                output +=*its +',';
        cout << output.substr(0, output.length()-1) << endl;
    }
    return 0;
}
