int sqrt(int x) {
    
    if(x<1) return x;
    int left = 0, right = x, mid;
    while(right > left) {
	mid = (left+right)/2;
	if(mid*mid == x)
	    return mid;
	else if(mid*mid < x) 
	    left = mid+1;
	else 
	    right = mid-1;
    }
    return left;

}
