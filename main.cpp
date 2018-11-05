#include "stdio.h"
#include "WeChatAPI.h"
#include <string.h>
//{"base_resp":{"errcode":0,"errmsg":"ok"},"deviceid":"gh_ee5f5486e852_73322ef614804f50","qrticket":"http:\/\/we.qq.com\/d\/AQCVTVvThKGxUJyAkQp7jnmECezy7JEFZDcpXF3I","devicelicence":"F6939BC3713BC3E72A7EE8B03BF55F0837245FAF0C8318EBF7AD746C46A7C19AA326999A613B7657FD426F9AF8F098900E6C79417EBF7860A5E09739F13753160C4DD59D780A448D204E1E27DBCC3865"}

//https://mp.weixin.qq.com/debug?token=92898811&lang=zh_CN
void onReceiveRsp(int taskid, int errcode, unsigned int funcid, const unsigned char* body, unsigned int bodylen) {
    printf("===>onReceiveRsp taskid= %d,body = %s\n",taskid,body);
}
void onReceiveNtf(unsigned int funcid, const unsigned char* body, unsigned int bodylen) {
    printf("===>onReceiveNtf funcid= %d\n",funcid);
}

void onSDKEventCB(EventValue event_value) {
    const unsigned char* body;
    int ret;
    unsigned char bodyArray[] ="{\"msg_type\":\"notify\",\"services\":{\"operation_status\":{\"status\":1},\"air_conditioner\":{\"tempe_indoor\":  26,\"tempe_outdoor\": 31,}}}";
    printf("===>EventValue = %d\n",event_value);

    body = bodyArray;
    ret = WeChatAPI::instance()->sendDataToServer(1,body,5);
    printf("===>sendDataToServer() ret = %d,body = %s\n",ret,body);
    //WeChatAPI::instance()->release();
}
int main(int argc, char* argv[]) {
    char*     devlicence="CA43C9E2A9E9EBBFA07EF8E8B75B1868E2A1B3E49AC67684E66EDA48A10BF155494FD09937A2562B769B7827CA12AA2441FAFFE1B1870365DECF2096F45FC2B326C5132D3FB444CFA6BDE17EC910DE9E";
    int licencelen;
    const char* venderId;
    const char* deviceId;
    const char* SDKVersion;
    bool retBool,ret;
    //unsigned char bodyArray[] ="{\"love\":[\"LOL\",\"Go shopping\"]}";

    licencelen = strlen(devlicence);
    printf("hello licencelen=%d\n",licencelen);
    retBool = WeChatAPI::instance()->start(devlicence,licencelen);
    printf("===>start() retBool = %d\n",retBool);
    WeChatAPI::instance()->setCallBack(onReceiveRsp);
    WeChatAPI::instance()->setNotifyCallBack(onReceiveNtf);
    WeChatAPI::instance()->setSDKEventCallBack(onSDKEventCB);

    venderId = WeChatAPI::instance()->getVenderId();
    deviceId = WeChatAPI::instance()->getDeviceId();
    SDKVersion = WeChatAPI::instance()->getSDKVersion();
    printf("===>venderId = %s,deviceId = %s,SDKVersion=%s\n",venderId,deviceId,SDKVersion);
    //sleep(2*1000);

    while(1);
    return 0;
}

