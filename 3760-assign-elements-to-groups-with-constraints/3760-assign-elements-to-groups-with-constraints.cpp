class Solution {
private:
vector<int> get_divisors(int g) {
    vector<int> divisors;
    for (int i = 1; i * i <= g; i++) {
        if (g % i == 0) {
            divisors.push_back(i);
            if (i != g / i) {
                divisors.push_back(g / i);
            }
        }
    }
    return divisors;
}
public:
    vector<int> assignElements(vector<int>& groups, vector<int>& elements) {
        unordered_map<int, int> mp;
    for (int j = 0; j < elements.size(); j++) {
        if (mp.find(elements[j]) == mp.end()) {
            mp[elements[j]] = j;
        }
    }

        vector<int> result;
    for (auto &g : groups) {
        vector<int> divisors = get_divisors(g);
        int minInd = -1;
        for (auto &d : divisors) {
            auto it = mp.find(d);
            if (it != mp.end()) {
                if (minInd == -1 || it->second < minInd) {
                    minInd = it->second;
                }
            }
        }
        result.push_back(minInd);
    }

    return result;
    }
};