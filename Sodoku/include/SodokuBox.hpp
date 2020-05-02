#ifndef SODOKUBOX_HPP
#define SODOKUBOX_HPP
#include "Widget.hpp"
#include "graphics.hpp"

class SodokuBox:public Widget
{
    public:
        SodokuBox(int x, int y,int width, int height, int value, bool b);
        virtual ~SodokuBox();
         virtual void draw();
        virtual void handle(const event ev);


        int getValue();
        int getInNumber();


        void setRGB(int r,int g,int b);
        void setHide(bool b);

    protected:

    private:
        int value;
        int int_start;
        int int_end;
        bool hidden;
        int in_number;
        std::vector<int> bg_rgb;

};

#endif // SODOKUBOX_HPP
