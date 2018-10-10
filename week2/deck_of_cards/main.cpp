#include <iostream>
#include <vector>

bool checker(int newer, int older, int k){
    return std::abs(newer-k) < std::abs(older-k);
}
int main(){

    int tests = 0;
    std::cin >> tests;
    std::vector<int> results_i;
    std::vector<int> results_j;

    for (int i = 0; i < tests; i ++){
        
        int n, k;
        std::cin >> n;
        std::cin >> k;

        std::vector<int> values;
        std::vector<int> prefix_sum;

        
        for (int j = 0; j < n; j++){

            int temp;
            std::cin >> temp;
            values.push_back(temp);

            if (j == 0){
                prefix_sum.push_back(temp);
            } else {
                prefix_sum.push_back(temp + prefix_sum[j-1]);
            }

        }

        int best_i = 0;
        int best_j = 0;
        int best_value = prefix_sum[0];

        int curr_i = 0;
        int curr_j = 0;

        int j = 0;

        while(curr_j < n){

            curr_j ++;

            while (curr_i < curr_j){

                int temp2;
                
                if (curr_i == 0){
                    temp2 = 0;
                } else {
                    temp2 = prefix_sum[curr_i-1];
                }

                if (checker(prefix_sum[curr_j] - prefix_sum[curr_i], prefix_sum[curr_j] - temp2, k)){
                    curr_i++;
                } else {
                    break;
                }
            }

            int current_value = 0;
            if (curr_i == 0){
                current_value = prefix_sum[curr_j];
            } else {
                current_value = prefix_sum[curr_j] - prefix_sum[curr_i -1];
            }

            if (checker(current_value, best_value, k)){
                best_i = curr_i;
                best_j = curr_j;
                best_value = current_value;
            }            

        }

        results_i.push_back(best_i);
        results_j.push_back(best_j);
    }

    for (int s = 0; s < results_i.size(); s++){
        std::cout << results_i[s] << " " << results_j[s] << std::endl;
    }
    return 0;
}