

Approach 1

Pick up chunks  1 Giga byte, sort & store them as separate sorted files. You end up with 1000 1 
Giga byte  sorted files on the file system. Now, it's simply a problem of merging k-sorted arrays 
 using heap sort 
i.e. k = 1000 (files) in our case. ( 1GB ram can store 1000 numbers )

Approach 2

Any kind of comparison-based sorting would be expensive here as it results in runtime 
complexity of nlogn where n is 256 billion integers (1 Tera byte  divide by 4). There are only 
4 billion possible integers which means there are lot of  duplicates. We could use hashes or 
array with index being the integer and value being the number of times that integer is repeated.

We have 2 power 31 (2GB) RAM and in the worst case there could be only one integer repeated 
256 billion times. For this, we will need 64-bit integer (8 bytes)  to store the count. This will
 reduce the size  of our array to 2 power 28 indices.  We could divide the 4  billion integers into
 16 ranges each covering 2 power 28 integers. At the end of it, we have a sorted file.


// C++ program to merge k sorted arrays of size n each.
#include<bits/stdc++.h>
using namespace std;
#define n 4


// A utility function to print array elements
void printArray(int arr[], int size)
{
for (int i=0; i < size; i++)
    cout << arr[i] << " ";
}

// This function takes an array of arrays as an argument and
// All arrays are assumed to be sorted. It merges them together
// and prints the final sorted output.
void mergeKArrays(int arr[][n], int a, int output[])
{
    int c=0;
    
    //traverse the matrix
    for(int i=0; i<a; i++)
    {
        for(int j=0; j<n ;j++)
            output[c++]=arr[i][j];
    }
    
    //sort the array
    sort(output,output + n*a);
    
}


// Driver program to test above functions
int main()
{
    // Change n at the top to change number of elements
    // in an array
    int arr[][n] = {{2, 6, 12, 34},
                    {1, 9, 20, 1000},
                    {23, 34, 90, 2000}};
    int k = sizeof(arr)/sizeof(arr[0]);
    
    int output[n*k];
    
    mergeKArrays(arr, 3, output);

    cout << "Merged array is " << endl;
    printArray(output, n*k);

    return 0;
}

