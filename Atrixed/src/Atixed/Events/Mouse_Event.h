#pragma once

#include "Event.h"
#include <sstream>

namespace Atrixed{

    class ATRIXED_API MouseMovedEvent : public Event {
    public:
        MouseMovedEvent(float X , float Y) : {}

        inline float Getx() const {return m_MouseX; }
        inline float Gety() const {return m_MouseY; }
        

        std::ToString() const override{
            std::stringstream ss;
            ss<< "Mouse Moved Event" << "X:" << m_MouseX << "\n" << "Y:" << m_MouseY;
            return ss.str();
        }

        EVENT_CLASS_TYPE(MouseMoved)
        EVENT_CLASS_CATAGORY( EventCatagoryMouse | EventCatagoryInpute)

    private:
        float m_MouseX , m_MouseY;
    };



    class ATRIXED_API MouseScrolledEvent :public Event {
    public:

        MouseScrolledEvent(float Xoffset , float Yoffset) : m_Xoffset(Xoffset) , m_Yoffset(Yoffset){}

        inline float Get_ X_Offset() const {return m_Xoffset;}
        inline float Get_Y_Offset() const {return m_Yoffset;}

        std::string ToString(){

            std::stringstream ss;
            ss<<"Mouse Scroll Event" << Get_ X_Offset() << "\n" << Get_Y_Offset();
            return ss.str();
            
        }

        EVENT_CLASS_TYPE(MouseScrolled)
        EVENT_CLASS_CATAGORY( EventCatagoryMouse | EventCatagoryInpute)

    private:
        float m_Xoffset , m_Yoffset 

    };

    class ATRIXED_API MouseButtonEvent : public Event{
    public:
        inline int getMouseButton() const {return m_button;}

        EVENT_CLASS_CATAGORY( EventCatagoryMouse | EventCatagoryInpute)

    protected:
        int m_button;
        MouseButtonEvent(int button) : m_button(button){}

    };

    class ATRIXED_API MouseButtonPressedEvent : public MouseButtonEvent{
    public:
        MouseButtonPressedEvent(int button) : MouseButtonEvent(button){}

        std::string ToString() const override{
            std::stringstream ss;
            ss << "MouseButtonPressed" << m_button;
            return ss.str();
        }   
        EVENT_CLASS_TYPE(MouseButtonPressed)
    };

    class ATRIXED_API MouseButtonRelesedEvent : public MouseButtonEvent{
    public:
        MouseButtonRelesedEvent(int button) : MouseButtonEvent(){}

        std::string ToString() const override{
            std::stringstream ss;
            ss<<"MouseButtonRelesed: "<< m_button
            return ss.str();
        }

        EVENT_CLASS_TYPE(MouseButtonRelesed)

    };


}