/*
Zachary Jagoda
Student ID: 2274813
Student Email: jagod101@mail.chapman.edu
CPSC 350-02
*/

#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <time.h>

using namespace std;

class Sorting {
  private:
    int numElements;

    double *quickSortArray;
    double *insertSortArray;
    //INCLUDE ANOTHER TYPE OF ARRAY

  public:
    Sorting();
    ~Sorting();

    void setFile(string file);

    void quickSort(double array[], int left, int right);
    int partition(double array[], int left, int right);
    void insertSort(double array[]);
    //void <INSERT OTHER METHOD>();

    void sortAll();
    void swap(double array[], int a, int b);
};
