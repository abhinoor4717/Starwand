#pragma once

#include "Core.h"
#include "Layer.h"

namespace Starwand {
    class STARWAND_API LayerStack {
    public:
        LayerStack();
        ~LayerStack();

        LayerStack(const LayerStack&) = delete;
        LayerStack& operator=(const LayerStack&) = delete;

        LayerStack(LayerStack&&) noexcept = default;
        LayerStack& operator=(LayerStack&&) noexcept = default;

        void OnEvent(Event& e);
        void OnUpdate(DeltaTime& dt);

        template<typename T, typename... Args>
        T* PushLayer(Args&&... args) {
            static_assert(std::is_base_of<Layer, T>::value, "T must inherit from Layer");
            auto layer = std::make_unique<T>(std::forward<Args>(args)...);
            T* ptr = layer.get();
            m_Layers.push_back(std::move(layer));
            return ptr;
        }

        void PopLayer(Layer* layer);

    private:
        std::vector<std::unique_ptr<Layer>> m_Layers;
    };
}
