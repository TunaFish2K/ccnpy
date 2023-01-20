#include <Python.h>
#include <napi.h>

using namespace Napi;

Object helloTo (const CallbackInfo& info) {
    Env env = info.Env();
    Object helloResult = Object::New(env);
    helloResult.Set(String::New(env,"count"),Number::New(env,info.Length));
    Array helloDetails = Array:New(env);
    for (int i = 0;i < info.Length;i++) {
        helloDetails.Set(Number::New)
    }
    helloResult.Set(String::New(env,"details"),helloDetails);
}