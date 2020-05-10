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


    widgets.push_back(new PushButton(100,20,120,40,"Új játék"));
    widgets.push_back(new PushButton(240,20,120,40,"Help"));
    widgets.push_back(new PushButton(380,20,120,40,"Solve"));


    std::vector<SodokuBox*> lines;
     for(int i=0; i<9; i++){

           for(int j=0; j<9;j++){


        lines.push_back(new SodokuBox( 100+j*(40), 100+i*40 , 40, 40,0, 0));


            }
            boxes.push_back(lines);
            lines.clear();

    }

 master = new JatekMester(boxes);

    widgets.push_back(new SodokuFrame(100,100,374,374));




}

Application::~Application()
{
    //dtor
}

void Application::run_app(){

gout.open(X,Y);

event ev;
master->generateSodoku();

while(gin>>ev){

this->clearscreen();
handle_key_events(ev);
    master->check();
for(size_t i =0; i< 9; i++){
for(int j=0;j<9;j++){
        boxes[i][j]->select(ev.pos_x,ev.pos_y,ev);
        boxes[i][j]->handle(ev);
        boxes[i][j]->draw();
}
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
void Application::handle_key_events(event ev){

if(widgets[0]->getSelected()){
  master->generateSodoku();
  widgets[0]->setSelected(false);
}else if(widgets[1]->getSelected()){
master->help();
widgets[1]->setSelected(false);
}else if(widgets[2]->getSelected()){
master->solveit();
widgets[2]->setSelected(false);
}

}
