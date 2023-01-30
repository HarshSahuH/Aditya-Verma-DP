// min_number_of_insertions = min_number_of_deletions

int lcs(int n, int m, string A, string B)
   {
     // here n is the length of string A and m is length for string B  
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
                if(A[i-1]==B[j-1]){
                    t[i][j] = 1 + t[i-1][j-1]; 
                }
                
                else {
                    t[i][j] = max( t[i][j-1],t[i-1][j] );
                }
            }
        }
        
        return t[n][m];
    }
    
    int longestPalinSubseq(string A) {
        
        // LPS of string A = LCS of (string A , reverse of string A)
        // so reverse string A and store in a string B 
        string B = A;
        reverse(B.begin(),B.end() );
        
        int length_of_LPS = lcs(A.length(),B.length(),A,B);
        
        return  length_of_LPS;
      
    }
    
    int minDeletions(string str, int n) 
    { 
        int len = longestPalinSubseq(str);
        return n-len ;  
    } 

    int findMinInsertions(string S){
        
        int minInsertion = minDeletions(S,S.length());
        return minInsertion;
    }
};
