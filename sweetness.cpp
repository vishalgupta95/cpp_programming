#include <vector>
#include <numeric>
#include <algorithm>
#include <iostream>

using namespace std;

/*
Problem Description:
You have one chocolate bar that consists of some chunks. Each chunk has its own sweetness given by the array sweetness.

You want to share the chocolate with your k friends so you start cutting the chocolate bar into k + 1 pieces using k cuts, each piece consists of some consecutive chunks.

Being generous, you will eat the piece with the minimum total sweetness and give the other pieces to your friends.

Find the maximum total sweetness of the piece you can get by cutting the chocolate bar optimally.

Example 1:
Input: sweetness = [1,2,3,4,5,6,7,8,9], k = 5
Output: 6
Explanation: You can divide the chocolate to [1,2,3], [4,5], [6], [7], [8], [9]

Example 2:
Input: sweetness = [5,6,7,8,9,1,2,3,4], k = 8
Output: 1
Explanation: There is only one way to cut the bar into 9 pieces.

Example 3:
Input: sweetness = [1,2,2,1,2,2,1,2,2], k = 2
Output: 5
Explanation: You can divide the chocolate to [1,2,2], [1,2,2], [1,2,2]
*/

bool canSplit(const vector<int>& sweetness, int k, int min_sweetness) {
    int current_sum = 0;
    int pieces = 0;
    
    for (int sweet : sweetness) {
        current_sum += sweet;
        if (current_sum >= min_sweetness) {
            pieces++;
            current_sum = 0; // start a new piece
        }
    }
    
    return pieces >= k + 1;
}

int maxSweetness(const vector<int>& sweetness, int k) {
    // Binary search for the maximum minimum sweetness
    int left = *min_element(sweetness.begin(), sweetness.end());
    int right = accumulate(sweetness.begin(), sweetness.end(), 0);
    int result = left;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (canSplit(sweetness, k, mid)) {
            result = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    return result;
}

int main() {
    // Example 1
    vector<int> sweetness1 = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int k1 = 5;
    cout << "Maximum minimum sweetness (Example 1): " << maxSweetness(sweetness1, k1) << endl;

    // Example 2
    vector<int> sweetness2 = {5, 6, 7, 8, 9, 1, 2, 3, 4};
    int k2 = 8;
    cout << "Maximum minimum sweetness (Example 2): " << maxSweetness(sweetness2, k2) << endl;

    // Example 3
    vector<int> sweetness3 = {1, 2, 2, 1, 2, 2, 1, 2, 2};
    int k3 = 2;
    cout << "Maximum minimum sweetness (Example 3): " << maxSweetness(sweetness3, k3) << endl;

    return 0;
}

