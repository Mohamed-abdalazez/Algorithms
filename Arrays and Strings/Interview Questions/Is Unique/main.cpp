#include "bits/stdc++.h"

using namespace std;

/*First Solution*/

int vis[128];

bool isUniqueCharsFirst(string str)
{
  if (str.size() > 128)
    return false;
  /*
  why 128?!
  assumtion to the string is an ASCII string So:
  - ASCII control characters (character code 0-31)
  - ASCII printable characters (character code 32-127)
  */
  for (int i = 0; i < str.size(); i++)
  {
    int cur = str[i];
    if (vis[cur])
      return false;
    vis[cur] = 1;
  }
  return true;
}

bool isUniqueCharsSecond(string str)
{
  int checker = 0;
  for (int i = 0; i < str.size(); i++)
  {
    int cur = str[i] - 'a';
    if ((checker & (1 << cur)) > 0)
    {
      // cout << (checker & (1 << cur)) << endl;
      return false;
    }
    checker |= (1 << cur);
  }
  return true;
}
/*
note: (1 << cur) equivalent 2^n

String : aba
trace:

first iteration
checker = 0;
cur = 'a' - 'a' = 0;
if(0 & (1)) ✖
0000
 &
0001
----
0000
0 |= 1 = 1

Second iteration

checker = 1;
cur = 'b' - 'a' = 1;
if (1 & (2)) ✖
0001
 &
0010
----
0000
1 |= 1 = 1


third iteration

cur = 'a' - 'a' = 0;
if (1 & (1)) ✔
0001
 &
0001
----
0001

return false

*/

bool isUniqueCharsThird(string str)
{
  map<char, int> vis;
  for (auto it : str)
  {
    if (vis[it])
      return false;
    vis[it] = 1;
  }
  return true;
}

int main()
{
  string s;
  cin >> s;
  cout << (isUniqueCharsFirst(s) == 1 ? "hi, I'm a unique string form isUniqueCharsFirst() Fn.\n" : "hi, I'm not a unique string form isUniqueCharsFirst() Fn.\n");
  cout << (isUniqueCharsSecond(s) == 1 ? "hi, I'm a unique string form isUniqueCharsSecond() Fn.\n" : "hi, I'm not a unique string form isUniqueCharsSecond() Fn.\n");
  cout << (isUniqueCharsThird(s) == 1 ? "hi, I'm a unique string form isUniqueCharsThird() Fn.\n" : "hi, I'm not a unique string form isUniqueCharsThird() Fn.\n");
  return 0;
}