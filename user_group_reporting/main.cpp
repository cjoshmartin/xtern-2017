// Josh Martin
// contact@cjoshmartin.com
// 2017


// NOTE: I am unsure if you want me to show off, or if you want the most simple solution

#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <regex>

using namespace std;
int main()
{
  string input;
  regex isAlphabet("[A-Za-z ]+"); // this regex pattern will check if the group
  //  name & member name are alphabetic

  std::map<string, vector<string> > groups; // I choose to store inside a map because I can use the group names as the keys instead of using a index. The map will also sort the keys for me, automatically.
  while(getline(cin, input)) // will store the the current line from user input into `input` string
  {
    size_t split = input.find(" "); // finds the location of the first space
    string memberName = input.substr(0,split); // using the space will store the first half as the 'membername'.
    string groupName  = input.substr(split+1,input.length());

    if(regex_match(memberName, isAlphabet) && regex_match(groupName, isAlphabet)) // checks both the groupname and member name to see if they are alphabetic.
    {
      // low casing both so that I don't have multiple keys with the same name, and so the keys sort correctly.
      transform(memberName.begin(), memberName.end(), memberName.begin(), ::tolower);
      transform(groupName.begin(), groupName.end(), groupName.begin(), ::tolower);
      groups[groupName].push_back(memberName);
    }
  }


  for(map<string,vector<string> >::iterator it = groups.begin(); it != groups.end(); ++it) {

    string name = it->first; // groupname
    string output =""; // where we will store our output. 'output' will be clear each time a new group is load
    cout << name << ','; // print the groupname

    sort(groups[name].begin(), groups[name].end()); // sort the members' names in each of the group.

    for (std::vector<string>::iterator memberIterator=groups[name].begin(); memberIterator!=groups[name].end(); ++memberIterator) // iterates through each group
    output +=*memberIterator +','; // add current user in current group to the output

    cout << output.substr(0, output.length()-1) << endl; // output users in current group, removes the last `,`
  }
  return 0;
}
