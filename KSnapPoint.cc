#include <iostream>
#include <vector>
#include <deque>
#include <unordered_set>
#include <limits.h>

using namespace std;

struct Point {
    int x;
    int y;
    Point(int xx, int yy): x(xx), y(yy) {}
    bool operator==(const Point &other) const
      { return (x == other.x
                && y == other.y);
      }
};
struct Hash {
    size_t operator()(const Point& k) const {
        return hash<string>()(to_string(k.x) + "," + to_string(k.y));
    }
};
//K-snap point: a point whose digits sum up to less than or equal
//to k. ignore the sign.
int sumOfDigits(int num) {
    long n = abs((long)num);
    int res = 0;
    while(n > 0) {
        res += n % 10;
        n /= 10;
    }
    return res;
}
bool isSnapPoint(Point p, int k) {
    if(sumOfDigits(p.x) + sumOfDigits(p.y) <= k) return true;
    return false;
}

//Rechable k-snap point: A k-snap Point is , if there is a path
//from (0,0) to that point, where the path only consists of k-snap
//point.
//Given k, return all the reachable k-snap points
vector<Point> rechableKSnapPoint(int k) {
    vector<Point> res;
    if(k < 0) return res;
    Point src(0,0);
    deque<Point> q;
    unordered_set<Point, Hash> visited;
    q.push_back(src);
    visited.insert(src);
    
    int next[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
    while(!q.empty()) {
        Point pt = q.front(); 
        q.pop_front();
        res.push_back(pt);
        for(int ind = 0; ind < 4; ind++) {
            Point nxt(pt.x + next[ind][0], pt.y+next[ind][1]);
            if(visited.find(nxt) == visited.end()) {
                //not visited
                visited.insert(nxt);
                if(isSnapPoint(nxt, k)) q.push_back(nxt);
            }
        }
    }
    return res;
}
int main() {
	//cout <<sumOfDigits(-19191);
	//cout <<isSnapPoint(Point(10,31), 4);
	vector<Point> ksnaps =  rechableKSnapPoint(2);
	for(Point p : ksnaps) {
	    cout <<p.x <<" "<<p.y <<endl;
	}
	return 0;
}
