#include <bits/stdc++.h>
using namespace std;


bool check(string s, string next)
{
  int n = s.size();
  for (int i = 0; i < n; i++)
  {
    if (s[i] == next[i])
      return false;
  }
  return true;
}

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    bool f = true;
    int n;
    cin >> n;
    vector<string> s;
    for (int i = 0; i < n; i++)
    {
      string temp = "";
      for (int j = 0; j < n; j++)
      {
        char c;
        cin >> c;
        temp += c;
      }
      s.push_back(temp);
    }

    for (int i = 0; i < n - 1; i++)
    {
      string nxt = s[i + 1];
      if (!check(s[i],nxt))
      {
        f = false;
        break;
      }
      else
      {
        continue;
      }
    }
    cout << (f?"Yes\n":"No\n");
  }

}

/*

0 1 0
1 0 1
0 1 0

010
101
010

*/
