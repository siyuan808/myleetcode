vector<vector<int> > combine(int n, int k) {
    
    vector<vector<int>> res;
    if(k<=0) return res;
    for(int i=1; i<=n; i++) {
	vector<int> init;
	init.push_back(i);
	res.push_back(init);
    }
 
    return combine(res, 2, n, k);
   
}

vector<vector<int>> combine(vector<vector> &oldV, int c, int n, int k) {
    if(c > k) return oldV;
    vector<vector<int>> newV;
    for(int i=0; i<oldV.size();i++) {
	if(oldV[i].size() == c-1) 
	{
	    if(n > oldV[i].back()) {
		for(int j=oldV[i].back()+1; j<=n;j++) {
		    vector<int> v = oldV[v];
		    v.push_back(j);
		    newV.push_back(v);
		}
	    }
	}
    }

    return combine(newV, c+1, n, k);
}

//another method 
vector<vector<int>> combine(int n, int k) {
    if(n<k) return NULL;
    vector<vector<int>> res;
    if(k<=0) return res;

    if(k==1) {
	for(int i=1; i<=n; i++){
	    vector<int> one;
	    one.push_back(i);
	    res.push_back(one);
	}
	return res;
    }

    for(int i=n; i>=k; i++) {
	vector<vector<int>> v = combine(i-1, k-1);
        for(int j=0; j<v.size(); j++) {
	    v[j].push_back(i);
	    res.push_back(v[j]);
	}
    }
    return res;
}

//Another method of building on the numbers
vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> res;
    if(k<=0 || n<k) return res;
    vector<int> v(k, 0);
    build(n, k, 0, 1, v, res);
    return res;
}

void build(int n, int k, int pos, int start, vector<int> &v, vector<vector<int>> &res) {
    if(pos == k) {
	res.push_back(v);
	return;
    }
    for(int i= start; i<=n; i++) {
	v[pos] = i;
	build(n, k, pos+1, i+1, v, res);
    }
}
