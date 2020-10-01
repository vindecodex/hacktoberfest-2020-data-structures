#include <iostream>
using namespace std;

/*******************
Merge Sort:
1) Is a stable sort which means that the relative order of
equal sort items is preserved.

2) Overall time complexity of Merge sort is O(nLogn).
It is more efficient as it is in worst case also the runtime is O(nlogn)

3) It's not an in-place sorting algorithm. The space complexity of Merge sort is O(n). 
*******************/

void merge(int *arr, int *l, int nL, int *r, int nR)
{
    int i = 0, j = 0, k = 0;
    //merging logic: `i` points to the smallest element in left array
    //`j` points to the smallest element in right sub array
    //`k` points to the index where next element has to be over-written in `arr`
    while (i < nL && j < nR)
    {
        //if else using ternary operator
        (l[i] <= r[j]) ? arr[k++] = l[i++] : arr[k++] = r[j++];
    }

    //if left array still has elements, write all those elements to `arr`
    while (i < nL)
        arr[k++] = l[i++];

    //if right array still has elements, write all those elements to `arr`
    while (j < nR)
        arr[k++] = r[j++];
}

void mergeSort(int *arr, int n)
{
    //base case is when there is only one element in the array
    if (n < 2)
        return;

    // get the middle index and divide the array into two halves `left` and `right`
    // `left` array will have `mid` number of elements
    // `right` array will have `n-mid` number of elements
    int mid = n / 2;
    int left[mid];
    int right[n - mid];

    //fill the arrays with respective elements from the original array
    for (int i = 0; i < mid; i++)
        left[i] = arr[i];
    for (int i = mid; i < n; i++)
        right[i - mid] = arr[i];

    mergeSort(left, mid);                  // call mergesort on the left array until there's only one element left
    mergeSort(right, n - mid);             // call mergesort on the right array until there's only one element left
    merge(arr, left, mid, right, n - mid); // when done merge the array so that you get a sorted array
}

int main()
{
    int arr[] = {10, -90, 30, -100, 309, 170, 39, 0, 1, 65, 10, -11, 19};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Unsorted array: " << endl;
    for (int i = 0; i < n; i++)
        cout << arr[i] << "  ";
    cout << endl;

    mergeSort(arr, n);

    cout << "\nSorted array:" << endl;
    for (int i = 0; i < n; i++)
        cout << arr[i] << "  ";
    cout << endl;
}