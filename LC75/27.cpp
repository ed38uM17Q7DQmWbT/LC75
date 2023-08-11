//844. Backspace String Compare
class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> dummyS;
        stack<char> dummyT;


        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '#')
            {
                if (!dummyS.empty())
                    dummyS.pop();
            }
            else
                dummyS.push(s[i]);
        }
        s.clear();
        while (!dummyS.empty()) {
            s += dummyS.top();
            dummyS.pop();
        }


        for (int i = 0; i < t.size(); i++) {
            if (t[i] == '#')
            {
                if (!dummyT.empty())
                    dummyT.pop();
            }
            else
                dummyT.push(t[i]);
        }
        t.clear();
        while (!dummyT.empty()) {
            t += dummyT.top();
            dummyT.pop();
        }


        return (s == t) ? true : false;
    }
};