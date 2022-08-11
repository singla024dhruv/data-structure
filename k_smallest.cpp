#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#include <queue>
vector<int> kSmallest(int arr[], int n, int k) {
    // Write your code here
    vector<int>ans;
    priority_queue<int>pq;
    for(int i=0;i<k;i++)
    {
        pq.push(arr[i]);
    }
    for(int i=k;i<n;i++)
    {
        if(pq.top()>arr[i])
        {
            pq.pop();
            pq.push(arr[i]);
        }
        else
        {
            continue;
        }
    }
    for(int i=0;i<k;i++)
    {
        ans.push_back(pq.top());
        pq.pop();
    }
    return ans;

}
int main() {
    int size;
    cin >> size;

    int *input = new int[size];

    for (int i = 0; i < size; i++) {
        cin >> input[i];
    }

    int k;
    cin >> k;

    vector<int> output = kSmallest(input, size, k);
    sort(output.begin(), output.end());

    for (int i = 0; i < output.size(); i++) {
        cout << output[i] << " ";
    }

    delete[] input;
}