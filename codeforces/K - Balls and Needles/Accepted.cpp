/****************************************************************************************
*  @author: JU_AAA: prdx9_abir, aniks2645, kzvd4729#         created: Sep/20/2017 19:58                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 451 ms                                          memory_used: 33500 KB                             
*  problem: https://codeforces.com/gym/101174/problem/K
****************************************************************************************/
/*
 ___________________________________________
|      __                                   |
|     /  \     |\   |   |  |  /             |
|    /____\    | \  |   |  |_/              |
|   /      \   |  \ |   |  | \              |
|  /        \  |   \|   |  |  \             |
|                                           |
|  IIT-45th Batch, Jahangirnagar University.|
|___________________________________________|
/*******************************************/
 #include<bits/stdc++.h>
 using namespace std;
 #define    pf               printf
#define    PF(a)            printf("%d\n",(a))
#define    get(a)           cin>>a
#define    sf               scanf
#define    SF(a)            scanf("%d",&a)
#define    gl(a)            getline(cin,(a))
#define    gc()             getchar()
#define    pb               push_back
#define    m_p              make_pair
#define    pc()             printf("Case %d: ",tt++)
#define    tc()             cout<<"Case "<<tt++<<": "
#define    SZ(a)            (int)(a).size()
#define    FF               first
#define    SS               second
#define    MAX              12345678910
#define    MOD              1000000007
#define    MM               100005
#define    PI               2*acos(0.0)
#define    cond(n,m)        (xx>=0 && xx<(n) && yy>=0 && yy<(m))
 #define    mem(a)           memset((a),0,sizeof (a))
#define    SET(a)           memset((a),-1,sizeof (a))
#define    output           freopen("output.txt","w",stdout);
#define    input            freopen("input.txt","r",stdin);
#define    I_O              ios_base::sync_with_stdio(0); cin.tie(0)
#define    rep(a)           for(int i=0;i<(a);i++)
#define    FOR(a,b)         for(int i=(a);i<(b);i++)
#define    REP(a)           for(int j=0;j<(a);j++)
#define    rev(a)           for(int i=(a);i>=0;i--)
 int dx[]  = {0, 0, 1, -1};
int dy[]  = {1, -1, 0, 0};
int dx8[] = {0, 0, 1, 1, 1, -1, -1, -1};
int dy8[] = {1, -1, -1, 0, 1, -1, 0, 1};
 typedef long long ll;
typedef priority_queue < int > PQ;
typedef pair < int , int > pi;
typedef vector < int > vi;
typedef pair < int, pi > pii;
int res = 0;
 map < pii, vector < pii > > adj;
map < pii , bool> vis;
 void dfs( pii s , pii p)
{
        //cout<<s.first<<" "<<s.second.first<<" "<<s.second.second<<endl;
    if(vis[s]==true || res)
    {
        res = 1;
        return;
    }
    vis[s] = true;
    int sz= SZ(adj[s]);
    pii d;
    rep(sz)
    {
        d = adj[s][i];
        if(d!=p)
        {
            dfs(d,s);
        }
    }
}
map < pi, vector < pi > > adj2;
map < pi , bool> vis2;
map < pi, map< pi, bool > > check;
 void dfs( pi s , pi p)
{
    //cout<<s.first<<" "<<s.second<<endl;
    if(vis2[s]==true || res)
    {
        res = 1;
        return;
    }
    vis2[s] = true;
    int sz= SZ(adj2[s]);
    pi d;
    rep(sz)
    {
        d = adj2[s][i];
        if(d!=p && d!=s)
        {
            dfs(d,s);
        }
    }
}
   int main() {
     I_O;
    int n,a,b,c,d,e,f;
    pii p,q;
    pi p1,q1;
    vector < pii > v;
    vector < pi > v1;
    cin>>n;
    rep(n)
    {
        cin>>a>>b>>c>>d>>e>>f;
        p = m_p(a,m_p(b,c));
        q = m_p(d,m_p(e,f));
        adj[p].pb(q);
        adj[q].pb(p);
        v.pb(p);
        v.pb(q);
        p1 = m_p(a,b);
        q1 = m_p(d,e);
        if(check[p1][q1])continue;
        adj2[p1].pb(q1);
        adj2[q1].pb(p1);
        v1.pb(p1);
        v1.pb(q1);
        check[p1][q1] = check[q1][p1] = 1;
    }
    int sz = SZ(v);
    rep(sz)
    {
        if(vis[v[i]]==0)
        {
            res = 0;
            dfs(v[i],m_p(-1,m_p(-1,-1)));
            if(res){cout<<"True closed chains"<<endl;break;}
        }
    }
    if(res==0)cout<<"No true closed chains"<<endl;
    sz = SZ(v1);
    rep(sz)
    {
        if(vis2[v1[i]]==0)
        {
            res = 0;
            dfs(v1[i],m_p(-1,-1));
            if(res){cout<<"Floor closed chains"<<endl;break;}
        }
    }
    if(res==0)cout<<"No floor closed chains"<<endl;
      return 0;
}
 /*
2
1 2 3 4 5 6
4 5 6 7 8 9
 */