class Solution {
public:
    bool checkStrings(string s1, string s2) {
        if (s1 == s2) return true;

        int n = s1.length();

        map<char, int> em;  // even map
        map<char, int> om;  // odd map

        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                em[s1[i]]++;
                em[s2[i]]--;

                if (em[s1[i]] == 0) em.erase(s1[i]);
                if (em[s2[i]] == 0) em.erase(s2[i]);

            } else {
                om[s1[i]]++;
                om[s2[i]]--;

                if (om[s1[i]] == 0) om.erase(s1[i]);
                if (om[s2[i]] == 0) om.erase(s2[i]);
            }
        }

        return em.empty() && om.empty();
    }
};