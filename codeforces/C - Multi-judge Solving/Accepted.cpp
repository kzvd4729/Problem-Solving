/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/16/2017 22:30                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 2700 KB                              
*  problem: https://codeforces.com/contest/825/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
long long int n,k,arr[100004],ans,i,b;
int main()
{
    cin>>n>>k;
    for(i=1;i<=n;i++)
    {
        cin>>arr[i];
    }
    sort(arr+1,arr+n+1);
     b=k;
     for(i=1;i<=n;i++)
    {
        while(true)
        {
            if(arr[i]>b*2)
            {
                b=b*2;
                ans++;
            }
            else
            {
                b=max(b,arr[i]);
                break;
            }
        }
     }
    cout<<ans<<endl;
    return 0;
}