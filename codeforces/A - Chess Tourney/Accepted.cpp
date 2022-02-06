/****************************************************************************************
*  @author: kzvd4729#                                        created: Aug/22/2017 18:42                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/845/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
#define N 105
using namespace std;
long arr[N],n;
int main()
{
    ///ofstream cout("out.txt");
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     cin>>n;
    for(long i=1;i<=2*n;i++)cin>>arr[i];
    sort(arr+1,arr+2*n+1);
    if(arr[n]==arr[n+1])
    {
        cout<<"NO"<<endl;
    }
    else cout<<"YES"<<endl;
     return 0;
}