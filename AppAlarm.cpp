#include "Initializer.h"

#include <memory>
#include <cstdlib>
#include "pistache/endpoint.h"

using namespace std;

using namespace Pistache;

class HelloHandler : public Http::Handler {
public:

    HTTP_PROTOTYPE(HelloHandler)

    void onRequest(const Http::Request& request, Http::ResponseWriter response) {

        cout << request.resource() <<endl;
    	response.send(Http::Code::Ok, "Hello, World");
    }
};

int main()
{
    Initializer::getInstance()->init();
    Initializer::getInstance()->begin();

	//Http::listenAndServe<HelloHandler>("*:9080");
    return 0;
}
