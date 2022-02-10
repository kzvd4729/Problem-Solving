/****************************************************************************************
*  @author: kzvd4729                                         created:                                          
*  solution_verdict: Accepted                                language: C++                                     
*  run_time: 11 ms                                           memory_used: 656 KB                               
*  problem: 
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long a,b,ans,mx=-1;
long check(long x)
{
    long cnt=0,r;
    while(x)
    {
        r=x%10;
        x/=10;
        if(r==0||r==6||r==9)cnt++;
        if(r==8)cnt+=2;
    }
    return cnt;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>a>>b;
    for(long i=a;i<=b;i++)
    {
        if(check(i)>mx)
        {
            mx=check(i);
            ans=i;
        }
    }
    ///cout<<mx<<endl;
    cout<<ans<<endl;
    return 0;
}