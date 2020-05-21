#include "clip.h"
#include <cassert>
#include <iostream>

Napi::Value Copy(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() < 1) {
    Napi::TypeError::New(env, "An argument is needed")
        .ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[0].IsString()) {
    Napi::TypeError::New(env, "Argument must be a string").ThrowAsJavaScriptException();
    return env.Null();
  }
  string arg0 = info[0].As<Napi::String>();
  clip::set_text(arg0);
}

Napi::Value Get(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  std::string value;
  bool result = clip::get_text(value);
  Napi::String text = Napi::String::New(env, value);
  return text;
}
