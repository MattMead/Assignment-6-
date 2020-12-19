#include "SortingClass.h"
#include <array>
#include <string>
#include <fstream>
#include <iostream>
#include <time.h>
#include <ctime>
#include <chrono>
using namespace std;

int main(int argc, char** argv){
  typedef std::chrono::high_resolution_clock Time;
  typedef std::chrono::duration<float> fsec;
  typedef std::chrono::milliseconds ms;


  //Getting a file input
  string inputFile;
  inputFile = argv[1];
  ifstream inputStream;
  inputStream.open(inputFile);
  if(!inputStream){
    cerr << "Could not open File." << inputFile << endl;
    exit(1);
  }
  string line = "";
  getline(inputStream, line);
  if(line ==  ""){
    cerr << "This file was not formatted correctly" << endl;
    exit(1);
  }
  int totalNums = 0;
  try{
    totalNums = stoi(line);
  }
  catch(invalid_argument e){
    cout << "File not formatted correctly." << endl;
  }


  //Arrays
  double* arrayBubble = new double[totalNums];
  int lineNumber = 0;
  //Creating the 5 separate arrays
  while(getline(inputStream,line))
  {
    arrayBubble[lineNumber] = stod(line);
    ++lineNumber;
  }


  double* arraySelection = new double[totalNums];
  for(int i = 0; i < totalNums; ++i)
  {
    arraySelection[i] = arrayBubble[i];
  }

  double* arrayInsertion = new double[totalNums];
  for(int i = 0; i < totalNums; ++i)
  {
    arrayInsertion[i] = arrayBubble[i];
  }


  double* arrayQuick = new double[totalNums];
  for(int i = 0; i < totalNums; ++i)
  {
    arrayQuick[i] = arrayBubble[i];
  }

  double* arrayMerge = new double[totalNums];
  for(int i = 0; i < totalNums; ++i)
  {
    arrayMerge[i] = arrayBubble[i];
  }


  //////////////////////
  //SORTING ALGORITHMS//
  //////////////////////


  //Bubble Sort Algorithm
  //Sorting Start Time
  cout << "Starting Bubble Sort At: " << endl;
  auto start = chrono::system_clock::now();
  time_t startTime = chrono::system_clock::to_time_t(start);
  cout << "Start Time: " << ctime(&startTime);

  //Sorting using Bubble Sort
  SortingClass::BubbleSort(arrayBubble, totalNums);

  //End time for the sorting
  auto end = chrono::system_clock::now();
  cout << "Bubble Sort has been completed! " << endl;
  time_t endTime = chrono::system_clock::to_time_t(end);
  cout << "End Time: " << ctime(&endTime);
  cout << "Time it took: " << endl;

  //exact amount of time to sort
  fsec seconds = end - start;
  cout << seconds.count() << " seconds." << endl;
  cout << endl;
  cout << endl;



  // Selection Sort Algorithm
  //Sorting Start Time
  cout << "Starting Selection Sort At: " << endl;
  start = chrono::system_clock::now();
  startTime = chrono::system_clock::to_time_t(start);
  cout << "Start Time: " << ctime(&startTime);

  //Sorting using selection sort
  SortingClass::SelectionSort(arraySelection, totalNums);


  //End time for the sorting
  end = chrono::system_clock::now();
  cout << "Selection Sort has been completed! " << endl;
  endTime = chrono::system_clock::to_time_t(end);
  cout << "End Time: " << ctime(&endTime);
  cout << "Time it took: " << endl;


  //exact amount of time to sort
  seconds = end - start;
  cout << seconds.count() << " seconds." << endl;
  cout << endl;
  cout << endl;



  // Insertion Sort Algorithm
  //Sorting Start Time
  cout << "Starting Insertion Sort At: " << endl;
  start = chrono::system_clock::now();
  startTime = chrono::system_clock::to_time_t(start);
  cout << "Start Time: " << ctime(&startTime);

  //Sorting using insertion sort
  SortingClass::InsertSort(arrayInsertion, totalNums);


  //End time for the sorting
  end = chrono::system_clock::now();
  cout << "Insertion Sort has been completed! " << endl;
  endTime = chrono::system_clock::to_time_t(end);
  cout << "End Time: " << ctime(&endTime);
  cout << "Time it took: " << endl;


  //exact amount of time to sort
  seconds = end - start;
  cout << seconds.count() << " seconds." << endl;
  cout << endl;
  cout << endl;



  //Quick Sort Algorithm
  //Sorting Start Time
  cout << "Starting Quick Sort At: " << endl;
  start = chrono::system_clock::now();
  startTime = chrono::system_clock::to_time_t(start);
  cout << "Start Time: " << ctime(&startTime);


  //Sorting using quick sort
  SortingClass::QuickSort(arrayQuick, 0, totalNums -1);


  //End time for the sorting
  end = chrono::system_clock::now();
  cout << "Quick Sort has been completed! " << endl;
  endTime = chrono::system_clock::to_time_t(end);
  cout << "End Time: " << ctime(&endTime);
  cout << "Time it took: " << endl;


  //exact amount of time to sort
  seconds = end - start;
  cout << seconds.count() << " seconds." << endl;
  cout << endl;
  cout << endl;



  //Merge Sort Algorithm
  //Sorting Start Time
  cout << "Starting Merge Sort At: " << endl;
  start = chrono::system_clock::now();
  startTime = chrono::system_clock::to_time_t(start);
  cout << "Start Time: " << ctime(&startTime);

  //Sorting using quick sort
  SortingClass::MergeSort(arrayMerge, 0, totalNums -1);

  //End time for the sorting
  end = chrono::system_clock::now();
  cout << "Merge Sort has been completed! " << endl;
  endTime = chrono::system_clock::to_time_t(end);
  cout << "End Time: " << ctime(&endTime);
  cout << "Time it took: " << endl;


  //exact amount of time to sort
  seconds = end - start;
  cout << seconds.count() << " seconds." << endl;
  cout << endl;
  cout << endl;


  cout<< "All sorting has been completed." << endl;
}
