#pragma once

#include "Events/Event.hpp"

namespace Sage {

    class SAGE_API WindowResizeEvent : public Event
    {
    private:
        unsigned int m_Width, m_Height;
    public:
        WindowResizeEvent(unsigned int width, unsigned int height)
            : m_Width{width}, m_Height{height} {}
        
        inline unsigned int GetWidth() const {return m_Width;}
        inline unsigned int GetHeight() const {return m_Height;}

        std::string ToString() const override
        {
            std::stringstream strstream;
            strstream << "WindowResizeEvent: " << m_Width << ", " << m_Height;
            return strstream.str();
        }

        EVENT_CLASS_TYPE(WindowResize)
        EVENT_CLASS_CATEGORY(EventCategoryApplication)
    };

    class SAGE_API WindowCloseEvent : public Event
    {
    public:
        WindowCloseEvent() {}

        EVENT_CLASS_TYPE(WindowClose)
        EVENT_CLASS_CATEGORY(EventCategoryApplication)
    };

    class SAGE_API AppTickEvent: public Event
    {
    public:
        AppTickEvent() {}

        EVENT_CLASS_TYPE(AppTick)
        EVENT_CLASS_CATEGORY(EventCategoryApplication)
    };

    class SAGE_API AppUpdateEvent: public Event
    {
    public:
        AppUpdateEvent() {}

        EVENT_CLASS_TYPE(AppUpdate)
        EVENT_CLASS_CATEGORY(EventCategoryApplication)
    };

    class SAGE_API AppRenderEvent: public Event
    {
    public:
        AppRenderEvent() {}

        EVENT_CLASS_TYPE(AppRender)
        EVENT_CLASS_CATEGORY(EventCategoryApplication)
    };




}