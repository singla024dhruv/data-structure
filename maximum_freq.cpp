#include <iostream>
using namespace std;
#include <unordered_map>
#include <bits/stdc++.h>
int highestFrequency(int arr[], int n) {
    // Write your code here
    vector<int>helper;
    if(n==0)
    {
        return 0;
    }
    unordered_map<int,int> output;
    int max=arr[0];
    int y=0;
    for(int i=0;i<n;i++)
    {
          output[arr[i]]++;
        //  if(y<output[arr[i]])
          //{
            //  y=output[arr[i]];
              //max=arr[i];
          //}
    }
    for(int i=0;i<n;i++)
    {
        helper.push_back(output[arr[i]]);
        if(y<helper.at(i))
        {
            y=helper.at(i);
            max=arr[i];
        }
    }
        return max;
}


int main() {
    int n;
    cin >> n;

    int* arr = new int[n];

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    cout << highestFrequency(arr, n);

    delete[] arr;
}