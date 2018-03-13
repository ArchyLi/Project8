#include <stdio.h>
    bool Find(int target, vector<vector<int> > array) {
        int row = 0;
        int col = array[0].size()-1;
        while((row <= (array.size() - 1 ))&& col >= 0)
        {
            if(target == array[row][col])
                return true;
            if(target < array[row][col])
                col--;
            if(target > array[row][col])
                row++;
        }
        return false;
        
    }
