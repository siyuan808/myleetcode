#include <iostream>
#include <vector>
#include <deque>
#include <unordered_set>
#include <limits.h>

using namespace std;

class PeakQueue {
    deque<pair<int,int>> _data;
    deque<int> _minData, _maxData;
public:
    void enqueue(int val, int t) {
        _data.push_back(make_pair(val, t));
        
        //maintain _maxData
        while(!_maxData.empty()) {
            if(_maxData.back() < val) _maxData.pop_back();
        }
        _maxData.push_back(val);
        
        //maintain _minData
        while(!_minData.empty()) {
            if(_minData.back() > val) _minData.pop_back();
        }
    }
    
    void dequeue() {
        int frontVal = front().first;
        _data.pop_front();
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
        return _maxData.front();
    }
    
    int getMin() {
        return _minData.front();
    }
}

class TimeNumber {
    PeakQueue _pq;
    int _sum;
    int _cnt;
    int _interval;
public:
    TimeNumber(int interval) {
        _sum = _cnt = 0;
        _interval = interval;
    }
    
    void add(int val, int t) {
        _pq.enqueue(val, t);
        sum += val;
        _cnt++;
    }
    
    void cleanUp(int cntTime) {
        //deque all the data with time older than cntTime
        while(!_pq.empty()) {
            pair<int,int> data = _pq.front();
            if(data.second < cntTime-_interval) {
                _pq.dequeue();
                sum-= data.first;
                cnt--;
            }
        }
    }
    
    double getAverage(int cntTime) {
        cleanUp(cntTime);
        if(_cnt == 0) return 0;
        return (double) _sum / _cnt; 
    }
    
    int getMax(int cntTime) {
        cleanUp(cntTime);
        return _pq.getMax();
    }
    int getMin(int cntTime) {
        cleanUp(cntTime);
        return _pq.getMin();
    }
}


int main() {
	cout <<time(NULL)<<endl;
	sleep(10)<<endl;
	cout <<time(NULL)<<endl;
}
