#include "JatekMester.hpp"
#include "graphics.hpp"
#include "Widget.hpp"

using namespace genv;
JatekMester::JatekMester(std::vector<SodokuBox*> b)

{
boxes = b;

    //ctor
}

JatekMester::~JatekMester()
{
    //dtor
}

void JatekMester::check()
{
  for(size_t i=0; i< boxes.size();i++){
    if(boxes[i]->getSelected() && boxes[i]->getValue() != boxes[i]->getInNumber()&& boxes[i]->getInNumber() != 0){

        boxes[i]->setRGB(255,0,0);
    }else{
    boxes[i]->setRGB(255,255,255);
    }

  }
}
