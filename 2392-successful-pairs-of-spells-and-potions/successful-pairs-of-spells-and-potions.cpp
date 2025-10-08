class Solution {
public:
vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        // Step 1: Sort potions array
        sort(potions.begin(), potions.end());
        int m = potions.size();
        vector<int> ans;

        // Step 2: For each spell, find how many potions can make success
        for (int i = 0; i < spells.size(); i++) {
            long long spellPower = spells[i];

            // Step 3: Calculate minimum potion needed to achieve success
            long long minPotion = (success + spellPower - 1) / spellPower; // ceiling division

            // Step 4: Binary search (using lower_bound)
            int index = lower_bound(potions.begin(), potions.end(), minPotion) - potions.begin();

            // Step 5: Remaining potions are successful
            int count = m - index;

            ans.push_back(count);
        }

        return ans;
    }
};
