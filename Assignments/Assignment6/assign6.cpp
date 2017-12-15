/*
Zachary Jagoda
Student ID: 2274813
Student Email: jagod101@mail.chapman.edu
CPSC 350-02
*/

#include "assign6.h"

using namespace std;

Sorting::Sorting() {

}

Sorting::~Sorting() {
  delete[] quickSortArray;
  delete[] insertSortArray;
  delete [] gnomeSortArray;
}

void Sorting::setFile(string file) {
  string nElements;
  string line;
  double size;
  int numLine = 1;

  ifstream inputFile;
  inputFile.open(file.c_str());

  getline(inputFile, nElements);

  numElements = atoi(nElements.c_str());

  quickSortArray = new double[numElements];
  insertSortArray = new double[numElements];
  gnomeSortArray = new double[numElements];

  for(int i = 0; i < numElements; ++i) {
    numLine++;

    getline(inputFile, line);

    try {
      size = atof(line.c_str());
    }
    catch(exception e) {
      cout << "INVALID FORMAT" << endl;
      return;
    }

    quickSortArray[i] = size;
    insertSortArray[i] = size;
    gnomeSortArray[i] = size;
  }

  inputFile.close();
  sortAll();
}

void Sorting::quickSort(double array[], int left, int right) {
  int idx = partition(array, left, right);

  if(left < idx - 1) {
    quickSort(array, left, idx - 1);
  }
  if(right > idx) {
    quickSort(array, idx, right);
  }
}

int Sorting::partition(double array[], int left, int right) {
  //Middle Value becomes Pivot
  int pivot = array[(left + right) / 2];

  while (left <= right)
  {
    //Objects to Left of Pivot in Array
    while (array[left] < pivot) {
      left++;
    }

    //Objects to Right of Pivot in Array
    while (array[right] > pivot) {
      right--;
    }

    //Swap Left and Right Objects
    if (left <= right) {
      swap(array, left, right);
      left++;
      right--;
    }
  }

  return left;
}

void Sorting::insertSort(double array[]) {
  //Marker
  for(int j = 1; j < numElements; ++j) {
    //Store Marked Item
    double temp = array[j];
    //Where to start Shifting
    int k = j;

    //While the thing to the left is larger, shift
    while(k > 0 && array[k-1] >= temp) {
      array[k] = array[k-1];
      --k;
    }
    //Puts Marked Item in Right Spot
    array[k] = temp;
  }
}

void Sorting::gnomeSort(double array[]) {
  int idx = 0;

  while (idx < numElements) {
    if (idx == 0 || array[idx-1] <= array[idx]) {
      ++idx;
    }

    else {
      double temp = array[idx];
      array[idx] = array[idx-1];
      array[--idx] = temp;
    }
  }
}

void Sorting::sortAll() {
  clock_t clockStart;
  clock_t clockEnd;
  float calculatedTime;

  cout << "\nSORTING PROCESSES UNDERWAY...\n\n";

  //Quick Sort
  clockStart = clock();
  quickSort(quickSortArray, 0, numElements - 1);
  clockEnd = clock();

  calculatedTime = (float(clockEnd - clockStart)/CLOCKS_PER_SEC) * 1000;
  cout << "+ Quick Sort took " << calculatedTime << "ms to sort " << numElements << " numbers\n";

  //Insert Sort
  clockStart = clock();
  insertSort(insertSortArray);
  clockEnd = clock();

  calculatedTime = (float(clockEnd - clockStart)/CLOCKS_PER_SEC) * 1000;
  cout << "+ Insert Sort took " << calculatedTime << "ms to sort " << numElements << " numbers\n";

  //Gnome Sort
  clockStart = clock();
  gnomeSort(gnomeSortArray);
  clockEnd = clock();

  calculatedTime = (float(clockEnd - clockStart)/CLOCKS_PER_SEC) * 1000;
  cout << "+ Gnome Sort took " << calculatedTime << "ms to sort " << numElements << " numbers\n";

  cout <<"...SORTING COMPLETED\n";
}

void Sorting::swap(double array[], int a, int b) {
  double tempArray = array[a];
  array[a] = array[b];
  array[b] = tempArray;
}
