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

void shakerSort(int *array, int length)
{
  int start = 0;
  int end = length - 2;
  while (start <= end)
  {
    for (int i = start; i < length - 1 - start; ++i)
    {
      if (array[i] > array[i+1])
        swap(array[i], array[i+1]);
    }
    for (int i = end ; i > 0 + start; --i)
    {
      if (array[i] < array[i-1])
        swap(array[i], array[i-1]);
    }
    start += 1;
    end -= 1;
  }
}

void combSort(int *array, int length)
{
  int gap = length;
  while (gap >= 1)
  {
    for (int i = 0; i + gap < length; ++i)
    {
      if (array[i] > array[i+gap])
        swap(array[i], array[i+gap]);
    }
    gap /= 1.247;
  }
  for (int i = 0; i < length - 1; ++i)
  {
    for (int j = 0; j < length - 1 - i; ++j)
    {
      if (array[j] > array[j+1])
        swap(array[j], array[j+1]);
    }
  } 
}

void insertSort(int *array, int length)
{
  int i, j, key;
  for (int i = 1; i < length; ++i)
  {
    key = array[i];
    j = i - 1;

    while (j >= 0 && array[j] > key)
    {
      array[j+1] = array[j];
      j--;
    }
    array[j+1] = key;
  }
}

void quickSort(int *array, int finish, int begin)
{
  int r = begin;
  int l = finish;
  int mid = array[(r+l)/2];
  while (r < l)
  {
    while (array[r] < mid) 
      r++;
    while (array[l] > mid) 
      l--;
    if (r <= l)
    {
      swap(array[r], array[l]);
      r++;
      l--;
    } 
  }
  if (begin < l)
    quickSort(array, l, begin);
  if (r < finish)
    quickSort(array, finish, r);
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
    if (array[i] < mn)
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
  if (abs(number) - int(abs(number)) >= 0.5)
  {
    if (number > 0)
    {
      return int(number)+1;
    }
    return int(number)-1;
  }
  else
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

int binarySearch(int *array, int length, int aim) 
{
  int start = 0;
  int end = length-1;
  while (start <= end) 
  {
    int mid = (start + end) / 2;
    if (aim == array[mid])
      return mid;
    else if (aim > array[mid])
      start = mid + 1;
    else end = mid - 1;
  }
  return -1;
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
  cout << "Выбeрете пункт программы: " << endl 
    << "1. Получить случайный массив" << endl 
    << "2. Получить отсортированный массив и время на его сортировку" << endl
    << "3. Получить мин/макс эл-ты массива, время их поиска в неотсорт/отсорт массиве" << endl
    << "4. Получить среднее значение элемента массива, индексы эл-т равных среднему, их кол-во" << endl
    << "5. Получить кол-во элементов, меньших заданного значения" << endl
    << "6. Получить кол-во элементов, больших заданного значения" << endl
    << "7. Проверить наличие числа в массиве перебором и бинарным поиском" << endl
    << "8. Поменять выбранные эл-ты массива местами по индексам" << endl
    << "Нажмите Ctrl+c для выхода из программы" << endl;
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
      int finish = N - 1;
      int begin = 0;
      quickSort(a, finish, begin);

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
      int finish = N - 1;
      int begin = 0;
      quickSort(a, finish, begin);
      start = chrono::high_resolution_clock::now();
      mxMnSorted(a, N);
      end = chrono::high_resolution_clock::now();
      chrono::duration<float> duration1 = end - start;
      cout << "Время поиска мин/макс в неотсортированном массиве: " << (duration1.count() * 1000) << " мс";
    }
      break;

    case 4:
    {
      int mx = mxNonSorted(a, N);
      int mn = mnNonSorted(a, N);
      int average = round((float(mx) + float(mn))) / 2.0;
      int averageCount = 0;
      cout << "Индексы элементов равных среднему значению: " << endl;
      auto start = chrono::high_resolution_clock::now();
      for (int i = 0; i < N; ++i)
      {
        if (a[i] == average)
        {
          cout << i << ' ';
          averageCount += 1;
        }
      }
      auto end = chrono::high_resolution_clock::now();
      chrono::duration<float> duration = end - start;
      cout << endl;
      cout << "Их количество: "<< averageCount << endl;
      cout << "Время поиска: " << (duration.count() * 1000) << " мс";
    }
      break;

    case 5: 
    {
      int finish = N - 1;
      int begin = 0;
      quickSort(a, finish, begin);
      int lessNumber = 0;
      int number;
      cin >> number;
      int start = searchD(a, N, number);
      for (int i = start - 1; i >= 0; --i)
      {
        if (a[i] < number)
          lessNumber += 1;
      }
      cout << lessNumber;
    }
      break;

    case 6:
    {
      int finish = N - 1;
      int begin = 0;
      quickSort(a, finish, begin);
      int greaterNumber = 0;
      int number;
      cin >> number;
      int start = searchD(a, N, number);
      for (int i = start + 1; i < N; ++i)
      {
        if (a[i] > number)
          greaterNumber += 1;
      }
      cout << greaterNumber ;
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
      int finish = N - 1;
      int begin = 0;
      quickSort(a, finish, begin);
      start = chrono::high_resolution_clock::now();
      result = binarySearch(a, N, number);
      end = chrono::high_resolution_clock::now();
      chrono::duration<float> duration1 = end - start;
      cout << "Время поиска бинарным поиском:  " << (duration1.count() * 1000) << " мс" << endl;
      cout << "Бинарный поиск быстрее в " << duration.count()/duration1.count() << "разa" << endl;
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
