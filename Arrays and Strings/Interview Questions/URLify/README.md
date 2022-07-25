# 1.3 URLify

Problem Statement: Write a method to replace all spaces in a string with '%20'. You may assume that the string
has sufficient space at the end to hold the additional characters, and that you are given the "true"
length of the string. (Note: if implementing in Java, please use a character array so that you can
perform this operation in place.).

> ### **Notes about solution:**

> #### First Solution (My Solution):

```c++
string replaceSpacesFirst(string str, int trueLength)
{
  string ans = "", temp = "";
  for (int i = 0; i < str[i]; i++)
  {
    if (str[i] == ' ')
    {
      temp += "%20";
    }
    else
    {
      if (temp.size())
      {
        ans += temp;
        temp = "";
      }
      ans += str[i];
    }
  }
  ans += temp;
  return ans;
}

```

> - under construction.

---

> #### Second Solution:

```c++

// under construction

```

> - under construction.

> **_`You can see the full code above in the main.cpp file.`_**
