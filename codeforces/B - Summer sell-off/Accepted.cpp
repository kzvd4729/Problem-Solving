/****************************************************************************************
*  @author: kzvd4729                                         created: May/21/2017 00:49                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 93 ms                                           memory_used: 2400 KB                              
*  problem: https://codeforces.com/contest/810/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long int
using namespace std;
long n,f,x,y,z,ans,i;
struct data
{
    long k;
    long l;
    long dif;
}arr[100005];
bool cmp(data A,data B)
{
    return A.dif>B.dif;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>f;
    for(i=0;i<n;i++)
    {
        cin>>arr[i].k>>arr[i].l;
        x=min((2*arr[i].k),arr[i].l);
        arr[i].dif=x-arr[i].k;
    }
    sort(arr,arr+n,cmp);
    ans=0;
    for(i=0;i<n;i++)
    {
        if(f>0)
        {
            z=min((2*arr[i].k),arr[i].l);
            f--;
        }
        else z=min(arr[i].k,arr[i].l);
        ans=ans+z;
    }
    cout<<ans<<endl;
    return 0;
}