/****************************************************************************************
*  @author: kzvd4729                                         created: 2017-08-24 16:10:03                      
*  solution_verdict: Time limit exceeded                     language: C++                                     
*  run_time (ms):                                            memory_used (MB):                                 
*  problem: https://vjudge.net/problem/UVALive-6137
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
string a[55];
int vis[55][55], n, m,res;
int dx[]={0, 0, 1, -1};
int dy[]={1, -1, 0, 0};

void dfs(int x, int y, int k)
{
    vis[x][y]=1;
    bool flg=true;
    int xx,yy;
    for(int i=0;i<4;i++)
    {
        xx = x + dx[i];
        yy = y + dy[i];
        if(xx>=0 && xx<n && yy>=0 && yy<m && vis[xx][yy]==0 && a[xx][yy]=='.')
        {
            dfs(xx,yy,k+1);
            flg=false;
        }
    }
    if(flg==true && k%2==0){
        res=1;
        return;
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    while(cin>>n>>m)
    {
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        bool flg=false;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(a[i][j]=='.')
                {
                    memset(vis, 0, sizeof (vis));
                    res=0;
                    dfs(i,j,1);
                    if(res==0 ){
                        cout<<1<<endl;
                        flg=true;
                        break;
                    }
                }
            }
            if(flg)break;
        }
        if(!flg)
        cout<<2<<endl;
    }
    return 0;
}