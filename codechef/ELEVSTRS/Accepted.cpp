/****************************************************************************************
*  @author: kzvd4729                                         created: 20-08-2017 21:46:04                      
*  solution_verdict: Accepted                                language: C++14                                   
*  run_time: 0.00 sec                                        memory_used: 14.9M                                
*  problem: https://www.codechef.com/COOK85/problems/ELEVSTRS
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
#define N 1.4142135623730950
using namespace std;
double n,v1,v2,n1,n2;
long t;
int main()
{
    ///ofstream cout("out.txt");
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>t;
    while(t--)
    {
        cin>>n>>v1>>v2;
        n1=(double)sqrt(2)*n;
        n2=n*2.0;
        if((double)(n1/v1)>(double)(n2/v2))
        {
            cout<<"Elevator"<<endl;
        }
        else cout<<"Stairs"<<endl;
    }
    return 0;
}