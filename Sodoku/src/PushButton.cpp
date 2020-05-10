#include "PushButton.hpp"
#include "graphics.hpp"
#include "Widget.hpp"
#include <string>
#include <iostream>
using namespace genv;

PushButton::PushButton(int x, int y, int w, int h, std::string t):Widget(x,y,w,h)
{
    pushed = false ;
    title = t;

    //ctor
}

PushButton::~PushButton()
{
    //dtor
}

void PushButton::draw(){
gout<< move_to(x,y) << color(0,0,0)<<box_to(x+width,y+height);
gout << move_to(x+2,y+2) << color(255,255,255)<<box_to(x+width-2,y+height-2);
gout << move_to(x+10, y+height/2+gout.cascent()/2)<< color(0,0,0) << text(title);
}
void PushButton::handle(event ev){
if(selected){
    pushed = true;

}else{
pushed=false;

}
}
void PushButton::setPushed(bool b ){
pushed = b;
}
