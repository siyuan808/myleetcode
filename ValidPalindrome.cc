class Solution {
public:
    bool isPalindrome(string s) {
            // Start typing your C/C++ solution below
	    //         // DO NOT write int main() function
  	if(s==NULL) return false;
	if(s.empty()) return true;
	char ch[s.length()];
	int chLen = 0;
	for(int i=0; i<s.length(); i++) {
	    char c = s[i];
	    if( c >='0' && c<='9'|| c>='a'&& c<='z') 
	        ch[chLen++] = c;
	    else if(c >= 'A' && c<='Z')
	        ch[chLen++] = tolower(c);
	}

	//now we have the ch with len of chLen
	for(int i=0; i< chLen/2; i++) {
	    if(ch[i] != ch[chLen-1-i])
	        return false;
	}
	return true;
    }
    //Acutally we do not need to create a new char 
    bool isPalindrome(string s) {
	int i=0, j=s.length()-1;
	while(i<=j) {
	    if(!isAlphaNum(s[i])) i++;
	    else if(!isAlphaNum(s[j])) j--;
	    else if(tolower(s[i]) != tolower(s[j]))
	        return false;
	    else {
	        i++;
		j--;
   	     }
	}
	return true;
    }

    bool isAlphaNum(char c) {
	return (c>='0'&&c<='9' || c>='a'&&c<='z' || c>='A' && c<='Z');
    }
};
