#include "SortingClass.h"
#include <array>
using namespace std;

//Merge sorting algorithm
void SortingClass::MergeSort(double *array, int a, int b){
int i = 0;
   if (a < b) {
      i = (a + b) / 2;
      MergeSort(array, a, i);
      MergeSort(array, i + 1, b);
      Merge(array, a, i, b);
   }
}

//Insert sorting algorithm
void SortingClass::InsertSort(double *array, int size){
  for(int i = 0; i < size; ++i){
    double temp = array[i];
    int j = i;
    while(j > 0 && array[j-1]>=temp){
      array[j] = array[j-1];
      j--;
    }
    array[j] = temp;
  }
}

//Selection sorting algorithm
void SortingClass::SelectionSort(double *array, int size){
  int i, j, minimumIndex, temp;
  for(i = 0; i < size-1;i++){
    minimumIndex = i;
    for(j = i+1; j < size; j++){
      if(array[j] < array[minimumIndex]){
        minimumIndex = j;
      }
    }
    if (minimumIndex != i){
      temp = array[i];
      array[i] = array[minimumIndex];
      array[minimumIndex] = temp;
    }
  }
}

//Bubble sorting algorithm
void SortingClass::BubbleSort(double *array, int size){
  bool swappedElement;
  for(int i = 0; i < size - 1; ++i){
    swappedElement = false;
    for(int j = 0; j < size -i - 1; ++j){
      if(array[j] > array[j+1]){
        swap(array[j], array[j+1]);
        swappedElement = true;
      }
    }
    if(swappedElement == false){
      break;
    }
  }
}

//Quick sort step
double SortingClass::QuickSortStep(double *array, int a, int b){
  int pivot = array[b];
  int leftEdge = a;
  for(int i = a; i < b; ++i){
    if(array[i] <= pivot){
      swap(array[i], array[leftEdge]);
      leftEdge++;
    }
  }
  swap(array[leftEdge], array[b]);
  return leftEdge;
}


//Quick sorting algorithm
void SortingClass::QuickSort(double *array, int a, int b){
  if(a < b){
    int leftEdge = QuickSortStep(array, a, b);
    QuickSort(array, a, leftEdge - 1);
    QuickSort(array, leftEdge + 1, b);
  }
}

//Merge
void SortingClass::Merge(double *array, int a, int b, int c) {
   int mergedSize = c - a + 1;
   int mergePosition = 0;
   int leftPosition = 0;
   int rightPosition = 0;
   double* mergedNumbers = new double[mergedSize];
   leftPosition = a;
   rightPosition = b + 1;
   while (leftPosition <= b && rightPosition <= c) {
      if (array[leftPosition] <= array[rightPosition]){
         mergedNumbers[mergePosition] = array[leftPosition];
         ++leftPosition;
      }
      else{
         mergedNumbers[mergePosition] = array[rightPosition];
         ++rightPosition;
      }
      ++mergePosition;
   }
   while (leftPosition <= b){
      mergedNumbers[mergePosition] = array[leftPosition];
      ++leftPosition;
      ++mergePosition;
   }
   while (rightPosition <= c){
      mergedNumbers[mergePosition] = array[rightPosition];
      ++rightPosition;
      ++mergePosition;
   }
   for (mergePosition = 0; mergePosition < mergedSize; ++mergePosition){
      array[a + mergePosition] = mergedNumbers[mergePosition];
   }
}
