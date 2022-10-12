#include <iostream>
#include <vector>
#include <string>

struct Direction {
   static inline const std::string up = "UP";
    static inline const std::string down = "DOWN";
    static inline const std::string right = "RIGHT";
    static inline const std::string left = "LEFT";
};

struct FieldType {
   static constexpr char princess = 'p';
    __attribute__((unused)) static constexpr char bot = 'm';
    __attribute__((unused)) static constexpr char field = '-';
};

void nextMove(const int b_i, const int b_j, const int p_i, const int p_j) {
    if(b_i > p_i) {
        std::cout << Direction::up;
    }
    else if (b_i < p_i) {
        std::cout << Direction::down;
    }
    else if(b_j > p_j) {
        std::cout << Direction::left;
    }
    else if(b_j < p_j) {
        std::cout << Direction::right;
    }
}

int main() {
   std::vector<std::string> grid;
    int n, b_i, b_j, p_i, p_j;
    std::cin >> n;
    std::cin >> b_i >> b_j;
    for(int i = 0; i < n; i++) {
        std::string s;
        std::cin >> s;
        grid.push_back(s);
        for (int j = 0; j < s.length(); j++) {
            if(FieldType::princess == s[j]) {
                p_i = i;
                p_j = j;
            }
        }
    }
    nextMove(b_i, b_j, p_i, p_j);
    return 0;
}
