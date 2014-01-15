class Solution {
public:
    string convert(string s, int nRows) {
            // Start typing your C/C++ solution below
	    //         // DO NOT write int main() function    
 	string res("");
	if(nRows<=0) return res;
	//append the first line
	int i=0;
	while(i<s.size()) {
	    res.push_back(s[i]);
	    i+= (2*nRows -2);
	}
	//append the middle lines
	for(int row = 1; row < nRows-1 ; row++) {
	    int i=row;
	    while(i<s.size()) {
		res.push_back(s[i]);
		res.push_back(s[i+ 2*nRows-2 -row*2]);
		i+= (2*nRows -2);
	    }
	}
	//append the last line;
        i=nRows-1;
	while(i<s.size()){
	    res.push_back(s[i]);
	    i+=(2*nRows-2);
	}
	return res;
    }
    
    //method 2
    string convert(string s, int nRows) {
	if(nRows == 1) return s;
	string res = "";
	int diff = 2*nRows -2;
	for(int i = 0; i<nRows; i++) {
	    int index = i;
	    while(index < s.length()) {
		res += s[index];
		index += diff;
		if(i!=0 && i!=nRows-1 &&index-2*i<s.length()){
		    res += s[index-2*i];
		}
	    }
	}
        return res;
    }
 
};
