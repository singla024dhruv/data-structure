#include <iostream>
using namespace std;

bool isMaxHeap(int arr[], int n) {
    // Write your code here
    if(n==0||n==1)
    {
        return true;
    }
    int parent=0;
    while(parent<n)
    {
        int leftin=2*parent+1;
            int rightin=2*parent+2;
            if(leftin>=n)
            {
                parent++;
                continue;
            }
            if(leftin<n&&rightin>=n)
            {  
                if(arr[parent]<arr[leftin])
                {
                    return false;
                }
                else
                {
                    parent++;
                    continue;
                }
            }
        if(arr[parent]>arr[leftin]&&arr[parent]>arr[rightin])
        {
            parent++;
            
            continue;
        }
        else
        {
            return false;
        }
        
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    int *arr = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << (isMaxHeap(arr, n) ? "true\n" : "false\n");

    delete[] arr;
}