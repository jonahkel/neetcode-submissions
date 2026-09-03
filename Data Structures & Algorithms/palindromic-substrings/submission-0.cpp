/*

O(1) plan:

A substring is a palindrome if the surrou

*/


class Solution {
private:
    std::vector<std::vector<int8_t>> is_palindrome;
public:

    int helper(string& s, int i, int j){
        if (is_palindrome[i][j] != -1) {
            return is_palindrome[i][j];
        }
        else if (j == i+1){
            is_palindrome[i][j] = (s[i] == s[j]) ? 1 : 0;
        }
        else{
            is_palindrome[i][j] = (s[i] == s[j]) ? helper(s, i+1, j-1) : 0;
        }
        return is_palindrome[i][j];
    }

    int countSubstrings(string s) {
        is_palindrome = vector<vector<int8_t>>(s.size(), vector<int8_t>(s.size(), -1));
        for (int i = 0; i < s.size(); ++i){
            is_palindrome[i][i] = 1;
        }
        int num_palindromes = 0;
        for (int i = 0; i < s.size(); ++i){
            for (int j = i; j < s.size(); ++j){
                if (helper(s, i, j)) num_palindromes++;
            }
        }

        return num_palindromes;

    }
};
