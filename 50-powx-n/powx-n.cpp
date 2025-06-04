class Solution {
public:
    double myPow(double x, int n) {
        if(n==0) return 1;
        if(x==0) return 0;
        if(x==1) return 1;
        if(x==-1 && n%2==0) return 1; 
        if(x==-1 && n%2!=0) return -1;
        long long binForm = n;
        if(binForm<0){
            x = 1/x;
            binForm = -binForm;
        }
        double ans = 1;

        while(binForm>0){
            if(binForm % 2==1){
                ans = ans * x;
            }

            x = x*x;
            binForm /= 2;
        }

        return ans;
    }
};