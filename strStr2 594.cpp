class Solution {
public:
    /*
     * @param source: A source string
     * @param target: A target string
     * @return: An integer as index
     */
    int strStr2(const char* source, const char* target) {
        // write your code here
        if (target && source) {
            int m = strlen(source), n = strlen(target);
            if (n == 0){
                return 0;
            }
            vector <int> kmp(n);
            int i = 0, k = -1;
            while(i < n){
                if ( (k == -1) || (target[i] == target[k]) ){
                    kmp[i] = k;
                    i += 1;
                    k += 1;
                } else {
                    k = kmp[k];
                }
            }
            for(int i = 0, j = -1; i < m; i++) {
                while(j >= 0 && (source[i] != target[j]) ){
                    j = kmp[j];
                }
                j += 1;
                if(j == n){
                    return i-j+1;
                }
            }            
        }
        return -1;
    }
};
