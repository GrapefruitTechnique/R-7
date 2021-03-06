/*
* Copyright (C) 2017 by Godlike
* This code is licensed under the MIT license (MIT)
* (http://opensource.org/licenses/MIT)
*/

#include <unicorn/system/profiler/KeyProfiler.hpp>

#include <unicorn/system/Manager.hpp>

#include <unicorn/system/input/Modifier.hpp>

#include <unicorn/utility/InternalLoggers.hpp>

namespace unicorn
{
namespace system
{

KeyProfiler::KeyProfiler(Manager& manager)
    : m_systemManager( manager )
{
    LOG_PROFILER->Info("KeyProfiler created");

    m_systemManager.WindowCreated.connect(this, &KeyProfiler::OnWindowCreated);
}

KeyProfiler::~KeyProfiler()
{
    m_systemManager.WindowCreated.disconnect(this, &KeyProfiler::OnWindowCreated);

    LOG_PROFILER->Info("KeyProfiler destroyed");
}

void KeyProfiler::OnWindowCreated(Window* pWindow)
{
    LOG_PROFILER->Info("KeyProfiler binds to Keyboard events of Window[{}]", pWindow->GetId());

    pWindow->Keyboard.connect(this, &KeyProfiler::OnWindowKeyboard);
    pWindow->Unicode.connect(this, &KeyProfiler::OnWindowUnicode);
}

void KeyProfiler::OnWindowKeyboard(Window::KeyboardEvent const& keyboardEvent)
{
    Window* const& pWindow = keyboardEvent.pWindow;
    input::Key const& key = keyboardEvent.key;
    uint32_t const& scancode = keyboardEvent.scancode;
    input::Action const& action = keyboardEvent.action;
    input::Modifier::Mask const& modifiers = keyboardEvent.modifiers;

    LOG_PROFILER->Info("Window[{}]: Key input received: {}[{}] {} {}", pWindow->GetId(), input::Stringify(key), scancode, input::Stringify(action), input::Modifier::Stringify(modifiers).c_str());
}

void KeyProfiler::OnWindowUnicode(Window* pWindow, uint32_t unicode, input::Modifier::Mask modifiers)
{
    LOG_PROFILER->Info("Window[{}]: unicode input received: {} {}", pWindow->GetId(), unicode, input::Modifier::Stringify(modifiers).c_str());
}

}
}
