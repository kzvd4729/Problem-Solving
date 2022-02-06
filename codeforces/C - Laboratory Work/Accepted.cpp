/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/04/2018 22:44                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 78 ms                                           memory_used: 2600 KB                              
*  problem: https://codeforces.com/contest/931/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long inf=1e14;
long n,arr[100005],mn=inf,mx=-inf,one,two,thr,sum,c1=inf,c2=inf,c3=inf,ans=inf,mth,sm,lo,md,hi,smm;
map<long,long>mp;
void extra(void)
{
    for(long i=0;i<=n;i++)
    {
        if(i*mn+(n-i)*mx==sum)
        {
            mth=min(mp[mn],i)+min(mp[mx],n-i);
            if(mth<ans)
            {
                ans=mth;
                c1=i;
                c2=n-i;
            }
        }
    }
    cout<<ans<<endl;
    while(c1--)cout<<mn<<" ";
    while(c2--)cout<<mx<<" ";
    cout<<endl;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
     cin>>n;
    for(long i=1;i<=n;i++)
    {
        cin>>arr[i];
        sum+=arr[i];
        mp[arr[i]]++;
        mn=min(mn,arr[i]);
        mx=max(mx,arr[i]);
    }
    if(mn==mx)
    {
        cout<<n<<endl;
        for(long i=1;i<=n;i++)cout<<arr[i]<<" ";
        cout<<endl;
        return 0;
    }
    if(mn+1==mx)
    {
        extra();
        return 0;
    }
    one=mn;
    two=mn+1;
    thr=mx;
     for(long i=0;i<=n;i++)
    {
        sm=one*i;
        lo=0;
        hi=n-i;
        while(hi-lo>3)
        {
            smm=sm;
            md=(lo+hi)/2;
            smm+=md*two;
            smm+=(n-md-i)*thr;
             if(smm>sum)lo=md;
            else hi=md;
          }
        for(long j=lo;j<=hi;j++)
        {
            smm=sm;
            smm+=(two*j);
            smm+=(n-j-i)*thr;
            if(smm==sum)
            {
                mth=min(mp[one],i)+min(mp[two],j)+min(mp[thr],n-j-i);
                if(mth<ans)
                {
                    ans=mth;
                    c1=i;
                    c2=j;
                    c3=n-i-j;
                }
            }
        }
    }
    cout<<ans<<endl;
    while(c1--)cout<<one<<" ";
    while(c2--)cout<<two<<" ";
    while(c3--)cout<<thr<<" ";
    cout<<endl;
    return 0;
}