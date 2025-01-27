#include <iostream>
using namespace std;

template <typename T>
void merge(T array[], int start, int mid, int end)
{
    int n1 = mid - start + 1;
    int n2 = end - mid;

    T* left = new T[n1];
    T* right = new T[n2];

    for (int i = 0; i < n1; i++)
        left[i] = array[start + i];
    for (int j = 0; j < n2; j++)
        right[j] = array[mid + 1 + j];

    int i = 0, j = 0, k = start;
    while (i < n1 && j < n2)
    {
        if (left[i] <= right[j])
        {
            array[k] = left[i];
            i++;
        }
        else
        {
            array[k] = right[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        array[k] = left[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        array[k] = right[j];
        j++;
        k++;
    }

    delete[] left;
    delete[] right;
}

template <typename T>
void merge_sort(T array[], int start, int end)
{
    if (start < end)
    {
        int mid = start + (end - start) / 2;
        merge_sort(array, start, mid);
        merge_sort(array, mid + 1, end);
        merge(array, start, mid, end);
    }
}

template <typename T>
void show(T A[], int size)
{
    for (int i = 0; i < size; ++i)
    {
        cout << "A[" << i << "] = " << A[i] << endl;
    }
}

int main()
{
    int A[5] = {1, 4, 6, 3, 5};
    cout<<"before sorting \n";
    show(A, 5);
    merge_sort(A, 0, 4);
    cout<<"after sorting \n";
    show(A, 5);

    char B[5] = {'z', 'f', 'c', 'j', 'e'};
    cout<<"before sorting \n";
    show(B, 5);
    merge_sort(B, 0, 4);
    cout<<"after sorting \n";
    show(B, 5);

    char C[5] = {'A', 'E', 'D', 'C', 'B'};
    cout<<"before sorting \n";
    show(C, 5);
    merge_sort(C, 0, 4);
    cout<<"after sorting \n";
    show(C, 5);

    double D[7] = {1.4, 2.3, 4.6, 4.4, 4.8, 2.5, 2.7};
    cout<<"before sorting \n";
    show(D, 7);
    merge_sort(D, 0, 6);
    cout<<"after sorting \n";
    show(D, 7);

    return 0;
}
