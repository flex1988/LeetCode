double myPow(double x, int n) {

    if(x==1) return x;
    if(x==-1) return n%2>0?-1:1;
    if(n<0) {
        if(n==-2147483648){
            return 0;
        }
        return 1/myPow(x,-n);
    }
    if(n==0) return 1;
    if(n==1) return x;

    else{

        int odd = n%2>0?1:0;
        if(!odd) {
            double ret = myPow(x,n/2);
            return ret*ret;
        }else{

            double ret = myPow(x,n/2);

            return ret*ret*x;
        }
    }
}
