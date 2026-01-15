class Solution {
    private boolean check(double mid_y,double total,int[][] squares){
        double bottomArea = 0.0;

        for(int[] square: squares){
            double bottom_y = square[1];
            double side = square[2];
            double top_y = bottom_y + side;

            if(mid_y >= top_y){
                bottomArea += side*side;
            }else if(mid_y > bottom_y){
                bottomArea += side*(mid_y - bottom_y);
            }
        }

        return bottomArea >= total/2.0;
    }
    public double separateSquares(int[][] squares) {
        double low = Integer.MAX_VALUE;
        double high = Integer.MIN_VALUE;
        double total = 0.0;

        for(int[] square: squares){
            double bottom_x = square[0];
            double bottom_y = square[1];
            double side = square[2];

            double top_y = bottom_y + side;

            total += side*side;
            low = Math.min(low,bottom_y);
            high = Math.max(high,top_y);

        }

        double min_y = 0.0;
        while(high - low > 1e-5){
            double mid_y = low + (high - low)/2;
            min_y = mid_y;

            if(check(mid_y,total,squares)){
                high = mid_y;
            }else{
                low = mid_y;
            }
        }

        return min_y;
    }
}