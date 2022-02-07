/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-06-08 23:55:07                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time: 0                                               memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-10777
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
int t,tc,x,n;
double p;
int main()
{
ios_base::sync_with_stdio(0);
cin.tie(0);

cin>>t;
while(t--)
{
cin>>n;
int f=0;
double dn=1.00,nm=0.0;
        
for(int i=1;i<=n;i++)
{
cin>>x>>p;
            
if(x>0)
{
f=1;
nm+=(x*p);      
}
else
{
x=-x;
nm+=(x*p);
dn-=p;      
}
             
}
cout<<"Case "<<++tc<<": ";
cout<<setprecision(2)<<fixed;
if(f==0)cout<<"God! Save me"<<endl;
else cout<<(nm/dn)<<endl;  

}


return 0;
}