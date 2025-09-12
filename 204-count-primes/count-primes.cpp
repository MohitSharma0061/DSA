class Solution {
public:
    int countPrimes(int n) {
        int cnt = 0;
        vector<bool> prime(n+1, true);   // keep n+1 as you had
        if (n <= 1) return 0;            // handle small n
        prime[0] = prime[1] = false;

        for (int i = 2; i < n; i++) {
            if (prime[i]) {
                cnt++;
                // FIX: step should be j += i, not j++
                for (long long j = 1LL * i * i; j < n; j += i) {
                    prime[j] = false;
                }
            }
        }
        return cnt;
    }
};
