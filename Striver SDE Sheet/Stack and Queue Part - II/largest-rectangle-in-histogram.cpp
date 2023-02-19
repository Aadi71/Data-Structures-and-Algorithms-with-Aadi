// https://leetcode.com/problems/largest-rectangle-in-histogram/

// Brute Force. Time Limit Exceeded, TC: O(N^2)
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int area = 0;
        for(int i = 0; i<heights.size(); i++){
            int h = INT_MAX;
            for(int j = i; j < heights.size(); j++){
                h = min(h, heights[j]);
                area = max(area, h * (j - i + 1));
            }
        }
        return area;
    }
};

// Using Monotonic Stack, finding left greater and right greater and finding area for each index.
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> leftSmaller;
        stack<int> rightSmaller;
        vector<int> v1(n);
        vector<int> v2(n);

        for(int i = 0; i<n; i++){
            while(!leftSmaller.empty() && heights[leftSmaller.top()] >= heights[i]) leftSmaller.pop();
            if(!leftSmaller.empty()) v1[i] = leftSmaller.top() + 1;
            else v1[i] = 0;
            leftSmaller.push(i);
        }
        for(int i = n - 1; i>=0; i--){
            while(!rightSmaller.empty() && heights[rightSmaller.top()] >= heights[i]) rightSmaller.pop();
            if(!rightSmaller.empty()) v2[i] = rightSmaller.top() - 1;
            else v2[i] = n - 1;
            rightSmaller.push(i);
        }
        int area = 0;
        for(int i = 0; i<n; i++){
            cout << v1[i] << " " << v2[i] << endl;
            area = max(area, heights[i] * (v2[i] - v1[i] + 1));
        }
        return area;
    }
};

// Most Optimied approach with TC: O(N) and SC: O(N)
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> s;
        int area = 0;
        for(int i = 0; i <= heights.size(); i++){
            while(!s.empty() && (i == heights.size() || heights[s.top()] >= heights[i])){
                int h = heights[s.top()];
                s.pop();
                int w;
                if(s.empty()) w = i;
                else w = i - s.top() - 1;
                area = max(area, w * h);
            }
            s.push(i);
        }
        return area;
    }
};

