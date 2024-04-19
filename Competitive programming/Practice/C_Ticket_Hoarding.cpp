#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

  

    int k, m;
    cout << "Enter values of k and m: ";
    cin >> m >> k;
      vector<int> a(n);
    cout << "Enter " << n << " integers separated by space: ";
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int numElements = min(k, m);

    vector<int> lowestElementsIndices;

    // Find the indices of the smallest elements without sorting
    for (int i = 0; i < numElements; ++i) {
        int minIndex = 0;
        for (int j = 1; j < n; ++j) {
            if (a[j] < a[minIndex] && find(lowestElementsIndices.begin(), lowestElementsIndices.end(), j) == lowestElementsIndices.end()) {
                minIndex = j;
            }
        }
        lowestElementsIndices.push_back(minIndex);
    }

    cout << "The " << numElements << " lowest elements in the array are: [";
    for (int i = 0; i < numElements; ++i) {
        cout << a[lowestElementsIndices[i]];
        if (i < numElements - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;

    return 0;
}
