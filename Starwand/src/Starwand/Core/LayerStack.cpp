#include "swpch.h"

#include "LayerStack.h"

namespace Starwand {
    LayerStack::LayerStack() {}

    LayerStack::~LayerStack() {}

    template<typename T, typename... Args>
    T* LayerStack::PushLayer(Args&&... args) {
        static_assert(std::is_base_of<Layer, T>::value, "T must inherit from Layer");
        auto layer = std::make_unique<T>(std::forward<Args>(args)...);
        T* ptr = layer.get();
        m_Layers.push_back(std::move(layer));
        return ptr;
    }

    void LayerStack::PopLayer(Layer* layer) {
        m_Layers.erase(std::remove_if(m_Layers.begin(), m_Layers.end(),
            [&](const std::unique_ptr<Layer>& l) { return l.get() == layer; }),
            m_Layers.end());
    }

}