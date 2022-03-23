#include <vector>
#include <string>
#include "Direction.hpp"

namespace ariel{
    class Notebook{
        private:
            const int col = 100;
            int row;
            int pages;
            

        public:
            void write(int page, int row, int column, ariel::Direction direction, const std::string& text);
            static std::string read(int page, int row, int column, ariel::Direction direction, int length);
            void erase(int page, int row, int column, ariel::Direction direction, int length);
            void show(int page);
    };
}