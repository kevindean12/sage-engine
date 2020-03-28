#pragma once

#include "Events/Event.hpp"

#include <sstream>

namespace Sage {

    class SAGE_API KeyboardEvent: public Event
    {
    protected:
        KeyboardEvent(int keycode): m_KeyCode{keycode} {}
        int m_KeyCode;

    public:
        inline int GetKeyCode() const {return m_KeyCode;}

        EVENT_CLASS_CATEGORY(EventCategoryKeyboard)
    };

    class SAGE_API KeyPressedEvent: public KeyboardEvent
    {
    private:
        int m_RepeatCount;

    public:
        KeyPressedEvent(int keycode, int repeatCount)
            : KeyboardEvent{keycode}, m_RepeatCount{repeatCount} {}
        
        inline int GetRepeatCount() const {return m_RepeatCount;}

        std::string ToString() const override
        {
            std::stringstream strstream;
            strstream << "KeyPressedEvent: " << m_KeyCode << " (" << m_RepeatCount << " repeats)";
            return strstream.str();
        }

        EVENT_CLASS_TYPE(KeyPressed)
    };

    class SAGE_API KeyReleasedEvent: public KeyboardEvent
    {
    public:
        KeyReleasedEvent(int keycode) :KeyboardEvent{keycode} {}

        std::string ToString() const override
        {
            std::stringstream strstream;
            strstream << "KeyReleasedEvent: " << m_KeyCode;
            return strstream.str();
        }

        EVENT_CLASS_TYPE(KeyReleased)
    };


}