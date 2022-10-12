#include <iostream>
#include <vector>
#include <array>
#include <string>

struct Direction {
   const std::string up = "UP";
   const std::string down = "DOWN";
   const std::string right = "RIGHT";
   const std::string left = "LEFT";
};

struct FieldType {
   static constexpr char princess = 'p';
   static constexpr char bot = 'm';
    __attribute__((unused)) static constexpr char field = '-';
};

void displayPathtoPrincess(const int n, FieldType& ft, std::array<int,2>& bot, const std::vector<std::string>& grid) {
   std::vector<std::string> botDirection;
   Direction direct;
   if(grid[0][0] == FieldType::princess) {
      // top left
      while((bot[0] >= 0) || (bot[1] >= 0)) {
         if((bot[0] == 0) && ( bot[1] == 0)) break; // done
         if(bot[0] != 0) {
            // go to up
            bot[0] -= 1;
            botDirection.push_back(direct.up);
         }
         else {
            // go to left
            bot[1] -= 1;
            botDirection.push_back(direct.left);
         }
      }
   }
   else if(grid[0][n - 1] == FieldType::princess) {
      // top right
      while((bot[0] >= 0) || (bot[1] != n - 1)) {
         if((bot[0] == 0) && ( bot[1] == n - 1)) break; // done
         if(bot[0] != 0) {
            // go up
            bot[0] -= 1;
            botDirection.push_back(direct.up);
         }
         else {
            // go right
            bot[1] += 1;
            botDirection.push_back(direct.right);
         }
      }
   }
   else if(grid[n - 1][0] == FieldType::princess) {
      // bottom left
      while((bot[0] <= n - 1) || (bot[1] >= 0)) {
         if((bot[0] == n - 1) && ( bot[1] == 0)) break; // done
         if(bot[0] != n - 1) {
            // go down
            bot[0] += 1;
            botDirection.push_back(direct.down);
         }
         else {
            // go left
            bot[1] -= 1;
            botDirection.push_back(direct.left);
         }
      }
   }
   else {
      // bottom right
      while((bot[0] <= n - 1) || (bot[1] <= n - 1)) {
         if((bot[0] == n - 1) && ( bot[1] == n - 1)) break; // done
         if(bot[0] != n - 1) {
            // go down
            bot[0] += 1;
            botDirection.push_back(direct.down);
         }
         else {
            // go right
            bot[1] += 1;
            botDirection.push_back(direct.right);
         }
      }
   }
   // print result -----------------
    for (auto &value: botDirection)
        std::cout << value << '\n';
}

int main() {
   std::vector<std::string> grid; // main grid
   std::array<int, 2> bot{}; // bot coords
   FieldType ft; // field type
    int n; // number of grid: NxN
    std::cin >> n;
    for(int i = 0; i < n; i++) {
        std::string s;
        std::cin >> s;
        // save coords of objects
        for(int j = 0; j < s.length(); j++) {
           if(FieldType::bot == s[j]) {
              bot[0] = i;
              bot[1] = j;
           }
        }
        grid.push_back(s);
    }
    displayPathtoPrincess(n, ft, bot, grid);
    return 0;
}
