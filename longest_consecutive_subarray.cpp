// C++ program to find longest 
// contiguous subsequence 
#include <bits/stdc++.h> 
using namespace std; 

/*
Input: arr[] = {1, 9, 3, 10, 4, 20, 2}
Output: 4
Explanation: 
The subsequence 1, 3, 4, 2 is the longest 
subsequence of consecutive elements

Input: arr[] = {36, 41, 56, 35, 44, 33, 34, 92, 43, 32, 42}
Output: 5
Explanation: 
The subsequence 36, 35, 33, 34, 32 is the longest 
subsequence of consecutive elements.
*/

// Returns length of the longest 
// contiguous subsequence 
int findLongestConseqSubseq(int arr[], int n) 
{ 
	int ans = 0, count = 0; 

	// sort the array 
	sort(arr, arr + n); 

	vector<int> v; 
	v.push_back(arr[0]); 

	//insert repeated elements only once in the vector 
	for (int i = 1; i < n; i++) 
	{ 
		if (arr[i] != arr[i - 1]) 
			v.push_back(arr[i]); 
	} 
	// find the maximum length 
	// by traversing the array 
	for (int i = 0; i < v.size(); i++) 
	{ 
		
		// Check if the current element is equal 
		// to previous element +1 
		if (i > 0 && v[i] == v[i - 1] + 1) 
			count++; 
		// reset the count 
		else
			count = 1; 

		// update the maximum 
		ans = max(ans, count); 
	} 
	return ans; 
} 

// Driver code 
int main() 
{ 
	int arr[] = { 1, 2, 2, 3 }; 
	int n = sizeof arr / sizeof arr[0]; 
	cout << "Length of the Longest contiguous subsequence "
			"is "
		<< findLongestConseqSubseq(arr, n); 
	return 0; 
}
