/****************************************************************************************
*  @author: kzvd4729                                         created: 2017-09-11 14:07:15                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time: 0                                               memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-11060
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long ind[102],n,m,now,tc;
priority_queue<long>zero;
map<string,long>mp;
vector<long>adj[102];
vector<string>ans;
string qw[102];
void mem(void)
{
    for(long i=1;i<=100;i++)
    {
        ind[i]=0;
        adj[i].clear();
    }
    mp.clear();
    ans.clear();
    while(zero.size())zero.pop();
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    while(cin>>n)
    {
        mem();

        for(long i=1; i<=n; i++)
        {
            string s;
            cin>>s;
            qw[i]=s;
            mp[s]=i;
        }

        cin>>m;
        while(m--)
        {
            string s,ss;
            cin>>s>>ss;
            adj[mp[s]].push_back(mp[ss]);
            ind[mp[ss]]++;
        }

        for(long i=1; i<=n; i++)
        {
            if(ind[i]==0)zero.push(-i);
        }
        while(zero.size())
        {
            now=-zero.top();
            zero.pop();
            ans.push_back(qw[now]);
            for(long i=0; i<adj[now].size(); i++)
            {
                long xx=adj[now][i];
                ind[xx]--;
                if(ind[xx]==0)zero.push(-xx);
            }
        }
        cout<<"Case #"<<++tc<<": Dilbert should drink beverages in this order:";
        for(long i=0;i<ans.size();i++)
        {
            cout<<" "<<ans[i];
        }
        cout<<"."<<endl;
        cout<<endl;
    }
    return 0;

}