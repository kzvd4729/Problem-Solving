/****************************************************************************************
*  @author: kzvd4729                                         created: 2017-02-10 00:11:34                      
*  solution_verdict: Time Limit Exceeded                     language: C++                                     
*  run_time (ms):                                            memory_used (MB):                                 
*  problem: https://vjudge.net/problem/LightOJ-1023
****************************************************************************************/
#include<iostream>
#include<cstring>
using namespace std;
int taken[20],vis[20],cnt;
char c;
void per(int i,int n,int k)
{
    if(cnt==k)return;
    if(i==n)
    {
        cnt++;
        for(int k=0; k<n; k++)
        {
            c=taken[k]+64;
            cout<<c;
        }
        cout<<endl;
        return;
    }
    for(int j=1; j<=n; j++)
    {
        if(!vis[j])
        {
            taken[i]=j;
            vis[j]=1;
            per(i+1,n,k);
            vis[j]=0;

        }
    }


}
int main()
{
    int t,n,k,tc=0;
    while(cin>>t)
    {
        for(tc=1; tc<=t; tc++)
        {
            cin>>n>>k;
            cnt=0;
            memset(vis,0,sizeof(vis));
            cout<<"Case "<<tc<<":"<<endl;
            per(0,n,k);
        }
    }

    return 0;
}