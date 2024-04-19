#include <iostream>
#include <cmath>
using namespace std;

int min_height(int a, int b, int c) {
    if (a == 0) {
        if (b == 0) {
            if (c == 0) {
                return 0;
            } else {
                return 1;
            }
        } else {
            return 1;
        }
    }
    
    int total_vertices = a + b + c;
    int min_height = b + c;
    min_height += ceil(a / 2.0);
    
    return min_height;
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int a, b, c;
        cin >> a >> b >> c;
        cout << min_height(a, b, c) << endl;
    }
    
    return 0;
}
