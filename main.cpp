#include "stdio.h"
#include "WeChatAPI.h"
#include <string.h>
//{"base_resp":{"errcode":0,"errmsg":"ok"},"deviceid":"gh_ee5f5486e852_73322ef614804f50","qrticket":"http:\/\/we.qq.com\/d\/AQCVTVvThKGxUJyAkQp7jnmECezy7JEFZDcpXF3I","devicelicence":"F6939BC3713BC3E72A7EE8B03BF55F0837245FAF0C8318EBF7AD746C46A7C19AA326999A613B7657FD426F9AF8F098900E6C79417EBF7860A5E09739F13753160C4DD59D780A448D204E1E27DBCC3865"}

//https://mp.weixin.qq.com/debug?token=92898811&lang=zh_CN
void onReceiveRsp(int taskid, int errcode, unsigned int funcid, const unsigned char* body, unsigned int bodylen) {
    printf("===>onReceiveRsp taskid= %d\n",taskid);
}
void onReceiveNtf(unsigned int funcid, const unsigned char* body, unsigned int bodylen) {
    printf("===>onReceiveNtf funcid= %d\n",funcid);
}
void onSDKEventCB(EventValue event_value) {
    printf("===>EventValue = %d\n",event_value);
}
int main(int argc, char* argv[]) {
    char*     devlicence="F6939BC3713BC3E72A7EE8B03BF55F0837245FAF0C8318EBF7AD746C46A7C19AA326999A613B7657FD426F9AF8F098900E6C79417EBF7860A5E09739F13753160C4DD59D780A448D204E1E27DBCC3865";
    int licencelen;
    const char* venderId;
    const char* deviceId;
    const char* SDKVersion;
    bool ret;
    unsigned char bodyArray[] ="{\"love\":[\"LOL\",\"Go shopping\"]}";
    const unsigned char* body;//= "{\"love\":[\"LOL\",\"Go shopping\"]}";
    licencelen = strlen(devlicence);
    printf("hello licencelen=%d\n",licencelen);
    ret = WeChatAPI::instance()->start(devlicence,licencelen);
    WeChatAPI::instance()->setCallBack(onReceiveRsp);
    WeChatAPI::instance()->setNotifyCallBack(onReceiveNtf);
    WeChatAPI::instance()->setSDKEventCallBack(onSDKEventCB);
    printf("===>ret = %d\n",ret);

    body = bodyArray;
    WeChatAPI::instance()->sendDataToServer(1,body,5);
    venderId = WeChatAPI::instance()->getVenderId();
    deviceId = WeChatAPI::instance()->getDeviceId();
    SDKVersion = WeChatAPI::instance()->getSDKVersion();
    printf("===>venderId = %s,deviceId = %s,SDKVersion=%s\n",venderId,deviceId,SDKVersion);


    while(1);
    return 0;
}

