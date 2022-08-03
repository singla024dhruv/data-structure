/*                                program for heap sort                      */
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void heapform(int i,int arr[])
{
    int childindex=i;
  //  int parentindex=(childindex-1)/2;
    while(childindex>0)
    {
    int parentindex=(childindex-1)/2;

        if(arr[childindex]<arr[parentindex])
        {
            swap(arr[childindex],arr[parentindex]);
        }
        else
        {
            return ;
        }
        childindex=parentindex;
    }
    return ;
}
void heap_sort(int arr[],int size)
{
     if(size==0)
     {
        return;
     }
     int parent=0;
     int leftin=1;
     int rightin=2;
     while(1)
     {
        int minin=parent;
        if(leftin<=size && arr[leftin]<arr[minin])
        {
            minin=leftin;
        }
        if(rightin<=size && arr[rightin]<arr[minin])
        {
            minin=rightin;
        }
        if(minin==parent)
        {
            break;
        }
        swap(arr[parent],arr[minin]);
             parent=minin;
             leftin=2*parent+1;
             rightin=2*parent+2;
     }
     return;
}
void heapSort(int arr[], int n) {
    // Write your code
    if(n==0||n==1)
    {
        return ;
    }
    int i=1;
    while(i<n)
    {
        heapform(i,arr);
        i++;
    }
    int size=n-1;
    while(size!=0)
    {
        swap(arr[0],arr[size]);
        heap_sort(arr,size-1);
        size--;
         

    }
    

}
int main() {
    int size;
    cin >> size;

    int *input = new int[size];

    for (int i = 0; i < size; i++) {
        cin >> input[i];
    } 

    heapSort(input, size);

    for (int i = 0; i < size; i++) {
        cout << input[i] << " ";
    } 

    delete[] input;
}
