#include <iostream>
#include <cstdlib>
#include <time.h>
#include <cmath>

using namespace std;

void SelectionSort(int array[],int n);
void PrintArray(int array[],int size);
void BubbleSort(int array[],int n);
void InsertionSort(int array[],int n);
void merge(int array[],int first,int mid,int last);
void mergeSort(int array[],int first, int last);
int partition(int array[],int low, int high);
void quickSort(int arr[], int low, int high);

int main() {
//    int size;
//    cout<< "Enter the size of the array" << endl;
//    cin >> size;
//
//    int array[size];
//    srand(time(NULL));
//    for(int i=0; i<size; i++){
//        array[i] = rand();
//        cout << array[i] << endl;
//    }
        int array[5]={2,1,5,10,4};
        //SelectionSort(array,5);
 //   BubbleSort(array,5);
     //   InsertionSort(array,5);
   // mergeSort(array,0,4);
    quickSort(array,0,4);
        PrintArray(array,5);
       return 0;
}

void SelectionSort(int array[],int n){
    int min,i,j;
    for(i=0;i<=n-2;i++){
        min=i;
        for (j = i+1; j <= n-1;j++) {
            if(array[j] < array[min]){
                min=j;
            }
        }
        if(min != i){
            swap(array[i],array[min]);
        }
    }
}

void BubbleSort(int array[],int n){
    for (int i = 0; i < n ; i++) {
        for (int j = 0; j <= n-i-1 ; j++) {
            if(array[j+1]<array[j]) {
                swap(array[j], array[j + 1]);
            }
        }
    }
}

void InsertionSort(int array[],int n){
    for (int i = 1; i < n; ++i) {
        int key=array[i];
        int hole=i;
        while(hole>0 && array[hole-1]>key){
            array[hole]=array[hole-1];
            hole-=1;
        }
        array[hole]=key;
    }
}

void merge(int array[],int first,int mid,int last){
    int nl= mid-first+1;
    int nr= last-mid;
    int L[nl],R[nr];

    for (int i = 0; i < nl; i++) {
        L[i]=array[i+first];
    }
    for (int j = 0; j < nr; j++) {
        R[j]=array[mid+1+j];
    }

    int i=0,j=0,k=first;

    while(i<nl && j<nr){
        if(L[i]<=R[j]) {
            array[k] = L[i];
            i++;
        } else {
            array[k]=R[j];
            j++;
        }
        k++;
    }

    while(i<nl){
        array[k] = L[i];
        i++;
        k++;
    }

    while(j<nr){
        array[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int array[],int first, int last){
    if (first>=last) return;
    int mid=(first+last)/2;
    mergeSort(array,first,mid);
    mergeSort(array,mid+1,last);
    merge(array,first,mid,last);
}

void quickSort(int arr[], int low, int high){
    if (low < high)
    {
        int pivot = partition(arr, low, high);
        quickSort(arr, low, pivot - 1);
        quickSort(arr, pivot + 1, high);
    }
}

int partition(int array[],int low, int high){
    int pivot=array[low];
    int j=low+1;
    for (int i = low+1; i <= high; ++i) {
        if(array[i]<pivot){
            swap(array[i],array[j]);
            j++;
        }
    }
    array[low]=array[j-1];
    array[j-1]=pivot;

    return j-1;
}
void PrintArray(int array[],int size){
    for(int i=0;i<size;i++){
        cout<<array[i]<<" ";
    }
}



