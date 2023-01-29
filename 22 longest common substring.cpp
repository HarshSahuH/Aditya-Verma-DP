 int longestCommonSubstr (string S1, string S2, int n, int m)
    {
      
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
                if(S1[i-1]==S2[j-1]){
                    t[i][j] = 1 + t[i-1][j-1]; 
                }
                
                else {
                    t[i][j] = 0;
                }
            }
        }
        
        
        // we have to return the max value in the matrix and not t[m][n].
        // Just traverse through the matrix once and store max value in a variable
        // and return that
        int mx = INT_MIN;
        for(int i = 0; i<n+1; i++){
            for(int j = 0; j<m+1; j++){
                mx = max(mx,t[i][j]);
            }
        }
        return mx;
    }
