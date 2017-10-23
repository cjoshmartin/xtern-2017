// Josh Martin
// contact@cjoshmartin.com
// 2017

/*
::Sources ::
  https://en.wikipedia.org/wiki/Uniform_Resource_Identifier
  https://www.ietf.org/rfc/rfc3986.txt
*/
#include <iostream>
#include <vector>
#include <regex>
using namespace std;

int main()
{
  string input; // where we will store our links
  string root =""; // the root url like http://wwww.cjoshmartin.com
  int i = 0; // where we are in the history
  vector<string> history; // where we store our history
  while(getline(cin, input)) // takes an input until we don't have anymore newlines
  {
    if(input != "BACK" && input != "FORWARD") // Imporant that we don't mess with our back and forward commands
    {
      transform(input.begin(), input.end(), input.begin(), ::tolower); // The scheme and host are case-insensitive. The proposed normalization solution will convert these to lowercase.
    }
    // WOOWW! last year, I learn python during this interview, this year, I learned how to use regex! SWEET!

    regex isHTTP("(http(|s):\/\/)(www\.)?([a-z0-9]+)(\.[a-z0-9]+)(\.[a-z0-9]+)?"); // check for a url like http://foo.com or http://foo.co.uk or http://www.foo.co.uk
    regex isServer("([a-z0-9]+:\/\/)(([a-z0-9]+)(:[a-z0-9]+)?)?(\@)?([a-z0-9]+)(\:[0-9]+)?"); // check if a url is like foo://tacos foo://tacos:8080 or foo://username:password@tacos:80
    regex isMailTo("mailto:([a-z0-9]+)(\@)([a-z0-9]+)(\.[a-z0-9]+)"); // for mailto address like mailto:contact@cjoshmartin.com
    regex isIP("^(?:(?:25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\.){3}(?:25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)(\:[0-9]+)?$"); // check if a url is an IP like 3.60.124.136 or 3.60.124.136:80

    if(regex_match(input, isHTTP) || regex_match(input, isIP) || regex_match(input, isServer) || regex_match(input, isMailTo))
    {
      // this if statemant is where it check if the path is absolute
      root=input; // store the absolute path for the relative paths later
      history.insert(history.begin() + i++,root); // push it to the vector so we can travers it later
    }
    else if(input == "BACK")
    {
      i--; // move back one spot in history
    }
    else if(input == "FORWARD")
    {
      if(i < history.size()) // checking if it is we can move forward
      i++; // how we move forward
    }
    else if(root!= "") { // making sure that our path we have a root path before we start adding relative pathes
      if(input.find("/") == 0) // checks if the path starts with a `/`. EXAMPLE: /tacos
      {
        history.insert(history.begin()  + i++,root + input); // gets the root path and adds on the realtive path then inserts to the position of i
      }
      else
      {
        if(history.size() > 0) // if we going to add a path like `tacos` (without a `/`) then when need to check that we have been somewhere first
        {
          history.insert( history.begin() + i, history[i-1] + "/" + input); // check if a reltive path has been path in before
          i++; // `i` is here because we push the current history using `i` so we need to increment after we push
        }
        else
        {
          // if the history is only has the root url just append the relative path
          history.insert(history.begin() + i++,root +  "/" + input);
        }
      }
    }
    // prints the links
    cout << history[i-1] << "\n"; // this is the magic allows me not to use a stack or queue or linklist... (try it, was way over think it haha)
  }
  return 0;
}
