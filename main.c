#include "stdio.h"
#include "WeChatAPI.h"


int main(int argc, char* argv[]) {
    const char* devlicence;
    unsigned int licencelen;
    printf("hello\n");
    WeChatAPI::instance()->start(devlicence,licencelen);
    WeChatAPI::instance()->getSDKVersion();
    return 0;
}
