string countAndSay(int n) {
    string s(""); 
    if(n<=0) return s; 
    if(n==1) {
        s+="1";
    }
    else {
    	string prev = countAndSay(n-1);
	int cnt = 0;
	char c = prev[0];
	for(int i=1; i<prev.length(); i++) {
	    if(prev[i] == c) {
		cnt++;
	    } else {
		s += to_string(cnt);
		s += c;
		cnt = 1;
		c = prev[i];
	    }
	}
	s += to_string(cnt);
	s += c;
    }
    return s;
    
}
