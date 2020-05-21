#include <fstream>
#include <sstream>
#include <string>

Napi::Value ReadFile(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() < 1) {
    Napi::TypeError::New(env, "At least 1 argument is needed")
        .ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[0].IsString()) {
    Napi::TypeError::New(env, "Argument must be a string").ThrowAsJavaScriptException();
    return env.Null();
  }

  string st = info[0].As<Napi::String>();

   ifstream f(st); //taking file as inputstream

   string str;

   if(f) {
      ostringstream ss;
      ss << f.rdbuf(); // reading data
      str = ss.str();
    }

      Napi::String content = Napi::String::New(env, str);
      return content;
}
