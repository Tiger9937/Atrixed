#pragma once
#include "core.h"
#include "./Events/Event.h"
#include "./Events/Application_Event.h"

namespace Atrixed {
	class ATRIXED_API App {

		public:
			App();
			virtual ~App();
			void Run();
	};
	App* CreateApplication();
}


