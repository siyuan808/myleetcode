#include <iostream>
#include <vector>
#include <deque>
#include <unordered_set>
#include <unordered_map>
#include <limits.h>

using namespace std;

class SetWithRandom {
    unordered_map<int, int> _indexMap;
    vector<int> _data;
public:
  void insert(int val) {
      if(_indexMap.find(val) != _indexMap.end()) return;
      _data.push_back(val);
      _indexMap[val] = _data.size()-1;
  }
  int getRandom() {
      srand(time(NULL));
      return _data[rand() % _data.size()];
  }
  void erase(int val) {
      int lastVal = _data.back();
      _indexMap[lastVal] = _indexMap[val];
      _data[_indexMap[val]] = lastVal;
      _indexMap.erase(val);
      _data.pop_back();
  }
  void print() {
      for(int x: _data)  cout <<x <<" ";
  }
  bool exists(int val) {
      return _indexMap.find(val) != _indexMap.end();
  }
  int get(int val) {
      if(!exists(val)) return -1;
      return _indexMap[val];
  }
};


int main() {
    SetWithRandom s;
    for(int i = 1; i < 10; i++) s.insert(i);
    s.erase(2);
    s.erase(1);
    s.print();
    cout <<s.get(8)<<endl;
    cout <<s.get(9);
}
