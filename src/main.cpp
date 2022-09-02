#include <iostream>
#include "Engine/engine.hpp"

using namespace std;

int main(int argc, char *argv[]) {
    cout << "Hi" << endl;
    
    Engine e = Engine();
    return e.Run(argc, argv);
}