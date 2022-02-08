/****************************************************************************************
*  @author: kzvd4729                                         created: 06-08-2017 08:02:47                      
*  solution_verdict: Accepted                                language: C++14                                   
*  run_time: 0.27 sec                                        memory_used: 16.5M                                
*  problem: https://www.codechef.com/AUG17/problems/CHEFMOVR
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
long long int t,n,d,arr[100004],sum,f,g,i,x,j,ans;
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n>>d;
        sum=0;
        for(i=1;i<=n;i++)
        {
            cin>>arr[i];
            sum+=arr[i];
        }
        if(sum%n!=0)
        {
            cout<<-1<<endl;
            continue;
        }
        x=sum/n;
        g=0;
        for(i=1;i<=n;i++)
        {
            if(arr[i]!=x)g=1;
        }
        if(g==0)
        {
            cout<<0<<endl;
            continue;
        }
        if(d>n)
        {
            cout<<-1<<endl;
            continue;
        }
        ans=0;
        f=0;
        for(i=n; ;i--)
        {
            if(i==n-d)break;
            for(j=i;j>=1;j=j-d)
            {
                if(j-d<1)break;
                if(arr[j]<x)
                {
                    ans=ans+x-arr[j];
                    arr[j-d]=arr[j-d]-(x-arr[j]);
                    arr[j]=x;
                }
                else
                {
                    ans=ans+arr[j]-x;
                    arr[j-d]=arr[j-d]+arr[j]-x;
                    arr[j]=x;
                }
            }
        }
        for(i=1;i<=n;i++)
        {
            if(arr[i]!=x)f=1;
        }
        if(f==1)
        {
            cout<<-1<<endl;
            continue;
        }
        else cout<<ans<<endl;
    }
    return 0;
}