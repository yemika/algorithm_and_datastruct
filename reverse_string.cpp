#include <iostream>
#include <string>
using namespace std;


void reverse_string(string &s)
{
  int len = s.length();
  for(int i=0; i<len/2;i++)
  {
    char c = s[i];
    s[i] = s[len-1-i];
    s[len-1-i] = c;
  }
}

int main()
{
  string s;
  while(cin>>s)
  {
    reverse_string(s);
    cout<<s<<endl;
  }
}
