#include <algorithm>
#include <cstdlib>
#include <iostream>
using namespace std;
// #2
void bubbleSort(int *array, int length)
{
  for (int i = 0; i < length - 1; ++i)
  {
    for (int j = 0; j < length - 1; ++j)
    {
      if (array[j] > array[j+1])
      {
        swap(array[j], array[j+1]);
      }
    }
  }
}

// #3
void mxMnNonSorted(int *array, int length)
{
  int mxA = -99;
  int mnA = 99;
  for (int i = 0; i < length; ++i)
  {
    if (array[i] < mnA)
      mnA = array[i];
    if (array[i] > mxA)
      mxA = array[i];
  }
  cout << mxA << ' ' << mnA << endl; 
}
void mxMnSorted(int *array, int length)
{
  int mxA = array[length-1];
  int mnA = array[0];
  cout << mxA << ' ' << mnA;
}

// search
int count(int *array, int length, int aim)
{
  int counter = 0;
  for (int i = 0; i < length; ++i)
  {
    if (array[i] == aim)
    {
      counter += 1;
    }
  }
  return counter;
}

int searchD(int *array, int length, int aim)
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

int binarySearch()
{
  return 0;
}

// #8
void swapByIndecies(int *array, int length)
{
  cout << "Before swap:" << endl;
  for (int i = 0; i < length; ++i)
  {
    cout << array[i] << ' ';
  }
  cout << endl;
  int n1, n2;  
  cout << "Indices you want to swap:" << endl;
  cin >> n1 >> n2;
  swap(array[n1], array[n2]);
  cout << "After swap:" << endl;
  for (int i = 0; i < length; ++i)
  {
    cout << array[i] << ' ';
  }
  cout << endl;
}

int main()
{
  srand(time(0));
  const int N = 100;
  int a[N];
  for (int i = 0; i < N; i++)
  {
    a[i] = rand() % 199 - 99;
  }
  int b[N];
  for (int i = 0; i < N; i++)
  {
    b[i] = a[i];
  }
  while (true)
  {
  int choice;
  cin >> choice;
  switch (choice)
  {
    case 1:
      cout << "Randomly generated array:" << endl;
      for (int i = 0; i < N; ++i)
      {
        cout << b[i] << ' ';
      }
      break;

    case 2:
      cout << "Non-sorted array:" << endl;
      for (int i = 0; i < N; ++i)
      {
        cout << b[i] << ' ';
      }
      cout << endl;
      bubbleSort(a, N);
      cout << "Sorted array:" << endl;
      for (int i = 0; i < N; ++i)
      {
        cout << a[i] << ' ';
      }
      break;

    case 3:
      mxMnNonSorted(a, N);

      bubbleSort(a, N);

      mxMnSorted(a, N);
      break;

    case 4:
      break;

    case 5: 
      {
      int uNum;
      cin >> uNum;
      bubbleSort(a, N);
      int start = searchD(a, N, uNum);
      int c = 0;
      for (int i = start; i >= 0; --i)
      {
        if (a[i] < uNum)
        {
          c += 1;
        }
      }
      cout << c;
      }
      break;

    case 6:
      break;

    case 7:
      break;

    case 8:
      swapByIndecies(a, N);
      break;

    default:
      cout << "Введено неверное значение";
  }
  cout << endl;
  }
  return 0;
}
