class Solution {
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        multiset<pair<int, int>> point;
        vector<pair<int, int>> res;
        multiset<int> height{0};
        for(int i = 0; i < buildings.size(); i++){
            point.insert(make_pair(buildings[i][0], -buildings[i][2]));
            point.insert(make_pair(buildings[i][1], buildings[i][2]));
        }
        int mx = 0;
        for(multiset<pair<int, int>>::iterator iter = point.begin(); iter != point.end(); iter++){
            if((*iter).second < 0){
                height.insert(-(*iter).second);
            }else{
                height.erase(height.find((*iter).second));
            }
            if(*(height.rbegin()) != mx){
                res.push_back(make_pair((*iter).first, *(height.rbegin())));
                mx =  *(height.rbegin());
            }
        }
        return res;
    }
};
