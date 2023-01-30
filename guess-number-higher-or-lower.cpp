// https://leetcode.com/problems/guess-number-higher-or-lower/
public:
    int guessNumber(int n) {
        int min = 1;
        int max = n;
        int mid;
        while(min <= max){
            mid = min + (max - min) / 2;
            if(guess(mid) == -1) max = mid - 1;
            else if(guess(mid) == 1) min = mid + 1;
            else return mid;
        }
        return -1;
    }
};
