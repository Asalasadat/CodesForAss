#include <bits/stdc++.h>
using namespace std;
void bubbleSort(long long arr[], long long n)
{
    long long i, j;
    bool swapped;
    for (i = 0; i < n - 1; i++) {
        swapped = false;
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (swapped == false)
            break;
    }
}
void selectionSort(long long arr[], long long n) 
{ 
    long long i, j, min_idx; 
    for (i = 0; i < n - 1; i++) { 
        min_idx = i; 
        for (j = i + 1; j < n; j++) { 
            if (arr[j] < arr[min_idx]) 
                min_idx = j; 
        } 
        if (min_idx != i) 
            swap(arr[min_idx], arr[i]); 
    } 
} 
void merge(long long array[], long long const left, long long const mid, long long const right)
{
    long long const subArrayOne = mid - left + 1;
    long long const subArrayTwo = right - mid;
    auto *leftArray = new long long[subArrayOne],
         *rightArray = new long long[subArrayTwo];
    for (auto i = 0; i < subArrayOne; i++)
        leftArray[i] = array[left + i];
    for (auto j = 0; j < subArrayTwo; j++)
        rightArray[j] = array[mid + 1 + j];
    auto indexOfSubArrayOne = 0, indexOfSubArrayTwo = 0;
    long long indexOfMergedArray = left;
    while (indexOfSubArrayOne < subArrayOne
           && indexOfSubArrayTwo < subArrayTwo) {
        if (leftArray[indexOfSubArrayOne]
            <= rightArray[indexOfSubArrayTwo]) {
            array[indexOfMergedArray]
                = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        }
        else {
            array[indexOfMergedArray]
                = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
    }
    while (indexOfSubArrayOne < subArrayOne) {
        array[indexOfMergedArray]
            = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }
    while (indexOfSubArrayTwo < subArrayTwo) {
        array[indexOfMergedArray]
            = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }
    delete[] leftArray;
    delete[] rightArray;
}
void mergeSort(long long array[], long long const begin, long long const end)
{
    if (begin >= end)
        return;
 
    long long mid = begin + (end - begin) / 2;
    mergeSort(array, begin, mid);
    mergeSort(array, mid + 1, end);
    merge(array, begin, mid, end);
}
long long partition(long long arr[],long long low,long long high)
{   
  long long pivot=arr[high];
  long long i=(low-1);
  for(long long j=low;j<=high;j++)
  {
    if(arr[j]<pivot)
    {
      i++;
      swap(arr[i],arr[j]);
    }
  }
  swap(arr[i+1],arr[high]);
  return (i+1);
}         
void quickSort(long long arr[],long long low,long long high)
{
  if(low<high)
  {
    long long pi=partition(arr,low,high);
    quickSort(arr,low,pi-1);
    quickSort(arr,pi+1,high);
  }
}
void PrintArray(long long A[], long long size)
{
    for (long long i = 0; i < size; i++)
        cout << A[i] << " ";
    cout << endl;
}
int main()
{
     long long random;
    long long arr[10];
    srand((unsigned) time(NULL));
    for(long long i=0 ; i < 10; i++)
    {
	    random = rand()%1000000000000;
        arr[i]=random;
    }
    PrintArray(arr,10);
    auto start = chrono::steady_clock::now();
    bubbleSort(arr,10);
    auto end = chrono::steady_clock::now();
    auto diff = end - start;
    PrintArray(arr,10);
    cout << chrono::duration <double, milli> (diff).count() << " ms" << endl;
}
/*
bubbleSort
selectionSort
mergeSort
quickSort
*/