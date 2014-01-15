class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        stack<int> s;
        for(string op : tokens) {
            if(op == "+" || op == "-" || op == "*" || op == "/") {
                    int op1 = s.top();
                    s.pop();
                    int op2 = s.top();
                    s.pop();
                    int res;
                    switch(op[0]) {
                        case '+':
                            res = op2 + op1;
                        case '-':
                            res = op2 - op1;
                        case '*':
                            res = op2 * op1;
                        case '/':
                            res = op2 / op1;
                    }
                    s.push(res);
                    break;
            } else
                s.push(atoi(op.c_str()));
        }
        return s.top();
    }
};