class Solution {
public:
    int maxDepth(string s) {
        int maxi = 0;
        stack<char> st;

        for (char c : s) {
            if (c == '(') {
                st.push(c);
                maxi = max(maxi, (int)st.size());
            }

            if (c == ')') {
                st.pop();
            }
        }

        return maxi;
    }
};