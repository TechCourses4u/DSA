/* Find all unique prime factors of a number
Problem Link : https://practice.geeksforgeeks.org/problems/prime-factors5052/1
Time : O(sqrt(N))
Space : O(1)
*/
class Solution{
	public:
	vector<int>AllPrimeFactors(int N) {
	    vector<int> primes;
	    // loop from 2 to sqrt(N) 
        for (int i = 2; i*i <= N; i++) {
            if (N % i == 0) {
	            primes.push_back(i);
                while (N % i == 0)
                    N /= i;
            }
        }
        // to handle case , if number has a prime factor greater than sqrt(num) 
        // Eg - 10 -> 2, 5.  5 is greater than sqrt(10) -> 3
        if (N > 1)
            primes.push_back(N);
        return primes;
	}
};
