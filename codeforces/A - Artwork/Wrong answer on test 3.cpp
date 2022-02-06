/****************************************************************************************
*  @author: JU_Quanta: tariqiitju, mh755628, kzvd4729#       created: Oct/09/2019 17:56                        
*  solution_verdict: Wrong answer on test 3                  language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 9200 KB                              
*  problem: https://codeforces.com/gym/101550/problem/A
****************************************************************************************/
#include <bits/stdc++.h>
using namespace std;
#define pf                  printf
#define sc                  scanf
#define pb                  push_back
#define eb                  emplace_back
#define present(c,x)        ((c).find(x) != (c).end())
#define mp                  make_pair
#define xx                  first
#define yy                  second
#define endl                '\n'
#define SZ(v)               ((int) (v).size())
#define all(v)              (v).begin(), (v).end()
typedef long long           ll;
typedef long double         LD;
typedef unsigned long long  ull;
typedef pair<int,int>       pii;
const LD EPS =              1e-9;
const LD PI=                acos(-1.0);
const int MX=               6e5+5;
ll mod=                     1e9+7;
 int cnt[1001][1001];
 int ax[10005],ay[10005],bx[10005],by[10005];
 int dx[]={0,0,-1,1};
int dy[]={1,-1,0,0};
 int n,m;
bool valid(int x,int y){
    return x>=0 and y>=0 and x<n and y<m and cnt[x][y] == 0;
}
bool vis[1001][1001];
int par[1001*1001];
 int fpar(int u){return par[u] = (par[u]==u?u : fpar(par[u]));}
 void dfs(int x,int y,int s){
     vis[x][y] = 1;
    par[x*m+y] = s;
    for(int i=0;i<4;i++){
        int vx = x + dx[i];
        int vy = y + dy[i];
         if(valid(vx,vy) and !vis[vx][vy])dfs(vx,vy,s);
    }
}
 int main()
{
    cin>>m>>n;
    int q;cin>>q;
    for(int l=0;l<q;l++){
        int x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        x1--,y1--,x2--,y2--;
        swap(x1,y1);
        swap(x2,y2);
        ax[l] = x1 , ay[l] = y1;
        bx[l] = x2 , by[l] = y2;
        if(x1==x2){
            for(int j=y1;j<=y2;j++){
                    cnt[x1][j]++;
            }
        }else{
            for(int i=x1;i<=x2;i++){
                cnt[i][y1]++;
            }
        }
    }
     // for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++){
    //         cerr<<cnt[i][j]<<" ";
    //     }
    //     cerr<<endl;
    // }
     int ans = 0;
     //cerr<<cnt[3][0]<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!vis[i][j] and cnt[i][j]==0){
                //cerr<<i<<" "<<j<<"  3 0 "<<vis[3][0]<< endl;
                ans++;
                dfs(i,j,i*m+j);
            }
        }
    }
    //cerr<<ans<<endl;
     vector<int> res;
    for(int l = q-1;l>=0;l--){
        res.pb(ans);
        int x1,y1,x2,y2;
        x1 = ax[l]; y1 = ay[l];
        x2 = bx[l] , y2 = by[l];
        if(x1==x2){
            for(int j=y1;j<=y2;j++){
                cnt[x1][j]--;
                int c = m * x1 + j;
                if(cnt[x1][j]==0){
                    set<int> tmp;
                    par[c] = c;
                    ans++;
                    for(int k=1;k<4;k++){
                        int vx = x1 + dx[k];
                        int vy = j + dy[k];
                        if(valid(vx,vy)){
                            tmp.insert(fpar(m*vx+vy));
                        }
                    }
                    for(int u : tmp){
                        ans--;
                        par[u]=c;
                    }
                 }
            }
        }else{
            for(int i=x1;i<=x2;i++){
                cnt[i][y1]--;
                int c = m * i + y1;
                if(cnt[i][y1]==0){
                    vector<int> tmp;
                    par[c] = c;
                    ans++;
                    for(int k=0;k<3;k++){
                        int vx = i + dx[k];
                        int vy = y1 + dy[k];
                        if(valid(vx,vy)){
                            tmp.pb(fpar(m*vx+vy));
                        }
                    }
                    for(int u : tmp){
                        ans--;
                        par[u]=c;
                    }
                 }
            }
        }
    }
     for(int i=q-1;i>=0;i--)cout<<res[i]<<"\n";cout<<endl;
       return 0;
}
 /**
                     Md. Tariqul Islam
                          IIT,JU
                      fb/tariqiitju
                    tarik.amtoly@gmail.com
*/