#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>

double max_prob(int start, int goal, int days, int current_amount, int current_day, std::vector<double> &probs, std::vector< std::vector < double > > &dp_table){

    if (current_amount >= goal){
        return 1.0;
    } else if (current_amount == 0) {
        return 0.0;
    }else if (current_day == probs.size()-1){
        if (2 * current_amount < goal){
            return 0.0;
        } else {
            return probs[probs.size()-1];
        }
    }

    double max_p = 0.0;
    
    for (int bet = 0; bet <= current_amount; bet++){

        if (current_amount+bet > goal){
            continue;
        }

        double loose = 0.0;

        if (dp_table[current_amount-bet][current_day+1] != -1.0){
            loose = dp_table[current_amount-bet][current_day+1];
        } else {
            loose = max_prob(start, goal, days, current_amount-bet, current_day + 1, probs, dp_table);
            dp_table[current_amount-bet][current_day+1] = loose;
        }

        double win = 0.0;
        
        if (dp_table[std::min(current_amount+bet, goal)][current_day+1] != -1.0){
            win = dp_table[std::min(current_amount+bet, goal)][current_day+1];
        } else {
            win = max_prob(start, goal, days, std::min(current_amount+bet, goal), current_day + 1, probs, dp_table);
            dp_table[std::min(current_amount+bet, goal)][current_day+1] = win;
        }

        double current = loose * (1 - probs[current_day]) + win * probs[current_day];

        if (current > max_p){
            max_p = current;
        }
    }

    dp_table[std::min(current_amount, goal)][current_day] = max_p;

    return max_p;
}

int main(){

    std::ios_base::sync_with_stdio(false);

    int tests;
    std::cin >> tests;

    std::vector<double> results;

    for(int i = 0; i < tests; i ++){

        int len, start, goal;
        std::cin >> len;
        std::cin >> start;
        std::cin >> goal;

        std::vector< std::vector < double > > dp_table;
        std::vector<double> probs;

        for (int s = 0; s < len; s ++){
            double temp;
            std::cin >> temp;
            probs.push_back(temp);
        }

        for (int s = 0; s <= std::max(start, goal); s ++){

            std::vector<double> a((len+1), -1.0);
            if (s == start){
                a[0] = 1.0;
            } else {
                a[0] = 0.0;
            }
            dp_table.push_back(a);

        }

        int current = 0;
        
        double mp = max_prob(start, goal, len, start, current, probs, dp_table);

        results.push_back(mp);
    }

    
    std :: cout << std :: fixed << std::setprecision(5);
    for (double i : results){
        std::cout << i << std::endl;
    }

    return 0;
}