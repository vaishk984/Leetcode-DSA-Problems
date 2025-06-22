class Solution {
public:
    double myPow(double a, int n) {
        long power = n;
        double result = 1;
        double currentProduct = a;
        if(n<0){
            currentProduct = 1 / currentProduct;
            power = -power;
        }
        while (power > 0) {
            if (power % 2 == 1) {
                result *= currentProduct;  
            }
            currentProduct *= currentProduct;            
            power /= 2;           
        }
        return result;
    }
};