/****************************************************************************************
*  @author: kzvd4729                                         created: 2017-10-13 13:03:12                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time: 0                                               memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-190
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
double s1,s2;
struct point
{
    double x;
    double y;
}center,a,b,c;
struct equation
{
    double qx;
    double qy;
    double cn;
}e1,e2;
double dist(point aa,point bb)
{
    return sqrt((aa.x-bb.x)*(aa.x-bb.x)+(aa.y-bb.y)*(aa.y-bb.y));
}
void solve_equation(void)
{
    double D=(e1.qx*e2.qy)-(e1.qy*e2.qx);
    double Dx=(e1.cn*e2.qy)-(e1.qy*e2.cn);
    double Dy=(e1.qx*e2.cn)-(e1.cn*e2.qx);
    center.x=Dx/D;
    center.y=Dy/D;

}
void print(void)
{
    double r1=dist(center,a);
    if(r1<0)center.x*=-1,center.y*=-1;
    cout<<"(x";
    if(center.x>=0)cout<<" - ";
    else cout<<" + ";
    cout<<setprecision(3)<<fixed<<fabs(center.x);
    cout<<")^2 + (y";
    if(center.y>=0)cout<<" - ";
    else cout<<" + ";
    cout<<setprecision(3)<<fixed<<fabs(center.y);
    cout<<")^2 = ";
    cout<<setprecision(3)<<fixed<<fabs(r1);
    cout<<"^2"<<endl;


    double hx=-2*center.x;
    double yk=-2*center.y;
    double cns=center.x*center.x+center.y*center.y-r1*r1;
    cout<<"x^2 + y^2";

    if(hx>=0)cout<<" + ";
    else cout<<" - ";
    cout<<setprecision(3)<<fixed<<fabs(hx)<<"x";

    if(yk>=0)cout<<" + ";
    else cout<<" - ";
    cout<<setprecision(3)<<fixed<<fabs(yk)<<"y";

    if(cns>=0)cout<<" + ";
    else cout<<" - ";
    cout<<setprecision(3)<<fixed<<fabs(cns);

    cout<<" = 0"<<endl<<endl;

}
int main()
{
    ///ofstream cout("out.txt");
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    while(cin>>a.x>>a.y>>b.x>>b.y>>c.x>>c.y)
    {
        point mid1;
        mid1.x=(a.x+b.x)/2.0;
        mid1.y=(a.y+b.y)/2.0;
        s1=(1/((a.y-b.y)/(a.x-b.x)))*(-1);
        e1.cn=mid1.y-s1*mid1.x;
        e1.qx=-s1;
        e1.qy=1;


        point mid2;
        mid2.x=(b.x+c.x)/2.0;
        mid2.y=(b.y+c.y)/2.0;
        s2=(1/((b.y-c.y)/(b.x-c.x)))*(-1);
        e2.cn=mid2.y-s2*mid2.x;
        e2.qx=-s2;
        e2.qy=1;

        solve_equation();

        print();


    }
    return 0;
}