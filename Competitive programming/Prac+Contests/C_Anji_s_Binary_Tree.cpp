#include <iostream>
#include <vector>

using namespace std;

struct Node {
    char letter;
    int parent;
};

// Function to calculate the minimum changes needed for each leaf node
vector<int> minChangesForLeaves(vector<Node> &tree, vector<int> &leafNodes) {
    vector<int> minChanges;

    for (int leaf : leafNodes) {
        int currentNode = leaf;
        int changes = 0;

        while (currentNode != 0) {
            char currentLetter = tree[currentNode].letter;
            char parentLetter = (currentNode != 1) ? tree[tree[currentNode].parent].letter : 'U';

            if ((tree[tree[currentNode].parent].leftChild == currentNode && parentLetter != 'L') ||
                (tree[tree[currentNode].parent].rightChild == currentNode && parentLetter != 'R') ||
                (tree[tree[currentNode].parent].leftChild == 0 && tree[tree[currentNode].parent].rightChild == 0 && parentLetter != 'U')) {
                ++changes;
            }

            currentNode = tree[currentNode].parent;
        }

        minChanges.push_back(changes);
    }

    return minChanges;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<Node> tree(n + 1);
        vector<int> leafNodes;

        for (int i = 1; i <= n; ++i) {
            cin >> tree[i].letter;

            int leftChild, rightChild;
            cin >> leftChild >> rightChild;

            tree[leftChild].parent = i;
            tree[rightChild].parent = i;

            if (leftChild == 0 && rightChild == 0) {
                leafNodes.push_back(i);
            }

            tree[i].parent = 0;
        }

        vector<int> changes = minChangesForLeaves(tree, leafNodes);

        int maxChange = 0;
        for (int change : changes) {
            maxChange = max(maxChange, change); // Calculate maximum changes among leaf nodes
        }
        cout << maxChange << endl;
    }

    return 0;
}
