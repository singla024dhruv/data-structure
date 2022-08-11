#include <iostream>
using namespace std;
#include <bits/stdc++.h>
int pairSum(int *arr, int n) {
	// Write your code here
    unordered_map<int,int> output;
    int x=0;
    for(int i=0;i<n;i++)
    {
        if(output[arr[i]*-1]>0)
        {
            x+=output[arr[i]*-1];
        }
        output[arr[i]]++;
    }
    return x;

}

int main() {
    int n;
    cin >> n;

    int* arr = new int[n];

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    cout << pairSum(arr, n);

    delete[] arr;
}