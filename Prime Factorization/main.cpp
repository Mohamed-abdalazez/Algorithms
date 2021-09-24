#include <bits/stdc++.h>
using namespace std;
#define ll long long
/*
  Prime Factorization
*/

vector<ll> generateDivisors(ll n)
{
  vector<ll> Divisors;
  ll i;
  for (i = 1; i * i < n; i++)
  {
    if (n % i == 0)
    {
      Divisors.push_back(i);
      Divisors.push_back(n / i);
    }
  }
  //cout << i << endl;
  if (i * i == n)
  {
    Divisors.push_back(i);
  }
  /*
    if n == 36 && i == 6 
    Divisors.push_back(i); i = 6;
    Divisors.push_back(n / i); 36 / 6 = 6 
    Note : we can use set to avoid redundancy :)
  */
  return Divisors; // Not Sorted
}

set<ll> generateDivisorsI(ll n) //using set
{
  set<ll> Divisors;
  ll i;
  for (int i = 1; i * i < n; i++)
  {
    if (n % i == 0)
    {
      Divisors.insert(i);
      Divisors.insert(n / i);
    }
  }
  return Divisors; // Sorted
}

vector<ll> Factorization(ll n)
{
  vector<ll> Primes;
  for (int i = 2; i * i <= n; i++)
  {
    while (n % i == 0)
    {
      Primes.push_back(i);
      n /= i;
    }
  }
  if (n > 1)
    Primes.push_back(n);
  return Primes;
}

/*
  Safrot(i) Refers to number of divisors of i, calculate sum of Safrot(i) in range in
*/
ll sumNumberOfDivisorsInRange(ll n)
{
  ll sum = 0;
  for (int i = 1; i <= n; i++)
    sum += generateDivisors(i).size();
  return sum;
}

// another way

ll sumNumberOfDivisorsInRangeI(ll n)
{
  ll sum = 0;
  vector<ll> freq(n + 1);
  for (int i = 1; i <= n; i++)
  {
    for (int j = i; j <= n; j += i)
      freq[j]++;
  }
  for (int i = 1; i <= n; i++)
    sum += freq[i];
  return sum;
}

int main()
{

  ll n;
  cin >> n;
  cout << "Generate Divisors Using Vector - Not Sorted - List\n";
  for (auto it : generateDivisors(n))
    cout << it << " ";
  cout << "\n";
  cout << "Generate Divisors Using Set - Sorted - List\n";
  for (auto it : generateDivisorsI(n))
    cout << it << " ";
  cout << "\n";
  cout << "Prime Factorization for n = " << n << "\n";
  for (auto it : Factorization(n))
    cout << it << " ";
  cout << "\n";
  cout << "The Sum Number Of Divisors In Range n = " << n << "\n";
  cout << sumNumberOfDivisorsInRange(n) << "\n";
  cout << "The Sum Number Of Divisors In Range n = " << n << " -Another Way-\n";
  cout << sumNumberOfDivisorsInRange(n) << "\n";
  return 0;
}
