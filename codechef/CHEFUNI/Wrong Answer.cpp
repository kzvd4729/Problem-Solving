/****************************************************************************************
*  @author: kzvd4729                                         created: 07-12-2017 18:34:43                      
*  solution_verdict: Wrong Answer                            language: C++14                                   
*  run_time: 0.00 sec                                        memory_used: 0M                                   
*  problem: https://www.codechef.com/DEC17/problems/CHEFUNI
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long ans,x,y,z,a,b,c,t;
long case1(long xx,long yy,long zz)
{
    return (x+y+z)*a;
}
long case2(long xx,long yy,long zz)
{
    if((xx+yy)<zz)
    {
        return (xx+yy)*b+(zz-xx-yy)*a;
    }
    long sum=xx+yy+zz;
    if(sum%2==0)return (sum/2)*b;
    else if(xx>=1)return min((sum/2)*b+a,((sum-3)/2)*b+c);
    else return (sum/2)*b+a;
}
long case3(long xx,long yy,long zz)
{
    return xx*c+(yy+zz-xx-xx)*a;
}
long case4(long xx,long yy,long zz)
{
    return xx*c+(yy-xx)*b+(zz-yy)*a;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>t;
    while(t--)
    {
        cin>>x>>y>>z>>a>>b>>c;
        if(x>z)swap(x,z);
        if(y>z)swap(y,z);
        if(x>y)swap(x,y);
        ans=999999999999999;
        ans=min(ans,case1(x,y,z));
        ans=min(ans,case2(x,y,z));
        ans=min(ans,case3(x,y,z));
        ans=min(ans,case4(x,y,z));
        cout<<ans<<endl;
    }
    return 0;
}