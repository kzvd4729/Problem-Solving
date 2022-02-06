/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/21/2017 22:38                        
*  solution_verdict: Wrong answer on test 6                  language: GNU C++14                               
*  run_time: 1246 ms                                         memory_used: 1700 KB                              
*  problem: https://codeforces.com/contest/244/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long vis[11],ans,n;
map<long,long>mp;
void fx(long arr[],long pos)
{
    if(pos>10)return ;
    long sum=0,cnt=0;
    memset(vis,0,sizeof(vis));
    for(long i=pos-1;i>=1;i--)
    {
        sum=sum*10+arr[i];
        vis[arr[i]]=1;
    }
    if(sum>n)return ;
    for(long i=0;i<=9;i++)
    {
        if(vis[i])cnt++;
    }
    if(cnt>3)return ;
    if(cnt<=2&&sum!=0)
    {
        /*for(long i=pos-1;i>=1;i--)
        {
            cout<<arr[i];
        }
        cout<<endl;*/
        if(mp[sum]==0)ans++;
        mp[sum]=1;
    }
    for(long i=0;i<=9;i++)
    {
        arr[pos]=i;
        fx(arr,pos+1);
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     cin>>n;
     long arr[11];
    fx(arr,1);
     cout<<ans<<endl;
     return 0;
}
 