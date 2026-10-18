class Solution {
public:
/*
max = INT_MIN
fleet = 0
[6,8]
[3,2] target = 10
[1.33, 1] max < cur ++fleet 
1 + 1 + 1
*/
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        std::vector<std::pair<int, int>> posSpeedVec;

        for(int i=0;i<position.size();i++)
        {
            posSpeedVec.push_back({position[i], speed[i]});
        }
        std::sort(posSpeedVec.begin(), posSpeedVec.end());

        int fleets = 0;
        double maxFleetTime = -1.0;
        for(int i=posSpeedVec.size()-1;i>=0;i--)
        {
            double currentFleetTime = 1.0 * (target-posSpeedVec[i].first)/posSpeedVec[i].second;
            if(currentFleetTime > maxFleetTime)
                fleets++; // 2

            maxFleetTime = max(maxFleetTime, currentFleetTime); //6
        }
        return fleets;
    }
};
