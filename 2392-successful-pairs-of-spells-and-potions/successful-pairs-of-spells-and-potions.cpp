class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
    sort(potions.begin(), potions.end());
    int n = spells.size(), m = potions.size();
    vector<int> answer;

    for (int i = 0; i < n; i++) {
        long long minPotion = (success + spells[i] - 1) / spells[i];  // ceiling division
        auto it = lower_bound(potions.begin(), potions.end(), minPotion);
        int count = potions.end() - it;  // all potions from it to end are successful
        answer.push_back(count);
    }

    return answer;
}

};