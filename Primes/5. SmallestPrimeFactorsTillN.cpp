/* Find smallest prime factor of numbers from 1 to N 
Problem Link : https://practice.geeksforgeeks.org/problems/least-prime-factor5216/1
Time : O(N log(log(N))
Space : O(N)
*/

class Solution {
  public:
    vector<int> leastPrimeFactor(int n) {
        vector<int> spf(n+1);
        // create initial array - each value equal to index
        for(int i=1; i<=n; i++)
            spf[i] = i;

        // update Smallest Prime Factor using sieve
        for(int i=2; i*i<=n; i++){
            if(spf[i] == i){      // prime number
                for(int j=i*i; j<=n; j=j+i)
                    if(spf[j] == j)       // not yet marked
                        spf[j] = i;       // mark it
            }
        }
        return spf;
    }
};
