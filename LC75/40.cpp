//2131. Longest Palindrome by Concatenating Two Letter Words
class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> mp;

        //storing occurances of all words
        for (auto i : words) mp[i]++;

        //this variable will be used later
        bool flag = false;
        int ans = 0;

        //iterating our map
        for (auto i : mp) {

            string temp = i.first;
            reverse(temp.begin(), temp.end());

            //checking if it is palindrome word itself and the count of it is odd
            //this word can be inserted in the middle of our palindrome as it is palindrome itself
            //but this can be done only once 

            if (temp == i.first and i.second % 2 != 0 and flag == false) {
                //we mark our flag to true because we want to insert this element only once in the middle
                flag = true;
                ans += 2;
                mp[temp]--;
            }

            //checking if the word as well its reverse exist in the map
            if (mp.find(i.first) != mp.end() and mp.find(temp) != mp.end()) {

                //for the case when the word is not palindrome we will increase our ans by minimum of the count of word in the map and reverse of word in the map multiplied by 4
                if (i.first != temp) {
                    ans += min(mp[i.first], mp[temp]) * 2 * 2;
                    mp[i.first] = mp[temp] = 0;
                }
                //for the case when it is palindrome we just divide the count of the word by 2 and then multiply by 4 and add to the ans
                else {
                    ans += mp[temp] / 2 * 2 * 2;
                    mp[i.first] = mp[temp] = 0;

                }
            }
        }
        return ans;

    }
};