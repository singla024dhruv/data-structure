#include <iostream>
#include <vector>
using namespace std;
#include <bits/stdc++.h>
vector<int> mergeKSortedArrays(vector<vector<int>*>arr) {
   int n = arr.size() * arr[0].size();
   priority_queue <pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> minHeap;
   for (int i = 0; i < arr.size(); i++) {
       minHeap.push( {arr[i][0], {i, 0} } );
   }
   vector<int> sortedArray;
   while(!minHeap.empty()) {
       sortedArray.push_back(minHeap.top().first);
       pair<int, int> index = {minHeap.top().second.first, minHeap.top().second.second + 1};
       minHeap.pop();
       if (index.second != arr[0].size()) {
           minHeap.push({arr[index.first][index.second], {index.first, index.second}});
       }
   }
   return sortedArray;
}
int main() {
    int k;
    cin >> k;

    vector<vector<int> *> input;

    for (int j = 1; j <= k; j++) {
        int size;
        cin >> size;
        vector<int> *current = new vector<int>;

        for (int i = 0; i < size; i++) {
            int a;
            cin >> a;
            current->push_back(a);
        }

        input.push_back(current);
    }

    vector<int> output = mergeKSortedArrays(input);

    for (int i = 0; i < output.size(); i++) {
        cout << output[i] << " ";
    }

    return 0;
}