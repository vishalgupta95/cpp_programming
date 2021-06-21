#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

const int SIZE = 268;


struct  WordCount
{
    string name;
    int count = 0;
};

void bubbleSort(string arr[], int size)
{
    for (int stopMarker = 1; stopMarker < size; stopMarker++)
    {
        for (int j = size - 1; j >= stopMarker; j--)
        {
            if (arr[j] < arr[j - 1])
            {
                swap(arr[j], arr[j - 1]);
            }
        }
    }
}

int main()
{
    string wordArray[SIZE];
    WordCount arr[SIZE];
    WordCount item;

    ifstream input;

    input.open("F:\\gdp.txt");



    for (int i = 0; i < SIZE; i++)
    {
        input >> wordArray[i];
    }

    input.close();

    bubbleSort(wordArray, SIZE);

    for (int i = 0; i < SIZE; i++)
    {
        item.name = wordArray[i];
        item.count = 1;
        arr[i] = item;
    }

    cout << "Array content..." << endl << endl;

    for (int i = 0; i < SIZE; i++)
    {
        cout << setw(13) << left << arr[i].name << setw(10) << "Count = " << arr[i].count << endl;
    }

    return 0;
}
