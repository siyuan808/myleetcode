#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

class Solution {
public:
    vector<string> oneEditedWords(string s, const unordered_set<string> &dict) {
        vector<string> words;
        for(int  i = 0; i < s.length(); i++ ) {
            string w = s;
            for(char c = 'a'; c <= 'z'; c++) {
                w[i] = c;
                if(w != s && dict.find(w) != dict.end()) {
                    words.push_back(w);
                }
            }
        }
        return words;
    }
    
    void buildPath(string s, vector<string> &path, unordered_map<string, vector<string> > &childToFather, vector<vector<string> > &res) {
        string key = s;
        while(childToFather.find(key) != childToFather.end()) { //not start
            vector<string> v = childToFather[key];
            if(v.size() == 0) break;
            if(v.size() > 1) {
                for(int i = 0; i < v.size(); i++) {
                    path.insert(path.begin(), v[i]);
                    buildPath(v[i], path, childToFather, res);
                    path.erase(path.begin());
                }
            } else { // ==1
                path.insert(path.begin(),v[0]);
                key = v[0];
            }
        }
        res.push_back(path);
    }
    
    vector<vector<string> > findLadders(string start, string end, unordered_set<string> &dict) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        //Error check
        vector<vector<string> > res;
        if(start.length() != end.length() || start.length() <= 0) return res;
        vector<string> path;
        if(start == end) { path.push_back(end); res.push_back(path); return res;}
        
        unordered_map<string, vector<string> > childToFather;
        unordered_set<string> visited;
        unordered_set<string> current, next;
        
        current.insert(start);
        vector<string> dummy;
        childToFather[start] = dummy;
        
        bool find = false;
        
        while(!current.empty() && !find) {
            for(auto w : current) {
                visited.insert(w);
            }
            for(auto s: current) {
                vector<string> nextWords = oneEditedWords(s, dict);
                for(auto ns : nextWords) {
                    if(end == ns) {
                        //find a path, build a path
                        find = true;
                        path.clear();
                        path.push_back(end);
                        path.insert(path.begin(), s);
                        //build path
                        buildPath(s, path, childToFather, res);
                        break;
                    } 
                    if(!find) {
                        if(visited.find(ns) == visited.end() ) { // not visited
                            next.insert(ns);
                            childToFather[ns].push_back(s);
                        }
                    }
                }
            }
            current.clear();
            swap(current, next);
        }
        return res;
    }
};

int main() {
    unordered_set<string> dict;
    dict.insert(dict.end(), "red");
    dict.insert(dict.end(), "ted");
    dict.insert(dict.end(), "rex");
    dict.insert(dict.end(), "tex");
    dict.insert(dict.end(), "tad");
    dict.insert(dict.end(), "tax");

    Solution s;
    vector<vector<string> > paths = s.findLadders("red", "tax", dict);
    for(int i = 0; i < paths.size(); i++) { 
  	for(int j = 0; j < paths[i].size(); j++) 
	    cout <<paths[i][j] << " -> ";
        cout <<endl;
    } 
    return 0;
}
