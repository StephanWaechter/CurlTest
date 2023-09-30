// Type your code here, or load an example.
#include <fdownload/MainWindow.hpp>
#include <gtkmm.h>
#include <stdexcept>
#include <iostream>

namespace dm = fdownload;

int main(
    [[maybe_unused]] int argc,
    [[maybe_unused]] char** argv
) 
{
    try
    {
        auto controller = dm::Controller();
        auto app = Gtk::Application::create(GTK_APPLICATION_NAME);
        return app->make_window_and_run<dm::MainWindow>(argc, argv, controller);
    }
    catch (std::exception const& e)
    {
        std::cout << e.what() << '\n';
        return -1;
    }
    catch (...)
    {
        std::cout << "Unknown exception\n";
        return -1;
    }
}