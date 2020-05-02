#include "Widget.hpp"
#include "graphics.hpp"
#include <string>
Widget::Widget(int wx, int wy, int ww, int wh):x(wx), y(wy), width(ww),height(wh)
{
    //ctor
}

Widget::~Widget()
{
    //dtor;
}

void Widget::select(int mx, int my,event ev){
if(mx > x && mx< x+width && my > y && my < y + height && ev.type == ev_mouse && ev.button == btn_left){
selected = true;

}else if(!(mx > x && mx< x+width && my > y && my < y + height) && ev.type == ev_mouse && ev.button == btn_left){
selected = false;

}
};

int Widget::getHeight(){
return height;
}
int Widget::getWidth(){
return width;
}
void Widget::setWidth(int w){
width = w;
}
void Widget::setHeight(int h){
height = h;
}
bool Widget::getSelected(){
return selected;
}
