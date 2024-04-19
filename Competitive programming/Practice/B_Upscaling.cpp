#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> checkerboard(int n) {
    vector<string> result;

    for (int i = 0; i < 2 * n; ++i) {
        string row;
        for (int j = 0; j < 2 * n; ++j) {
            if ((i / 2 + j / 2) % 2 == 0) {
                row += '#';
            } else {
                row += '.';
            }
        }
        result.push_back(row);
    }

    return result;
}

int main() {

    int t;
    cin>>t;

    while(t--)
    {
         int n ;
         cin>>n;
        vector<string> output = checkerboard(n);
        for (const string& row : output) {
            cout << row << endl;
        }
        
    }
    
    
   

    return 0;
}
