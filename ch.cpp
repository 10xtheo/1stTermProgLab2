#include <algorithm>
#include <iostream>
using namespace std;
int search(int *array, int length, int aim)
{
  int r = 0;
  for (int i = 0; i < length; ++i)
  {
    if (array[i] == aim)
    {
      r = i;
      break;
    }
  }
  return r;
}

int main()
{
  const int N = 5;
  int a[N] = {1, 2, 3, 4, 5};
  int start = search(a, N, 3);
  int c = 0;
  for (int i = start; i >= 0; --i)
  {
    if (a[i] < 3)
    {
      c += 1;
    }
  }
  cout << c;
  return 0;
}
