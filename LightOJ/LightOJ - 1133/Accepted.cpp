/****************************************************************************************
*  @author: kzvd4729                                         created: 2017-05-18 19:53:47                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 12                                         memory_used (MB): 1.7                             
*  problem: https://vjudge.net/problem/LightOJ-1133
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define long long long int
long t,n,m,a[105],x,temp[105],id,y,i,tc;
char c;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        for(i=0;i<n;i++)
        {
            cin>>a[i];
        }
        while(m--)
        {
            cin>>c;
            if(c=='S')
            {
                cin>>x;
                for(i=0;i<n;i++)
                {
                    a[i]=a[i]+x;
                }
            }
            else if(c=='M')
            {
                cin>>x;
                for(i=0;i<n;i++)
                {
                    a[i]=a[i]*x;
                }
            }
            else if(c=='D')
            {
                cin>>x;
                for(i=0;i<n;i++)
                {
                    a[i]=a[i]/x;
                }
            }
            else if(c=='R')
            {
                for(i=0;i<n;i++)
                {
                    temp[i]=a[i];
                }
                id=-1;
                for(i=n-1;i>=0;i--)
                {
                    a[++id]=temp[i];
                }
            }
            else if(c=='P')
            {
                cin>>x>>y;
                swap(a[x],a[y]);
            }
        }
        cout<<"Case "<<++tc<<":"<<endl;
        for(i=0;i<n;i++)
        {
            cout<<a[i];
            if(i!=n-1)cout<<" ";
            else cout<<endl;
        }
    }
    return 0;
}