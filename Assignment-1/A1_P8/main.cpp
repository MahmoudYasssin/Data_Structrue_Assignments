/*
Mahmoud yassin mahmoud
20200506

Ahmed hassan ahmed foad
20200010

Omar AbdEl-Aziz El-Sayed
20200831

youssef Mohammed galal
20200664

*/
#include <iostream>
#include <chrono>
#include <algorithm>


using namespace std::chrono;
using namespace std;
int binarySearch(int *to_be_sorted, int key, int low, int high)
{
    while (low <= high)
    {
        int middle =(low+ high) / 2;
        if (key == to_be_sorted[middle])
            return middle + 1;
        else if (key > to_be_sorted[middle])
            low = middle + 1;
        else
            high = middle - 1;
    }

    return low;
}

void binary_insertionSort(int *to_be_sorted, int n)
{
    int first, location, last, temp;

    for (first = 1; first < n; ++first)
    {
        last = first - 1;
        temp = to_be_sorted[first];
        location = binarySearch(to_be_sorted, temp, 0, last);

        while (last >= location)
        {
            to_be_sorted[last + 1] = to_be_sorted[last];
            last--;
        }
        to_be_sorted[last + 1] = temp;
    }
}
void insertionSort (int *to_be_sorted, int n)
{
   for (int i = 1, j; i < n; i++)
    {
        int tmp = to_be_sorted[i];
            for (j = i; j > 0 && tmp < to_be_sorted[j-1]; j--)
            {
                to_be_sorted[j] = to_be_sorted[j-1];
            }
        to_be_sorted[j] = tmp;
    }

}



int main()
{

for (int i=0 ; i < 3 ; i++)
{
    int* Arr;
    int n;
    auto f = []() -> int {return rand()%100000;};
    cin>>n;
    Arr = new int[n];
    generate(Arr, Arr + n, f);
    auto start = high_resolution_clock::now();
    insertionSort(Arr, n);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Time taken by insertion sort: "<<duration.count()<< " microseconds" << endl;
}
for (int i=0 ; i < 3 ; i++)
{
    int* Arr;
    int n;
    auto f = []() -> int {return rand()%100000;};
    cin>>n;
    Arr = new int[n];
    generate(Arr, Arr + n, f);
    auto start = high_resolution_clock::now();
    binary_insertionSort(Arr, n);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Time taken by binary insertion sort: "<<duration.count()<< " microseconds" << endl;
}
}
