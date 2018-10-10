#include <iostream>
#include <vector>

int main(){

    int test_cases;
    int current;

    std::vector<int> results;

    std::cin >> test_cases;
    
    for (int i = 0; i < test_cases; i++){
        int len;
        std::cin >> len;

        current = 0;
        int temp;

        for (int j = 0; j < len; j++){
            std::cin >> temp;
            current += temp;
        }

        results.push_back(current);

    }

    for (int i : results){
        std::cout << i << std::endl;
    }

    return 0;
}