#include <iostream>
#include <vector>

int main(){
    int tests;
    std::cin >> tests;
    std::vector<int> results;

    for(int i = 0; i < tests; i ++){

        int len;
        std::cin >> len;

        int falling = 1;
        int j = 0;
        int curr = 0;

        while (falling > 0 && j < len){
            std::cin >> curr;
            if (curr > falling-1){
                falling = curr;
            }
            falling--;
            j++;
        }

        int k;
        for (int s = j; s < len; s++){
            std::cin >> k;
        }
        
        results.push_back(j);
    }

    for (int i : results){
        std::cout << i << std::endl;
    }

    return 0;
}