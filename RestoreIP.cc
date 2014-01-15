vector<string> restoreIpAddresses(string s) {
    vector<string> res;
    int part[3];
    restore(s, 0, part, res);
    return res;
}

bool checkOneIP(const string s) {
    if(s.length() > 1 && s[0] == '0' || stoi(s) > 255)
        return false;
    return true;
}

void restore(const string s, int n, int part[], vector<string> &res) {
    int start = 0;
    int i=0;
    if(n>0) start += part[n-1]+1;

    int left = s.length() - start;
    if(left < (4-n) || left > 3*(4-n))
        return;

    if(n == 3) {
        string last_ip = s.substr(part[2]+1);
	if(!checkOneIP(last_ip))
	    return;
	string ip;
	ip += s.substr(0, part[0]+1) + "." + s.substr(part[0]+1, part[1]-part[0])
	        + "." + s.substr(part[1]+1, part[2]-part[1]) + "." + s.substr(part[2]+1);
	res.push_back(ip);
	return;
    }

    for(i = 1; i<= 3; i++) {
	string one_ip = s.substr(start, i);
	if(checkOneIP(one_ip)) {
	    part[n] = start + i -1;
	    restore(s, n+1, part, res);
	} else 
	    break;
    }
}
