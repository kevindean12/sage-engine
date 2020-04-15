#pragma once

#include "Sagepch.hpp"

#include "Sage/Core.hpp"
#include "Sage/Events/Event.hpp"

namespace Sage {

    struct WindowProps
    {
        std::string Title;
        unsigned int Width;
        unsigned int Height;
    };

    inline WindowProps buildMyWindowProps(const std::string& title="Sage Engine", unsigned int width = 1280, unsigned int height = 720)
    {
        return {title, width, height};
    }

    //interface representing a desktop window, to be implemented per-platform
    class SAGE_API Window {
    public:
        using EventCallbackFn = std::function<void(Event&)>;

        virtual ~Window() = default;

        virtual void OnUpdate() = 0;

        virtual unsigned int GetWidth() const = 0;
        virtual unsigned int GetHeight() const = 0;

        //window attributes
        virtual void SetEventCallback(const EventCallbackFn& callback) = 0;
        virtual void SetVSync(bool enabled) = 0;
        virtual bool IsVSync() const = 0;

        //virtual void* GetNativeWindow() const = 0;

        static Window* Create(const WindowProps& props = buildMyWindowProps()); 

    };

}