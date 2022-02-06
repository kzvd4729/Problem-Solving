/****************************************************************************************
*  @author: kzvd4729                                         created: Oct/17/2017 21:23                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 296 ms                                          memory_used: 4200 KB                              
*  problem: https://codeforces.com/contest/496/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long arr[100005];
vector<pair<long,long> >v;
long n;
struct data
{
    long one;
    long two;
} cnt[100005];
struct data2
{
    long id;
    long on;
    long tw;
} point;
long search1(long val)
{
    long lo=1,hi=n,mid;
    while(hi-lo>4)
    {
        mid=(lo+hi)/2;
        if(cnt[mid].one<val)lo=mid+1;
        else hi=mid-1;
    }
    for(long i=lo-1; i<=min(n,hi+1); i++)if(cnt[i].one==val)return i;
    return 0;
}
long search2(long val)
{
    long lo=1,hi=n,mid;
    while(hi-lo>4)
    {
        mid=(lo+hi)/2;
        if(cnt[mid].two<val)lo=mid+1;
        else hi=mid-1;
    }
    for(long i=lo-1; i<=min(n,hi+1); i++)if(cnt[i].two==val)return i;
    return 0;
}
long checker(long value)
{
    long val1=value,val2=value,cone=0,ctwo=0;
    while(true)
    {
        long yy=search1(val1);
        long zz=search2(val2);
        /*if(value==2)
        {
            cout<<yy<<" "<<zz<<endl;
        }*/
        if(yy==0&&zz==0)return 0;
        if(yy==n&&zz==0)
        {
            cone++;
            if(cone>ctwo)return cone;
            else return 0;
        }
        if(zz==n&&yy==0)
        {
            ctwo++;
            if(ctwo>cone)return ctwo;
            else return 0;
        }
        if(zz==0)
        {
            cone++;
            val1=cnt[yy].one+value;
            val2=cnt[yy].two+value;
        }
        else if(yy==0)
        {
            ctwo++;
            val1=cnt[zz].one+value;
            val2=cnt[zz].two+value;
        }
        else
        {
            if(yy<zz)
            {
                cone++;
                val1=cnt[yy].one+value;
                val2=cnt[yy].two+value;
            }
            else
            {
                ctwo++;
                val1=cnt[zz].one+value;
                val2=cnt[zz].two+value;
            }
        }
      }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     cin>>n;
    for(long i=1; i<=n; i++)
    {
        cin>>arr[i];
        if(arr[i]==1)
        {
            cnt[i].one=cnt[i-1].one+1;
            cnt[i].two=cnt[i-1].two;
        }
        else
        {
            cnt[i].one=cnt[i-1].one;
            cnt[i].two=cnt[i-1].two+1;
        }
     }
    for(long i=1; i<=n; i++)
    {
        long ans=checker(i);
        if(ans!=0)v.push_back(make_pair(ans,i));
    }
    sort(v.begin(),v.end());
    cout<<v.size()<<endl;
    for(long i=0; i<v.size(); i++)cout<<v[i].first<<" "<<v[i].second<<endl;
    return 0;
}