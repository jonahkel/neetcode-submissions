/*

eeetcode
neeetcode
neetcode

neetcode

eetcode
neetcode

For each character that disagrees, we have two main options: 
Remove the letter in the first word
Add the letter in the second word

Note that adding a letter to the second word is equivalent to removing that letter from the top word

Likewise, adding a letter to both words at the same time is equivalent to a replacement

Main idea, is keep going through words, adding letters until words match.

Always add to shorter word to keep lengths close

Example:

monkeys
money

monkeys
monkey

monkey
monkeys

answer: 2

neat
neetcode

neetcoat
neetcode

neeatcodee
neeatcode

None of this works...maybe a more direct DP approach?

Once there's a difference, split into 3 paths, based on the three options:

If either word is at the end, we know we need to insert/remove the difference
in word length

Otherwise try all three options


Keep best number so far and use backtracking?
Also use DP to keep track of found solutions?

*/

class Solution {
private:
    std::vector<std::vector<int>> strings_distance;
public:

    int helper(const string& word1, const string& word2, const int ptr1, const int ptr2) {
        if (strings_distance[ptr1][ptr2] != -1) return strings_distance[ptr1][ptr2];
        if (ptr1 < word1.size() && ptr2 < word2.size()) {
            if (word1[ptr1] == word2[ptr2]) {
                strings_distance[ptr1][ptr2] = helper(word1, word2, ptr1+1, ptr2+1);
            }
            else {
                int remove_changes = helper(word1, word2, ptr1+1, ptr2);
                int replace_changes = helper(word1, word2, ptr1+1, ptr2+1);
                int insert_changes = helper(word1, word2, ptr1, ptr2+1);
                strings_distance[ptr1][ptr2] = 1+std::min(replace_changes, std::min(
                    remove_changes, insert_changes
                ));

            }
        }
        else if (ptr1 == word1.size()){
            strings_distance[ptr1][ptr2]= word2.size()-ptr2;
        }
        else if (ptr2 == word2.size()) {
            strings_distance[ptr1][ptr2] = word1.size()-ptr1;
        }

        return strings_distance[ptr1][ptr2];

    }

    int minDistance(string word1, string word2) {
        strings_distance = std::vector<std::vector<int>>(word1.size()+1, std::vector<int>(word2.size()+1, -1));
        return helper(word1, word2, 0, 0);
    }
};