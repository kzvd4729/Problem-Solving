/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-01-31 02:05:50                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time: 0                                               memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-10242
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
double a,b,c,e,d,f,g,h,x,y;
int main()
{
    while(cin>>a>>b>>c>>e>>d>>f>>g>>h)
    {
        if(a==d&&b==f)x=c+g-a,y=e+h-b;
        else if(a==g&&b==h)x=c+d-a,y=e+f-b;
        else if(c==d&&e==f)x=a+g-c,y=b+h-e;
        else x=a+d-c,y=b+f-e;
        cout<<setprecision(3)<<fixed<<x<<" "<<setprecision(3)<<fixed<<y<<endl;
    }
    return 0;
}