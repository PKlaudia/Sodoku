#ifndef APPLICATION_HPP
#define APPLICATION_HPP
#include "graphics.hpp"
#include "Widget.hpp"
#include <vector>
#include "JatekMester.hpp"
#include "SodokuBox.hpp"
class Application
{
    public:
        Application();
        virtual ~Application();
        void clearscreen();
        void handle_key_events(const genv::event ev);
        void run_app();

        void close_app();
    protected:


    private:
        const int X = 600;
        const int Y =600;
        std::vector<Widget*> widgets;
        std::vector<std::vector<SodokuBox*>> boxes;
        JatekMester* master;

        std::ifstream file;

};

#endif // APPLICATION_HPP
