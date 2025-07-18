#pragma once

namespace Starwand {
    class DeltaTime {
    public:
        inline static DeltaTime FromSeconds(float sec) {return DeltaTime(sec*1000); }
        inline static DeltaTime FromMilliseconds(float ms) { return DeltaTime(ms); }

        inline float GetMilliseconds() { return m_Milliseconds; };
        inline float GetSeconds() { return m_Milliseconds / 1000; }
    private:
        inline DeltaTime(float ms) : m_Milliseconds(ms) {};
        float m_Milliseconds;
    };
}