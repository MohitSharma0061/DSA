class Solution {
public:
    int compress(vector<char>& chars) {
        
        int i = 0; 
        int ansindex = 0;
        int n = chars.size();
        while (i < n) {
            int j = i + 1;
            while (j < n && chars[i] == chars[j]) {
                j++;
            }
            // yaha kab aainge 
            // case 1.ya toh vector poora traverse ho jaiga tb 
            // case 2. ya koi different character aa ja tb

            // old character store kr lo
            chars[ansindex++] = chars[i];

            int count = j - i;   // FIXED: pehle galat j-1 likha tha, ab sahi count h
            if (count > 1) {
                // count ko string me convert kro aur har digit ko store kr lo
                string cnt = to_string(count);
                for (char ch : cnt) {
                    chars[ansindex++] = ch;
                }
            }
            // ab naye different character pe move kr jao
            i = j;   // FIXED: pehle sirf if ke andar tha, ab hamesha hoga
        }
        return ansindex;
    }
};
