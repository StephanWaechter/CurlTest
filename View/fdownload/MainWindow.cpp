#include "MainWindow.hpp"

namespace fdownload
{
	static void set_label_to_counter(auto& counter, auto& controller)
	{
		counter.set_text(
			std::to_string(controller.Counter.value())
		);
	}

	MainWindow::MainWindow(Controller& controller)
	{
		auto& box = *Gtk::make_managed<Gtk::Box>();
		box.set_orientation(Gtk::Orientation::VERTICAL);

		auto& label = *Gtk::make_managed<Gtk::Label>("Hello World!!!");
		
		auto& counter = *Gtk::make_managed<Gtk::Label>();
		set_label_to_counter(counter, controller);

		auto on_click = [&counter, &controller] {
			
			controller.Counter.set(
				controller.Counter.value() + 1
			);
			set_label_to_counter(counter, controller);
		};

		auto& button = *Gtk::make_managed<Gtk::Button>("OKAY");
		button.signal_clicked().connect(
			sigc::track_object(
				on_click,
				*this
				)
		);
		
		box.append(label);
		box.append(button);
		box.append(counter);

		set_child(box);
		show();
	};
}