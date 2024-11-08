#pragma once
#include "core.h"


namespace Atrixed {
	class  ATRIXED_API App {

		public:
			App();
			virtual ~App();
			void Run();

	};
	
	App* CreatApplication();


}


