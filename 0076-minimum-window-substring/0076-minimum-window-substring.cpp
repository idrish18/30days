class Solution {
public:
    string minWindow(string s, string t) {
        if (s.empty() || t.empty()) return "";

        unordered_map<char, int> need, window;
        for (char c : t) need[c]++;

        int have = 0, needCount = need.size();
        int left = 0, right = 0;
        int minLen = INT_MAX, start = 0;

        while (right < s.length()) {
            char c = s[right];
            window[c]++;
            
            if (need.count(c) && window[c] == need[c]) {
                have++;
            }

            // Try to shrink the window from the left
            while (have == needCount) {
                if ((right - left + 1) < minLen) {
                    minLen = right - left + 1;
                    start = left;
                }

                // Remove from the left
                window[s[left]]--;
                if (need.count(s[left]) && window[s[left]] < need[s[left]]) {
                    have--;
                }
                left++;
            }

            right++;
        }

        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};