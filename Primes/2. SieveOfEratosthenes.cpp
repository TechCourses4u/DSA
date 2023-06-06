 /* Count All primes less than N  
 Problem Link : https://leetcode.com/problems/count-primes/
Approach : Sieve of Eratosthenes
1. Create Sieve Array
2. Scan Sieve array and count primes
Time : O(n * log(log(n)))
Space : O(n)
*/

class Solution {
public:
    int countPrimes(int n) {
        // Create Sieve vector
        vector<bool> sieve(n+1, true);
        for(int i=2; i*i<=n; i++){
            if(sieve[i]){
                for(int j=i*i; j<=n; j=j+i)
                    sieve[j] = false;
            }
        }

        // count primes
        int ans =0;
        for(int i=2; i<n;i++)
            if(sieve[i])
                ans++;

        return ans;
    }
};
