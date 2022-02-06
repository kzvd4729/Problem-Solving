/****************************************************************************************
*  @author: kzvd4729                                         created: May/15/2017 21:46                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 717 ms                                          memory_used: 3300 KB                              
*  problem: https://codeforces.com/contest/808/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define long long long int
double arr[200005],qm[200005],sum,num,ans;
long i,n,k;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>k;
    for(i=1;i<=n;i++)
    {
        cin>>arr[i];
    }
    qm[1]=arr[1];
    for(i=2;i<=n;i++)
    {
        qm[i]=qm[i-1]+arr[i];
    }
    for(i=k;i<=n;i++)
    {
        num=qm[i]-qm[i-k];
        ///avg=(double)(num/(double)k);
        sum=sum+num;
    }
    ans=sum/(n-k+1);
    cout<<setprecision(10)<<fixed<<ans<<endl;
    return 0;
}