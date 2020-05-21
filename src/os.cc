#include <napi.h>
#include "os_host.h"
#include "os_ip.h"
#include "add.h"
#include "sub.h"
#include "find.h"
#include "prob.h"

Napi::Object Init(Napi::Env env, Napi::Object exports) {
  exports.Set("host", Napi::Function::New(env, HostName));
  exports.Set("ip", Napi::Function::New(env, IPInfo));
  exports.Set("add", Napi::Function::New(env, Add));
  exports.Set("minus", Napi::Function::New(env, Minus));
  exports.Set("find", Napi::Function::New(env, Find));
  exports.Set("probability",  Napi::Function::New(env, Probability));
  return exports;
}

NODE_API_MODULE(os, Init)
