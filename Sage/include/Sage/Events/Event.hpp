#pragma once
#include "Core.hpp"
#include <string>
#include <functional>
#include <sstream>

namespace Sage{

    enum class EventType
    {
        None = 0,
        WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
        AppTick, AppUpdate, AppRender,
        KeyPressed, KeyReleased,
        MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
    };

    enum EventCategory
    {
        None = 0,
        EventCategoryApplication = BIT(0),
        EventCategoryInput = BIT(1),
        EventCategoryKeyboard = BIT(2),
        EventCategoryMouse = BIT(3),
        EventCategoryMouseButton = BIT(4)
    };

/*
    These macros are used in the subclasses of Event to override the pure virtual functions GetEventType, GetName, and GetCategoryFlags
    Note: ## pastes tokens together, so this allows setting the EventType
    Note: # puts quotes around a token, so stringifies type in GetName
*/
//------------------------------------------------------------------------------------------
#define EVENT_CLASS_TYPE(type) static EventType GetStaticType() {return EventType::##type;}\
                                                        virtual EventType GetEventType() const override {return GetStaticType();}\
                                                        virtual const char* GetName() const override {return #type;}   

#define EVENT_CLASS_CATEGORY(category) virtual int GetCategoryFlags() const override {return category;}
//------------------------------------------------------------------------------------------

    class Event
    {
    public:
        bool Handled = false;

        virtual EventType GetEventType() const = 0;
        virtual const char* GetName() const = 0;
        virtual int GetCategoryFlags() const = 0;
        virtual std::string ToString() const {return GetName();}

        //category is a bitfield. Returns bitwise-and to test if the event is in the given category
        //ie, returns true when category's bit ==1 and flag's bit ==1, false otherwise
        inline bool IsInCategory(EventCategory category)
        {
            return GetCategoryFlags() & category;
        }
    };

    class EventDispatcher
    {
    private:
        Event& m_Event;
    public:
        EventDispatcher(Event& event) : m_Event{event}{}

        //T is any Event type, F is the type 
        template<typename T, typename F>
        bool Dispatch(const F& func)
        {
            if(m_Event.GetEventType() == T::GetStaticType())
            {
                m_Event.Handled = func(static_cast<T&>(m_Event));
                return true;
            }
            return false;
        }
    };

    //for the logging library's usage
    inline std::ostream& operator<<(std::ostream& os, const Event& event)
    {
        return os << event.ToString();
    }
}