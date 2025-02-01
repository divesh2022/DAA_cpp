# include <iostream>
using namespace std;

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
    // code // enter the sorting function
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
