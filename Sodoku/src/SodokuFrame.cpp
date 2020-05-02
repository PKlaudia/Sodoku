#include "SodokuFrame.hpp"
#include "SodokuBox.hpp"
#include "graphics.hpp"
#include "Widget.hpp"
using namespace genv;
SodokuFrame::SodokuFrame(int x, int y, int w, int h):Widget(x,y,w,h)
{
    smallborder = 1;
    bigborder = 2;
    boxsize = 40;


    //ctor
}

SodokuFrame::~SodokuFrame()
{
    //dtor
}

void SodokuFrame::draw(){
for(size_t i=0; i<boxes.size();i++){

    /*boxes[i]->draw();*/

}
for(int i=0; i<10; i++){

           if(i%3!=0){
  gout<<color(169,169,169);
   gout<<move_to(x,y+i*(boxsize))<<box_to(x+(9*boxsize),y+i*(boxsize)+smallborder);
gout<< move_to(x+i*(boxsize),y)<<box_to(x+i*(boxsize)+smallborder,y+(9*boxsize));

        }
}
for(int i=0; i<10; i++){
        if(i%3 ==0){
  gout<<color(0,0,0);
    gout<<move_to(x,y+i*(boxsize))<<box_to(x+(9*boxsize),y+i*(boxsize)+bigborder);
    gout<< move_to(x+i*(boxsize),y)<<box_to(x+i*(boxsize)+bigborder,y+(9*boxsize));
        }

}


}
void SodokuFrame::handle(event ev){
for(size_t i=0; i<boxes.size();i++){

    boxes[i]->handle(ev);

}
};

