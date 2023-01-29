#include<bits/stdc++.h>
using namespace std;

int t[7][8];

int lcs(string s1, string s2, int n , int m){
// make table size depend on change input/variable 
        

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

string printLcSubstring(string X,string Y,int n,int m){
    int i=n;
    int j=m;
    string  s;
    while(i>0 && j>0){
     if(X[i-1]==Y[j-1]){
         s.push_back(X[i-1]);
         i--;
         j--;
     }   
     else{
         if(t[i][j-1]>t[i-1][j]){
             j--;
         }
         else{
            i--;
         }
     }
    }
    
    reverse(s.begin(),s.end());
    return s; 
}

int main()
{
    string X = "acbcf";
    string Y = "abcdaf";
    int n = X.length();
    int m = Y.length();
    int length = lcs(X, Y, n, m);
    cout<<length<<endl;
    string y = printLcSubstring(X,Y,n,m);
    cout<<y;
    return 0;
}
