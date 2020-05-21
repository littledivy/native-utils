#include <napi.h>
#include "os_host.h"
#include "os_ip.h"
#include "add.h"
#include "sub.h"
#include "find.h"
#include "prob.h"
#include "clipboard.h"
#include "hash.h"

Napi::Object Init(Napi::Env env, Napi::Object exports) {

  exports.Set("host", Napi::Function::New(env, HostName));
  exports.Set("ip", Napi::Function::New(env, IPInfo));
  exports.Set("add", Napi::Function::New(env, Add));
  exports.Set("minus", Napi::Function::New(env, Minus));
  exports.Set("find", Napi::Function::New(env, Find));
  exports.Set("probability",  Napi::Function::New(env, Probability));
  exports.Set("copyToClipboard",  Napi::Function::New(env, Copy));
  exports.Set("getClipboardText",  Napi::Function::New(env, Get));
  exports.Set("sdbmHash",  Napi::Function::New(env, sdbm));
  exports.Set("djb2Hash",  Napi::Function::New(env, djb2));
  exports.Set("xor8Hash",  Napi::Function::New(env, xor8));
  exports.Set("adler32Hash",  Napi::Function::New(env, adler_32));
  exports.Set("crc32Hash",  Napi::Function::New(env, crc32));

  return exports;
}

NODE_API_MODULE(os, Init)
