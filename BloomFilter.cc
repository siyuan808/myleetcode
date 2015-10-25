#include <iostream>
#include <vector>

using namespace std;

class BloomFilter {
  int _thresh;
  int _len;
  int _count;
  vector<int (*)(string)> _hashFuns;
  vector<vector<int>> _bits;
public:
  BloomFilter(int len, double thresh, vector<int (*)(string)>& hashs) {
    _len = len;
    _thresh = _len * thresh;
    _count = 0;
    _hashFuns = hashs;
    _bits.push_back(vector<int>(_len, 0));
  }
  
  void add(string& str) {
      //added it into the last one
      vector<int>& lastBits = _bits.back();
      for(auto hashFun : _hashFuns) {
          int hashVal = hashFun(str) % _len;
          lastBits[hashVal]++;
          if(lastBits[hashVal] == 1) {
              _count++;
          }
      }
      //expand it if exceeds threshold
      if(_count >= _thresh) {
          resize();
      }
  }
  
  void resize() {
      _bits.push_back(vector<int>(_len, 0));
      _count = 0;
  }
  
  bool contains(vector<int>& oneBits, string& str) {
      for(auto hashFun : _hashFuns) {
          int hashVal = hashFun(str) % _len;
          if(oneBits[hashVal] == 0) {
              return false;
          }
      }
      return true;
  }
  
  bool mightContains(string str) {
        for(vector<int>& oneBits : _bits) {
            if(contains(oneBits, str)) return true;
        }
        return false;
  }
  
  void remove(string str) {
        for(vector<int>& oneBits : _bits) {
            if(contains(oneBits, str)) {
                for(auto hashFun : _hashFuns) {
                  int hashVal = hashFun(str) % _len;
                  oneBits[hashVal]--;
                }
            }
        }  
  }
  
  void printData() {
      for(vector<int>& oneBits : _bits) {
          for(int bit : oneBits) {
              cout <<bit <<" ";
          }
          cout <<endl;
      }
  }
};

int hash1(string s) { 
    return s.length();
}   

int main() {
    vector<int (*)(string)> hashs;
    hashs.push_back(hash1);
    BloomFilter bf(5,.8,hashs);
    vector<string> v{"h","he","hel","hell","hell0","hell1"};
    for(string s: v) bf.add(s);
    bf.printData();
    bf.remove("hello");
    bf.printData();
    bf.remove("hello");
    bf.printData();
    cout <<"Contain: " <<bf.mightContains("hell2");
}
