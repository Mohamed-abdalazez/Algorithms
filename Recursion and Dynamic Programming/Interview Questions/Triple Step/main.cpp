#include "bits/stdc++.h"

using namespace std;

// Brute Force Solution:
int solve(int n)
{
  if (n < 0)
    return 0;
  else if (n == 0)
    return 1;
  return solve(n - 1) + solve(n - 2) + solve(n - 3);
}

// Memoization Solution:

map<int, int> vis;
int solvememo(int n)
{

  if (n < 0)
    return 0;
  else if (n == 0)
    return 1;
  else if (vis[n])
  {
    return vis[n];
  }
  else
  {
    vis[n] = solvememo(n - 1) + solvememo(n - 2) + solvememo(n - 3);
    return vis[n];
  }
}

int main()
{
  int n;
  cin >> n;
  cout << solve(n) << endl;
  cout << solvememo(n) << endl;
  return 0;
}