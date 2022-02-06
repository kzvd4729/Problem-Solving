/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/18/2018 17:45                        
*  solution_verdict: Wrong answer on test 4                  language: GNU C++14                               
*  run_time: 30 ms                                           memory_used: 241500 KB                            
*  problem: https://codeforces.com/contest/159/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long k,vis[200005],oc,x,bit[30][1000006],q,xx;
char ch;
string tmp,s;
vector<long>adj[30];
void upd(long wh,long id)
{
    for( ;id<s.size();id+=id&-id)bit[wh][id]++;
}
long query(long wh,long id)
{
    long sum=0;
    for( ;id>0;id-=id&-id)sum+=bit[wh][id];
    return sum;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     cin>>k>>tmp;
    while(k--)s+=tmp;
    s.push_back('0');
    for(long i=s.size()-1;i>0;i--)s[i]=s[i-1];
     for(long i=1;i<s.size();i++)adj[s[i]-'a'].push_back(i);
     cin>>q;
    while(q--)
    {
        cin>>oc>>ch;
        x=ch-'a';
        xx=oc+query(x,oc);
        upd(x,xx);
        ///cout<<xx<<endl;
        vis[adj[x][xx-1]]=1;
    }
    for(long i=1;i<s.size();i++)if(!vis[i])cout<<s[i];
    cout<<endl;
    return 0;
}