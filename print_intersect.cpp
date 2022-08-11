#include <iostream>
using namespace std;
#include <bits/stdc++.h>
void printIntersection(int arr1[], int arr2[], int n, int m) {
    // Write your code here
    unordered_map<int,int> helper;
    priority_queue<int,vector<int>,greater<int>>ans;
    for(int i=0;i<n;i++)
    {
        helper[arr1[i]]++;
    }
    for(int i=0;i<m;i++)
    {
         if(helper[arr2[i]]>0)
         {
             ans.push(arr2[i]);
             helper[arr2[i]]--;
         }
         else
         {
            continue;
         }
    }
    while(!ans.empty())
    {
        cout<<ans.top();
        ans.pop();
        cout<<endl;
    }
}

int main() {
    int n;
    cin >> n;

    int* arr1 = new int[n];

    for (int i = 0; i < n; ++i) {
        cin >> arr1[i];
    }

    int m;
    cin >> m;

    int* arr2 = new int[m];

    for (int i = 0; i < m; ++i) {
        cin >> arr2[i];
    }

    printIntersection(arr1, arr2, n, m);

    delete[] arr1;
    delete[] arr2;
}