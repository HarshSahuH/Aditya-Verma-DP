 
 
 long long trappingWater(int arr[], int n){
 
         int mxL[n];    // this array will store maximum value in left of arr of that particular arr[i]
         mxL[0]=arr[0];
         for(int i=1; i<n; i++){
          mxL[i]=max(arr[i],mxL[i-1]);  
         }
        
        int mxR[n] ;    // this array will store maximum value in right of arr of that particular arr[i]
        mxR[n-1]=arr[n-1];
        for(int i=n-2;i>=0;i--){
            mxR[i]=max(arr[i],mxR[i+1]);
        }
        
        long long  water[n];
        for(int i=0; i<n; i++){
            water[i]=( min(mxL[i],mxR[i]) - arr[i] );
        }
        
        long long sum = 0 ;
        for(int i=0; i<n; i++){
            sum = sum + water[i];
        }
        return sum;
        }
