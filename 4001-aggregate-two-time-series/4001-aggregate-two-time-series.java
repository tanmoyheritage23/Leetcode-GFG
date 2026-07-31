class Solution {
    public List<List<Integer>> aggregateTimeSeries(int[][] series1, int[][] series2) {

        int first = 0;
        int second = 0;

        List<List<Integer>> result = new ArrayList<>();

        while (first < series1.length && second < series2.length) {

            int firstTimeStamp = series1[first][0];
            int secondTimeStamp = series2[second][0];

            int firstValue = series1[first][1];
            int secondValue = series2[second][1];

            if (firstTimeStamp == secondTimeStamp) {

                result.add(Arrays.asList(firstTimeStamp, firstValue + secondValue));
                first++;
                second++;

            } else if (firstTimeStamp < secondTimeStamp) {

                result.add(Arrays.asList(firstTimeStamp, firstValue + secondValue));
                first++;

            } else {

                result.add(Arrays.asList(secondTimeStamp, firstValue + secondValue));
                second++;
            }
        }

        while (first < series1.length) {

            result.add(Arrays.asList(
                    series1[first][0],
                    series1[first][1]
            ));
            first++;
        }

        while (second < series2.length) {

            result.add(Arrays.asList(
                    series2[second][0],
                    series2[second][1]
            ));
            second++;
        }

        return result;
    }
}