#ifndef PUSHBUTTON_HPP
#define PUSHBUTTON_HPP
#include "graphics.hpp"
#include "Widget.hpp"
#include <string>

class PushButton:public Widget
{
    public:
        PushButton(int x, int y,int width, int height, std::string t);
        virtual ~PushButton();
        virtual void draw();
        virtual void handle(event ev);

        void setPushed(bool b);
        bool getPushed();

    protected:

    private:
        bool pushed;

        std::string title;

};

#endif // PUSHBUTTON_HPP
