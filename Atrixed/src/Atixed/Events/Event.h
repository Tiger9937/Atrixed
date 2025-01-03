#pragma once

#include "../core.h"

#include <string>
#include <functional>

namespace Atrixed {
    enum class EventType{
        None=0,
        Windowclose , WindowResize , WindowFocuse , WindowLostFocus , WindowMoved,
        AppTick , AppUpdate , Apprender ,
        KeyPressed , KeyRelesed,
        MouseButtonPressed , MouseButtonRelesed , MouseMoved , MouseScrolled
    };

    enum EventCatagory{
        None=0,
        EventCatagoryAppliction = BIT(0),
        EventCatagoryInpute = BIT(1),
        EventCatagoryKeybord = BIT(2),
        EventCatagoryMouse = BIT(3),
        EventCatagoryMouseButton = BIT(4)
    };


#define EVENT_CLASS_TYPE(type) static EventType GetstaticType(){ return EventType::##type; }\
                               virtual EventType GetEventType()const override { return GetEventType();}\
                                virtual const char* GetName() const override { return #type; }

#define EVENT_CLASS_CATAGORY(Catagory) virtual int GetCatagoryFlage() const override { return Catagory; }


class ATRIXED_API  Event {
    friend class EventDispatcher;
public:
    virtual EventType GetEventType() const = 0;
    virtual const char* GetName() const = 0;
    virtual int GetCatagoryFlage() const = 0;
    virtual std::string ToString() const { return GetName();}

    inline bool IsInCatagory(EventCatagory catagory){
        return GetCatagoryFlage() & catagory;
        
    }

    protected:
        bool m_Handler = false;
};
                               
class ATRIXED_API EventDispatcher{
    template <typename T>
    using EventFn = std::function<bool(T&)>;

public:
    EventDispatcher(Event& event) :m_Event(event){

    }

    template <typename T>

    bool Dispatch(EventFn<T> func) {
        if (m_Event.GetEventType() == T::GetStaticType()) {
            m_Event.m_Handler = func(static_cast<T&>(m_Event));
            return true;
        }
        return false;
    }

private:
    Event& m_Event;
};

inline std::ostream& operator <<(std::ostream& os , const Event& e){
        return os<<e.ToString();
}

}