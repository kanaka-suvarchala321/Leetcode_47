class Solution {
    struct Node {
        int count = 0;
        long long length = 0;
    };

    vector<Node> tree;
    vector<int> coords;

    void update(int node, int start, int end, int l, int r, int val) {
        if (start > end || start > r || end < l) return;
        if (start >= l && end <= r) {
            tree[node].count += val;
        } else {
            int mid = start + (end - start) / 2;
            update(2 * node, start, mid, l, r, val);
            update(2 * node + 1, mid + 1, end, l, r, val);
        }

        if (tree[node].count > 0) {
            tree[node].length = coords[end + 1] - coords[start];
        } else if (start != end) {
            tree[node].length = tree[2 * node].length + tree[2 * node + 1].length;
        } else {
            tree[node].length = 0;
        }
    }

public:
    double separateSquares(vector<vector<int>>& squares) {
        struct Event {
            int x1, x2, y, type;
            bool operator<(const Event& other) const { return y < other.y; }
        };

        vector<Event> events;
        vector<int> x_coords;

        for (const auto& s : squares) {
            int x = s[0], y = s[1], l = s[2];
            events.push_back({x, x + l, y, 1});
            events.push_back({x, x + l, y + l, -1});
            x_coords.push_back(x);
            x_coords.push_back(x + l);
        }

        sort(events.begin(), events.end());
        sort(x_coords.begin(), x_coords.end());
        x_coords.erase(unique(x_coords.begin(), x_coords.end()), x_coords.end());
        coords = x_coords;

        int n = coords.size();
        tree.assign(4 * n, Node());

        auto get_idx = [&](int val) {
            return lower_bound(coords.begin(), coords.end(), val) - coords.begin();
        };

        vector<pair<double, double>> slabs;
        double totalArea = 0;

        for (int i = 0; i < events.size() - 1; ++i) {
            int l = get_idx(events[i].x1);
            int r = get_idx(events[i].x2) - 1;
            update(1, 0, n - 2, l, r, events[i].type);

            double height = events[i + 1].y - events[i].y;
            if (height > 0) {
                double width = tree[1].length;
                slabs.push_back({height, width});
                totalArea += height * width;
            }
        }

        double target = totalArea / 2.0;
        double currentArea = 0;
        double currentY = events[0].y;

        for (auto& slab : slabs) {
            double slabArea = slab.first * slab.second;
            if (currentArea + slabArea >= target) {
                double needed = target - currentArea;
                return currentY + (needed / slab.second);
            }
            currentArea += slabArea;
            currentY += slab.first;
        }

        return currentY;
    }
};