/****************************************************************************************
*  @author: kzvd4729                                         created: Oct/16/2017 14:52                        
*  solution_verdict: Wrong answer on test 4                  language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 1600 KB                              
*  problem: https://codeforces.com/gym/101466/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
string t,p;
long len,l1,l2,pi[100005],now,cnt[100005];
void make_prefix(void)
{
    pi[0]=now=-1;
    for(long i=1;i<l2;i++)
    {
        while(p[now+1]!=p[i]&&now!=-1)now=pi[now];
        if(p[now+1]==p[i])pi[i]=++now;
        else pi[i]=now=-1;
    }
}
void make_match(void)
{
    now=-1;
    for(long i=0;i<l1;i++)
    {
        while(p[now+1]!=t[i]&&now!=-1)now=pi[now];
        if(p[now+1]==t[i])cnt[++now]++;
        else now=-1;
    }
    for(long i=l2-1;i>=0;i--)
    {
        cnt[pi[i]]+=cnt[i];
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     cin>>t>>p>>len;
    l1=t.size();
    l2=p.size();
    p.push_back('#');
    make_prefix();
    make_match();
    /*for(long i=0;i<=10;i++)
    {
        cout<<pi[i]<<" ";
    }
    cout<<endl;
    for(long i=0;i<=10;i++)
    {
        cout<<cnt[i]<<" ";
    }
    cout<<endl;*/
     for(long i=l2;i>=0;i--)
    {
        if(cnt[i]>=len)
        {
            for(long j=0;j<=i;j++)
            {
                cout<<p[j];
            }
            cout<<endl;
            return 0;
        }
    }
    cout<<"IMPOSSIBLE"<<endl;
    return 0;
}
 