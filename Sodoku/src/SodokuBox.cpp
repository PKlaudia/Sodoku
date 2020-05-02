#include "SodokuBox.hpp"
#include "iostream"
SodokuBox::SodokuBox(int x, int y, int w, int h, int v, bool b):Widget(x,y,w,h)
{
    int_start = 1;
    int_end = 9;
    value=v;
    hidden = b;
    if(hidden){
     in_number = 0;
    }else{
    in_number = value;
    }
    for(size_t i=0; i<3; i++){
        bg_rgb.push_back(255);
    }
    //ctor
}

SodokuBox::~SodokuBox()
{
    //dtor
}
void SodokuBox::draw(){

gout<<color(bg_rgb[0],bg_rgb[1],bg_rgb[2]);
gout<<move_to(x,y)<<box_to(x+width,y+height);
if(in_number!=0){
gout << color(0,0,0) << move_to(x+width/2-gout.cascent()/2, y+height/2+gout.cascent()/2)<< text(std::to_string(in_number));
}

}
void SodokuBox::handle(event ev){
if(selected){
if(ev.keycode == 49){
    in_number=1;
    }else if(ev.keycode == 50){
   in_number=2;
}else if(ev.keycode == 51){
   in_number=3;
}else if(ev.keycode == 52){
   in_number=4;
}else if(ev.keycode == 53){
   in_number=5;
}else if(ev.keycode == 54){
   in_number=6;
}else if(ev.keycode == 55){
   in_number=7;
}else if(ev.keycode == 56){
    in_number=8;
}else if(ev.keycode == 57){
    in_number=9;
}else if(ev.keycode == key_backspace || ev.keycode==key_delete){
    in_number=0;
}

}


}
int SodokuBox::getValue(){
return value;
}
void SodokuBox::setRGB(int r,int g,int b){
bg_rgb[0] = r;
bg_rgb[1] = g;
bg_rgb[2] = b;

}
void SodokuBox::setHide(bool b){
hidden = b;
}
int SodokuBox::getInNumber(){
return in_number;
}
