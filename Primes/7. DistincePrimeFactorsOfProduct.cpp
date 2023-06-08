/* 2521. Distinct Prime Factors of Product of Array
Problem Link : 
https://leetcode.com/problems/distinct-prime-factors-of-product-of-array/
Solution : 
Approach 1 : https://leetcode.com/problems/distinct-prime-factors-of-product-of-array/submissions/966428965/
Approach 2 : https://leetcode.com/problems/distinct-prime-factors-of-product-of-array/submissions/966440940/
*/

/* Approach 1 :find prime factors of individual element and insert in set
Distint prime factors of product of array is same as distinct prime factors of individual elements
Eg: 4 - 2 * 2
    6 - 2 * 3
4*6 = 24 = 2 * 2 * 2 * 3
In both ways , distince prime factors will be 2 and 3.
So we will find prime factors of individual elements and insert in set for unique
Time : O(n * sqrt(R))  // sqrt(R) to find each prime factor of element with value R
Space : O(n)           // for unordered set
*/

class Solution {
public:
    void process(int num, unordered_set<int>& st){
        // loop from 2 to sqrt(num)
        for(int i=2; i*i <= num; i++) {
            if(num % i == 0){           // prime factor
                st.insert(i);           // insert in set
                while(num % i == 0)     // process all duplicate prime factors
                    num /= i;        
            }
        }
        // to handle case , if number has a prime factor greater than sqrt(num) 
        // Eg - 10 -> 2, 5.  5 is greater than sqrt(10) -> 3
        if(num > 1)
            st.insert(num);
    }
    int distinctPrimeFactors(vector<int>& nums) {
        unordered_set<int> st;
        for(int num : nums)
            process(num,st);
        return st.size();
    }
};

/* Approach 2 : Sieve of Eratothenes
We can optimize finding prime factors using sieve method
1. Create Smallest prime factor array (size 1001) using Sieve of eratothenes
2. Find prime factors of individual element using spf array and insert in set 

Time : O(n * log(R))  // log(R) to find prime factors of element with value R using spf array
Space : O(n)           // spf array + unordered set
*/
class Solution {
public:
    int distinctPrimeFactors(vector<int>& nums) {
        int N = 1001;           // 2 <= nums[i] <= 1000
        vector<int> spf(N+1);
        // create initial array - each value equal to index
        for(int i=1; i<=N; i++)
            spf[i] = i;

        // update Smallest Prime Factor using sieve
        for(int i=2; i*i<=N; i++){
            if(spf[i] == i){                    // prime number
                for(int j=i*i; j<=N; j=j+i)
                    if(spf[j] == j)             // not yet marked
                        spf[j] = i;             // mark it
            }
        }
        
        // find prime factors using spf array and use set for unique
        unordered_set<int> st;
        for(int num : nums) { 
            while(num != 1) { 
                st.insert(spf[num]);
                num /= spf[num];
            }
        }
        return st.size();
    }
};
