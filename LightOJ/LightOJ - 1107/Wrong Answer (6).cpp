/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-01-29 22:27:59                      
*  solution_verdict: Wrong Answer                            language: C++                                     
*  run_time (ms):                                            memory_used (MB):                                 
*  problem: https://vjudge.net/problem/LightOJ-1107
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int t,tc,a,b,c,d,x,y,n;
int main()
{
    ofstream cout("out.txt");
    scanf("%ld",&t);
    while(t--)
    {
        scanf("%ld%ld%ld%ld",&a,&b,&c,&d);
        scanf("%ld",&n);
        ///printf("Case %ld:\n",++tc);
        cout<<"Case "<<++tc<<":"<<endl;
        while(n--)
        {
            scanf("%ld%ld",&x,&y);
//            if(x<=a||x>=c||y<=b||y>=d)printf("No\n");
//            else printf("Yes\n");
if(x<=a||x>=c||y<=b||y>=d)cout<<"No"<<endl;
            else cout<<"Yes"<<endl;
        }
    }
    return 0;
}