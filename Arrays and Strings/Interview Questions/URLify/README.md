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
  bool fAllSpace = false;
  for (int i = 0; i < str.size(); i++)
  {
    if (str[i] == ' ')
    {
      temp += "%20";
      fAllSpace = true;
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
    fAllSpace = false;
  }
  if (fAllSpace)
    ans += temp;
  return ans;
}

```
---

> #### Second Solution:

```c++

/*Second Solution (Gayle Laakmann McDowell Solution)*/

string replaceSpacesSecond(string str, int trueLength)
{
  int spaceCount = 0, index;
  for (int i = 0; i < trueLength; i++)
    if (str[i] == ' ')
      spaceCount++;

  index = trueLength + (spaceCount * 2);

  /*
  Why spaceCount * 2 !?
  eg.
  srt = "Mohamed Abdalazez  "
  when replace the first space wiht %20
  srt = "Mohamed Abdalazez  "
  srt = "Mohamed%20Abdalazez  "
  As you can see, there will be two characters shifted to the right(ez).
  So:
  srt = "Mohamed Abdalazez  "
  trueLength = 17
  index = 17 + 1 * 2 = 19;
                iterate from here and backwards ⤵ index ⤵
  index=  1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18  19
  srt  = (M o h a m e d   A b  d   a  l  a  z  e  z ' ' ' ')
  */
  for (int i = trueLength - 1; i >= 0; i--)
  {
    if (str[i] == ' ')
    {
      str[index - 1] = '0';
      str[index - 2] = '2';
      str[index - 3] = '%';
      index -= 3;
    }
    else
    {
      str[index - 1] = str[i];
      index--;
    }
  }
  return str;
}

```



> **_`You can see the full code above in the main.cpp file.`_**
