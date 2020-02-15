#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Station
{
    double price;
    int distance;
    bool operator< (const Station s) const
    {
        return s.distance == this->distance ? s.price > this->price : s.distance > this->distance;
    }
};


int main()
{
    int c_max, d, d_avg, n;
    cin >> c_max >> d >> d_avg >> n;
    vector<Station> station(n + 2);
    station[0].price = 0;   station[0].distance = 0;
    station[n + 1].price = 0;   station[n + 1].distance = d;
    for(int i = 1; i <= n; i++)
    {
        cin >> station[i].price >> station[i].distance;
    }
    sort(station.begin(), station.end());
    // for(int i = 0; i < n; i++)
    // {
    //     cout << station[i].price << " " << station[i].distance << endl;
    // }
    for(int i = 1; i <= n + 1; i++)
    {
        int tmp = station[i].distance - station[i - 1].distance;
        if(tmp > c_max * d_avg)
        {
            int x = station[i - 1].distance + c_max * d_avg;
            cout << "The maximum travel distance = " << x << endl;
            return;
        }
    }
    
}