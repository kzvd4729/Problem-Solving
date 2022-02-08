/****************************************************************************************
*  @author: kzvd4729                                         created: 22-10-2017 21:48:33                      
*  solution_verdict: Accepted                                language: C++14                                   
*  run_time: 0.00 sec                                        memory_used: 15.7M                                
*  problem: https://www.codechef.com/COOK87/problems/CK87MEDI
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long t,arr[102],n,k;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        for(long i=1;i<=n;i++)
        {
            cin>>arr[i];
        }
        sort(arr+1,arr+n+1);
        cout<<arr[(n+k)/2+1]<<endl;
    }
    return 0;
}