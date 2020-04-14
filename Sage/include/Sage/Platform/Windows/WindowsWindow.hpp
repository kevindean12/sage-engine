#pragma once

#include "Window.hpp"

#include "GLFW/glfw3.h"

namespace Sage {

    class WindowsWindow : public Window
    {
    private:
        virtual void Init(const WindowProps& props);
        virtual void Shutdown();

        //GLFW
        GLFWwindow* m_Window;

        struct WindowData
        {
            std::string Title;
            unsigned int Width, Height;
            bool VSync;

            EventCallbackFn EventCallback;
        };

        WindowData m_Data;

    public: 
        WindowsWindow(const WindowProps& props);
        virtual ~WindowsWindow(); //so that if deleted from a pointer to a Window (ie the base class), it'll still free up memory associated with this derived class instance

        void OnUpdate() override;

        inline unsigned int GetWidth() const override {return m_Data.Width;}
        inline unsigned int GetHeight() const override {return m_Data.Height;}

        //Window attributes
        inline void SetEventCallback(const EventCallbackFn& callback) override {m_Data.EventCallback = callback;}
        void SetVSync(bool enabled) override;
        bool IsVSync() const override;
    };
}