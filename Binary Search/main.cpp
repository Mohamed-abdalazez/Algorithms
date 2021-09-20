#include <bits/stdc++.h>
using namespace std;

/*
  Binary Search Concept
*/

int binarySearch(int array[], int Target, int imin, int imax) // Recursive
{
  if (imax < imin)
  {
    return -1;
  }
  else
  {
    int mid = imin + (imax - imin) / 2;
    if (array[mid] > Target)
      return binarySearch(array, Target, imin, mid - 1);
    if (array[mid] < Target)
      return binarySearch(array, Target, mid + 1, imax);
    else
      return mid;
  }
}

int binarySearch_I(int array[], int Target, int imin, int imax) // Iterative
{
  while (imax >= imin)
  {
    int mid = imin + (imax - imin) / 2;
    if (array[mid] > Target)
      imax = mid - 1;
    else if (array[mid] < Target)
      imin = mid + 1;
    else
      return mid;
  }
  return -1;
}

int bestFindFirst(int array[], int start, int end, int value) // Best target from First
{
  while (start < end)
  {
    int mid = start + (end - start) / 2;

    if (array[mid] < value)
      start = mid + 1;
    else if (array[mid] > value)
      end = mid - 1;
    else
      end = mid;
  }
  return start;
}

int bestFindLast(int array[], int start, int end, int value) // Best target from Last
{
  while (start < end)
  {
    int mid = start + (end - start) / 2;

    if (array[mid] < value)
      start = mid + 1;
    else if (array[mid] > value)
      end = mid - 1;
    else
      start = mid;
  }
  return start;
}

int main()
{
  int n, target;
  cin >> n >> target;
  int arr[n];
  for (auto &it : arr)
    cin >> it;
  cout << "BinarySearch - Recursive \n";
  cout << binarySearch(arr, target, 0, n - 1) << "\n";
  cout << "BinarySearch - Iterative \n";
  cout << binarySearch_I(arr, target, 0, n - 1) << "\n";
  cout << "Best target from First\n";
  cout << bestFindFirst(arr, 0, n - 1, target) << "\n";
  cout << "Best target from Last\n";
  cout << bestFindLast(arr, 0, n - 1, target) << "\n";
  return 0;
}
