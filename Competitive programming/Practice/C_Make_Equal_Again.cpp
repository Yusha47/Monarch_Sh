#include<bits/stdc++.h>
using namespace std;

// Extended Euclidean Algorithm to find modular inverse
int extended_euclid(int a, int b, int& x, int& y) {
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  } else {
    int gcd = extended_euclid(b, a % b, y, x);
    y -= a / b * x;
    return gcd;
  }
}

// Calculate beautiful pairs count
int beautifulPairs(const std::vector<int>& a, int x, int y) {
  int n = a.size();
  int modular_inverse_of_x = 0, modular_inverse_of_y = 0;
  
  // Find modular inverses using Extended Euclidean Algorithm
  extended_euclid(x, y, modular_inverse_of_x, modular_inverse_of_y);
  
  // Calculate diff_mod_x and sum_mod_y for each element
  std::vector<int> diff_mod_x(n), sum_mod_y(n);
  for (int i = 0; i < n; ++i) {
    diff_mod_x[i] = (a[i] % x) * modular_inverse_of_y % x;
    sum_mod_y[i] = (a[i] % y) * modular_inverse_of_x % y;
  }
  
  // Count beautiful pairs
  int count = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      if ((a[j] - diff_mod_x[i]) % x == 0 && (a[j] + sum_mod_y[i]) % y == 0) {
        count++;
      }
    }
  }
  
  return count;
}

int main() {

    int t;
    cin>>t;
    while(t--)
    {
          int n, x, y;
  std::cin >> n >> x >> y;
  
  std::vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i];
  }
  
  int result = beautifulPairs(a, x, y);
  std::cout << result << std::endl;
  

    }

}