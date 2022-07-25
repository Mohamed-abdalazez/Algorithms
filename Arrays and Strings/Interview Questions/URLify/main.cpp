#include "bits/stdc++.h"

using namespace std;

/*First Solution (My Solution)*/

string replaceSpacesFirst(string str, int trueLength)
{
  string ans = "", temp = "";
  for (int i = 0; i < str[i]; i++)
  {
    if (str[i] == ' ')
    {
      temp += "%20";
    }
    else
    {
      if (temp.size())
      {
        ans += temp;
        temp = "";
      }
      ans += str[i];
    }
  }
  ans += temp;
  return ans;
}

/*Second Solution (Gayle Laakmann McDowell Solution)*/

int main()
{
  string s = "Mr John Smith";
  cout << s.size() << endl;
  cout << replaceSpacesFirst("Mr John Smith", 13) << endl;
}
