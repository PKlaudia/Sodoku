#ifndef JATEKMESTER_HPP
#define JATEKMESTER_HPP
#include "graphics.hpp"
#include "Widget.hpp"
#include "TextBox.hpp"
#include "PushButton.hpp"
#include "SodokuBox.hpp"
#include <vector>
#include <fstream>
class JatekMester
{
    public:

        virtual ~JatekMester();
        void check();
        bool solve(int row, int col);

        void help();
        void solveit();
        void generateSodoku();
        JatekMester(std::vector<std::vector<SodokuBox*>> &b);
        void which_box(int &r_end, int &c_end, int &r_start, int &c_start, int r, int c);

    protected:


    private:
        std::vector<std::vector<SodokuBox*>> boxes;
        std::vector<std::vector<int>> numbers;
};

#endif // JATEKMESTER_HPP
