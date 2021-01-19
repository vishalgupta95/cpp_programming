
//VectorStores elements contiguosly
//Provides insertion and deletion methods at middle and end
//Bad performance for insertion and deletion at the front
//Good performance for addition and deletion of elements at the end

#include <iostream>
#include <limits>
#include <vector>
#include <algorithm>
using namespace std;

int func_sort_int(vector<int> &intVec)
{
    sort(intVec.begin(), intVec.end());
    return 0;
}

int func_sort_string(vector<string> &stringVec)
{
    sort(stringVec.begin(), stringVec.end());
    return 0;
}

int sort_array(int arr[], int n)
{

    //	sort(arr, arr + n); normal sort
    //   sort(arr, arr + n, greater<int>()); //comparartor sort
    sort(arr, arr + n, [](const int &a, const &b) { return b < a; }); //comparartor sort

    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";

    return 0;
}

int abc1()
{
    int sum = 0;
    vector<int> myvector{1, 5, 6, 3, 9, 2};
    while (!myvector.empty())
    {
        sum = sum + myvector.back();
        myvector.pop_back();
    }
    cout << sum;
    return 0;
}

int abc2()
{
    vector<int> myvector{1, 2, 3, 4, 5};
    cout << myvector.size();
    return 0;
}

int main()
{
    vector<int> intVec = {9, 8, 76, 5, 4};
    vector<string> stringVec = {"John", "Bob", "Joe", "Zack", "Randy"};

    intVec.push_back(-10);

    func_sort_int(intVec);
    func_sort_string(stringVec);

    cout << "Elements after sorting" << endl;
    for (auto itr = intVec.begin(); itr != intVec.end(); ++itr)
        cout << *itr << endl;

    for (auto i : stringVec) // access by value, the type of i is int
        cout << i << ' ' << endl;
    vector<int> g1;

    for (int i = 1; i <= 5; i++)
        g1.push_back(i);

    cout << "Output of begin and end: ";
    for (auto i = g1.begin(); i != g1.end(); ++i)
        cout << *i << " ";

    cout << "\nOutput of cbegin and cend: ";
    for (auto i = g1.cbegin(); i != g1.cend(); ++i)
        cout << *i << " ";

    // using unique() method to remove duplicates
    

    abc1();
    abc2();

    int arr[] = {1, 5, 8, 9, 6, 7, 3, 4, 2, 0};
    int n = sizeof(arr) / sizeof(arr[0]);

    /*Here we take two parameters, the beginning of the
	array and the length n upto which we want the array to
	be sorted*/
    sort_array(arr, n);

    cout << "\nArray after sorting using "
            "default sort is : \n";
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
}
