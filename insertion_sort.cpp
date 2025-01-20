// insertion sort 
#include <iostream>
using namespace std;

template <typename T>
void insertion_sort(T A[], int size)
{
    for (int i = 0 ; i < size ; ++i)
    {
        T key = A[i];
        int j = i - 1;
        while(j >= 0 && key < A[j])
        {
            A[j+1] = A[j];
            j = j-1;
            A[j+1] = key;
        }
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
    insertion_sort(A,5);
    cout<<"after sorting \n";
    show(A,5);
    char B[5] = {'z','f','c','j','e'};
    cout<<"before sorting \n";
    show(B,5);
    insertion_sort(B,5);
    cout<<"after sorting \n";
    show(B,5);
    char C[5] = {'A','E','D','C','B'};
    cout<<"before sorting \n";
    show(C,5);
    insertion_sort(C,5);
    cout<<"after sorting \n";
    show(C,5);
    double D[7] = {1.4,2.3,4.6,4.4,4.8,2.5,2.7};
    cout<<"before sorting \n";
    show(D,5);
    insertion_sort(D,5);
    cout<<"after sorting \n";
    show(D,5);
    return 0;
}
