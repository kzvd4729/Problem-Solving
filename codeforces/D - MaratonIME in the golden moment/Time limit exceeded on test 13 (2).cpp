/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/05/2017 20:23                        
*  solution_verdict: Time limit exceeded on test 13          language: GNU C++14                               
*  run_time: 500 ms                                          memory_used: 2700 KB                              
*  problem: https://codeforces.com/gym/101375/problem/D
****************************************************************************************/
#include<iostream>
using namespace std;
long long int n,arr[100003],ans,i,j,x;
int main()
{
    cin>>n;
    for(i=1;i<=n;i++)cin>>arr[i];
    for(i=1;i<=n;i++)
    {
        for(j=i+1;j<=n;j++)
        {
            x=arr[i]*arr[j];
            ans+=x;
        }
    }
    cout<<ans<<endl;
    return 0;
}