/****************************************************************************************
*  @author: kzvd4729                                         created: 29-02-2020 22:17:56                      
*  solution_verdict: Accepted                                language: C++14                                   
*  run_time: 0.00 sec                                        memory_used: 15.2M                                
*  problem: https://www.codechef.com/LTIME81A/problems/SWAPPALI
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,inf=1e9;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int n;string s;cin>>n>>s;
    int i=0,j=n-1;
    int ans=0,l=-1,r=n+1;
    while(true)
    {
        if(i==j)break;
        if(j-i==1)
        {
            if(s[i]==s[j])break;
            else {ans=-1;break;}
        }
        if(j-i==2)
        {
            if(s[i]==s[i+2])break;
            if((s[i]!=s[i+1])&&(s[i]!=s[i+2])&&(s[i+1]!=s[i+2])){ans=-1;break;}
            //cout<<l<<" "<<r<<" "<<i<<" "<<j<<endl;
            if(s[j]==s[j-1]&&l>=i){ans=-1;break;}
            if(s[i]==s[i+1]&&r<=j){ans=-1;break;}
            ans++;break;
        }
        if(s[i]==s[j])
        {
            i++,j--;continue;
        }
        if(s[i+1]==s[j]&&l<i)
        {
            ans++;swap(s[i],s[i+1]);l=i+1;
        }
        else if(s[j-1]==s[i]&&r>j)
        {
            ans++;swap(s[j],s[j-1]);r=j-1;
        }
        else {ans=-1;break;}
        i++;j--;
        //cout<<s<<endl;
        //cout<<i<<" "<<j<<endl;
    }
    if(ans==-1)cout<<"NO\n";
    else cout<<"YES\n"<<ans<<"\n";
    //cout<<ans<<"\n";
  }
  return 0;
}