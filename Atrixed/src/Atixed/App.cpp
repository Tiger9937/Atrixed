#include "Axpch.h"
#include "App.h"
#include "../Atixed/Events/Event.h"
#include "./log.h"


namespace Atrixed {
	App::App() {

	};

	App::~App() {

	};

	void App::Run() {

		Atrixed::WindowResizeEvent e(1200,720);
		fmt::print("Event: {}\n", e.ToString());

		while (true);
	}
}
