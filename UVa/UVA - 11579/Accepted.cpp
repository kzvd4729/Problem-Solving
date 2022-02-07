/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-03-07 18:20:41                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time: 160                                             memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-11579
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long t,n;
double arr[100005],ans,s;
double area(double a,double b,double c)
{
    if(a+b<=c)return 0;
    s=(a+b+c)/2.0;
    return sqrt(s*(s-a)*(s-b)*(s-c));
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>t;
    while(t--)
    {
        cin>>n;
        for(long i=1;i<=n;i++)cin>>arr[i];
        sort(arr+1,arr+n+1);
        ans=0;
        for(long i=1;i<=n-2;i++)ans=max(ans,area(arr[i],arr[i+1],arr[i+2]));
        cout<<setprecision(2)<<fixed<<ans<<endl;
    }
    return 0;
}