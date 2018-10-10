#include <iostream>
#include <vector>

int main(){
    int tests;
    std::cin >> tests;
    std::vector<int> results;

    for(int i = 0; i < tests; i ++){

        int len;
        std::cin >> len;

        bool even_state = true;
        int even = 0;
        int odd = 0;
        int current = 0;

        for(int j = 0; j < len; j++){

            std::cin >> current;

            if (current == 1){
                even_state = !even_state;
            }

            if (even_state){
                even++;
            } else {
                odd++;
            }
        }
        
        results.push_back((even*(even-1))/2 + (odd*(odd-1))/2 + even);

    }

    for (int i : results){
        std::cout << i << std::endl;
    }

    return 0;
}