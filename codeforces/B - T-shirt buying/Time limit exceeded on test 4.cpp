/****************************************************************************************
*  @author: kzvd4729#                                        created: May/12/2017 01:30                        
*  solution_verdict: Time limit exceeded on test 4           language: GNU C++14                               
*  run_time: 3000 ms                                         memory_used: 6300 KB                              
*  problem: https://codeforces.com/contest/799/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
long long int n,i,vis[200002],m,x;
struct st
{
    long long int p;
    long long int a;
    long long int b;
    }arr[200002];
bool cmp(st A,st B)
{
    return A.p<B.p;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>arr[i].p;
    }
    for(i=1;i<=n;i++)
    {
        cin>>arr[i].a;
    }
    for(i=1;i<=n;i++)
    {
        cin>>arr[i].b;
    }
    sort(arr+1,arr+n+1,cmp);
    cin>>m;
    long long int one=0,two=0,three=0;
    for(i=1;i<=m;i++)
    {
        cin>>x;
        int f=0;
        if(x==1)
        {
            for(i=one+1;i<=n;i++)
            {
                if((arr[i].a==1||arr[i].b==1)&&vis[i]==0)
                {
                    cout<<arr[i].p<<endl;
                    f=1;
                    one=i;
                    vis[i]=1;
                    break;
                }
            }
        }
                if(x==2)
        {
            for(i=two+1;i<=n;i++)
            {
                if((arr[i].a==2||arr[i].b==2)&&vis[i]==0)
                {
                    cout<<arr[i].p<<endl;
                    f=1;
                    two=i;
                    vis[i]=1;
                    break;
                }
            }
        }
                if(x==3)
        {
            for(i=three+1;i<=n;i++)
            {
                if((arr[i].a==3||arr[i].b==3)&&vis[i]==0)
                {
                    cout<<arr[i].p<<endl;
                    f=1;
                    three=i;
                    vis[i]=1;
                    break;
                }
            }
        }
        if(f==0)cout<<-1<<endl;
    }
        return 0;
}