
// lintcode 6

class Solution {
public:
    /**
     * @param A: sorted integer array A
     * @param B: sorted integer array B
     * @return: A new sorted integer array
     */
    vector<int> mergeSortedArray(vector<int> &A, vector<int> &B) {
        int i = 0, j = 0;
        vector<int> array;
        while(true){
            if(i >= A.size() || j >= B.size()){
                break;
            }
            if(A[i] > B[j]){
                array.push_back(B[j]);
                j++;
            } else {
                array.push_back(A[i]);
                i++;
            }
        }
        if(i == A.size()){
            array.insert(array.end(), B.begin() + j, B.end());
        } else {
            array.insert(array.end(), A.begin() + i, A.end());
        }
        
        return array;
    }
};

//lintcode 3


class Solution {
public:
    /**
     * @param k: An integer
     * @param n: An integer
     * @return: An integer denote the count of digit k in 1..n
     */
    int digitCounts(int k, int n) {
        int count = 0;
        for(int i = 0; i <= n; i++){
            int num = i;
            while(num / 10){
                if(num % 10 == k){
                    count++;
                }
                num /= 10;
            }
            if(num == k){
                count++;
            }
        }
        return count;
    }
};
