# include <iostream>
using namespace std;

template <typename T>
void MySwap(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}

template <typename T>
void quick_sort(T array[] ,int start , int end)
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
    for (int i = 0 ; i< size;++i)
    {
        cout<<" A [ "<<i<<" ] = "<<A[i]<<endl;
    }
}
int main()
{
    int A[5] = {1,4,6,3,5};
    cout<<"before sorting \n";
    show(A,5);
    quick_sort(A,0,4);
    cout<<"after sorting \n";
    show(A,5);
    char B[5] = {'z','f','c','j','e'};
    cout<<"before sorting \n";
    show(B,5);
    quick_sort(B,0,4);
    cout<<"after sorting \n";
    show(B,5);
    char C[5] = {'A','E','D','C','B'};
    cout<<"before sorting \n";
    show(C,5);
    quick_sort(C,0,4);
    cout<<"after sorting \n";
    show(C,5);
    double D[7] = {1.4,2.3,4.6,4.4,4.8,2.5,2.7};
    cout<<"before sorting \n";
    show(D,5);
    quick_sort(D,0,4);
    cout<<"after sorting \n";
    show(D,5);
    return 0;
}
