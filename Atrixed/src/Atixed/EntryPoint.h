// main.cpp
#pragma once

#ifdef AX_PLATFORM_WINDOWS 

namespace Atrixed {
    extern Atrixed::App* CreateApplication();  
}


int main(int argc, char** argv) {
    
    Atrixed::Log::Init();

    AX_CORE_WARN("Loging now rasy");
    AX_CLIENT_FLUSH();

   
    auto app = Atrixed::CreateApplication();
    app->Run();
    delete app;
}

#endif // AX_PLATFORM_WINDOWS


