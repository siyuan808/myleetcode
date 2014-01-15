int numDistinct(string S, string T) {
    // we can derive this DP function
    // f(i, j) = f(i+1, j) + (s[i]==T[j])*f(i+1, j+1)
    vector<int> f(T.size()+1);
    f[T.size()] = 1;
    for(int i = S.size()-1; i >= 0; i--) 
        for(int j = 0; j < T.size(); j++) 
	    f[j] += (S[i] == T[j]) * f[j+1];
    return f[0];
}
