#include <iostream>
using namespace std;

/*******************
Quick Sort:
1) Is not a stable sort which, means that he relative order of
equal sort items is not preserved.

2) Overall time complexity of Quick sort is O(nLogn).
In worst case time complexity is O(n^2)

3) It is an in-place sorting algorithm, hence requires constant amount of space.
*******************/

int partition(int *arr, int start, int end)
{
    //take last element as the pivot element
    int pivot = arr[end];
    //and start moving all the elements less than or equal to pivot to left
    int pIndex = start; //set partition index as start initially
    for (int i = start; i < end; i++)
    {
        if (arr[i] <= pivot)
        {
            swap(arr[i], arr[pIndex]);
            pIndex++;
        }
    }
    //once all small values are accumulated towards the left side and all greater vals to the right end
    // swap the last element which acted as pivot to the index where it is supposed to be
    //and return that pIndex
    swap(arr[end], arr[pIndex]);
    return pIndex;
}

void quickSort(int *arr, int start, int end)
{
    if (start < end) //base case -> start>=end
    {
        //partition the array such that if we take a pivot element
        //all the values less than or equal to pivot must be on the left side of the pivot
        //all the values greater than or equal to pivot must be on the right side of pivot
        // and return the index of pivot element
        // then find pivot in the left array, followed by right array until start>=end or there is 1 or less
        //than one element in the array

        int pIndex = partition(arr, start, end);
        quickSort(arr, start, pIndex - 1);
        quickSort(arr, pIndex + 1, end);
    }
}

int main()
{
    int arr[] = {10, -90, 30, -100, 309, 170, 39, 0, 1, 65, 10, -11};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Unsorted array: " << endl;
    for (int i = 0; i < n; i++)
        cout << arr[i] << "  ";
    cout << endl;

    quickSort(arr, 0, n - 1);

    cout << "\nSorted array:" << endl;
    for (int i = 0; i < n; i++)
        cout << arr[i] << "  ";
    cout << endl;
}