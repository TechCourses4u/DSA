/* Find primes in range L to R inclusive
Problem Link : https://practice.geeksforgeeks.org/problems/count-primes-in-range1604/1
Time : O(R log(log(R))
Space : O(R)
*/
class Solution {
  public:
    
    int countPrimes(int L, int R) {
        int n = R+1;
        // Create Sieve Array
        vector<bool> sieve(n+1, true);
        for(int i=2; i*i<=n; i++){
            if(sieve[i]){
                for(int j=i*i; j<=n; j=j+i)
                    sieve[j] = false;
            }
        }
        sieve[0]=sieve[1]=false;
        // Create PrefixSum Array from Sieve array
        vector<int> prefixSum(n+1, 0);
        for(int i=1; i<=n; i++)
             prefixSum[i] = prefixSum[i-1] + sieve[i];
        
        // Use prefixSum array to return result in O(1)
        return prefixSum[R] - prefixSum[L-1];
    }
};
