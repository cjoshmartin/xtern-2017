// Josh Martin
// contact@cjoshmartin.com
// 2017



#include <iostream>
#include <map>
#include <vector>
#include <regex>

using namespace std;
int main()
{
  string input; // where we will be storing our input for the mean while
  string output = ""; // storing our output
  std::map<string, bool > processes; // store the processes that are running and are not running

  while(getline(cin, input)) // will store the the current line from user input into `input` string
  {
    regex isNumber("[[:digit:]]+"); // to check if input is a digit

    //using the regex pattern to check for value input
    if(regex_match(input, isNumber) && input != "0")
    // if true, make entry into map && sets to True: else will naggates the value at that postion in the map
    ( processes.find(input) == processes.end() ) ? processes[input] = true : processes[input] = !processes[input];
  }

  for(map<string, bool >::iterator it = processes.begin(); it != processes.end(); ++it) { // iterating through the map
    if(processes[it->first]) // check to see if a process is running (evaluates if the key's boolean value in the map is True).
    output += it->first +"\n";// if soo, add it to our output
  }
  // if a process is running show it : else print 0
  (output != "") ? cout << output : cout << "0" << endl;

  return 0;
}
