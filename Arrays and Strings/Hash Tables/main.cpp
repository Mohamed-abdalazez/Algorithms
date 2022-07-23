#include "bits/stdc++.h"

using namespace std;

// very simple implementation
class Hash
{
  int HASH_SIZE;
  vector<int> *Hash_table;

public:
  Hash(int V);
  void insertItems(int x);
  int hashFunction(int x)
  {
    return (x % HASH_SIZE);
  }
  void displayHash();
};

Hash::Hash(int b)
{
  this->HASH_SIZE = b;
  Hash_table = new vector<int>[HASH_SIZE];
}

void Hash::insertItems(int key)
{
  int index = hashFunction(key);
  Hash_table[index].push_back(key);
}

void Hash::displayHash()
{
  for (int i = 0; i < HASH_SIZE; i++)
  {
    cout << i;
    for (auto it : Hash_table[i])
    {
      cout << "-->" << it;
    }
    cout << "\n";
  }
}

int main()
{
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &it : a)
    cin >> it;
  int hash_size;
  cin >> hash_size;
  Hash h(hash_size);
  for (int i = 0; i < n; i++)
  {
    h.insertItems(a[i]);
  }
  h.displayHash();
  return 0;
}

/*
input:
n
arr[n]
hash_size
n -> number of elements you want hashed.
*/