/****************************************************************************************
*  @author: kzvd4729                                         created: Jan/13/2018 20:24                        
*  solution_verdict: Wrong answer on test 6                  language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 1900 KB                              
*  problem: https://codeforces.com/contest/915/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long aa[100],bb[100],fre[100],l1,l2,f;
string a,b;
vector<long>v;
void func(void)
{
    for(long st=1; st<=l2; st++)
    {
        for(long i=9; i>=0; i--)
        {
            if(fre[i])
            {
                if(f)
                {
                    v.push_back(i);
                    fre[i]--;
                    break;
                }
                else if(i<=bb[st])
                {
                    if(i==0)
                    {
                        if(v.size()==0)
                        {
                            f=1;
                            break;
                        }
                        else
                        {
                            v.push_back(0);
                            fre[0]--;
                            break;
                        }
                    }
                    else
                    {
                        v.push_back(i);
                        fre[i]--;
                        if(i!=bb[st])f=1;
                        break;
                    }
                }
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     cin>>a>>b;
    l1=a.size();
    l2=b.size();
    if(l2>l1)
    {
        sort(a.begin(),a.end());
        reverse(a.begin(),a.end());
        cout<<a<<endl;
        return 0;
    }
    for(long i=1; i<=l1; i++)aa[i]=a[i-1]-'0',fre[aa[i]]++;;
    for(long i=1; i<=l2; i++)bb[i]=b[i-1]-'0';
    func();
    if(v.size()==0)v.push_back(0);
     sort(a.begin(),a.end());
    reverse(a.begin(),a.end());
     long sum1=0,sum2=0;
    for(long i=1; i<l2; i++)
    {
        sum1=sum1*10+a[i-1]-'0';
    }
    for(long i=0; i<v.size(); i++)
    {
        sum2=sum2*10+v[i];
    }
    cout<<max(sum1,sum2);
     return 0;
}