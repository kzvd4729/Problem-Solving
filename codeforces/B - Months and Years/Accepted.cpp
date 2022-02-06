/****************************************************************************************
*  @author: kzvd4729                                         created: Dec/17/2017 13:07                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 30 ms                                           memory_used: 1900 KB                              
*  problem: https://codeforces.com/contest/899/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long mn[]={31,28,31,30,31,30,31,31,30,31,30,31};
long n,arr[100],cnt,f,k;
vector<long>v;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for(long i=0;i<12;i++)v.push_back(mn[i]);
    for(long i=0;i<12;i++)v.push_back(mn[i]);
    for(long i=0;i<12;i++)v.push_back(mn[i]);
    for(long i=0;i<12;i++)v.push_back(mn[i]);
     cin>>n;
    for(long i=0;i<n;i++)
    {
        cin>>arr[i];
        if(arr[i]==29)cnt++;
    }
    if(cnt>1)
    {
        cout<<"NO"<<endl;
        return 0;
    }
    for(long i=0;i<12;i++)
    {
        k=i;
        f=0;
        for(long j=0;j<n;j++)
        {
            if(v[k]!=arr[j])
            {
                if(v[k]==28&&arr[j]==29);
                else f=1;
                ///if(v[k]==30||v[k]==31||arr[j]==30||arr[j]==31)f=1;
            }
            k++;
        }
        if(f==0)
        {
            cout<<"YES"<<endl;
            return 0;
        }
    }
    cout<<"NO"<<endl;
    return 0;
}