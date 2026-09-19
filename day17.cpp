//problem 1) 1401. Circle and Rectangle Overlapping
class Solution {
public:
    bool checkOverlap(int radius, int xc, int yc, int x1, int y1, int x2, int y2) {

        int cx = max(x1, min(xc, x2));
        int cy = max(y1, min(yc, y2));

        int dx = xc - cx;
        int dy = yc - cy;

        return dx * dx + dy * dy <= radius * radius;
    }
};