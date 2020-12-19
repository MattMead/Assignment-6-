#include <iostream>
using namespace std;

class SortingClass{
public:
  static void QuickSort(double *array, int a, int b);
  static double QuickSortStep(double *array, int a, int b);
  static void Merge(double *array, int a, int b, int c);
  static void MergeSort(double *array, int a, int b);
  static void InsertSort(double *array, int size);
  static void SelectionSort(double *array, int size);
  static void BubbleSort(double *array, int size);

};
