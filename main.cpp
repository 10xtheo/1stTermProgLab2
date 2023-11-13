#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <chrono>

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

int mxNonSorted(int *array, int length)
{
  int mx = array[0];
  for (int i = 0; i < length; ++i)
  {
    if (array[i] > mx)
      mx = array[i];
  }
  return mx;
}

int mnNonSorted(int *array, int length)
{
  int mn = array[0];
  for (int i = 0; i < length; ++i)
  {
    if (array[i] > mn)
      mn = array[i];
  }
  return mn;
}

int mxSorted(int *array, int length)
{
  return array[length-1];
}

int mnSorted(int *array, int length)
{
  return array[0];
}

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
  //cout << mxA << ' ' << mnA;
}

int round(float number)
{
  if (number >= 0)
  {
    if (number - int(number) >= 0.5)
    {
      return int(number)+1;
    }
    else
      return int(number);
  }
  else 
  {
    if (abs(number + abs(int(number))) >= 0.5)
    {
      return int(number)-1;
    }
  }
  return int(number);
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
  int r = -1;
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

int binarySearch(int *array, int N, int aim)
{
  return 0;
}

// #8
void swapByIndecies(int *array, int length)
{
  cout << "До обмена:" << endl;
  for (int i = 0; i < length; ++i)
  {
    cout << array[i] << ' ';
  }
  cout << endl;
  int n1, n2;  
  cout << "Индексы для обмена:" << endl;
  cin >> n1 >> n2;
  swap(array[n1], array[n2]);
  cout << "После обмена:" << endl;
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
      cout << "Случайно сгенерированный массив:" << endl;
      for (int i = 0; i < N; ++i)
      {
        cout << b[i] << ' ';
      }
      break;

    case 2:
    {
      cout << "Неотсортированный массив:" << endl;
      for (int i = 0; i < N; ++i)
      {
        cout << b[i] << ' ';
      }
      cout << endl;
      auto start = chrono::high_resolution_clock::now();

      bubbleSort(a, N);

      auto end = chrono::high_resolution_clock::now();
      chrono::duration<float> duration = end - start;

      cout << "Отсортированный массив:" << endl;
      for (int i = 0; i < N; ++i)
      {
        cout << a[i] << ' ';
      }
      cout << endl;
      cout << "Время выполнения сортировки: " << (duration.count() * 1000) << " мс";
    }
      break;

    case 3:
    {
      cout << "Максимальный и минимальный элементы: ";
      auto start = chrono::high_resolution_clock::now();
      mxMnNonSorted(b, N);
      auto end = chrono::high_resolution_clock::now();
      chrono::duration<float> duration = end - start;
      cout << "Время поиска мин/макс в неотсортированном массиве: " << (duration.count() * 1000) << " мс" << endl;
      bubbleSort(a, N);
      start = chrono::high_resolution_clock::now();
      mxMnSorted(a, N);
      end = chrono::high_resolution_clock::now();
      chrono::duration<float> duration1 = end - start;
      cout << "Время поиска мин/макс в неотсортированном массиве: " << (duration1.count() * 1000) << " мс";
    }
      break;

    case 4:
      break;

    case 5: 
    {
      bubbleSort(a, N);
      int lessNumber = 0;
      int number;
      cin >> number;
      int start = searchD(a, N, number);
      for (int i = start - 1; i >= 0; --i)
      {
        if (a[i] < number)
          lessNumber += 1;
      }
      cout << lessNumber << endl;
    }
      break;

    case 6:
    {
      bubbleSort(a, N);
      int greaterNumber = 0;
      int number;
      cin >> number;
      int start = searchD(a, N, number);
      for (int i = start + 1; i < N; ++i)
      {
        if (a[i] > number)
          greaterNumber += 1;
      }
      cout << greaterNumber << endl;
    }
      break;

    case 7:
    {
      cout << "Введите число для поиска: " << endl;
      int number;
      cin >> number;
      auto start = chrono::high_resolution_clock::now();
      int result = searchD(b, N, number);
      auto end = chrono::high_resolution_clock::now();
      chrono::duration<float> duration = end - start;
      cout << "Время поиска перебором:  " << (duration.count() * 1000) << " мс" << endl;

      start = chrono::high_resolution_clock::now();
      // result = binarySearch(b, N, number);
      end = chrono::high_resolution_clock::now();
      chrono::duration<float> duration1 = end - start;
      cout << "Время поиска бинарным поиском:  " << (duration1.count() * 1000) << " мс" << endl;
      if (result != -1)
        cout << "Есть такой элемент, его индекс = " << result;
    }
      break;

    case 8:
    {
      auto start = chrono::high_resolution_clock::now();
      swapByIndecies(a, N);
      auto end = chrono::high_resolution_clock::now();
      chrono::duration<float> duration = end - start;
      cout << "Время обмена:  " << (duration.count() * 1000) << " мс";
      break;
    }
    default:
      cout << "Введено неверное значение";
  }
  cout << endl;
  }
  return 0;
}
