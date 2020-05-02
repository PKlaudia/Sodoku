#ifndef WIDGET_HPP
#define WIDGET_HPP
#include "graphics.hpp"
#include <string>
#include <vector>
using namespace genv;
class Widget
{
    protected:
        int x, y, width, height;
        int mouse_x =0;
        int mouse_y =0;
        bool selected = false;

    public:

    virtual ~Widget();
    void select(int mx, int my,event ev);
    virtual void handle(event ev)=0;
    Widget(int x, int y,int width, int height);
    virtual void draw()=0;




    int getWidth();
    int getHeight();
    bool getSelected();

    void setWidth(int w);
    void setHeight(int h);


};

#endif // WIDGET_HPP
