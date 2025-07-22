#include "swpch.h"

#include "LayerStack.h"

namespace Starwand {
    LayerStack::LayerStack() {}

    LayerStack::~LayerStack() {}

    void LayerStack::OnEvent(Event& e) {
        if (!e.Handled) {
            for (auto& layer: m_Layers) {
                layer->OnEvent(e);
            }
        }
    }

    void LayerStack::OnUpdate(DeltaTime& dt) {
        for (auto& layer: m_Layers) {
            layer->OnUpdate(dt);
        }
    }

    void LayerStack::PopLayer(Layer* layer) {
        m_Layers.erase(std::remove_if(m_Layers.begin(), m_Layers.end(),
            [&](const std::unique_ptr<Layer>& l) { return l.get() == layer; }),
            m_Layers.end());
    }

}