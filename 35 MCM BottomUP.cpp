 vector<vector<int>> t;
    
    int solve(int i,int j,int arr[]){
      
       // step 2 base condition
       if(i>=j) return 0 ;
       
       
       if(t[i][j] != -1) return t[i][j];
       
           int mn = INT_MAX;
        // step 3  find k loop Scheme   start k=i   end k = j-1 
     for(int k=i; k<j; k++)
     {
         int tempAns = solve(i,k,arr)+solve(k+1,j,arr)+ arr[i-1]*arr[k]*arr[j];
         
        //step 4 calculate ans from tempAns 
        if(tempAns < mn)
        mn = tempAns;
     }
     
     return t[i][j]=mn; 
    }
    
    
    
    int matrixMultiplication(int N, int arr[])
    {
        t.resize(N+1,vector<int>(N+1,-1));
        int i= 1,j=N-1;
        int cost = solve(i,j,arr);
        return cost;
    }
