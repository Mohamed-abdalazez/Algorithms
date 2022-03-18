#include "bits/stdc++.h"

using namespace std;

/**
 *
 * Project : Caesar Cipher algorithm.
 * author  : Mohamed Abdalazez Abdallah Mohamed.
 *
 **/

char alphabet[26];
const int MOD = 26;

void fillalphabet()
{
  int j = 0;
  for (char i = 'a'; i <= 'z'; i++)
  {
    alphabet[j] = i;
    j++;
  }
}

string Encrypt(string plainText, int key)
{
  string cipher = "";
  for (auto it : plainText)
  {
    if (it >= 'a' && it <= 'z')
    {
      int index = int(it) - 97;
      cipher += alphabet[(index + key) % MOD];
    }
    else
    {
      cipher += it;
    }
  }
  return cipher;
}

string Decrypt(string cipherText, int key)
{
  string plainText = "";
  for (auto it : cipherText)
  {
    if (it >= 'a' && it <= 'z')
    {
      int index = int(it) - 97;
      plainText += alphabet[((index - key) > 0 ? (index - key) : (index - key) + 26) % MOD];
    }
    else
    {
      plainText += it;
    }
  }
  return plainText;
}

vector<string> bruteForceAttack(string cipherText)
{
  vector<string> allPossibleplainText;
  for (int key = 1; key <= 26; key++)
  {
    allPossibleplainText.push_back(Decrypt(cipherText, key));
  }
  return allPossibleplainText;
}

int main()
{
  fillalphabet();
  string plainText;
  int key;
  cout << "Enter plainText and Key : " << endl;
  getline(cin, plainText);
  cin >> key;
  cout << "cipher: " << Encrypt(plainText, key) << endl;
  cout << "plainText: " << Decrypt(Encrypt(plainText, key), key) << endl;
  cout << "all Possible plain Text with bruteForceAttack funcation" << endl;
  for (auto it : bruteForceAttack(Encrypt(plainText, key)))
    cout << it << endl;
  return 0;
}
