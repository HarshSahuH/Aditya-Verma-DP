class Solution {
public:
int lcs(int n, int m, string s1, string s2){
        
    // make table size depend on change input/variable 
        int t[n+1][m+1];

        //intializing first row and first col based on base condition of recusive solution 
        for(int i=0; i<n+1; i++){
            for(int j=0;j<m+1; j++){
                if(i==0 || j==0){
                    t[i][j] = 0;
                }
            }
        }
        
    // filling other t[][] box    base on choice diagram   
        for(int i=1; i<n+1; i++){
            for(int j=1; j<m+1; j++){
                if(s1[i-1]==s2[j-1]){
                    t[i][j] = 1 + t[i-1][j-1]; 
                }
                
                else {
                    t[i][j] = max( t[i][j-1],t[i-1][j] );
                }
            }
        }
        
        return t[n][m];
    }
    bool isSubsequence(string a, string b) {
      int lcs_len = lcs(a.length(),b.length(),a,b);
        
        if(lcs_len==a.length())
        return true;
        
        else 
        return false;
    }
};
