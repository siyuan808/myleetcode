#include <iostream>
#include <string>
using namespace std;
    
    
    bool dfs(string &s1, int p1, string &s2, int p2, string &s3, int p3) {
        if(p3 == s3.length()) return true;
        if(s1[p1] != s2[p2]) {
            if(s1[p1] == s3[p3]) 
                return dfs(s1, p1+1, s2, p2, s3, p3+1);
            else if(s2[p2] == s3[p3])
                return dfs(s1, p1, s2, p2+1, s3, p3+1);
            else return false;
        } else {
            // s1[p1] == s2[p2]
            //try s1[p1]
            if(dfs(s1, p1+1, s2, p2, s3, p3+1))
                return true;
            else return dfs(s1, p1, s2, p2+1, s3, p3+1);
        }
    }

    bool isInterleave(string s1, string s2, string s3) {
        if(s1.length() + s2.length() != s3.length()) return false;
        return dfs(s1, 0, s2, 0, s3, 0);
    }

int main() {
    string s1; cin >>s1;
    string s2; cin >>s2;
    string s3; cin >>s3;
    cout <<"Is "<<s3<<" interveaving string of "<<s1 << " and "<<s2<<" "<<isInterleave(s1,s2,s3)<<endl;    return 0;    
}
