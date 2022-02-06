/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/07/2018 23:40                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 904 ms                                          memory_used: 29500 KB                             
*  problem: https://codeforces.com/contest/922/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
map<pair<pair<int,int>,int>,int>mp;
int n,ans,arr[5];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            int x=i^j;
            arr[1]=i;
            arr[2]=j;
            arr[3]=x;
            sort(arr+1,arr+4);
            if(arr[1]==0)continue;
            if(arr[3]>n)continue;
            if(arr[1]+arr[2]<=arr[3])continue;
            if(mp[{{arr[1],arr[2]},arr[3]}]==0)
                {
                    ans++;
                    mp[{{arr[1],arr[2]},arr[3]}]=1;
                }
        }
    }
    cout<<ans<<endl;
    return 0;
}