int areaOfMaxDiagonal(int** dimensions, int dimensionsSize, int* dimensionsColSize) {
   int result = 0;
   int maxArea = 0;

    for(int i = 0; i < dimensionsSize; i++){
        int length = dimensions[i][0];
        int width = dimensions[i][1];
        int Diagonal = length * length + width * width;
        int area = length * width;

        if(Diagonal > result){
            result = Diagonal;
            maxArea = area;
        }
        else if(Diagonal == result){
            if(area > maxArea){
                maxArea = area;
            }
        }
    }
    return maxArea;
}
