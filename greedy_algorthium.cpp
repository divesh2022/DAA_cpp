#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Cities {
    string city1;
    string city2;
    float distance;
    int traffic_probablity;
};

int main() {   
    int size;
    cout << "enter no of city connections: ";
    cin >> size;
    
    vector<Cities> city(size);
    for (int i = 0; i< size; i++) {
        cout << i+1 << "th connection" << endl;
        cout << "enter city 1: ";
        cin >> city[i].city1;
        cout << "enter city 2: ";
        cin >> city[i].city2;
        cout << "enter distance: ";
        cin >> city[i].distance;
        cout << "enter traffic probability: ";
        cin >> city[i].traffic_probablity;
    }
    cout<<"Unsorted"<<endl;
    for (int i = 0; i < size; i++) {
        cout << "route " << city[i].city1 << " to " << city[i].city2 << endl;
        cout << "distance: " << city[i].distance << endl;
        cout << "traffic probability: " << city[i].traffic_probablity << endl;
    }
    
    // Sorting based on distance to traffic probability ratio
    cout<<"Sorted based on distance to traffic probability ratio"<<endl;
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (city[i].distance / city[i].traffic_probablity < city[j].distance / city[j].traffic_probablity)
            {
                swap(city[i], city[j]);
            }
        }
    }
    for (int i = 0; i < size; i++) {
        cout << "route " << city[i].city1 << " to " << city[i].city2 << endl;
        cout << "distance: " << city[i].distance << endl;
        cout << "traffic probability: " << city[i].traffic_probablity << endl;
    }
    // GREEDY ALGORITHM
    int mcs;
    cout << "enter maximum no cities : "; 
    cin >> mcs;
    vector<string> knapsnack(mcs);
    float total_distance = 0;
    int total_traffic = 0;
    for(int i = 0; i< size; i++)
    {
     for(int i = 0; i < size; i++)
    {
         if(mcs > 0)
         {
            // add item to knapsnack
            knapsnack[i] = "route " + city[i].city1 + "to" +city[i].city2;
            total_distance = total_distance + city[i].distance;
            total_traffic = total_traffic + city[i].traffic_probablity;
            mcs = mcs -1;
         }
         else
         {
            cout<<"maximum city has been reached";
            break;
         }
     }
    }
    for(int i = 0; i<mcs;++i)
    {
        cout<<knapsnack[i]<<" ";
    }
    cout<<"total distance of journey "<<total_distance;
    cout<<"average traffic probablity "<<total_traffic/sizeof(knapsnack);

    return 0;
}

