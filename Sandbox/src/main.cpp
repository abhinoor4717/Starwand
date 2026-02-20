#include <iostream>
#include "StarwandEngine.h"

using namespace Starwand;

class TestApp : public Application {
public:
    TestApp() : Application("Test App", 800, 600) {

    }

    void Update() override {
        
    }

private:
    
};

int main() {
    Application("App", 800, 600).Run();
}