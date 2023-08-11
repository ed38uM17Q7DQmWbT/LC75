//278. First Bad Version
class Solution {
public:
    int firstBadVersion(int n) {
        int lobnd = 1;
        int index = 1;
        int hibnd = n;


        while (lobnd <= hibnd) {
            index = lobnd + ((hibnd - lobnd) / 2);
            if (isBadVersion(index)) {
                hibnd = index;
                hibnd--;
            }
            else {
                lobnd = index;
                lobnd++;
            }
        }
        return lobnd;
    }
};

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);