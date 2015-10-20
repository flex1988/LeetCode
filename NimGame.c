/*bool canWinNim(int n) {
    int pre1=1;
    int pre2=1;
    int pre3=1;
    int result=0;
    for(int i=3;i<n;i++){
        result=!pre1||!pre2||!pre3;
        pre1=pre2;
        pre2=pre3;
        pre3=result;
    }
    return result;
}
这题刚开始用递归做超时，改成DP做还是超时，实在忍不住跑去讨论区，看大神的解答这么简单，反思一下，有时候干活之前多花点时间先想好怎么做
再动手可能效率会更高些。
*/

bool canWinNim(int n) {
    return n%4;
}
