#include <iostream>
#include <string>
using namespace std;

template <typename T>
void MySwap(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}

template <typename T>
void quick_sort(T array[], int start, int end)
{
    if (start < end)
    {
        T ptr = array[start];
        int i = start;
        int j = end;
        while (i < j)
        {
            while (array[i] <= ptr && i < end)
            {
                i++;
            }
            while (array[j] >= ptr && j > start)
            {
                j--;
            }
            if (i < j)
            {
                MySwap(array[i], array[j]);
            }
        }
        MySwap(array[j], array[start]);
        quick_sort(array, start, j - 1);
        quick_sort(array, j + 1, end);
    }
}

template <typename T>
void show(T A[], int size)
{
    for (int i = 0 ; i < size; ++i)
    {
        cout << " A[ " << i << " ] = " << A[i] << endl;
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
            quick_sort(A, 0, size - 1);
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
            quick_sort(A, 0, size - 1);
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
            quick_sort(A, 0, size - 1);
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
            quick_sort(A, 0, size - 1);
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
            quick_sort(A, 0, size - 1);
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
        else if (ch != 'y' && ch != 'n')
        {
            cout << "Invalid input\n";
        }
    }
    return 0;
}
