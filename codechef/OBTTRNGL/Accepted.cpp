/****************************************************************************************
*  @author: kzvd4729                                         created: 20-08-2017 23:17:26                      
*  solution_verdict: Accepted                                language: C++14                                   
*  run_time: 0.11 sec                                        memory_used: 14.9M                                
*  problem: https://www.codechef.com/COOK85/problems/OBTTRNGL
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
#define N 100005
using namespace std;
long t,k,a,b;
int main()
{
    ///ofstream cout("out.txt");
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>t;
    while(t--)
    {
        cin>>k>>a>>b;
        if(a<b)swap(a,b);
        a=a-b-1;
        b=k-a-2;
        if(a==b)
        {
            cout<<0<<endl;
        }
        else cout<<min(a,b)<<endl;
    }
    return 0;
}