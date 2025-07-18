#pragma once

#include "Core.h"
#include "Events/Events.h"
#include "Utils/DeltaTime.h"

namespace Starwand {
    class STARWAND_API Layer {
    public:
        Layer(const char* name);
        ~Layer();

        virtual void OnEvent(Event& e) = 0;
        virtual void OnUpdate(DeltaTime& dt) = 0;

    private:
        std::string m_Name;
    };
}