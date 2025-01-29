// insertion sort 

#include <iostream>
#include <string>
using namespace std;

template <typename T>
void insertion_sort(T A[], int size)
{
    for (int i = 1; i < size; ++i)
    {
        T key = A[i];
        int j = i - 1;
        while (j >= 0 && key < A[j])
        {
            A[j + 1] = A[j];
            j = j - 1;
        }
        A[j + 1] = key;
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
        insertion_sort(A, size);
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
        insertion_sort(A, size);
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
        insertion_sort(A, size);
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
        insertion_sort(A, size);
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
        insertion_sort(A, size);
        cout << "After sorting:\n";
        show(A, size);
        delete[] A;
    }
    else
    {
        cout << "Invalid data type\n";
    }

    return 0;
}
