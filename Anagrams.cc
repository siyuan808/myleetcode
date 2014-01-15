vector<string> anagrams(vector<string> &strs) {
    vector<string> res;
    if(strs.size() == 0) return res;
    unordered_map<string, vector<string>> hash;
    for(int i=0; i<strs.size(); i++) {
	string key = strs[i];
	sort(key.begin(), key.end());
	hash[key].push_back(strs[i]);
    }
    unordered_map<string, vector<string>>::iterator hit;
    for(hit = hash.begin(); hit != hash.end(); hit++) {
	if(hit->second.size() > 1) {
	    for(int i=0; i<hit->second.size();i++)
	        res.push_back(hit->second.at(i));
	}
    }
    return res;
}
