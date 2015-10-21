#include <iostream>
#include <string>

using namespace std;

string add(string num1, string num2) {
    if(num2.size() > num1.size()) return add(num2,num1);
    
    int c = 0, sum = 0;
    for(int i1 = num1.size()-1, i2=num2.size()-1; i1 >= 0; i1--,i2--) {
        sum = c + num1[i1]-'0';
        if(i2 >= 0) sum += num2[i2]-'0';
        num1[i1] = sum % 10 + '0';
        c = sum / 10;
    }
    if(c > 0) return '1'+num1;
    return num1;
}

// Driver program to test above functions
int main()
{
	string num1 = "9";
	string num2 = "1";
	cout <<add(num1,num2)<<endl;
	return 0;
}
