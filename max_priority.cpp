/* program for implementing max priority queue*/
#include <iostream>
using namespace std;
#include <vector>
#include <climits>
class PriorityQueue {
    // Declare the data members here
    vector<int>pq;

   public:
    PriorityQueue() {
        // Implement the constructor here
    }
     
    /**************** Implement all the public functions here ***************/

    void insert(int element) {
        // Implement the insert() function here
        pq.push_back(element);
        int childindex=pq.size()-1;
        while(childindex>0)
        {
            int parentindex=(childindex-1)/2;
            if(pq[childindex]>pq[parentindex])
            {
                swap(pq[childindex],pq[parentindex]);
            }
            else
            {
                break;
            }
            childindex=parentindex;
        }

    }

    int getMax() {
        // Implement the getMax() function here
         if(isEmpty())
         {
            return INT_MIN; 
         }
         return pq[0];
    }

    int removeMax() {
        // Implement the removeMax() function here
        if(isEmpty())
        {
            return INT_MIN;
        }
        int ans=pq[0];
        pq[0]=pq[pq.size()-1];
        pq.pop_back();
        int parentindex=0;
        int leftindex=2*parentindex+1;
        int rightindex=2*parentindex+2;
        while(1)
        {
            int maxindex=parentindex;
            if(leftindex<pq.size() && pq[maxindex]<pq[leftindex])
            {
                maxindex=leftindex;
            }
            if(rightindex<pq.size() && pq[maxindex]<pq[rightindex])
            {
                maxindex=rightindex;
            }
            if(maxindex==parentindex)
            {
                break;
            }
            swap(pq[parentindex],pq[maxindex]);
            parentindex=maxindex;
            leftindex=2*parentindex+1;
            rightindex=2*parentindex+2;
        }
        return ans;
    }

    int getSize() { 
        // Implement the getSize() function here
        return pq.size();
    }

    bool isEmpty() {
        // Implement the isEmpty() function here
        return(pq.size()==0);
    }
};
int main() {
    PriorityQueue pq;
    int choice;
    cin >> choice;

    while (choice != -1) {
        switch (choice) {
            case 1:  // insert
                int element;
                cin >> element;
                pq.insert(element);
                break;
            case 2:  // getMax
                cout << pq.getMax() << "\n";
                break;
            case 3:  // removeMax
                cout << pq.removeMax() << "\n";
                break;
            case 4:  // size
                cout << pq.getSize() << "\n";
                break;
            case 5:  // isEmpty
                cout << (pq.isEmpty() ? "true\n" : "false\n");
            default:
                return 0;
        }
        
        cin >> choice;
    }
}