/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/15/2018 22:45                        
*  solution_verdict: Wrong answer on test 11                 language: GNU C++14                               
*  run_time: 30 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/351/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e3;
int qm1[N+2],qm2[N+2],arr[N+2];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n;cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
        arr[i]=abs(arr[i]);
    }
    vector<int>v;v.push_back(-1000000);
    for(int i=1;i<=n;i++)
    {
        int id=lower_bound(v.begin(),v.end(),arr[i])-v.begin();
        qm1[i]=qm1[i-1]+id-1;
        v.push_back(arr[i]);
        sort(v.begin(),v.end());
    }
    v.clear();v.push_back(-1000000);
    for(int i=n;i>=1;i--)
    {
        int id=lower_bound(v.begin(),v.end(),arr[i])-v.begin();
        qm2[i]=qm2[i+1]+id-1;
        v.push_back(arr[i]);
        sort(v.begin(),v.end());
    }
//    for(int i=1;i<=n;i++)
//    {
//        cout<<qm1[i]<<" ";
//    }
//    cout<<endl;
//    for(int i=1;i<=n;i++)
//    {
//        cout<<qm2[i]<<" ";
//    }
//    cout<<endl;
    int ans=1e9;
    for(int i=0;i<=n;i++)
        ans=min(ans,qm1[i]+qm2[i+1]);
    cout<<ans<<endl;
    return 0;
}