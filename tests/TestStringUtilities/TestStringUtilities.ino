#include <AUnitVerbose.h>

using namespace aunit;

void setup(void)
{
    #if !defined(EPOXY_DUINO)
        delay(1000);
    #endif

    Serial.begin(115200);
    while (!Serial);

    #if defined(EPOXY_DUINO)
        Serial.setLineModeUnix();
    #endif
}

void loop(void)
{
    TestRunner::run();
}