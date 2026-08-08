class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int fleets = 0;
        vector<pair<int, double>> cars;

        for(int i=0; i<position.size(); i++)
        {
            double time = (double)(target - position[i])/speed[i];
            cars.push_back({position[i], time});
        }

        sort(cars.begin(), cars.end(), greater<pair<int, double>>());

        stack<double> st;
        for(int i=0; i<cars.size(); i++)
        {
            if(st.empty() || cars[i].second > st.top())
                st.push(cars[i].second);
        }

        return st.size();
    }
};
