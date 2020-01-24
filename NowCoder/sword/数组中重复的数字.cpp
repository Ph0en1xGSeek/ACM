class Solution {
public:
    // Parameters:
    //        numbers:     an array of integers
    //        length:      the length of array numbers
    //        duplication: (Output) the duplicated number in the array number
    // Return value:       true if the input is valid, and there are some duplications in the array number
    //                     otherwise false
    bool duplicate(int numbers[], int length, int* duplication) {
        if(length == 0) {
            return false;
        }
        for(int i = 0; i < length; ++i) {
            int idx = numbers[i];
            if(idx >= length) {
                idx -= length;
            }
            if(numbers[idx] >= length) {
                *duplication = numbers[idx] - length;
                return true;
            }
            numbers[idx] += length;
        }
        return false;
    }
};