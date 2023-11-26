// C++ implementation for 
// above approach
#include <bits/stdc++.h>
using namespace std;

// Function to find the Kth
// not divisible by N
void kthNonDivisible(int N, int K)
{
	
	// Lowest possible value
	int L = 0; 

	// Highest possible value
	int H = INT_MAX; 

	// To store the Kth non 
	// divisible number of N
	int ans = 0; 

	// Using binary search
	while (L +1< H) 
	{
		
		
		int mid = L+(H-L) / 2; 

	
		int sol = mid - mid / N; 

		if (sol >= K) 
		{
            
		
			
            H=mid; 
		}
	
        else L=mid ;
	
		
	
	}

	// Print the answer
	cout << H <<endl;
}

// Driver Code
int main()
{

    int t;cin>>t;
    while(t--)
    {
        int N ;
	int K;
    cin>>N>>K;

	// Function Call
	kthNonDivisible(N, K);
    }
	
	return 0;
}
