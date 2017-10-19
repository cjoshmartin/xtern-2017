// TODO: sort groups alphabetically
// TODO: sort names in groups alphabetically
//
#include <iostream>
#include <map>
#include <vector>
using namespace std;
int main()
{
    string test;
    string spliter = " ";
    size_t split = 0;

    std::map<string, vector<string> > groups;
    while(getline(cin, test))
    {
        split = test.find(spliter); 
        string memberName = test.substr(0,split);
        string groupName  = test.substr(split+1,test.length());
        //cout << "Member Name is ='" << memberName<<"' Group name is ='" << groupName << "'" << endl;
        if(memberName != "")
            groups[groupName] += memberName ",";
    }
    //for(size_t i =0; i <)
    //cout << groupName << ", " << groups[groupName].substr(0,groups[groupName].length()-1) << endl;
    //vector<string> v;
    //for(map<string,string>::iterator it = groups.begin(); it != groups.end(); ++it) {
        //v.push_back(it->first);
        //cout << it->first << "\n";
    //}
    return 0;
}
