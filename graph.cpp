#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <list>

using namespace std;

struct SparseMatrix {
    int row;
    int col;
    int value;
} sparse_matrix[100];

int** create_2d_array(const int rows, const int cols)
{
    int** c = new int*[rows];
    for (int i = 0; i < rows; ++i) {
        c[i] = new int[cols];
    }
    return c;
}

// 1. create a graph
// array to store the edges of the graph
int Edges[100];
// function to insert edges in the graph
template <typename T>
void insert_Edge(int n)
{
    cout << "Enter the edges : \n";
    for (int i = 0; i<n; i++)
    {
        cout<<i+1<<" edge = ";
        cin >> Edges[i];
    }
}

// function to insert vertices in the graph
int** insert_Vertex(int n)
{
    int** Vertices = create_2d_array(n, n);
    cout << "Valid choices are weighted and unweighted\n";
    string choice;
    cout << "Enter your choice: ";
    cin >> choice;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            Vertices[i][j] = 0;
        }
    }
    if (choice == "weighted")
    {
        cout << "Valid choices are directed and undirected\n";
        string choice1;
        cout << "Enter your choice: ";
        cin >> choice1;
        if (choice1 == "directed")
        {
            for(int i = 0; i < n ; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if(i == j)
                    {
                        Vertices[i][j] = 0;
                    }
                    else
                    {
                        cout << "Enter the weight of the edge between " << Edges[i] << " and " << Edges[j] << " : ";
                        cin >> Vertices[i][j];
                    }
                }
            } 
        }
        if(choice1 == "undirected")
        {
            for(int i = 0; i < n ; i++)
            {
                for (int j = i; j < n; j++)
                {
                    if(i == j)
                    {
                        Vertices[i][j] = 0;
                    }
                    else
                    {
                        cout << "Enter the weight of the edge between " << Edges[i] << " and " << Edges[j] << " : ";
                        cin >> Vertices[i][j];
                        Vertices[j][i] = Vertices[i][j];
                    }
                }
            } 
        }
    }
    if (choice == "unweighted")
    {
        cout << "Valid choices are directed and undirected\n";
        string choice1;
        cout << "Enter your choice: ";
        cin >> choice1;
        cout<<"data will be entered in 0 and 1";
        if (choice1 == "directed")
        {
            for(int i = 0; i < n ; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if(i == j)
                    {
                        Vertices[i][j] = 0;
                    }
                    else
                    {
                        cin>>Vertices[i][j] ;
                    }
                }
            } 
        }
        if (choice1 == "undirected")
        {
            for(int i = 0; i < n ; i++)
            {
                for (int j = i; j < n; j++)
                {
                    if(i == j)
                    {
                        Vertices[i][j] = 0;
                    }
                    else
                    {
                        cout<<"enter the data at [ " <<i <<" ] ["<<j<<"] = ";
                        cin>>Vertices[i][j] ;
                        Vertices[j][i] = Vertices[i][j];
                    }
                }
            } 
        }
    }
    return Vertices;
}

int main()
{
    cout<<"simple graph \n";
    cout << "Enter the number of vertices: ";
    int n;
    cin >> n;
    insert_Edge<int>(n);
    int** Vertices = insert_Vertex(n);
    cout << "The graph is: \n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << Edges[i] << " and " << Edges[j] << " = " << Vertices[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
