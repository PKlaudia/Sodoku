#include "Application.hpp"
#include "graphics.hpp"
#include "Widget.hpp"
#include "iostream"
#include "SodokuBox.hpp"
#include "PushButton.hpp"
#include "JatekMester.hpp"
#include "SodokuFrame.hpp"
#include "fstream"

using namespace genv;
Application::Application()
{
    //ctor
file.open("sodoku.txt");

    widgets.push_back(new PushButton(100,20,120,40,"Új játék"));
    widgets.push_back(new PushButton(240,20,120,40,"Help"));
    widgets.push_back(new PushButton(380,20,120,40,"Solve"));

    int v=0;
    bool b;
    char c;
     for(int i=0; i<9; i++){
            for(int j=0; j<9;j++){
                       file >> v >> c >>  b >> c;
        boxes.push_back(new SodokuBox( 100+i*(40), 100+j*40 , 40, 40, v, b));


            }
    }

    widgets.push_back(new SodokuFrame(100,100,374,374));
    master = new JatekMester(boxes);
}

Application::~Application()
{
    //dtor
}

void Application::run_app(){
gout.open(X,Y);

event ev;

while(gin>>ev){

this->clearscreen();
master->check();
for(size_t i =0; i< boxes.size(); i++){
        boxes[i]->select(ev.pos_x,ev.pos_y,ev);
        boxes[i]->handle(ev);
        boxes[i]->draw();

}

for(size_t i =0; i< widgets.size(); i++){
        widgets[i]->select(ev.pos_x,ev.pos_y,ev);
        widgets[i]->handle(ev);
    widgets[i]->draw();


}







gout << refresh;
}


}
void Application::clearscreen(){
gout<< color(15,49,82) << move_to(0,0)<<box(X,Y);
}
