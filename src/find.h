#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

Napi::Value Find(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() < 2) {
    Napi::TypeError::New(env, "2 arguments needed")
        .ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[0].IsString() || !info[1].IsString()) {
    Napi::TypeError::New(env, "Arguments must be strings").ThrowAsJavaScriptException();
    return env.Null();
  }

  string arg0 = info[0].As<Napi::String>();
  string arg1 = info[1].As<Napi::String>();
  Napi::String word = Napi::String::New(env, arg1);

  if (arg0.find(arg1) == string::npos)
  {
    Napi::Boolean w = Napi::Boolean::New(env, false);
    return w;
  }
  else
  {
    if(arg1 == "") return Napi::Boolean::New(env, false);
    return word;
  }
}
