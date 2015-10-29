//O(nlgn) without additional space and not swap
int findDuplicate(vector<int>& nums) {
    int l = 1, r = nums.size()-1;
    while(l < r) {
        int m = l + (r-l)/2;
        //count all the number less or equal to m
        int cnt = 0;
        for(int x : nums) 
            if(x <= m) cnt++;
        if(cnt > m) r = m;
        else l = m+1;
    }
    return l;
}

//O(n), with swapping
int findDuplicate(vector<int>& nums) {
  int size  = nums.size();
  for(int ind = 0; ind < size; ind++) {
      int pos = ind;
      while(nums[pos] != pos+1) {
          int targetPos = nums[pos]-1;
          if(nums[targetPos] == targetPos+1) return nums[targetPos];
          //swap
          int tempVal = nums[targetPos];
          nums[targetPos] = nums[pos];
          nums[pos] = tempVal;
      }
  }
}  
  
  
