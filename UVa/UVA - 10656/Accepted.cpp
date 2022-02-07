/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-01-25 22:14:40                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time: 0                                               memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-10656
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long n,arr[10003];
vector<long>v;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    while(cin>>n)
    {
        if(n==0)break;
        for(long i=1;i<=n;i++)
        {
            cin>>arr[i];
        }
        v.clear();
        for(long i=1;i<=n;i++)
        {
            if(arr[i])v.push_back(arr[i]);
        }
        if(v.size()==0)cout<<0<<endl;
        else
        {
            for(long i=0;i<v.size();i++)
            {
                cout<<v[i];
                if(i==v.size()-1)cout<<endl;
                else cout<<" ";
            }
        }
    }
    return 0;
}