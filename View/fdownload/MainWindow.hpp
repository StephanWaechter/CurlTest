#pragma once
#include <gtkmm.h>
#include <fdownload/Controller.hpp>

namespace fdownload
{
	class MainWindow : public Gtk::ApplicationWindow
	{
	public:
		MainWindow(Controller& controller);
	};
}