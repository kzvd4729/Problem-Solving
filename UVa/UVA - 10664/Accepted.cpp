/****************************************************************************************
*  @author: kzvd4729                                         created: 2017-04-14 18:08:06                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time: 0                                               memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-10664
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
string s;
int l,arr[1000],id,qm;
int dp[1000][1000];
void convert(int i,int j)
{
    int c,k,n,x;
    c=1;
    id=id+1;
    n=0;
    for(k=i;k<=j;k++)
    {
        x=s[k]-'0';
        n=n*c+x;
        c=c*10;
    }
    arr[id]=n;
    return ;
}
int fx(int st,int v)
{
    if(st==id+1)
    {
        if(qm-2*v==0)return 1;
        else return 0;
    }
    if(st>id)return 0;
    if(dp[st][v]!=-1)return dp[st][v];
    return dp[st][v]=fx(st+1,v+arr[st])|fx(st+1,v);
}
int main()
{
    int t,mr,i;
    cin>>t;
    getchar();
    while(t--)
    {
        memset(arr,0,sizeof(arr));
        memset(dp,-1,sizeof(dp));
        getline(cin,s);
        l=s.size();
        id=-1;
        mr=0;
        for(i=0;i<=l;i++)
        {
            if(s[i]==' '||i==l)
            {
                convert(mr,i-1);
                mr=i+1;
            }
        }
        qm=0;
        for(i=0;i<=id;i++)
        {
            qm=qm+arr[i];
        }
        if(fx(0,0)==1)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
        s.clear();
    }
    return 0;
}