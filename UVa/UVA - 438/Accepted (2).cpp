/****************************************************************************************
*  @author: kzvd4729                                         created: 2017-10-13 13:37:38                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time: 0                                               memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-438
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
#define pi 3.141592653589793
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
    if(D==0)D=0.00000000000001;
    double Dx=(e1.cn*e2.qy)-(e1.qy*e2.cn);
    double Dy=(e1.qx*e2.cn)-(e1.cn*e2.qx);
    ///cout<<D<<" "<<Dx<<" "<<Dy<<endl;
    center.x=Dx/D;
    center.y=Dy/D;

}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    while(cin>>a.x>>a.y>>b.x>>b.y>>c.x>>c.y)
    {
        point mid1;
        mid1.x=(a.x+b.x)/2.0;
        mid1.y=(a.y+b.y)/2.0;
        ///s1=(1/((a.y-b.y)/(a.x-b.x)))*(-1);
        if((a.y-b.y)==0)s1=9999999999999;
        else s1=(a.x-b.x)/(a.y-b.y);
        s1=-s1;
        e1.cn=mid1.y-s1*mid1.x;
        e1.qx=-s1;
        e1.qy=1;


        point mid2;
        mid2.x=(b.x+c.x)/2.0;
        mid2.y=(b.y+c.y)/2.0;
        ///s2=(1/((b.y-c.y)/(b.x-c.x)))*(-1);
        if((b.y-c.y)==0)s2=9999999999999;
        else s2=(b.x-c.x)/(b.y-c.y);
        s2=-s2;
        e2.cn=mid2.y-s2*mid2.x;
        e2.qx=-s2;
        e2.qy=1;

        solve_equation();

        ///cout<<e1.qx<<" "<<e1.qy<<" "<<e1.cn<<endl;
        ///cout<<e2.qx<<" "<<e2.qy<<" "<<e2.cn<<endl;

        ///cout<<center.x<<" "<<center.y<<endl;

        cout<<setprecision(2)<<fixed<<2*pi*dist(center,a)<<endl;

    }
    return 0;
}