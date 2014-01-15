#include <iostream>
using namespace std;

int main() {
    int a[] = { 1, 9, 3, 8, 11, 4};
    cout <<"sizeof(a): "<<sizeof(a)<< " and sizeof a[0]: " <<sizeof(a[0])<<endl;
    int len = sizeof(a) / sizeof(a[0]);
    cout <<"Length: " <<len<<endl;
    int *p = a+3;
    cout <<"p[-1]: " <<p[-1]<<endl;
    return 0;
}
