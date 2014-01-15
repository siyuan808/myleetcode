vector<vector<int>> perpute(vector<int> &num) {
    vector<vector<int>> res;
    if(num.size() == 0) return res;

    return perpute(num, num.size()-1);
  
}

vector<vector<int>> perpute(const vector<int> &num, int i) {
    vector<vector<int>> res;
    if(i==0) {
        vector<int> v;
	v.push_back(num[i]);
	res.push_back(v);
	return res;
    }
    vector<vector<int>> prev = perpute(num, i-1);

    for(int j=0; j<prev.size(); j++) {
	vector<int> inner = prev[j];
	for(int k=0; k<=inner.size(); k++){
	    inner.insert(inner.begin()+k, num[i]);
	    res.push_back(inner);
	    inner.erase(inner.begin()+k);
	}
    }
    return res;
}

//Another method of building each postion
vector<vector<int>> perpute(vector<int> &num) {
    vector<vector<int>> res;
    if(num.size() == 0) return res;
    vector<int> v(num.size(), 0);
    unordered_map<int, bool> used;
    for(int i=0; i<num.size(); i++)
        used[i] = false;
    build(num, used, v, 0, res);
    return res;
}

void build(const vector<int> &num, unordered_map<int, bool> &used, vector<int> &v,  int pos, vector<vector<int>> &res){
   if(pos == num.size()){
	res.push_back(v);
	return;
   }
   for(int i=0; i<num.size(); i++) {
	if(used[i] == false) {
	    used[i] = true;
	    v[pos] = num[i];
	    build(num, used, v, pos+1, res);
	    used[i] = false;
	}
   }
}

