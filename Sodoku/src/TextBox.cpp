#include "TextBox.hpp"
#include "graphics.hpp"
#include "Widget.hpp"
#include <string>
using namespace genv;
TextBox::TextBox(int x, int y, int w, int h, std::string sz):Widget(x,y,w,h)
{
    szoveg = sz;
    //ctor
}

TextBox::~TextBox()
{
    //dtor
}

void TextBox::draw(){
gout << move_to(x,y) << color(0,0,0)<<box_to(x+width,y+height);
gout << move_to(x+2,y+2) << color(255,255,255)<<box_to(x+width-2,y+height-2);
gout << move_to(x+10, y+height/2+gout.cascent()/2)<< color(0,0,0) << text(szoveg);


}
void TextBox::handle(event ev){

}

