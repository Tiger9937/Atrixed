#pragma once

#include "Event.h"
#include <sstream>


namespace Atrixed{

    class ATRIXED_API KeyEvent : public Event{
    public:
        inline int GetKeyCode() const { return m_keycode ; }


        EVENT_CLASS_CATAGORY(EventCatagoryKeybord | EventCatagoryInpute)


        protected:
            KeyEvent(int keycode) : m_keycode(keycode){}

            int m_keycode;
    };

    class ATRIXED_API KeypressedEvent:public KeyEvent{
    public:
        KeypressedEvent(int keycode , int repeatCount) : KeyEvent(keycode) , m_RepeatCount() {}

        inline int GetRepeatCount() const {return m_RepeatCount;}

        std::string ToString() const override {

            std::stringstream ss;
            ss << "KeypressedEvent: " << m_keycode << " ( " << m_RepeatCount << "Repeats";
            return ss.str();

        }
        EVENT_CLASS_TYPE(KeyPressed)
        
        private:
            int m_RepeatCount;
        
    };

    class ATRIXED_API KeyRelesed:public KeyEvent{
    public:
        KeyRelesed(int keycode) : KeyEvent(keycode){}

        std::ToString() const override {

            std::stringstream ss;
            ss << "Key Relesed Event: " <<  m_keycode;
            return ss.str();    

        }
        EVENT_CLASS_TYPE(KeyRelesed)
    };

}
