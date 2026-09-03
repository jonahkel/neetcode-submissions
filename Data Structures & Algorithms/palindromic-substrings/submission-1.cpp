/*

A substring is a palindrome if the first and last letter are the same 
and the internal substring is a palindrome

O(n^2) space solution: keep a 2D array of whether each substring is a palindrome,
and iterate over each substring

O(1) space solution: Iterate over every possible "center", starting with the biggest range around it. One or two letters can be a center, latter if the letters are the same.

Two pointers: both start at 0.
Recursively find if palindrome, updating global counter.

Increment right pointer untul it hits end, then increment left pointer.

*/


class Solution {
private:
    int palindrome_count;
public:

    bool helper(string& s, int i, int j){
        if (i == j){
            ++palindrome_count;
            return true;
        } else if (j == i+1){
            if (s[i] == s[j]) {
                ++palindrome_count;
                return true;
            }
            return false;
        }
        else {
            if (helper(s, i+1, j-1) && s[i] == s[j]){
                ++palindrome_count;
                return true;
            } else {
                return false;
            }
        }
    }

    int countSubstrings(string s) {
        palindrome_count = 0;
        for (int j = 0; j < s.size(); ++j){
            helper(s, 0, j);
        }
        for (int i = 1; i < s.size(); ++i){
            helper(s,i,s.size()-1);
        }

        return palindrome_count;

    }
};
