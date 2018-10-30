#include "stdio.h"
#include "WeChatAPI.h"

int main(int argc, char* argv[]) {
    char* devlicence="dddd";
    unsigned int licencelen;
    bool ret;
    printf("hello\n");
    ret = WeChatAPI::instance()->start(devlicence,licencelen);
    printf("ret = %d,devlicence = %s\n",ret,devlicence);
    WeChatAPI::instance()->getSDKVersion();
    return 0;
}
