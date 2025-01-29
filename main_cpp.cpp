#include <iostream>
#include <string>

using namespace std;

// Main function
int main()
{
    char ch = 'y';
    while (ch == 'y')
    {
        cout << "Valid data types are int, float, double, char, string\n";
        string datatype;
        cout << "Enter data type of the array: ";
        cin >> datatype;
        if (datatype == "int")
        {
            // Code
        }
        else if (datatype == "char")
        {
            // Code
        }
        else if (datatype == "float")
        {
            // Code
        }
        else if (datatype == "double")
        {
            // Code
        }
        else if (datatype == "string")
        {
            // Code
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
    else
    {
        cout << "Invalid input\n";
    }

    return 0;
}
