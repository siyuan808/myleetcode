#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <deque>

using namespace std;

//Big number library
class BigInt{
    string num;
    bool neg;
public:
    BigInt() {
        neg = false;
        num = "0";
    }
    BigInt(string n) {
        BigInt();
        if(!n.empty()) {
            int i = 0;
            if(n[0] == '-') neg = true;
            if(n[0] == '+' || n[0] == '-') {
                i = 1;
            }
            while(i < n.length()) {
                if(n[i] < '0' || n[i] > '9') exit(1);
                if(n[i] != '0') break;
                i++;
            }
            num = n.substr(i);
            if(num == "") num = "0";
            if(num == "0") neg = false;
        }
    }
    
    string getNum(){ 
        if(neg) {
            return '-'+num;
        }
        return num;
    }
    
    static BigInt* abs(BigInt* n) {
        n->neg = false;
        return n;
    }    
    static BigInt* negate(BigInt* n) {
        n->neg = !n->neg;
        return n;
    }
    
    static string addIgnoreSign(BigInt* n1, BigInt* n2) {
        string str1 = n1->num;
        string str2 = n2->num;
        if(str1.length() < str2.length()) return addIgnoreSign(n2,n1);
        int i = str1.length()-1, j = str2.length()-1;
        int carry = 0;
        while(i >= 0) {
            int sum = str1[i] -'0' + carry;
            if(j >= 0) sum += str2[j] -'0';
            str1[i] = sum % 10 + '0';
            carry = sum / 10;
            j--;
            i--;
        }
        if(carry > 0) return '1'+str1;
        return str1;
    }
    
    static BigInt* add(BigInt* n1, BigInt *n2) {
        if(n1->neg == n2->neg) {
            BigInt *res = new BigInt(addIgnoreSign(n1, n2));
            res->neg = n1->neg;
        } else {
            if(n1->neg) return minus(n2,abs(n1));
            return minus(n1,abs(n2));
        }
    }
    
    static int compareIgnoreSign(BigInt* n1, BigInt *n2) {
        //two positive number
        string str1 = n1->num;
        string str2 = n2->num;
        if(str1.length() < str2.length()) return -1;
        else if(str1.length()>str2.length()) return 1;
        else {
            //same length
            for(int i = 0; i < str1.length(); i++) {
                if(str1[i] < str2[i]) return -1;
                else if(str1[i] > str2[i]) return 1;
            }
            return 0;
        }
    }
    
    static BigInt* minus(BigInt* n1, BigInt* n2) {
        if(n1->neg != n2->neg) { //and add
            return add(n1, negate(n2));
        } else {
            if(n1->neg) return minus(abs(n2),abs(n1)); //both negative
            //both positive
            int cmp = compareIgnoreSign(n1, n2);
            if(cmp == 0) return new BigInt();
            if(cmp < 0) return negate(minus(n2,n1));
            //n1 > n2
            string str1 = n1->num;
            string str2 = n2->num;
            int bor = 0;
            for(int i=str1.length()-1, j = str2.length()-1; i >= 0; j--,i--) {
                int a = str1[i]-'0' - bor;
                int b;
                if(j >=0) b = str2[j] - '0';
                else b = 0;
                if(a < b) {
                    a += 10;
                    bor = 1;
                } else bor = 0;
                str1[i] = a-b+'0';
            }
            int i = 0;
            while(str1[i] == '0') i++;
            str1 = str1.substr(i);
            return new BigInt(str1);
        }
        
    }
    
    static bool IsZero(BigInt* n) {
        return n->num == "0";
    }
    
    static BigInt* multiply(BigInt* n1, BigInt* n2) {
        if(IsZero(n1) || IsZero(n2)) return new BigInt();
        string str1 = n1->num;
        string str2 = n2->num;
        int len = str1.length()+str2.length();
        vector<int> prod(len, 0);
        for(int i = str1.length()-1; i >= 0; i--) {
            for(int j = str2.length()-1; j >= 0; j--) {
                int k  = i+j+1;
                prod[k] += (str1[i]-'0') * (str2[j] -'0');
            }
        }
        
        for(int i = len-1; i > 0; i--) {
            if(prod[i] >= 100) {
                prod[i-2] += prod[i] / 10;
                prod[i] %= 100;
            }
            if(prod[i] >= 10) {
                prod[i-1] += prod[i] / 10;
                prod[i] %= 10;
            }
        }
        string str;
        for(int i=0; i < len; i++) str += '0'+prod[i];
        BigInt* res = new BigInt(str);
        if(n1->neg != n2->neg) return negate(res);
        return res;
    }
    
};

int main() {
    BigInt *num1 = new BigInt("-123000");
    BigInt *num2 = new BigInt("-234");
    //cout <<BigInt::add(num1,num2)->getNum()<<endl;
    //cout <<BigInt::minus(num1,num2)->getNum()<<endl;
    cout <<BigInt::multiply(num1,num2)->getNum()<<endl;
    return 0;
}
