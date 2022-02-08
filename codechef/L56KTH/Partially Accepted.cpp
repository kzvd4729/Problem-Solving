/****************************************************************************************
*  @author: kzvd4729                                         created: 27-01-2018 22:04:42                      
*  solution_verdict: Partially Accepted                      language: C++14                                   
*  run_time: 2.17 sec                                        memory_used: 19.5M                                
*  problem: https://www.codechef.com/LTIME56/problems/L56KTH
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int n,k,arr[1000008],mn,xxr;
vector<int>v;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
    }
    for(int i=1;i<=n;i++)
    {
        mn=9999999;
        xxr=0;
        for(int j=i;j<=n;j++)
        {
            mn=min(mn,arr[j]);
            xxr=xxr^arr[j];
            v.push_back(mn*xxr);
        }
    }
    sort(v.begin(),v.end());
    cout<<v[k-1]<<endl;
    return 0;
}