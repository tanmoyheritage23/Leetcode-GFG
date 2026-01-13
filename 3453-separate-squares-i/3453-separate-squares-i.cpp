class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        vector<pair<int, int>> heightEvents;
    double totalSquareArea = 0.0; // Changed to double to prevent overflow

    for (auto& square : squares) {
        int bottomY = square[1], sideLength = square[2];
        heightEvents.emplace_back(bottomY, sideLength);
        heightEvents.emplace_back(bottomY + sideLength, -sideLength);
        totalSquareArea += static_cast<double>(sideLength) * sideLength; // Store in double
    }

    sort(heightEvents.begin(), heightEvents.end());

    double targetArea = totalSquareArea / 2.0;
    double accumulatedArea = 0.0, prevY = heightEvents[0].first;
    double activeWidthSum = 0.0;

    for (auto& [currentY, sideChange] : heightEvents) {
        if (currentY != prevY) {
            accumulatedArea += activeWidthSum * (currentY - prevY);
            if (accumulatedArea >= targetArea) {
                double remainingArea = targetArea - (accumulatedArea - activeWidthSum * (currentY - prevY));
                double splitY = prevY + remainingArea / activeWidthSum;
                return round(splitY * 100000.0) / 100000.0;
            }
            prevY = currentY;
        }
        activeWidthSum += sideChange;
    }

    return 0.0;
    }
};