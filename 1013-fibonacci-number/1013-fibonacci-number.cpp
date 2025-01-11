class Solution {
public:

    //--------------------------normal recursion---------------------
    int solve_using_recursion(int n){
        //base case
        if (n==0){
            return 0;
        }
        if (n==1){
            return 1;
        }
        //recursive relation
        int ans = solve_using_recursion(n-1) + solve_using_recursion(n-2);
        return ans;
    }


 
    //------------------------------------Top-Down approch---------------------------------
    //Rec+Memo
    int solve_using_memoization(int n,vector<int> &dp){
         if (n==0){
            // dp[n]=0;
            return 0;
        }
        if (n==1){
            // dp[n]=1;
            return 1;
        }
        //s-3: ans already present in dp so return that ans
        if(dp[n]!=-1){
            return dp[n];
        }
        //s-2: store and return dp array
         dp[n] = solve_using_memoization(n-1,dp) + solve_using_memoization(n-2,dp);
        return dp[n];
    }



        // -------------------------------  Tabulation Method  -------------------
        int using_Tabulation(int n){
            //s-1:create_DP_array
            vector<int> dp(n+1,-1);

            //s-2:
            dp[0]=0;
            if(n==0){
                return dp[0];
            }
            dp[1]=1;

            for(int i=2;i<=n;i++){
                //copy recursive logic
                dp[i]=dp[i-1]+dp[i-2];
            }
            return dp[n]; 
        }
        


    int fib(int n) {

    //--------------------------normal recursion---------------------
        // int ans=solve_using_recursion(n);
        // return ans;



    //------------------------------------Top-Down approch---------------------------------

    //s-1:create_DP_array
    // vector<int> dp(n+1,-1);
    // int ans=solve_using_memoization(n,dp);
    // return ans;
     

      // -------------------------------  Tabulation Method  -------------------
    

    

    //s-3:
   int ans=using_Tabulation(n);
   return ans; 





    }
};