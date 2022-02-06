/****************************************************************************************
*  @author: JU_Quanta: tariqiitju, mh755628, kzvd4729#       created: Oct/09/2019 20:31                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 2011 ms                                         memory_used: 11200 KB                             
*  problem: https://codeforces.com/gym/101550/problem/K
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
 struct point{
    LD x,y;
    point(){x=y=0;}
    inline void in(){
        cin>>x>>y;
    }
    point(double a,double b){
        x = a;
        y = b;
    }
    point operator -(point a){
        return point(x - a.x , y - a.y);
    }
    point operator +(point a){
        return point(x + a.x , y + a.y);
    }
    point operator *(LD a){
        return point(x * a , y *a);
    }
  };
 LD len(point a){
    return sqrt(a.x*a.x+a.y*a.y);
}
point go(point from,point to,LD l){
    return (to - from)*(l/len(to - from)) + from;
}
 const int LIMIT = 70;
 LD close(point a,point b,point c,point d){
     LD l = 0, r = 1;
    LD ln = len(b-a);
    if(ln < EPS) return len(a-c);
    point aa = (b-a)*(1.0/ln);
    point bb = (d-c)*(1.0/ln);
    for(int loop = LIMIT;loop--;){
        LD m1 = l +  (r-l)/3;
        LD m2 = r - (r-l)/3;
         point a1 = a + aa*(ln*m1);
        point b1 = c + bb*(ln*m1);
         point a2 = a + aa*(ln*m2);
        point b2 = c + bb*(ln*m2);
         if(len(a1-b1) < len(a2-b2)) r = m2;
        else l = m1;
    }
    point a1 = a + aa*(ln*l);
    point b1 = c + bb*(ln*l);
    return len(a1-b1);
 }
  int main()
{
      int n,m;
    cin>>n;
    vector<point> a(n);
    for(int i=0;i<n;i++)a[i].in();
    cin>>m;
    vector<point> b(m);
    for(int i=0;i<m;i++)b[i].in();
     point cur1 = a[0];
    point cur2 = b[0];
    int next1 = 1;
    int next2 = 1;
     LD res = len(cur1-cur2);
     while(next1 < n and next2 < m){
          LD d1 = len(a[next1] - cur1);
        LD d2 = len(b[next2] - cur2);
         if(fabs(d1-d2) < EPS){
            res = min(res,close(cur1,a[next1],cur2,b[next2]));
            cur1 = a[next1++];
            cur2 = b[next2++];
         }
        else if(d1 < d2){
            point nx = go(cur2,b[next2],d1);
            res = min(res,close(cur1,a[next1],cur2,nx));
            cur2 = nx;
            cur1 = a[next1++];
        }else{
            point nx = go(cur1,a[next1],d2);
            res = min(res,close(cur1,nx,cur2,b[next2]));
            cur2 = b[next2++];
            cur1 = nx;
        }
    }
     cout<<setprecision(10)<<fixed<<res<<endl;
     return 0;
}
 /**
                     Md. Tariqul Islam
                          IIT,JU
                      fb/tariqiitju
                    tarik.amtoly@gmail.com
*/