/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/15/2018 20:53                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 764 ms                                          memory_used: 95800 KB                             
*  problem: https://codeforces.com/contest/932/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long sm,arr[1000006],fr[1000006][11],q,l,r,k;
long get(long x)
{
    long sum=1,r;
    while(x)
    {
        r=x%10;
        x/=10;
        if(r)sum*=r;
    }
    return sum;
}
void precal(void)
{
    for(long i=1;i<=1000000;i++)
    {
        sm=i;
        while(true)
        {
            if(arr[sm])
            {
                arr[i]=arr[sm];
                break;
            }
            if(sm<10)
            {
                arr[i]=sm;
                break;
            }
            sm=get(sm);
        }
    }
//    for(long i=1;i<=20;i++)cout<<arr[i]<<" ";
//    cout<<endl;
     for(long i=1;i<=1000000;i++)
    {
        for(long j=1;j<=9;j++)fr[i][j]=fr[i-1][j];
        fr[i][arr[i]]++;
    }
 }
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
     precal();
     cin>>q;
    while(q--)
    {
        cin>>l>>r>>k;
        cout<<fr[r][k]-fr[l-1][k]<<endl;
    }
     return 0;
}