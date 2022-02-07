/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-01-25 22:08:56                      
*  solution_verdict: Wrong answer                            language: C++                                     
*  run_time:                                                 memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-10656
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long n,arr[1003],now;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    while(cin>>n)
    {
        if(n==0)break;
        for(long i=1;i<=n;i++)
        {
            cin>>arr[i];
        }
        while(true)
        {
            if(arr[n]==0)n--;
            else break;
        }
        now=1;
        while(true)
        {
            if(arr[now]==0)now++;
            else break;
        }
        if(now>n)cout<<0<<endl;
        else
        {
            for(long i=now;i<=n;i++)
            {
                cout<<arr[i];
                if(i==n)cout<<endl;
                else cout<<" ";
            }
        }
    }
    return 0;
}