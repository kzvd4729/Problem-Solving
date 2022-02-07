/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-03-11 22:08:29                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time: 0                                               memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-11437
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const double eps = 0.00000001;
long t;
struct point
{
    double x, y;
};
struct equation
{
    double a, b, c;
} be, ad, cf;
equation make_equation(point p1, point p2)
{
    equation tmp;
    tmp.a = (p2.y - p1.y);
    tmp.b = (p1.x - p2.x);
    tmp.c = (p1.x * (p1.y - p2.y) + p1.y * (p2.x - p1.x));
    return tmp;
}
point segment_cross(equation e1, equation e2)
{
    point p;
    double det = e1.a * e2.b - e1.b * e2.a;
    if(fabs(det) < eps)return {1e9, 1e9};
    p.x = (e1.b * e2.c - e1.c * e2.b) / det;
    p.y = (e1.c * e2.a - e1.a * e2.c) / det;
    return p;
}
double area(point a, point b, point c)
{
    return 0.5 * (a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y));
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while(t--)
    {
        point a, b, c, d, e, f;
        cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y;

        d = {b.x + (c.x - b.x) / 3.00, b.y + (c.y - b.y) / 3.00};
        e = {c.x + (a.x - c.x) / 3.00, c.y + (a.y - c.y) / 3.00};
        f = {a.x + (b.x - a.x) / 3.00, a.y + (b.y - a.y) / 3.00};

//  cout<<d.x<<" "<<d.y<<endl;
//  cout<<e.x<<" "<<e.y<<endl;
//  cout<<f.x<<" "<<f.y<<endl;

        be = make_equation(b, e);
        ad = make_equation(a, d);
        cf = make_equation(c, f);

//  cout<<be.a<<" "<<be.b<<" "<<be.c;
//  cout<<ad.a<<" "<<ad.b<<" "<<ad.c;
//  cout<<cf.a<<" "<<cf.b<<" "<<cf.c;

        point p, r, q;
        p = segment_cross(be, ad);
        q = segment_cross(be, cf);
        r = segment_cross(ad, cf);

//  cout<<p.x<<" "<<p.y<<endl;
//  cout<<q.x<<" "<<q.y<<endl;
//  cout<<r.x<<" "<<r.y<<endl;

        cout << setprecision(0) << fixed << area(p, q, r) << endl;
    }

    return 0;
}