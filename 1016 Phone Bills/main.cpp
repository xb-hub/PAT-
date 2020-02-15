#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

struct Customer
{
    string name;
    int month, day, hour, mintue, time;
    string stauts;
};

bool cmp(Customer c1, Customer c2)
{
    return c1.name != c2.name ? c1.name < c2.name : c1.time < c2.time; 
}

double comput(Customer c, vector<int> cost)
{
    double total = c.day * 60 * cost[24] + c.mintue * cost[c.hour];
    for(int i = 0; i < c.hour; i++)
    {
        total += cost[i] * 60;
    }
    return total;
}

int main()
{
    int n;
    string name, stauts;
    int month, day, hour, mintue;
    vector<int> cost(25, 0);
    vector<Customer> customer;
    map<string, vector<Customer>> record;
    for(int i = 0; i < 24; i++)
    {
        cin >> cost[i];
        cost[24] += cost[i];
    }
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> name;
        scanf("%d:%d:%d:%d", &month, &day, &hour, &mintue);
        cin >> stauts;
        int time = day * 24 * 60 + hour * 60 + mintue;
        customer.push_back({name, month, day, hour, mintue, time, stauts});
    }
    sort(customer.begin(), customer.end(), cmp);
    for(int i = 1; i < customer.size(); i++)
    {
        if(customer[i].name == customer[i - 1].name && customer[i].stauts == "off-line" && customer[i - 1].stauts == "on-line")
        {
            record[customer[i - 1].name].push_back(customer[i - 1]);
            record[customer[i].name].push_back(customer[i]);
        }
    }
    for(auto it = record.begin(); it != record.end(); it++)
    {
        cout << it->first << " ";
        printf("%02d\n", it->second[0].month);
        double sum = 0;
        for(int i = 1; i < it->second.size(); i += 2)
        {
                double total = 0;
                total = comput(it->second[i], cost) - comput(it->second[i - 1], cost);
                printf("%02d:%02d:%02d %02d:%02d:%02d %d $%.2f\n",it->second[i - 1].day, it->second[i - 1].hour, it->second[i - 1].mintue, 
                        it->second[i].day, it->second[i].hour, it->second[i].mintue, it->second[i].time - it->second[i - 1].time, total / 100);
                sum += total;
            }
        printf("Total amount: $%.2f\n", sum / 100);
    }
}