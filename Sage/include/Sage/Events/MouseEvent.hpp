#pragma once

#include "Events/Event.hpp"

#include <sstream>

namespace Sage {

    class SAGE_API MouseMovedEvent: public Event
    {
    private:
        float m_MouseX, m_MouseY;
    public:
        MouseMovedEvent(float x, float y): m_MouseX{x}, m_MouseY{y}{}

        inline float GetX() {return m_MouseX;}
        inline float GetY() {return m_MouseY;}

        std::string ToString() const override
        {
            std::stringstream strstream;
            strstream << "MouseMovedEvent: " << m_MouseX << ", " << m_MouseY;
            return strstream.str();
        }

        EVENT_CLASS_TYPE(MouseMoved)
        EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
    };

    class SAGE_API MouseScrolledEvent: public Event
    {
    private:
        float m_xOffset, m_yOffset;
    public:
        MouseScrolledEvent(float xOffset, float yOffset): m_xOffset{xOffset}, m_yOffset{yOffset}{}
        
        inline float GetXOffset() const {return m_xOffset;}
        inline float GetYOffset() const {return m_yOffset;}

        std::string ToString() const override
        {
            std::stringstream strstream;
            strstream << "MouseScrolledEvent: " << m_xOffset << ", " << m_yOffset;
            return strstream.str();
        }

        EVENT_CLASS_TYPE(MouseScrolled)
        EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
    };

    class SAGE_API MouseButtonEvent : public Event
    {
    private:
        int m_Button;
    protected:
        MouseButtonEvent(int button): m_Button{button} {}
    public:
        inline int GetMouseButton() const {return m_Button;}
        EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)

    };

    class SAGE_API MouseButtonPressedEvent: public MouseButtonEvent
    {
    public:
        MouseButtonPressedEvent(int button): MouseButtonEvent{button} {}

        std::string ToString() const override
        {
            std::stringstream strstream;
            strstream << "MouseButtonPressedEvent: " << GetMouseButton();
            return strstream.str();
        }

        EVENT_CLASS_TYPE(MouseButtonPressed)
    };

    class SAGE_API MouseButtonReleasedEvent: public MouseButtonEvent
    {
    public:
        MouseButtonReleasedEvent(int button): MouseButtonEvent{button} {}

        std::string ToString() const override
        {
            std::stringstream strstream;
            strstream << "MouseButtonReleasedEvent: " << GetMouseButton();
            return strstream.str();
        }

        EVENT_CLASS_TYPE(MouseButtonReleased)
    };

}