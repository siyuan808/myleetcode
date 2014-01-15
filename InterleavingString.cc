class Solution {

public:
    bool isInterleave(string s1, string s2, string s3) {
            // Start typing your C/C++ solution below
	    //         // DO NOT write int main() function    
  	/*This algorithm costs too much time if there are a lot of same letter*/
   	if(s3.length() != s1.length() + s2.length())
	    return false;
	return isInterleave(s1, 0, s2, 0, s3, 0);
    }

    bool isInterleave(sting &s1, int p1, string &s2, int p2, string &s3, int p3) {
	if(p3==s3.length())
	    return true;
	if(p1==s1.length())
	    return (s3[p3] == s2[p2])&& isInterleave(s1, p1, s2, p2+1, s3, p3+1);
	if(p2==s2.length())
	    return (s3[p3] == s1[p1]) && isInterleave(s1, p1+1, s2, p2, s3, p3+1);
	if(s3[p3] != s1[p1] && s3[p3] != s2[p2])
	    return false;
	if(s1[p1] == s2[p2])
	    return isInterleave(s1, p1+1, s2, p2, s3, p3+1) ||
	    	   isInterleave(s1, p1, s2, p2+1, s3, p3+1);
	else if(s3[p3] == s1[p1])
	    return isInterleave(s1, p1+1, s2, p2, s3, p3+1);
	else return isInterleave(s1, p1, s2, p2+1, s3, p3+1);
    }
};
