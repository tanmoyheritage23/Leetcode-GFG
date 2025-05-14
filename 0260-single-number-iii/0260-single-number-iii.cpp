class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xors = 0;
        for(int num: nums){
            xors ^= num;
        }

     int rightMostSetBit = 1;

     while((rightMostSetBit & xors) == 0){
        rightMostSetBit = rightMostSetBit << 1;
     }

        int a = 0, b = 0;

        for(int num: nums){
            if(num & rightMostSetBit){
                a ^= num;
            }else{
                b ^= num;
            }
        }

        return {a,b};
    }
       
};


           

