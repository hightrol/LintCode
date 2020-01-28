class TwoSum {
public:
    /**
     * @param number: An integer
     * @return: nothing
     */
    map <int, int> counter; 
     
    void add(int number) {
        // write your code here
        if(counter.count(number)){
            counter[number] += 1;
        } else {
            counter[number] = 1;
        }
    }

    /**
     * @param value: An integer
     * @return: Find if there exists any pair of numbers which sum is equal to the value.
     */
    bool find(int value) {
        // write your code here
        for (auto it: counter){
            int j = it.first;
            if(counter.count(value-j)){
                if( 2*j != value){
                    return true;
                } else if(it.second >= 2){
                    return true;
                }
            }
        }
        return false;

    }
};
