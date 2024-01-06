// C++ implementation of the approach
#include <bits/stdc++.h>
using namespace std;

// Function to return the lexicographically
// largest sub-sequence of s
string getSubSeq(string s, int n)
{
	stack<char> st;
	for (int i = 0; i < n; i++) {
		while (!st.empty() && s[i] > st.top())
			st.pop();
		st.push(s[i]);
	}
	string res = "";
	while (!st.empty()) {
		res += st.top();
		st.pop();
	}
	reverse(res.begin(), res.end());
	return res;
}

// Driver code
int main()
{
	string s = "zbca";
	int n = s.length();
	cout << getSubSeq(s, n);
}
