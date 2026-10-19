class Solution {
public:
    bool isAlphaNum(char c)
    {
        return (c >= 'A' && c <= 'Z' ||
                c >= 'a' && c <= 'z' ||
                c >= '0' && c <= '9');
    }
    bool isPalindrome(string s) {
        int l = 0;
        int r = s.length()-1;

        while(l<r)
        {
            if(!isAlphaNum(s[l]))
            {
                l++;
            }else if(!isAlphaNum(s[r]))
            {
                r--;
            }
            else if(tolower(s[l]) != tolower(s[r])){
                return false;
            }else{
                l++;
                r--;
            }
        }
        return true;
    }
};
