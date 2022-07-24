#include "bits/stdc++.h"

using namespace std;

/*First Solution*/

bool isPermutationFirst(string a, string b)
{
  if (a.size() != b.size())
    return false;
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  return a == b ? true : false;
}

/*Second Solution*/

int vis[128];
/*
  why 128?!
  assumtion to the string is an ASCII string So:
  - ASCII control characters (character code 0-31)
  - ASCII printable characters (character code 32-127)
*/
bool isPermutationSecond(string a, string b)
{
  if (a.size() != b.size())
    return false;
  for (auto it : a)
    vis[it]++;
  for (auto it : b)
  {
    vis[it]--;
    if (vis[it] < 0)
      return false;
  }
  return true;
}

int main()
{
}