/****************************************************************************************
*  @author: kzvd4729                                         created: 06/10/2021 18:58                         
*  solution_verdict: Accepted                                language: cpp                                     
*  run_time: 84 ms                                           memory_used: 37.7 MB                              
*  problem: https://leetcode.com/problems/my-calendar-i
****************************************************************************************/
class MyCalendar {
public:
    vector<pair<int,int> >v;
    MyCalendar() 
    {
        v.clear();
    }
        bool book(int l, int r) 
    {
        for(auto x:v)
        {
            if(x.second<=l || x.first>=r);
            else return false;
        }
        v.push_back(make_pair(l,r));
        return true;
    }
};
/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */