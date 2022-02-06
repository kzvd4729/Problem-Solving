/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/08/2018 01:03                        
*  solution_verdict: Wrong answer on pretest 4               language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 5000 KB                              
*  problem: https://codeforces.com/contest/922/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long n;
string k;
struct data
{
    string s;
    long cnt;
}arr[100005];
bool cmp(data A,data B)
{
    return A.cnt>B.cnt;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     cin>>n;
    for(long i=1;i<=n;i++)
    {
        cin>>arr[i].s;
        string tmp=arr[i].s;
        long hh=0,ss=0;
        for(long j=tmp.size()-1;j>=0;j--)
        {
            if(tmp[j]=='h')
            {
                arr[i].cnt-=ss;
                hh++;
            }
            else
            {
                arr[i].cnt+=hh;
                ss++;
            }
        }
        if(arr[i].cnt==0)
        {
            if(tmp[0]=='s')arr[i].cnt=999999999;
            else arr[i].cnt=-999999999;
        }
     }
    sort(arr+1,arr+n+1,cmp);
    for(long i=1;i<=n;i++)k+=arr[i].s;
    long cnt=0,ans=0;
    for(int i=k.size()-1;i>=0;i--)
    {
        if(k[i]=='h')cnt++;
        else ans+=cnt;
    }
    cout<<ans<<endl;
    return 0;
}