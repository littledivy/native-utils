#include "keypress.h"

Napi::Value Type(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() < 1) {
    Napi::TypeError::New(env, "2 arguments needed")
        .ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[0].IsString()) {
    Napi::TypeError::New(env, "Argument must be a string")
        .ThrowAsJavaScriptException();
    return env.Null();
  }

  string arg0 = info[0].As<Napi::String>();
  const char *cstr = arg0.c_str();

  typeStringDelayed(cstr, 0);

  return Napi::Boolean::New(env, true);
}
