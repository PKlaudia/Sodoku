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
        JatekMester(std::vector<SodokuBox*> b);

    protected:
        std::vector<SodokuBox*> boxes;

    private:
};

#endif // JATEKMESTER_HPP
