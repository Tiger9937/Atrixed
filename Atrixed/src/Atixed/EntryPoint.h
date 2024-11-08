#pragma once

#ifdef AX_PLATFORM_WINDOWS 

extern Atrixed::App* Atrixed::CreatApplication();

int main(int argc , char** argv) {

	printf("Well come to Atrixed");
	auto app = Atrixed::CreatApplication();
	app->Run();
	delete app;
}

#endif 