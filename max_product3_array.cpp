// A O(n) C++ program to find maximum product pair in
// an array.
#include <bits/stdc++.h>
using namespace std;

/* Function to find a maximum product of a triplet
in array of integers of size n */
int maxProduct(int arr[], int n)
{
    // if size is less than 3, no triplet exists
    if (n < 3)
        return -1;

    // Initialize Maximum, second maximum and third
    // maximum element
    int maxA = INT_MIN, maxB = INT_MIN, maxC = INT_MIN;

    // Initialize Minimum and second mimimum element
    int minA = INT_MAX, minB = INT_MAX;

    for (int i = 0; i < n; i++)
    {
        // Update Maximum, second maximum and third
        // maximum element
        if (arr[i] > maxA)
        {
            maxC = maxB;
            maxB = maxA;
            maxA = arr[i];
        }

        // Update second maximum and third maximum element
        else if (arr[i] > maxB)
        {
            maxC = maxB;
            maxB = arr[i];
        }

        // Update third maximum element
        else if (arr[i] > maxC)
            maxC = arr[i];

        // Update Minimum and second mimimum element
        if (arr[i] < minA)
        {
            minB = minA;
            minA = arr[i];
        }

        // Update second mimimum element
        else if(arr[i] < minB)
            minB = arr[i];
    }

    return max(minA * minB * maxA,
            maxA * maxB * maxC);
}

// Driver program to test above function
int main()
{
    int arr[] = { 1, -4, 3, -6, 7, 0 };
    int n = sizeof(arr) / sizeof(arr[0]);

    int max = maxProduct(arr, n);

    if (max == -1)
        cout << "No Triplet Exists";
    else
        cout << "Maximum product is " << max;

    return 0;
}

