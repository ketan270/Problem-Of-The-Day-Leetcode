class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {

        // Max-heap to store the gain in pass ratio and the corresponding class index
        priority_queue<pair<double, int>> pq;

        // Step 1: Calculate the initial gain for each class and push it into the heap
        for (int i = 0; i < classes.size(); ++i) {
            int a = classes[i][0]; 
            int b = classes[i][1]; 
            // Calculate the gain in pass ratio if one extra student is added
            double gain = ((double)(a + 1) / (b + 1)) - ((double)a / b);
            pq.push({gain, i});
        }

        // Step 2: Distribute the extra students
        while (extraStudents > 0) {
            // Get the class with the highest gain in pass ratio
            auto pre = pq.top();
            pq.pop();

            int idx = pre.second; gain

            // Add one student to this class
            classes[idx][0] += 1; 
            classes[idx][1] += 1; 

            // Recalculate the gain for the updated class
            int a = classes[idx][0];
            int b = classes[idx][1];
            double newGain = ((double)(a + 1) / (b + 1)) - ((double)a / b);

            
            pq.push({newGain, idx});

            extraStudents--; 
        }

        // Step 3: Calculate the final average pass ratio
        double result = 0.0;
        for (const auto& cls : classes) {
            result += (double)cls[0] / cls[1]; 
        }

        // Divide by the number of classes to get the overall average
        return result / classes.size();
    }
};
