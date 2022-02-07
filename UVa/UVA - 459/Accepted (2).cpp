/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-05-03 15:29:00                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time: 0                                               memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-459
****************************************************************************************/
#include<bits/stdc++.h>

using namespace std;

vector<int>graph[110];
int color[110];

void resetColor(int m)
{
    for(int i=0; i<m; i++)
    {
        color[i]=0;
    }
}

void init(int m)
{
    resetColor(m);
    for(int i=0; i<m; i++)
    {
        graph[i].clear();
    }
}

bool isValidMove(int n)
{
    if(color[n]==0)return true;
    return false;
}

void dfs(int u)
{
    color[u]=1;

    int v;

    for(int i=0; i<graph[u].size(); i++)
    {
        v=graph[u][i];
        if(isValidMove(v))
        {
            dfs(v);
        }
    }
    color[u]=2;
}
int main()
{
    int ks,m;
    char ch[10];

    scanf("%d\n",&ks);

    for(int cas=1; cas<=ks; cas++)
    {

        cin>>ch;
        m=ch[0]-'A'+1;
        gets(ch);

        init(m);

        while(gets(ch)&&strlen(ch))
        {
            graph[ch[0]-'A'].push_back(ch[1]-'A');
            graph[ch[1]-'A'].push_back(ch[0]-'A');
        }
        int ans=0;
        for(int i=0; i<m; i++)
        {
            if(color[i]==0)
            {
               dfs(i);
               ans++;
            }
        }
        if(cas!=1)cout<<endl;
        cout<<ans<<endl;
    }
}
/*

*/