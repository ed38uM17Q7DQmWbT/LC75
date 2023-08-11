//227. Basic Calculator II
class Solution {
public:
    bool isoperation(char& c) {
        if (c == '+') return true;
        if (c == '-') return true;
        if (c == '*') return true;
        if (c == '/') return true;
        return false;
    }

    int calculate(string s) {
        int number = 0;
        int product = 0;
        int solution = 0;
        char operation = '+';

        for (int i = 0; i < s.length(); i++) {
            if (isdigit(s[i])) {
                number = (number * 10) + (s[i] - '0');
            }
            if (isoperation(s[i]) || i == s.length() - 1) {
                if (operation == '+') {
                    solution += product;
                    product = number;
                }
                if (operation == '-') {
                    solution += product;
                    product = -number;
                }
                if (operation == '*') {
                    product *= number;
                }
                if (operation == '/') {
                    product /= number;
                }
                operation = s[i];
                number = 0;
            }
        }
        return solution + product;
    }

};