class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length())
            return false;

        unordered_map<char, int> freq;

        for (int i = 0; i < s.length(); i++) {
            freq[s[i]]++;   // fix: use s[i], not s[ns_]
        }

        for (int i = 0; i < t.length(); i++) {
            freq[t[i]]--;   // fix: proper loop that advances
        }

        for (auto& p : freq) {
            if (p.second != 0)  // fix: all counts must be zero
                return false;
        }
        return true;
    }
};