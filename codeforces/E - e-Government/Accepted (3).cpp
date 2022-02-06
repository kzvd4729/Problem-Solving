/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/03/2018 16:12                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 467 ms                                          memory_used: 208600 KB                            
*  problem: https://codeforces.com/contest/163/problem/E
****************************************************************************************/
/// *********************************************** K
/// B *                                           * H
/// I *    Solved By : Bir Bahadur Khatri(B'ru)   * A
/// R *      Be Positive,be Happy.                * T
/// U *                                           * R
/// *********************************************** I
 #include<bits/stdc++.h>
 #define LL long long int
#define ULL unsigned LL
#define PI 2.0*acos(0.0)
#define D double
#define sz size()
#define PB push_back
#define cp printf("***** here here here here *****\n");
#define NL printf("\n")
#define CHR getchar()
#define SQR(n) (n*n)
#define xx first
#define yy second
#define MEM(a,val) memset(a,val,sizeof(a))
#define Max(a,b) ((a>b)?a:b)
#define Min(a,b) ((a<b)?a:b)
#define _Max(a,b,c) Max(a,Max(b,c))
#define _Min(a,b,c) Min(a,Min(b,c))
#define S1(a) a=in<int>()
#define S2(a,b) a=in<int>(),b=in<int>()
#define S3(a,b,c) a=in<int>(),b=in<int>(),c=in<int>()
#define SL1(a) a=in<LL>()
#define SL2(a,b) a=in<LL>(),b=in<LL>()
#define SL3(a,b,c) a=in<LL>(),b=in<LL>(),c=in<LL>()
#define F(i,a,b) for(int i=a;i<b; i++)
#define R(i,a,b) for(int i=a-1;i>=b; i--)
#define all(a) a.begin(),a.end()
#define BitCnt(a) __builtin_popcountll(a)
#define InpOut freopen("A.in","r",stdin),freopen("A1.out","w",stdout)
#include <time.h>
 using namespace std;
template <typename T> T in(){char ch;T n = 0;bool ng = false;while (1){ch = getchar();if (ch == '-'){ng = true;ch = getchar();break;}if (ch>='0' && ch<='9')     break;}while (1){n = n*10 + (ch - '0');ch = getchar();if (ch<'0' || ch>'9')   break;}return (ng?-n:n);}
template<typename T>inline T Dist(T x1,T y1,T x2, T y2){return sqrt( SQR(x1-x2) + SQR(y1-y2) );}
template<typename T>inline T POW(T B,T P){ if(P==0) return 1; if(P&1) return B*POW(B,P-1);  else return SQR(POW(B,P/2));}
template<typename T>inline T ABS(T a) {if(a<0)return -a;else return a;}
template<typename T>inline T Gcd(T a,T b){if(a<0)return Gcd(-a,b);if(b<0)return Gcd(a,-b);return (b==0)?a:Gcd(b,a%b);}
template<typename T>inline T Lcm(T a,T b) {if(a<0)return Lcm(-a,b);if(b<0)return Lcm(a,-b);return a*(b/Gcd(a,b));}
long long Bigmod(long long base, long long power, long long MOD){long long ret=1;while(power){if(power & 1)ret=(ret*base)%MOD;base=(base*base)%MOD;power>>=1;}return ret;}
long long ModInverse(long long number, long long MOD){return Bigmod(number, MOD-2, MOD);}
int Set(int N,int pos){ return N=N | (1<<pos);}
int Reset(int N,int pos){return N= N & ~(1<<pos);}
bool Chkbit(int N,int pos){return (bool)(N & (1<<pos));}
bool isVowel(char ch){ ch=toupper(ch); if(ch=='A'||ch=='U'||ch=='I'||ch=='O'||ch=='E') return true; return false;}
bool isConst(char ch){if (isalpha(ch) && !isVowel(ch)) return true; return false;}
int toInt(string s)  { int sm; stringstream ss(s); ss>>sm; return sm; }
long long int toLlint(string s) { long long int sm; stringstream ss(s); ss>>sm; return sm;}
 ///**********************************************************//
  ///         0123456789
