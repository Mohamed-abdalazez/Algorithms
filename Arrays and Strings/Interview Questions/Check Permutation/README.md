# 1.2 Check Permutation

Problem Statement: Given two strings, write a method to decide if one is a permutation of the other.

> ### **Notes about solution:**

> #### First Solution:

```c++
bool isPermutation(string a, string b)
{
  if (a.size() != b.size()) // If they are different in size, it is normal to return false.
    return false;
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  return a == b ? true : false;
}

```

> - Sort the 2 arrays first and then compare them together.
> - We will assume for this problem that the comparison is case sensitive and whitespace is significant.
> - This algorithm is not optimal in some senses. If efficiency is very important, we can implement it in a different way.

---

> #### Second Solution:

```c++
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

```

> - Why `int vis[128];`? assumtion to the string is an ASCII string So:
>   - ASCII control characters (character code 0-31).
>   - ASCII printable characters (character code 32-127).

> **_`You can see the full code above in the main.cpp file.`_**
