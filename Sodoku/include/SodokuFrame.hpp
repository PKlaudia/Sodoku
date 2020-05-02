#ifndef SODOKUFRAME_HPP
#define SODOKUFRAME_HPP
#include "Widget.hpp"
#include "SodokuBox.hpp"
#include "graphics.hpp"
#include <vector>



class SodokuFrame: public Widget
{
    public:

        virtual ~SodokuFrame();

        virtual void handle(event ev);
        SodokuFrame(int x, int y,int width, int height);
        virtual void draw();



    protected:

    private:
        int bigborder,smallborder,boxsize;
        std::vector<SodokuBox*> boxes;
};

#endif // SODOKUFRAME_HPP
