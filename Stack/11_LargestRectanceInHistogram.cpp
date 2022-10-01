//Link: https://leetcode.com/problems/largest-rectangle-in-histogram/
//Ref: https://www.youtube.com/watch?v=lJLcqDsmYfg&list=PLDzeHZWIZsTrhXYYtx4z8-u8zA-DzuVsj&index=3&t=764s&ab_channel=CodeHelp-byBabbar
//13:00
class Solution {
public:
    vector<int> nextSmallerElementIndexes(vector<int>& heights, int n){
        vector<int> res(n);
        
        stack<int> s;
        s.push(-1);
        
        for(int i=n-1; i>=0; i--){
            int curr = heights[i];
            
            // Since s.top contains the indexes, heights[s.top()] to compare the values
            // s.top() != -1 to check if the stack is not empty
            while(s.top() != -1 and heights[s.top()] >= curr)
                s.pop();
            
            res[i] = s.top();
            // Push the index of the next smaller element
            s.push(i);
        }
        return res;
    }

    vector<int> prevSmallerElementIndexes(vector<int>& heights, int n){
        vector<int> res(n);
        
        stack<int> s;
        s.push(-1);
        
        for(int i=0; i<n; i++){
            int curr = heights[i];
            
            // Since s.top contains the indexes, heights[s.top()] to compare the values
            // s.top() != -1 to check if the stack is not empty
            while(s.top() != -1 and heights[s.top()] >= curr)
                s.pop();
            
            res[i] = s.top();
            // Push the index of the prev smaller element
            s.push(i);
        }
        return res;
    }

    
    int largestRectangleArea(vector<int>& heights) {
     
        int n = heights.size();
        
        vector<int> next(n);
        next = nextSmallerElementIndexes(heights, n);
        
        vector<int> prev(n);
        prev = prevSmallerElementIndexes(heights, n);
        
        int area = INT_MIN;
        
        for(int i=0; i<n; i++){
            int l = heights[i];
            
            // Careful here
            // if heights[] = [2,2,2,2]
            // then next[] = [-1,-1,-1,-1]
            // then prev[] = [-1,-1,-1,-1]
            // So, we keep next at the end;
            if(next[i] == -1)
                next[i] = n;
            
            int w = next[i] - prev[i] - 1;
            int newArea = l * w;
            area = max(area, newArea);
        }
        
        return area;
    }
};
