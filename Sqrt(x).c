int mySqrt(int x) {
    if(x==1) return x;
    if(x<1) {
        return 0;
    }
    if(x>1){
        int y = 1;
        int z = x/y;
        while(y-z>1||y-z<-1){
            y=(y+z)/2;
            z=x/y;
        }

        y = y<0?-y:y;
        z = z<0?-z:z;
        return y<z?y:z;
    }
}
