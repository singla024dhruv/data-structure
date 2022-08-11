#include <iostream>
using namespace std;
#include <bits/stdc++.h>
int lengthOfLongestSubsetWithZeroSum(int* arr, int n) {
    // Write your code here
    unordered_map<int,int> helper;
    int x=0;
    int maxlength=0;
    for(int i=0;i<n;i++)
    {
        x+=arr[i];
        if(helper.count(x)>0)
        {
            maxlength=max(maxlength,i-helper[x]);
            continue;
        }
        else
        {
            helper[x]=i;
        }

    }
    return maxlength;
}


int main() {
    int size;
    cin >> size;

    int* arr = new int[size];

    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    cout << lengthOfLongestSubsetWithZeroSum(arr, size);

    delete[] arr;
}