#include <iostream>
#include <cstring>
#include <stack>
#include <vector>

using namespace std;
class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        stack<int> s;
        for(int i = 0; i < tokens.size(); i++) {
			string op = tokens[i];
            if(op == "+" || op == "-" || op == "*" || op == "/") {
				// cout <<"Operator"<<endl;
                    int op1 = s.top();
                    s.pop();
                    int op2 = s.top();
                    s.pop();
                    int res;
                    switch(op[0]) {
                        case '+':
                            res = op2 + op1;
							break;
                        case '-':
                            res = op2 - op1;
							break;
                        case '*':
                            res = op2 * op1;
							break;
                        case '/':
                            res = op2 / op1;
							break;
                    }
                    s.push(res);
            } else
                s.push(stoi(op));
        }
        return s.top();
    }
};

int main() {
	vector<string> tokens;
	tokens.push_back("2");
	tokens.push_back("1");
	tokens.push_back("+");
	tokens.push_back("3");
	tokens.push_back("*");
	for(int i = 0; i < tokens.size(); i++)
		cout <<tokens[i]<<" ";
	cout <<endl;
	Solution s;
	cout <<s.evalRPN(tokens)<<endl;
	return 0;
}