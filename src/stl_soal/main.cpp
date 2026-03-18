#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> x(n), c(n);

    for(int i = 0; i < n; i++)
        cin >> x[i];

    for(int i = 0; i < n; i++)
        cin >> c[i];

    vector<pair<int,int>> packages;

    for(int i = 0; i < n; i++)
        packages.push_back({x[i], c[i]});

    sort(packages.begin(), packages.end());

    set<int> taken;
    int count = 0;

    for(auto p : packages)
    {
        if(taken.find(p.second) == taken.end())
        {
            taken.insert(p.second);
            count++;
        }
    }

    cout << count << endl;
}