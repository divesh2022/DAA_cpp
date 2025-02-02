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

template <typename T>
void array_data(T A[], int size)
{
    for (int i = 0; i<size; i++)
    {
        cout<<"enter data at index "<<i<<" : ";
        cin>>A[i];
    }
    cout<<"Before sorting :\n";
    show(A,size);
    quick_sort(A,0,size-1);// code // enter the sorting function
    cout<<"After sorting :\n";
    show(A,size);
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
