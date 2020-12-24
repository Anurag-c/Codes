
bool searchMatrix(vector<vector<int>>& matrix, int k) 
{
    if(matrix.size() == 0 || matrix[0].size() == 0) return false; // [] and [[]]
    int n = matrix.size();
    int m = matrix[0].size();
    int start = 0;
    int end = (n * m) - 1;
    while(start <= end)
    {
        int mid = (start + end)/2
        int val = matrix[mid/m][mid % m];
        if(val == k) return true;
        else if(val < k) start = mid + 1;
        else end = mid - 1;
    }
    return false;
}

bool searchMatrix(vector<vector<int>>& matrix, int target) 
{
    int row = matrix.size()-1;
    int col = 0;
    while(row >= 0 && col < matrix[0].size()){
        if(target < matrix[row][col]){
            row--;
        } else if (target > matrix[row][col]){
            col++;
        } else {
            return true;
        }
    }
    return false;
}