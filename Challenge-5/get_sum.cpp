class Solution {
public:
    int getSum(int a, int b) {

        while(b>0){
            b--;
            a++;
        }
        while(b<0){
            b++;
            a--;
        }
        return a;
        
    }
};