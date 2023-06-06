/* Sieve method to find prime factors of a number - multiple queries
Problem Link : https://practice.geeksforgeeks.org/problems/prime-factorization-using-sieve/1
Time : 
O(N * log(log(N))) – once for creating spf
O(Q * log N) -- log Nfor each query to find prime factors

Space : O(N)
*/

class Solution {
  public:
    void sieve() {}

    vector<int> findPrimeFactors(int N) {
        vector<int> spf(N+1);
        // create initial array - each value equal to index
        for(int i=1; i<=N; i++)
            spf[i] = i;

        // update Smallest Prime Factor using sieve
        for(int i=2; i*i<=N; i++){
            if(spf[i] == i){      // prime number
                for(int j=i*i; j<=N; j=j+i)
                    if(spf[j] == j)       // not yet marked
                        spf[j] = i;       // mark it
            }
        }
        
        // find primes using spf array
        vector<int> primes; 
        while(N != 1){
            primes.push_back(spf[N]);
            N /= spf[N];
        }
        return primes;
    }
};
