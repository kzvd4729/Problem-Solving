/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/05/2017 20:29                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 140 ms                                          memory_used: 2700 KB                              
*  problem: https://codeforces.com/gym/101375/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
long long int n,arr[100003],qm,ans,i,j,x;
int main()
{
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>arr[i];
        qm+=arr[i];
    }
    for(i=1;i<=n;i++)
    {
        qm-=arr[i];
        ans+=qm*arr[i];
    }
    cout<<ans<<endl;
    return 0;
}