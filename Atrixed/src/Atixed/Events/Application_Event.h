#pragma once

#include "Event.h"
#include <sstream>


namespace Atrixed{
    class ATRIXED_API WindowResizeEvent : public Event {
    public:
        WindowResizeEvent(unsigned int width, unsigned int hight) :m_width(width), m_hight(hight) {}

        inline unsigned int GetWindow_width() const { return m_width; }
        inline unsigned int GetWindow_hight() const { return m_hight; }

        std::string ToString() const override {
            std::stringstream ss;
            ss << "WindowResize: " << "width: " << "," << GetWindow_width() << "hight: " << GetWindow_hight();
            return ss.str();
        }

        EVENT_CLASS_TYPE(WindowResize);
        EVENT_CLASS_CATAGORY(EventCatagoryAppliction);


    private:
        unsigned int m_width, m_hight;

    };


    class ATRIXED_API WindowcloseEvent : public Event{
        WindowcloseEvent(){};
        
        EVENT_CLASS_TYPE(Windowclose);
        EVENT_CLASS_CATAGORY(EventCatagoryAppliction);
    };

    class ATRIXED_API ApprenderEvent : public Event{
        ApprenderEvent(){}

        EVENT_CLASS_TYPE(Apprender);
        EVENT_CLASS_CATAGORY(EventCatagoryAppliction);
    };

    class ATRIXED_API AppUpdatEvent : public Event{
        AppUpdatEvent(){}

        EVENT_CLASS_TYPE(AppUpdate);
        EVENT_CLASS_CATAGORY(EventCatagoryAppliction);
    };

    class ATRIXED_API AppTickEvent : public Event{
        AppTickEvent(){}

        EVENT_CLASS_TYPE(AppTick);
        EVENT_CLASS_CATAGORY(EventCatagoryAppliction);
    };


}
