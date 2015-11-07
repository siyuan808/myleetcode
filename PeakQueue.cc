#include <iostream>
#include <vector>
#include <deque>
#include <unordered_set>
#include <limits.h>

using namespace std;

class PeakQueue {
    deque<pair<int,int>> _data; //first: val, second: time stamp
    deque<int> _minData, _maxData;
    int _sum = 0;
public:
    void enqueue(int val, int t) {
        _data.push_back(make_pair(val, t));
        _sum += val;
        
        //maintain _maxData
        while(!_maxData.empty()) {
            if(_maxData.back() < val) _maxData.pop_back();
            else break;
        }
        _maxData.push_back(val);
        
        //maintain _minData
        while(!_minData.empty()) {
            if(_minData.back() > val) _minData.pop_back();
            else break;
        }
        _minData.push_back(val);
    }
    
    void dequeue() {
        int frontVal = front().first;
        _data.pop_front();
        _sum -= frontVal;
        if(frontVal == _maxData.front()) _maxData.pop_front();
        if(frontVal == _minData.front()) _minData.pop_front();
    }
    
    bool empty() {
        return _data.empty();
    }
    
    pair<int,int> front() {
        return _data.front();
    }
    
    int getMax(){
        if (empty()) {
            return INT_MIN;
        }
        return _maxData.front();
    }
    
    int getMin() {
        if (empty()) {
            return INT_MAX;
        }
        return _minData.front();
    }
    
    double getAverage() {
        if (empty()) return 0;
        return (double)_sum / _data.size();
    }
};

class TimeNumber {
    PeakQueue _pq;
    int _interval;
public:
    TimeNumber(int interval) {
        _interval = interval;
    }
    
    void add(int val, int t) {
        _pq.enqueue(val, t);
    }
    
    void cleanUp(int cntTime) {
        //deque all the data with time older than cntTime
        while(!_pq.empty()) {
            pair<int,int> data = _pq.front();
            if(data.second < cntTime-_interval) {
                _pq.dequeue();
            } else break;
        }
    }
    
    double getAverage(int cntTime) {
        cleanUp(cntTime);
        return _pq.getAverage();
    }
    
    int getMax(int cntTime) {
        cleanUp(cntTime);
        return _pq.getMax();
    }
    int getMin(int cntTime) {
        cleanUp(cntTime);
        return _pq.getMin();
    }
};


int main() {
    TimeNumber tn(10);
    tn.add(3, 1);
    tn.add(4, 2);
    tn.add(5, 5);
    
    int t = 12;
    
    cout <<"Max: " <<tn.getMax(t)<<" min: "<<tn.getMin(t) <<" Avg: " <<tn.getAverage(t)<<endl;
    return 0;
}
