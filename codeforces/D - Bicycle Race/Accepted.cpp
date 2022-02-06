/****************************************************************************************
*  @author: kzvd4729                                         created: Oct/06/2017 16:28                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 100 KB                               
*  problem: https://codeforces.com/contest/659/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long n;
struct point
{
    long x;
    long y;
}arr[1004];
bool ck1(long p)
{
    if(arr[p].y==arr[p+1].y&&arr[p+1].x==arr[p+2].x&&arr[p].x<arr[p+1].x&&arr[p+1].y<arr[p+2].y)return true;
    return false;
}
bool ck2(long p)
{
    if(arr[p].x==arr[p+1].x&&arr[p+1].y==arr[p+2].y&&arr[p].y>arr[p+1].y&&arr[p+1].x<arr[p+2].x)return true;
    return false;
}
bool ck3(long p)
{
    if(arr[p].y==arr[p+1].y&&arr[p+1].x==arr[p+2].x&&arr[p].x>arr[p+1].x&&arr[p+1].y>arr[p+2].y)return true;
    return false;
}
bool ck4(long p)
{
    if(arr[p].x==arr[p+1].x&&arr[p+1].y==arr[p+2].y&&arr[p].y<arr[p+1].y&&arr[p+1].x>arr[p+2].x)return true;
    return false;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     cin>>n;
    n++;
    for(long i=1; i<=n; i++)cin>>arr[i].x>>arr[i].y;
    long ans=0;
    ///cout<<endl<<endl;
    for(long i=1; i<=n-2; i++)
    {
        if(ck1(i)||ck2(i)||ck3(i)||ck4(i))
        {
            ans++;
            ///cout<<arr[i+1].x<<" "<<arr[i+1].y<<endl;
        }
    }
    cout<<ans<<endl;
    return 0;
}
 