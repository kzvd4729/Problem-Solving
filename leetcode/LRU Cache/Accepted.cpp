/****************************************************************************************
*  @author: kzvd4729                                         created: 06/11/2021 21:36                         
*  solution_verdict: Accepted                                language: cpp                                     
*  run_time: 412 ms                                          memory_used: 169.7 MB                             
*  problem: https://leetcode.com/problems/lru-cache
****************************************************************************************/
class LRUCache 
{
public:
  unordered_map<int,pair<int,int> >mp;
  unordered_set<int>con;
  int cp,tim,pt;
  LRUCache(int capacity) 
  {
    cp=capacity;
    tim=0;pt=0;
  }
  void put(int key, int value) 
  {
    tim++;
    if(mp.count(key))
    {
      if(con.count(mp[key].second))con.erase(mp[key].second);
      mp[key]=make_pair(value,tim);
      con.insert(tim);
    }
    else
    {
      mp[key]=make_pair(value,tim);
      con.insert(tim);
    }
    while((int)con.size()>cp)
    {
      if(con.count(pt))con.erase(pt);
      pt++;
    }
  }
  int get(int key) 
  {
    if(mp.count(key)==0)return -1;
    if(mp[key].second<pt)return -1;
    put(key,mp[key].first);
    return mp[key].first; 
  }
};
/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */