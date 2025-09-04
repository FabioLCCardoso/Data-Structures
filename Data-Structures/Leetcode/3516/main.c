int findClosest(int x, int y, int z) {
    int diff1, diff2;

    diff1 = x - z;
    diff2 = y - z;

    if(diff1 < 0) {
        diff1 = diff1 * -1;
    }
    if(diff2 < 0){
        diff2 *= -1;
    }

    if(diff1 > diff2 ) return 2;
    else if(diff1 < diff2) return 1;
    else if(diff1 == diff2) return 0;

    return 0;

}
