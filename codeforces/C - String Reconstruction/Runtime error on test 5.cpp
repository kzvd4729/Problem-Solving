/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/12/2017 19:21                        
*  solution_verdict: Runtime error on test 5                 language: GNU C++14                               
*  run_time: 311 ms                                          memory_used: 55200 KB                             
*  problem: https://codeforces.com/contest/828/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
vector<string>v[1000006];
vector<int>vv;
string s;
char ans[1000006];
int n,p,mark[1000006],vis[1000006],i,k;
void mem(void)
{
    for(i=1;i<=1000003;i++)
    {
        ans[i]='.';
        v[i].push_back("");
    }
}
int main()
{
    mem();
    cin>>n;
    while(n--)
    {
        cin>>s;
        cin>>k;
        while(k--)
        {
            cin>>p;
            vis[p]=1;
            if(s.size()>v[p][0].size())v[p][0]=s;
        }
    }
     for(i=1;i<=1000003;i++)if(vis[i]==1)vv.push_back(i);
     /*for(auto z:vv)
    {
        cout<<z<<" "<<v[z][0]<<endl;
    }*/
     int id,jd,mx=0,wg;
    for(auto p:vv)
    {
        id=mark[p];
        jd=mark[p]+p;
        wg=p+v[p][0].size()-1;
        mx=max(mx,wg);
        while(true)
        {
            if(id>=v[p][0].size())break;
            ans[jd]=v[p][0][id];
            mark[jd]=wg-jd+1;
            id++;
            jd++;
         }
     }
    for(i=1;i<=mx;i++)
    {
        if(ans[i]=='.')ans[i]='a';
        cout<<ans[i];
    }
    cout<<endl;
     return 0;
}