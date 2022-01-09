package leetcode;

public class leetcode223 {

    private static final int dummy = 0;

    private int getArea(int x1, int y1, int x2, int y2){
        //(x1,y1) :  bottom-left corner
        //(x2,y2) :  bottom-left corner
        return (x2-x1) * (y2-y1);
    }

    public int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int mx1 = dummy,my1 = dummy, mx2= dummy, my2= dummy;
        if(!(ax2 <= bx1 || bx2 <=ax1 ||  ay2 <= by1 || by2 <=ay1)){
            mx1 = ax1 > bx1 ? ax1 : bx1;
            mx2 = ax2 < bx2 ? ax2 : bx2;
            my1 = ay1 > by1 ? ay1 : by1;
            my2 = ay2 < by2 ? ay2 : by2;
        }
        return getArea(ax1,ay1,ax2,ay2) + getArea(bx1,by1,bx2,by2) - getArea(mx1,my1, mx2, my2);
    }
}
