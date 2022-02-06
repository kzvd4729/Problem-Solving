/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/06/2020 11:49                        
*  solution_verdict: Accepted                                language: GNU C++17                               
*  run_time: 46 ms                                           memory_used: 8000 KB                              
*  problem: https://codeforces.com/contest/1326/problem/D1
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=5e3;
//od[i] is largest palindromic substring centered at i;
vector<int>od;
//ev[i] is largest palindromic substring centered at i and i+1;
vector<int>ev;
void manachar(string s)
{
  string x="@#";
  for(auto c:s)x.push_back(c),x.push_back('#');
  x.push_back('$');s=x;
  int n=s.size();
  int l=0,r=0;vector<int>pp(n);
  for(int i=0;i<n;i++)
  {
    pp[i]=min(r-i,pp[l+r-i]);
    while(s[i-pp[i]]==s[i+pp[i]])pp[i]++;
    if(i+pp[i]>r)l=i-pp[i],r=i+pp[i];
  }
  for(int i=2;i<n-1;i+=2)od.push_back(pp[i]-1);
  for(int i=3;i<n-1;i+=2)ev.push_back(pp[i]-1);
}
 const int M = (int)(2e6 + 239);
 int pref[M], c;
 string solve_palindrome(const string& s)
{
    string a = s;
    reverse(a.begin(), a.end());
    a = s + "#" + a;
    c = 0;
    for (int i = 1; i < (int)a.size(); i++)
    {
        while (c != 0 && a[c] != a[i])
            c = pref[c - 1];
        if (a[c] == a[i])
            c++;
        pref[i] = c;
    }
    return s.substr(0, c);
}
 void solve(string t)
{
    int l = 0;
    while (l < (int)t.size() - l - 1)
    {
        if (t[l] != t[(int)t.size() - l - 1])
            break;
        l++;
    }
    if (l > 0)
        cout << t.substr(0, l);
    if ((int)t.size() > 2 * l)
    {
        string s = t.substr(l, (int)t.size() - 2 * l);
        string a = solve_palindrome(s);
        reverse(s.begin(), s.end());
        string b = solve_palindrome(s);
        if ((int)a.size() < (int)b.size())
            swap(a, b);
        cout << a;
    }
    if (l > 0)
        cout << t.substr((int)t.size() - l, l);
    cout << "\n";
}
 int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    string s,r;cin>>r;s=r;od.clear();ev.clear();
    reverse(r.begin(),r.end());
    if(s==r)
    {
      cout<<s;cout<<endl;
      continue;
    }
    int pt=0;
    for(int i=0; ;i++)
    {
      if(s[i]==s[(int)s.size()-1-i])pt++;
      else break;
    }
    solve(s);continue;
    r=s.substr(pt,(int)s.size()-pt-pt);
    manachar(r);
    //cout<<r<<endl;
    int a=0,b=0;
    for(int i=0;i<od.size();i++)
    {
      if(i-od[i]/2==0)a=max(a,od[i]);
      if(i+od[i]/2==r.size()-1)b=max(b,od[i]);
    }
    for(int i=0;i<ev.size();i++)
    {
      if(i-ev[i]/2==-1)a=max(a,ev[i]);
      if(i+ev[i]/2==r.size()-1)b=max(b,ev[i]);
    }
    if(a>=b)
    {
      for(int i=0;i<pt;i++)cout<<s[i];
      for(int i=0;i<a;i++)cout<<r[i];
      for(int i=pt-1;i>=0;i--)cout<<s[i];
      cout<<endl;
    }
    else
    {
      reverse(r.begin(),r.end());
      for(int i=0;i<pt;i++)cout<<s[i];
      for(int i=0;i<b;i++)cout<<r[i];
      for(int i=pt-1;i>=0;i--)cout<<s[i];
      cout<<endl;
    }
  }
  return 0;
}