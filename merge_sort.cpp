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
void array_show(T A[], int size)
{
    for (int i = 0; i < size; ++i)
    {
        cout << "A[" << i << "] = " << A[i] << endl;
    }
}

template <typename T>
void array_data(T A[], int size)
{
    for (int i = 0; i<size; i++)
    {
        cout<<"enter data at index "<<i<<" : ";
        cin>>A[i];
    }
    cout<<"Before sorting :\n";
    array_show(A,size);
    merge_sort(A,0,size - 1);// code // enter the sorting function
    cout<<"After sorting :\n";
    array_show(A,size);
}

int main ()
{
    char ch = 'y';
    while (ch == 'y')
    {
        int size;
        cout<<"enter the size of the array : ";
        cin>>size;
        cout << "Valid data types are int, float, double, char, string\n";
        string datatype;
        cout << "Enter data type of the array: ";
        cin >> datatype;
        if (datatype == "int")
        {
            int*A = new int[size];
            array_data(A,size);
            delete[] A;
        }
        else if (datatype == "char")
        {
            char*A = new char[size];
            array_data(A,size);
            delete[] A;
        }
        else if (datatype == "float")
        {
            float*A = new float[size];
            array_data(A,size);
            delete[] A;
        }
        else if (datatype == "double")
        {
            double*A = new double[size];
            array_data(A,size);
            delete[] A;
        }
        else if (datatype == "string")
        {
            string*A = new string[size];
            array_data(A,size);
            delete[] A;
        }
        else
        {
            cout << "Invalid data type\n";
        }
        cout << "Do you want to continue? (y/n): ";
        cin >> ch;
    }
    if(ch == 'n')
    {
        cout << "Goodbye!\n";
    }
    else if (ch != 'y' && ch != 'n')
    {
        cout << "Invalid input\n";
    }
    return 0;
}
