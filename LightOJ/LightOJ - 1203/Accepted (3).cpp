/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-09-08 23:19:13                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 308                                        memory_used (MB): 14.4                            
*  problem: https://vjudge.net/problem/LightOJ-1203
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
const double con=180.0/acos(-1);
int t,tc,n,nn,u,v;
map<pair<int,int>,int>vis;
struct point
{
    long x,y;
} arr[N+2];
stack<point>st;
vector<point>up,lw,hull;

bool cmp(point A,point B)
{
    if(A.x!=B.x)
        return A.x<B.x;
    else
        return A.y<B.y;
}

long area(point a,point b,point c)
{
    b.x-=a.x;
    b.y-=a.y;
    c.x-=a.x;
    c.y-=a.y;
    return b.x*c.y-c.x*b.y;
}

void balance(void)
{
    point one,two,thr;
    while(true)
    {
        if(st.size()<3)
            break;
        thr=st.top();
        st.pop();
        two=st.top();
        st.pop();
        one=st.top();
        if(area(one,two,thr)>0)
            st.push(thr);
        else
        {
            st.push(two);
            st.push(thr);
            break;
        }
    }
}

void upper(void)
{
    for(int i=1; i<=n; i++)
    {
        st.push(arr[i]);
        balance();
    }
    up.clear();
    while(st.size())
    {
        up.push_back(st.top());
        st.pop();
    }
}

void lower(void)
{
    for(int i=n; i>=1; i--)
    {
        st.push(arr[i]);
        balance();
    }
    lw.clear();
    while(st.size())
    {
        lw.push_back(st.top());
        st.pop();
    }
}

void _merge(void)
{
    hull.clear();
    for(int i=0; i<lw.size(); i++)
        hull.push_back(lw[i]);
    for(int i=1; i<up.size()-1; i++)
        hull.push_back(up[i]);
}

double find_ang(point a,point b,point c)
{
    b.x-=a.x;
    b.y-=a.y;
    c.x-=a.x;
    c.y-=a.y;
    double mg=b.x*1.0*c.x+b.y*1.0*c.y;
    double ma=sqrt(b.x*1.0*b.x+b.y*1.0*b.y);
    double mb=sqrt(c.x*1.0*c.x+c.y*1.0*c.y);
    return fabs(acos(mg/(ma*mb)));
}

int main()
{
    cin>>t;
    while(t--)
    {
        n=0;
        vis.clear();
        cin>>nn;
        for(int i=1; i<=nn; i++)
        {
            cin>>u>>v;
            if(vis[make_pair(u,v)])
                continue;
            vis[make_pair(u,v)]=1;
            ++n;
            arr[n].x=u;
            arr[n].y=v;
        }
        sort(arr+1,arr+n+1,cmp);
        upper();
        lower();
        _merge();
        double ang=1e8;
        for(int i=0,l=hull.size(); i<l; i++)
            hull.push_back(hull[i]);
        for(int i=1; i<hull.size()-1; i++)
            ang=min(ang,find_ang(hull[i],hull[i-1],hull[i+1]));
        /*for(int i=0;i<hull.size();i++)
                cout<<hull[i].x<<" "<<hull[i].y<<endl;*/
        cout<<setprecision(6)<<fixed;
        ang*=con;
        if(n<3)
            ang=0.0;
        cout<<"Case "<<++tc<<": "<<ang<<endl;

    }
    return 0;
}