#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int single(int a[]) {
    int size = sizeof(a) / sizeof(a[0]);
    if(size <= 0) return -1;
    int r = a[0];
    for(int i=1; i<size; i++) 
        r ^= a[i];
    return r;
}

bool comp(int a, int b) {
    return a < b;
}

vector<int> list(int n) {
    vector<int> v(n);
    for(int i = 0; i < n; i++)
	v[i] = i;
    return v;
}

int main()  {
/*    double x = 5.500;
    int y = 5;

    if (y == x)
    {
 	 cout << "Same";
    }
    else
    {
    	cout << "Different";
    }
    cout <<endl;
*/
    int a[7] = {3, 4, 1, 7, 1, 4, 3};
    cout <<"Single: " <<single(a)<<endl;
 /*   vector<int> v;
    v.push_back(3);v.push_back(1), v.push_back(5);
    sort(v.begin(), v.end(), comp);
    for(int i=0; i<v.size(); i++)
        cout <<v[i]<<" ";
    cout <<endl;

    cout <<"Max-1: " <<INT_MAX - 1<<endl;
    
    int r = 0;
    int ori = -12340;
    cout <<ori;
    while(ori != 0) {
	r = r*10 + ori % 10;
	ori /= 10;
    }
    cout <<" reserse is "<< r <<endl;
    return 0;
*/
    vector<int> l = list(10);
    for(int i = 0; i < l.size(); i++) 
	cout << l.at(i)<<"\t";
    cout <<endl;
}
	

