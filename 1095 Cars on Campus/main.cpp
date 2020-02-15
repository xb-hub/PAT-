#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>
using namespace std;

struct Car
{
    string id;
    int time;
    int status;
};

struct Time
{
    int in;
    int out;
};

bool cmp(Car c1, Car c2)
{
    return c1.id == c2.id ? c1.time < c2.time : c1.id < c2.id;
}

int main()
{
    int n, k, hour, minute, second;
    string status;
    cin >> n >> k;
    vector<Car> record(n);
    vector<Time> r;
    unordered_map<int, vector<string>> id;
    unordered_map<string, int> car_time;
    for(int i = 0; i < n; i++)
    {
        cin >> record[i].id;
        scanf("%d:%d:%d", &hour, &minute, &second);
        record[i].time = hour * 60 * 60 + minute * 60 + second;
        cin >> status;
        status == "out" ? record[i].status = 0 : record[i].status = 1;
    }
    sort(record.begin(), record.end(), cmp);
    int max_time = 0;
    for(int i = 1; i < record.size(); i++)
    {
        if(record[i].id == record[i - 1].id && record[i].status == 0 && record[i - 1].status == 1)
        {
            r.push_back({record[i - 1].time, record[i].time});
            car_time[record[i].id] += (record[i].time - record[i - 1].time);
            if(car_time[record[i].id] >= max_time)
            {
                max_time = car_time[record[i].id];
                id[max_time].push_back(record[i].id);
            }
        }
    }
    // for(auto it : r)
    // {
    //     for(int i = 0; i < it.second.size(); i++)
    //     {
    //         cout << it.first << " " << it.second[i].in << " " << it.second[i].out << endl;
    //     }
    // }
    for(int i = 0; i < k; i++)
    {
        int count = 0;
        scanf("%d:%d:%d", &hour, &minute, &second);
        int tmp = hour * 60 * 60 + minute * 60 + second;
        for(int i = 0; i < r.size(); i++)
        {
            if(r[i].in <= tmp && r[i].out > tmp)
            {
                count++;
            }
            // cout << it.first << " " << it.second[i].in << " " << tmp << " " << it.second[i].out << endl;
        }
        printf("%d\n", count);
    }
    // for(auto it : car_time)
    // {
    //     if(it.second == max_time)
    //     {
    //         printf("%s ", it.first.c_str());
    //     }
    // }
    for(int i = 0; i < id[max_time].size(); i++)
    {
        printf("%s ", id[max_time][i].c_str());
    }
    printf("%02d:%02d:%02d\n", max_time / 3600, (max_time % 3600) / 60, max_time % 60);
}