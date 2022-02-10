/****************************************************************************************
*  @author: kzvd4729                                         created:                                          
*  solution_verdict: Accepted                                language: C++                                     
*  run_time: 281 ms                                          memory_used: 22 MB                                
*  problem: 
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long mat[505][505],ans[505][505],n,m,xx,yy,ii,jj;
long dr[]= {-1,-1,0,1,1,1,0,-1};
long dc[]= {0,1,1,1,0,-1,-1,-1};
vector<long>v;
map<long,pair<long,long>>mp;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(long i=1; i<=n; i++)
    {
        for(long j=1; j<=m; j++)
        {
            cin>>mat[i][j];
            v.push_back(mat[i][j]);
            mp[mat[i][j]]= {i,j};
            ans[i][j]=1;
        }
    }
    sort(v.begin(),v.end());
    reverse(v.begin(),v.end());
    for(auto x:v)
    {
        xx=mp[x].first;
        yy=mp[x].second;
        long mx=x,xxx,yyy;
        for(int i=0; i<8; i++)
        {
            xxx=xx+dr[i];
            yyy=yy+dc[i];
            if(xxx<1||xxx>n||yyy<1||yyy>m)continue;
            if(mat[xxx][yyy]<mx)
            {
                mx=mat[xxx][yyy];
                ii=xxx;
                jj=yyy;
            }
        }
        if(mx!=x)
        {
            ans[ii][jj]+=ans[xx][yy];
            ans[xx][yy]=0;
        }
        ///cout<<x<<" "<<mx<<endl;
    }
    for(long i=1; i<=n; i++)
    {
        for(long j=1; j<=m; j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}