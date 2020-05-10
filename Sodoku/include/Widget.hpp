#ifndef WIDGET_HPP
#define WIDGET_HPP
#include "graphics.hpp"
#include <string>
#include <vector>
using namespace genv;
class Widget
{


    public:

    virtual ~Widget();
    void select(int mx, int my,event ev);
    virtual void handle(event ev)=0;
    Widget(int x, int y,int width, int height);
    virtual void draw()=0;




    int getWidth();
    int getHeight();
    bool getSelected();
    void setSelected(bool b);
    void setWidth(int w);
    void setHeight(int h);

protected:
        int x, y, width, height;

        bool selected = false;
};

#endif // WIDGET_HPP
