#include <iostream>
#include <vector>
#include <deque>
#include <unordered_set>
#include <unordered_map>
#include <limits.h>
#include <math.h>

using namespace std;


vector<int> getFactor(int n) {
    if(n <= 0) return vector<int>();
    int x = sqrt(n+2);
    int y = x;
    int t = x*y;
    while(t < n || t > n+2) {
        if(t < n) y += 1;
        else x-=1;
        t = x * y;
    }
    return {x,y};
}


int main() {
    vector<int> r = getFactor(39);
    cout <<r[0]<< " "<<r[1];
}
