#include "Starwand.h"

class MainLayer : public Starwand::Layer {
public:
    MainLayer() : Layer("Main Layer") {}

    void OnUpdate(Starwand::DeltaTime& dt) override {
        using namespace Starwand;
        Renderer::Clear();
        Renderer::DrawRectangle({10, 200, 10, 20}, BLUE);
        Renderer::DrawCircle({300, 500}, 69);
        Renderer::DrawTriangle({300, 100}, {300, 200}, {410, 150});
        Renderer::DrawText(std::to_string(Application::Get().GetFPS()), {10, 10}, 20);
        
    }

    void OnEvent(Starwand::Event& e) {
        if (auto event = Starwand::ConvertEvent<Starwand::MouseButtonDownEvent>(e)) {
            Starwand::Renderer::DrawRectangle({(float)event->GetX(), (float)event->GetY(), 1, 1});
        }
    }
};

class MyApp : public Starwand::Application {
public:
    MyApp() : Application({"My Game", 1080, 720, Starwand::ApplicationConfigFlags::NONE}) {
        auto mainLayer = GetLayerStack().PushLayer<MainLayer>();
    }
};

int main(int argc, char* argv[]) {
    MyApp app;
    app.Run();
}