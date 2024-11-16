// main.cpp
#pragma once

#ifdef AX_PLATFORM_WINDOWS 

namespace Atrixed {
    extern App* CreateApplication(); // Declaration of CreateApplication function
}

int main(int argc, char** argv) {

    
   
    auto app = Atrixed::CreateApplication();
    app->Run();
    delete app;
}

#endif // AX_PLATFORM_WINDOWS
