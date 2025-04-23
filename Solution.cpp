class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        // Set of deadends where lock gets stuck
        unordered_set<string> nope(deadends.begin(), deadends.end());

        // Queue for BFS
        queue<string> q;

        // Start state check
        if (nope.find("0000") != nope.end()) return -1;

        // Start BFS from "0000"
        q.push("0000");
        int moves = 0;

        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                string current = q.front();
                q.pop();

                // If target is reached
                if (current == target) return moves;

                // Try turning each wheel up and down
                for (int i = 0; i < 4; ++i) {
                    char original = current[i];

                    // Rotate up
                    current[i] = (original == '9' ? '0' : original + 1);
                    if (nope.find(current) == nope.end()) {
                        nope.insert(current);
                        q.push(current);
                    }

                    // Rotate down
                    current[i] = (original == '0' ? '9' : original - 1);
                    if (nope.find(current) == nope.end()) {
                        nope.insert(current);
                        q.push(current);
                    }

                    // Restore original state
                    current[i] = original;
                }
            }
            moves++;
        }

        // Target not reachable
        return -1;
    }
};
