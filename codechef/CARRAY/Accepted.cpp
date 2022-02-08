/****************************************************************************************
*  @author: kzvd4729                                         created: 18-02-2018 23:26:45                      
*  solution_verdict: Accepted                                language: C++14                                   
*  run_time: 0.02 sec                                        memory_used: 16.4M                                
*  problem: https://www.codechef.com/COOK91/problems/CARRAY
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long t,n,k,b,tmp[100005],arr[100005],len;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>t;
    while(t--)
    {
        cin>>n>>k>>b;
        for(long i=1;i<=n;i++)cin>>arr[i];
        sort(arr+1,arr+n+1);
        len=0;
        for(long i=1;i<=n;i++)
        {
            if(len==0)tmp[++len]=arr[i];
            else if(arr[i]>=(tmp[len]*k+b))tmp[++len]=arr[i];
        }
        cout<<len<<endl;
    }
    return 0;
}