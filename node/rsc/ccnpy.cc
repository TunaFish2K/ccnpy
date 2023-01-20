#include <Python.h>
#include <napi.h>
#include<string>

using namespace Napi;

Value helloTo (const CallbackInfo& info) {
    Env env = info.Env();
    Object helloResult = Object::New(env);
    helloResult.Set(String::New(env,"count"),Number::New(env,info.Length));
    Array helloDetails = Array:New(env);
    string greeting;
    for (int i = 0;i < info.Length;i++) {
        greeting="Hello, " + info[i].As<String>();
        helloDetails.Set(Number::New(env,i),String::New(env,greeting));
    }
    helloResult.Set(String::New(env,"details"),helloDetails);
    return helloResult;
}

Object Init(Env env, Object exports){
    exports.Set(String::New(env,"HelloTo"),Function::New(env,helloTo));
    return exports;
}

NODE_API_MODULE(addon,Init);