#ifndef TEXTBOX_HPP
#define TEXTBOX_HPP
#include "Widget.hpp"
#include <string>
#include "graphics.hpp"

using namespace genv;
class TextBox:public Widget
{
    public:

        virtual ~TextBox();
        TextBox(int x, int y,int width, int height, std::string szoveg);
        virtual void draw();
        virtual void handle(event ev);



    protected:

    private:
        std::string szoveg;
};

#endif // TEXTBOX_HPP
