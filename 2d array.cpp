# include <iostream>
using namespace std;

int** create_2d_array(const int rows, const int cols)
{
    int** c = new int*[rows];
    for (int i = 0; i < rows; ++i) {
        c[i] = new int[cols];
    }
    return c;
}

int main ()
{
    int row, col;
    cout << "Enter the number of rows and columns: ";
    cin >> row >> col;

    int** c = create_2d_array(row, col);
    
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            cin>>c[i][j];
        }
    }
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            cout << c[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
