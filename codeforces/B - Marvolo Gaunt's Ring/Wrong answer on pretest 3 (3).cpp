/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/24/2017 22:32                        
*  solution_verdict: Wrong answer on pretest 3               language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/855/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long n,p,q,x,r,mx=-9999999999999999,mn=99999999999999,ans;
string con(long z)
{
    string ss;
    ss.clear();
    while(z)
    {
        long rm=z%10;
        ss.push_back(rm+'0');
        z=z/10;
    }
    return ss;
}
string add(string a,string b)
{
    string ss;
    long l1=a.size();
    long l2=b.size();
    long c=0;
    for(long i=0;i<max(l1,l2);i++)
    {
        if(i<l1&&i<l2)
        {
            long dd=a[i]-'0'+b[i]-'0'+c;
            c=dd/10;
            dd=dd%10;
            ss.push_back(dd+'0');
        }
        else if(i<l1)
        {
            long dd=a[i]-'0'+c;
            c=dd/10;
            dd=dd%10;
            ss.push_back(dd+'0');
        }
        else if(i<l2)
        {
            long dd=b[i]-'0'+c;
            c=dd/10;
            dd=dd%10;
            ss.push_back(dd+'0');
        }
    }
    if(c)ss.push_back(c+'0');
    return ss;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     cin>>n>>p>>q>>r;
    while(n--)
    {
        cin>>x;
        mx=max(mx,x);
        mn=min(mn,x);
    }
    long pp,qq,rr,f1=1,f2=1,f3=1;
    string s1,s2,s3;
     if(p<0)pp=p*mn;
    else pp=p*mx;
     if(pp<0)f1=0;
    if(pp<0)pp=pp*(-1);
     s1=con(pp);
     if(q<0)qq=q*mn;
    else qq=q*mx;
     if(qq<0)f2=0;
    if(qq<0)qq=qq*(-1);
     s2=con(qq);
     if(r<0)rr=r*mn;
    else rr=r*mx;
     if(rr<0)f3=0;
    if(rr<0)rr=rr*(-1);
     s3=con(rr);
     ///cout<<s1<<" "<<s2<<" "<<s3<<endl;
    ///cout<<add(s1,s2);
      string tmp,tmp2;
    long tm,f=0;
    if(f1==0&&f2==0&&f3==0)
    {
        tmp=add(s1,s2);
        tmp2=add(tmp,s3);
        cout<<"-";
        for(long i=tmp2.size()-1;i>=0;i--)cout<<tmp2[i];
        cout<<endl;
    }
    else if(f1==0&&f2==0&&f3==1)
    {
        tm=rr-qq;
        if(tm>=0)cout<<tm-pp;
        else
        {
            tmp=con(tm*(-1));
            tmp2=add(tmp,s1);
            cout<<"-";
            for(long i=tmp2.size()-1;i>=0;i--)cout<<tmp2[i];
            cout<<endl;
        }
    }
    else if(f1==0&&f2==1&&f3==0)
    {
        tm=qq-rr;
        if(tm>=0)cout<<tm-pp;
        else
        {
            tmp=con(tm*(-1));
            tmp2=add(tmp,s1);
            cout<<"-";
            for(long i=tmp2.size()-1;i>=0;i--)cout<<tmp2[i];
            cout<<endl;
        }
    }
    else if(f1==0&&f2==1&&f3==1)
    {
        tm=qq-pp;
        if(tm<=0)cout<<rr+tm;
        else
        {
            tmp=con(tm);
            tmp2=add(tmp,s3);
            for(long i=tmp2.size()-1;i>=0;i--)cout<<tmp2[i];
            cout<<endl;
        }
    }
     else if(f1==1&&f2==0&&f3==0)
    {
        tm=pp-qq;
        if(tm>=0)cout<<tm-rr;
        else
        {
            tmp=con(tm*(-1));
            tmp2=add(tmp,s3);
            cout<<"-";
            for(long i=tmp2.size()-1;i>=0;i--)cout<<tmp2[i];
            cout<<endl;
        }
    }
     else if(f1==1&&f2==0&&f3==1)
    {
        tm=pp-qq;
        if(tm<=0)cout<<tm+rr;
        else
        {
            tmp=con(tm);
            tmp2=add(tmp,s3);
            for(long i=tmp2.size()-1;i>=0;i--)cout<<tmp2[i];
            cout<<endl;
        }
    }
    else if(f1==1&&f2==1&&f3==0)
    {
        tm=qq-rr;
        if(tm<=0)cout<<tm+pp;
        else
        {
            tmp=con(tm);
            tmp2=add(tmp,s1);
            for(long i=tmp2.size()-1;i>=0;i--)cout<<tmp2[i];
            cout<<endl;
        }
    }
    else
    {
        tmp=add(s1,s2);
        tmp2=add(tmp,s3);
        for(long i=tmp2.size()-1;i>=0;i--)cout<<tmp2[i];
        cout<<endl;
    }
     return 0;
}