/*
* Copyright (C) 2017 by Godlike
* This code is licensed under the MIT license (MIT)
* (http://opensource.org/licenses/MIT)
*/

#ifndef UNICORN_GRAPHICS_SUBSYSTEM_HPP
#define UNICORN_GRAPHICS_SUBSYSTEM_HPP


namespace uc
{
    namespace graphics
    {
        class GraphicsSubsystem
        {
            virtual bool Init() = 0;
            virtual bool Deinit() = 0;
            virtual bool RecreateSwapChain() = 0;
            virtual bool Render() = 0;
            virtual ~GraphicsSubsystem() = 0;
        };
    }
}

#endif // UNICORN_GRAPHICS_SUBSYSTEM_HPP