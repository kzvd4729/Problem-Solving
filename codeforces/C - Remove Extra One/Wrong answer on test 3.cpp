/****************************************************************************************
*  @author: kzvd4729                                         created: Dec/21/2017 23:50                        
*  solution_verdict: Wrong answer on test 3                  language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 5000 KB                              
*  problem: https://codeforces.com/contest/900/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long n,tmp[100005],bit[100005];
struct data
{
    long vl,id;
}arr[100005];
bool cmp(data A,data B)
{
    if(A.vl==B.vl)return A.id<B.id;
    else return A.vl>B.vl;
}
void upd(long idx)
{
    for( ;idx<=n;idx+=idx&-idx)
    {
        bit[idx]++;
    }
}
long query(long idx)
{
    long sum=0;
    for( ;idx>0;idx-=idx&-idx)
    {
        sum+=bit[idx];
    }
    return sum;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     cin>>n;
    for(long i=1;i<=n;i++)
    {
        cin>>arr[i].vl;
        arr[i].id=i;
    }
     sort(arr+1,arr+n+1,cmp);
     for(long i=1;i<=n;i++)
    {
        tmp[arr[i].id]=query(arr[i].id-1);
        upd(arr[i].id);
    }
//    for(long i=1;i<=n;i++)
//    {
//        cout<<tmp[i]<<" ";
//    }
//    cout<<endl;
     long mx=0,mxcnt=0,cnt=0,ans=9999999999;
    arr[n+1].vl=9999999;
    for(long i=1;i<=n+1;i++)
    {
        if(arr[i].vl>mx)
        {
            if(cnt==mxcnt)ans=min(ans,mx);
            else if(cnt>mxcnt)
            {
                mxcnt=cnt;
                ans=mx;
            }
            mx=arr[i].vl;
            cnt=0;
        }
        if(tmp[i]==1)cnt++;
    }
    long xx=-1;
    for(long i=1;i<=n;i++)
    {
        if(tmp[i]==1)
        {
            cout<<ans<<endl;
            return 0;
        }
        if(tmp[i]>1)xx=arr[i].vl;
    }
     if(xx==-1)cout<<arr[1].vl<<endl;
    else cout<<xx<<endl;
     return 0;
}