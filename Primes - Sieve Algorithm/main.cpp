#include <bits/stdc++.h>
using namespace std;
#define ll long long



bool isPrimeI(ll n) // O(n)
{
  if (n == 2)
    return true;
  if (n < 2 || n % 2 == 0)
    return false;
  for (ll i = 3; i < n; i += 2)
    if (n % i == 0)
      return false;
  return true;
}

bool isPrimeII(ll n)
{
  if (n == 2)
    return true;
  if (n < 2 || n % 2 == 0)
    return false;
  for (ll i = 3; i <= sqrt(n); i += 2)
    if (n % i == 0)
      return false;
  return true;
}

/*
  why sqrt(n)??
  let say n = 64
  n = 1 * 64
  n = 2 * 32
  n = 4 * 8
  n = 8 * 8  after this point (sqrt(n)) the numbers are flipping, It is not necessary to check again 
  n = 8 * 4
  n = 32 * 2
  n = 64 * 1
*/

bool isPrimeIII(ll n) // O(sqrt(n))
{
  if (n == 2)
    return true;
  if (n < 2 || n % 2 == 0)
    return false;
  for (ll i = 3; i * i <= n; i += 2)
    if (n % i == 0)
      return false;
  return true;
}
/*
 i <= sqrt(n)  power two sides 
 i * i <= n
*/

/*
  count number of primes in range n
  **Sieve Algorithm**
*/

ll Sieve(ll n)
{
  ll cnt = 0;
  //ll vis[n + 1];
  //memset(vis, 1, sizeof(vis));
  vector<bool> vis(n + 1, true);
  vis[0] = vis[1] = 0;
  for (ll i = 2; i * i <= n; i++)
  {
    if (vis[i])
    {
      for (ll j = i * 2; j <= n; j += i)
        vis[j] = 0;
    }
  }

  for (auto it : vis)
    if (it)
      cnt++;
  return cnt;
}

int main()
{
  ll n = 100000000;
  for (ll i = 10; i <= n; i *= 10)
    cout << "between 0 and " << i << " there are " << Sieve(i) << " Prime number." << endl;
  return 0;
}
