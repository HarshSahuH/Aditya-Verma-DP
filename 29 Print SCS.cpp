#include<bits/stdc++.h>
#include <iostream>
using namespace std;

string printShortestSuperSeq(string X,string Y){

int m = X.length();
int n = Y.length();
int t[m+1][n+1];

// this is LCS code
//intializing first row and first col based on base condition of recusive solution 
        for(int i=0; i<m+1; i++){
            for(int j=0;j<n+1; j++){
                if(i==0 || j==0){
                    t[i][j] = 0;
                }
            }
        }
        
// filling other t[][] box   based on choice diagram   
        for(int i=1; i<m+1; i++){
            for(int j=1; j<n+1; j++){
                if(X[i-1]==Y[j-1]){
                    t[i][j] = 1 + t[i-1][j-1]; 
                }
                
                else {
                    t[i][j] = max( t[i][j-1],t[i-1][j] );
                }
            }
        }
        
    //we done with t[][] , with the help of LCS;
    
    //now printing SCS
    
    int i=m;
    int j=n;
    string  s="";
    
    while(i>0 && j>0){
     if(X[i-1]==Y[j-1]){
         s.push_back(X[i-1]);
         i--;
         j--;
     }   
     else{
         if(t[i][j-1]>t[i-1][j]){
             s.push_back(Y[j-1]);
             j--;
         }
         else{
            s.push_back(X[i-1]); 
            i--;
         }
     }
    }
    
    while(i>0){
        s.push_back(X[i-1]);
        i--;
    }
    
    while(j>0){
        s.push_back(Y[j-1]);
        j--;
    }
    
    reverse(s.begin(),s.end());
    return s; 
}

int main()
{
    string X = "acbcf";
    string Y = "abcdaf";
    int m = X.length();
    int n = Y.length();
    cout << printShortestSuperSeq(X, Y)<<endl;
    return 0;
}
