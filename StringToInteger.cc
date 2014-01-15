class Solution {
public:
    int atoi(const char *str) {
            // Start typing your C/C++ solution below
	    //         // DO NOT write int main() function
	int p=0;
	int ret = 0;
	while(str[p] == ' ') p++;
	int sign = 1;
	if(str[p] == '-') {
	    sign = -1;
	    p++;
	}else if(str[p] == '+') {
	    p++;
	}

	while(str[p] != '\0') {
	    if(str[p] >= '0' && str[p] <= '9') {
		if( ret > 214748364 || ret==214748364 && ((str[p] -'0') > 7))
		    return sign==1? INT_MAX:INT_MIN;
		else
		    ret = ret*10 + (str[p]-'0')
	    } else {
		break;
	    }
	    p++;
	}
	return sign*ret;
    }
};
