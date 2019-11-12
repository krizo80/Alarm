#include "Initializer.h"


using namespace std;


int main()
{
    Initializer::getInstance()->init();
    Initializer::getInstance()->begin();
    return 0;
}
