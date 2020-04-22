class Solution {
private:
    double r;
    double x;
    double y;
public:
    Solution(double radius, double x_center, double y_center) {
        r = radius;
        x = x_center;
        y = y_center;
    }
    
    vector<double> randPoint() {
        random_device rd;
        default_random_engine e(rd());
        uniform_real_distribution<double> uniform(-r, r);
        double rand_x = uniform(e);
        double rand_y = uniform(e);
        while(rand_x * rand_x + rand_y * rand_y > r * r) {
            rand_x = uniform(e);
            rand_y = uniform(e);
        }
        return {x + rand_x, y + rand_y};
        // double rand_r = uniform(e);
        // double rand_cos = uniform(e);
        // double rand_sin = uniform(e);
        // rand_sin = rand_sin > 0.5? sqrt(1 - rand_cos * rand_cos): -sqrt(1 - rand_cos * rand_cos);
        // double rand_x = r * rand_r * rand_cos;
        // double rand_y = r * rand_r * rand_sin;
        // return {x + rand_x, y + rand_y};
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj->randPoint();
 */