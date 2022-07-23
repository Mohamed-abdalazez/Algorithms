# 1.1 Is Unique

Problem Statement: Implement an algorithm to determine if a string has all unique characters. What if you cannot use additional data structures?

> ### **Notes about solution:**

> #### First Solution:

```c++
bool isUniqueChars(string str)
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
```

> - The time complexity: O(**n**).
> - you could also argue the time complexity O(**1**), since the for loop will never iterate through more than 128 characters.
> - if you didn't want to assume the character set is fixed, you could express the complexity as O(**c**) space and O(min(**c**, **n**)) or O(**c**) time, where **c** is the size of the character set.

---

> #### Second Solution:

```c++
bool isUniqueCharsI(string str)
{
  int checker = 0;
  for (int i = 0; i < str.size(); i++)
  {
    int cur = str[i] - 'a';
    if ((checker & (1 << cur)) > 0)
    {
      cout << (checker & (1 << cur)) << endl;
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

---

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
```

> - The time complexity: O(**n**).
> - In this Solution we reduce space usage by a factor of eight by using a bit vector.
> - assume that the string only uses the lowercase letters from 'a' to 'z'.

> #### third Solution:

```c++
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
```

> - The time complexity: O(**n**).
> - using map data structure from Standard Template Library(STL) in C++ Language.

> **_`You can see the full code above in the main.cpp file.`_**
