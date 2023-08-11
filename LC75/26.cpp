//299. Bulls and Cows
class Solution {
public:
    string getHint(string secret, string guess) {

        int bulls = 0;
        int cows = 0;
        vector<int> secret_cnt(10, 0);


        for (int i = 0; i < secret.size(); i++)
            secret_cnt[secret[i] - '0']++;


        int dummy = (secret.size() < guess.size()) ? secret.size() : guess.size();
        for (int i = 0; i < dummy; i++) {
            if (guess[i] == secret[i]) {
                bulls++;
            }
            if (secret_cnt[guess[i] - '0']) {
                cows++;
                secret_cnt[guess[i] - '0']--;
            }
        }


        cows -= bulls;
        return to_string(bulls) + 'A' + to_string(cows) + 'B';
    }
};