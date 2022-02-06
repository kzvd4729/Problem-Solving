/****************************************************************************************
*  @author: kzvd4729                                         created: Jun/01/2018 22:45                        
*  solution_verdict: Accepted                                language: GNU C++17                               
*  run_time: 31 ms                                           memory_used: 3400 KB                              
*  problem: https://codeforces.com/contest/988/problem/B
****************************************************************************************/
#include <bits/stdc++.h>
using namespace std;
 vector <string> v,v1;
bool compare(string a,string b)
{
    if(a.size()>b.size()) return false;
    if(a.size()<b.size()) return true;
    return a<b;
     return true;
}
int main()
{
    int n;
    cin  >> n;
    string t;
    for(int i=1;i<=n;i++)
    {
        cin >> t;
        v.push_back(t);
    }
    sort(v.begin(),v.end(),compare);
     for(int i=1;i<n;i++)
        if(v[i].find(v[i-1])>v[i].size())
    {
         cout << "NO\n";
        return 0;
    }
     cout << "YES\n";
    for(int i=0;i<n;i++)
        cout << v[i] << endl ;
}