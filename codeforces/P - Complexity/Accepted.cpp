/****************************************************************************************
*  @author: JU_AAA: prdx9_abir, aniks2645, kzvd4729          created: Sep/15/2017 21:36                        
*  solution_verdict: Accepted                                language: GNU C++11                               
*  run_time: 15 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/gym/100819/problem/P
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
  int a[200];
int main() {
     I_O;
    string s;
    int cnt = 0;
    cin>>s;
    rep(SZ(s))
    {
        if(a[s[i]]==0)cnt++;
        a[s[i]]++;
    }
    priority_queue < int > pq;
    vi v;
    FOR(90,124)
    {
        if(a[i]>0)pq.push(a[i]);
    }
    int res;
    if(cnt>2){
        res = pq.top();
        pq.pop();
        res += pq.top();
        cout<<SZ(s) - res <<endl;
    }
    else cout<<0<<endl;
       return 0;
}
 /*
  */