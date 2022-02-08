/****************************************************************************************
*  @author: kzvd4729                                         created: 2017-08-20 18:10:25                      
*  solution_verdict: RE                                      language: C++14 (GCC 5.4.1)                       
*  run_time: 99 ms                                           memory_used: 256 KB                               
*  problem: https://atcoder.jp/contests/arc081/tasks/arc081_a
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
#define N 100005
using namespace std;
long arr[N],fr[N],n;
vector<long>v;
int main()
{
    ///ofstream cout("out.txt");
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(long i=1;i<=n;i++)
    {
        cin>>arr[i];
        fr[arr[i]]++;
        if(fr[arr[i]]==2)
        {
            v.push_back(arr[i]);
            fr[arr[i]]=0;
        }
    }
    sort(v.begin(),v.end());
    if(v.size()<2)
    {
        cout<<0<<endl;
    }
    else
    {
        cout<<v[v.size()-1]*v[v.size()-2]<<endl;
    }
    return 0;
}