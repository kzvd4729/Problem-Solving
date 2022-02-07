/****************************************************************************************
*  @author: kzvd4729                                         created: 2017-12-06 06:07:36                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time: 200                                             memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-524
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long p[]= {0,0,1,1,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,0,0,0,0,1,0,1,0,0,0,0,0,1,0,1,0};
long n,vis[20],tc;
vector<long>v;
void fx(long cnt)
{
    ///cout<<"I am exist"<<endl;
    ///cout<<cnt<<endl;
    /*for(auto x:v)
    {
        cout<<x<<" ";
    }
    cout<<endl;*/
    if(cnt>=n)
    {
        if(p[v.front()+v.back()]==1)
        {
            for(long i=0; i<v.size(); i++)
            {
                if(i!=0)cout<<" ";
                cout<<v[i];
            }
            cout<<endl;
        }
        return ;
    }
    for(long i=2; i<=n; i++)
    {
        if(vis[i]==0&&p[i+v.back()]==1)
        {
            vis[i]=1;
            v.push_back(i);
            fx(cnt+1);
            v.pop_back();
            vis[i]=0;
        }
    }
}
int main()
{
    ///ofstream cout("out.txt");
    /*ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);*/

    while(cin>>n)
    {
        memset(vis,0,sizeof(vis));
        v.clear();

        if(tc)cout<<endl;
        cout<<"Case "<<++tc<<":"<<endl;

        v.push_back(1);
        vis[1]=1;
        fx(1);

    }
    return 0;
}