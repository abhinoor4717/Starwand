#pragma once

#include "Core.h"
#include "Layer.h"

namespace Starwand {
    class STARWAND_API LayerStack {
    public:
        LayerStack();
        ~LayerStack();

        template<typename T, typename... Args>
        T* PushLayer(Args&&... args);
        void PopLayer(Layer* layer);

    private:
        std::vector<std::unique_ptr<Layer>> m_Layers;
    };
}