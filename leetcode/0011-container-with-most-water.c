
#define min(a,b) (a < b ? a : b)
#define area(x,y) ((y - x) * min(height[x], height[y]))
int maxArea(int* height, int heightSize){
    int i, j;
    int max_area = 0;
    
    for (i=0; i<heightSize; i++) {
        for (j=i+1; j<heightSize; j++) {
            int _area = area(i, j);
            if (max_area < _area)
                max_area = _area;
        }
    }
    
    return max_area;
}
