#pragma once

namespace Starwand {

    class GraphicsAPI {
    public:
        enum class API {
            None = 0,
            OpenGL = 1
        };

        static API GetAPI() { return s_API; }
        static void SetAPI(API api) { s_API = api; }

    private:
        static API s_API;
    };

}