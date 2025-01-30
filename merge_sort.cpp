#include <iostream>
#include <string>
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

int main ()
{
    char ch = 'y';
    while(ch == 'y')
    {
        cout << "Valid data types are int, float, double, char, string\n";
        string datatype;
        cout << "Enter data type of the array: ";
        cin >> datatype;

        if (datatype == "int")
        {
            int size;
            cout << "Enter the size of the array: ";
            cin >> size;
            int* A = new int[size];
            for(int i = 0; i < size; i++)
            {
                cout << "Enter the element at index " << i << ": ";
                cin >> A[i];
            }
            cout << "Before sorting:\n";
            show(A, size);
            merge_sort(A, 0, size - 1);
            cout << "After sorting:\n";
            show(A, size);
            delete[] A;
        }
        else if (datatype == "float")
        {
            int size;
            cout << "Enter the size of the array: ";
            cin >> size;
            float* A = new float[size];
            for(int i = 0; i < size; i++)
            {
                cout << "Enter the element at index " << i << ": ";
                cin >> A[i];
            }
            cout << "Before sorting:\n";
            show(A, size);
            merge_sort(A, 0, size - 1);
            cout << "After sorting:\n";
            show(A, size);
            delete[] A;
        }
        else if (datatype == "double")
        {
            int size;
            cout << "Enter the size of the array: ";
            cin >> size;
            double* A = new double[size];
            for(int i = 0; i < size; i++)
            {
                cout << "Enter the element at index " << i << ": ";
                cin >> A[i];
            }
            cout << "Before sorting:\n";
            show(A, size);
            merge_sort(A, 0, size - 1);
            cout << "After sorting:\n";
            show(A, size);
            delete[] A;
        }
        else if (datatype == "char")
        {
            int size;
            cout << "Enter the size of the array: ";
            cin >> size;
            char* A = new char[size];
            for(int i = 0; i < size; i++)
            {
                cout << "Enter the element at index " << i << ": ";
                cin >> A[i];
            }
            cout << "Before sorting:\n";
            show(A, size);
            merge_sort(A, 0, size - 1);
            cout << "After sorting:\n";
            show(A, size);
            delete[] A;
        }
        else if (datatype == "string")
        {
            int size;
            cout << "Enter the size of the array: ";
            cin >> size;
            string* A = new string[size];
            for(int i = 0; i < size; i++)
            {
                cout << "Enter the element at index " << i << ": ";
                cin >> A[i];
            }
            cout << "Before sorting:\n";
            show(A, size);
            merge_sort(A, 0, size - 1);
            cout << "After sorting:\n";
            show(A, size);
            delete[] A;
        }
        else
        {
            cout << "Invalid data type\n";
        }

        cout << "Do you want to continue? (y/n): ";
        cin >> ch;
        if (ch == 'n')
        {
            cout << "Goodbye!\n";
        }
        else if (ch != 'y' || ch != 'n')
        {
            cout << "Invalid input\n";
        }
    }
    return 0;
}
