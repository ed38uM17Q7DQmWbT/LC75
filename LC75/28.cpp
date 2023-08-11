//394. Decode String
class Solution {
public:
    string decodeString(string input) {
        stack<string> chrstack;
        stack<int> numstack;
        int num = 0;
        string dummy;
        string solution;


        for (int i = 0; i < input.size(); i++) {
            if (isdigit(input[i])) {
                num = num * 10 + (input[i] - '0');
            }
            if (input[i] == '[') {
                numstack.push(num);
                num = 0;
                chrstack.push(solution);
                solution = "";
            }
            if (isalpha(input[i])) {
                solution.push_back(input[i]);
            }
            if (input[i] == ']') {
                dummy = solution;
                for (int j = 1; j < numstack.top(); j++) {
                    solution += dummy;
                }
                numstack.pop();
                solution = chrstack.top() + solution;
                chrstack.pop();
            }
        }
        return solution;
    }
};