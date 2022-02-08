/****************************************************************************************
*  @author: kzvd4729                                         created: 05-09-2017 22:56:24                      
*  solution_verdict: Wrong Answer                            language: C++14                                   
*  run_time: 0.00 sec                                        memory_used: 0M                                   
*  problem: https://www.codechef.com/SEPT17/problems/FILLMTR
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
#define inf 99999999999999999
using namespace std;
long t,n,q,ans[1000006];
struct data
{
    long rw;
    long cl;
    long vl;
} arr[1000005];
bool cmp(data A,data B)
{
    return A.rw<B.rw;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>t;
    while(t--)
    {
        cin>>n>>q;
        for(long i=1; i<=q; i++)
        {
            long x,y,z;
            cin>>x>>y>>z;
            if(x>y)swap(x,y);
            arr[i].rw=x;
            arr[i].cl=y;
            arr[i].vl=z;
        }
        sort(arr+1,arr+q+1,cmp);
        for(long i=1; i<=1000000; i++)
        {
            ans[i]=inf;
        }
        long f=0;
        for(long i=1; i<=q; i++)
        {
            long x,y,z;
            x=arr[i].rw;
            y=arr[i].cl;
            z=arr[i].vl;
            //cout<<x<<" "<<y<<" "<<z<<endl;
            if(x==y&&z==1)f=1;
            if(ans[x]==inf&&ans[y]==inf)
            {
                if(z==0)
                {
                    ans[x]=0;
                    ans[y]=0;
                }
                else
                {
                    ans[x]=0;
                    ans[y]=1;
                }
            }
            else if(ans[x]==inf&&ans[y]!=inf)
            {
                if(z==0)ans[x]=ans[y];
                else ans[x]=ans[y]-1;
            }
            else if(ans[x]!=inf&&ans[y]==inf)
            {
                if(z==0)ans[y]=ans[x];
                else ans[y]=ans[x]+1;
            }
            else
            {
                if(z==0)
                {
                    if(ans[x]!=ans[y])f=1;
                }
                else
                {
                    if(ans[x]+1!=ans[y])f=1;
                }
            }
        }
        if(f==1)cout<<"no"<<endl;
        else cout<<"yes"<<endl;
    }
    return 0;
}
/*
4
2 2
1 1 0
1 2 1
2 3
1 1 0
1 2 1
2 1 0
3 2
2 2 0
2 3 1
3 3
1 2 1
2 3 1
1 3 1
*/