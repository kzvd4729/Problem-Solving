/****************************************************************************************
*  @author: kzvd4729                                         created: 17-05-2017 14:26:10                      
*  solution_verdict: Accepted                                language: C++14                                   
*  run_time: 0.08 sec                                        memory_used: 4M                                   
*  problem: https://www.codechef.com/MAY17/problems/UNICOURS
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define long long long int
long t,n,a[100005],i,mx;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t;
    while(t--)
    {
        cin>>n;
        mx=0;
        for(i=1;i<=n;i++)
        {
            cin>>a[i];
            if(a[i]>mx)mx=a[i];
        }
        cout<<n-mx<<endl;
    }
    return 0;
}