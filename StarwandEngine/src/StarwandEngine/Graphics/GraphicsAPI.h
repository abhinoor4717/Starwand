#pragma once

namespace Starwand {

    class GraphicsAPI {
    public:
        enum class API {
            None = 0,
            OpenGL = 1
        };

        static inline API GetAPI() { return s_API; }
        static inline void SetAPI(API api) { s_API = api; }

        static void Initalize();

    private:
        static API s_API;
    };

}