#define MX  1000097
#define MOD 1000000007
#define INF 100000000
/// ==========================================////
 char s[MX];
 struct Nd
{
    int Fl,Fq,E[28];
    Nd() {
        Fl=Fq=0;
        MEM(E,0);
    }
};
 Nd Tree[MX+100000];
 int Id[MX],avail;
 void In(int id)
{
    int pos=1,r=strlen(s);
    for(int i=0;i<r;i++) {
        if(Tree[pos].E[ s[i]-'a' ]==0) {
            Tree[pos].E[ s[i]-'a' ]=++avail;
            Tree[avail]=Nd();
        }
        pos=Tree[pos].E[ s[i]-'a' ];
    }
    Id[ id ]=pos;
    Tree[pos].Fq=1;
    return;
}
 void Fail()
{
    queue<int> q; q.push(1);
    for(int i=0;i<26;i++) {
        Tree[0].E[ i ]=1;
    }
    Tree[1].Fl=0;
     while(q.sz) {
        int u=q.front(); q.pop();
         for(int i=0;i<26;i++) {
            if(Tree[u].E[i]) {
                Tree[ Tree[u].E[i] ].Fl=Tree[ Tree[u].Fl ].E[ i ];
                q.push( Tree[u].E[i] );
            }
            else {
                Tree[ u ].E[i]=Tree[ Tree[u].Fl ].E[i];
            }
        }
    }
    return;
}
 vector<int> A[MX];
 int St[MX],Ed[MX],Tme;
 int Tre[MX+100];
 void Update( int id ,int v ) { while(id<=MX-1) { Tre[id]+=v; id+=(id&-id); } }
int Query(int id) { int ans=0; while(id>0) { ans+=Tre[id]; id-=(id&-id); } return ans; }
 void Dfs(int u)
{
    St[u]=++Tme;
    for(int i=0;i<A[u].sz;i++) {
        int v=A[u][i];
        Dfs(v);
    }
    Ed[u]=Tme;
    if(Tree[u].Fq) {
        Update( St[u],1 );
        Update( Ed[u]+1,-1 );
    }
    return;
}
 int Ase[MX];
 int QUery1()
{
    int ln=strlen(s);
    int pos=1;
    int ans=0;
    for(int i=1;i<ln;i++) {
        pos=Tree[pos].E[ s[i]-'a' ];
        ans+=Query( St[ pos ] );
    }
    return ans;
}
 int main()
{
    Tree[1]=Nd();
    avail=1;
     int n,m;
    S2(n,m);
    for(int i=1;i<=m;i++) {
        scanf("%s",&s);
        In(i);
        Ase[i]=1;
    }
    Fail();
     for(int i=1;i<=avail;i++) {
        A[ Tree[i].Fl ].PB( i );
    }
    Dfs(1);
    for(int i=1;i<=n;i++) {
        scanf("%s",&s);
        if(s[0]=='?') {
            printf("%d\n",QUery1());
        }
        else if(s[0]=='-') {
            int nm=0;
            int Ln=strlen(s);
            for(int j=1;j<Ln;j++) {
                nm=(nm*10+(s[j]-'0'));
            }
            if(!Ase[ nm ]) continue;
             Update( St[ Id[ nm ] ] , -Tree[ Id[ nm ] ].Fq );
            Update( Ed[ Id[ nm ] ]+1 , Tree[ Id[ nm ] ].Fq );
            Ase[nm]=0;
         }
        else {
            int nm=0;
            int Ln=strlen(s);
            for(int j=1;j<Ln;j++) {
                nm=(nm*10+(s[j]-'0'));
            }
            if(Ase[ nm ]) continue;
             Ase[nm]=1;
            Update( St[ Id[ nm ] ] , Tree[ Id[ nm ] ].Fq );
            Update( Ed[ Id[ nm ] ]+1 , -Tree[ Id[ nm ] ].Fq );
        }
    }
     return 0;
}