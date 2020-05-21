#include <fstream>

Napi::Value WriteFile(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() < 2) {
    Napi::TypeError::New(env, "2 arguments are needed")
        .ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[0].IsString() || !info[1].IsString()) {
    Napi::TypeError::New(env, "Arguments must be string").ThrowAsJavaScriptException();
    return env.Null();
  }

  string st = info[0].As<Napi::String>();
  string txt = info[1].As<Napi::String>();

  ofstream myfile;

  myfile.open(st);

  if (myfile.is_open()) {

      myfile << txt;
      myfile.close();

      Napi::Boolean done = Napi::Boolean::New(env, true);
      return done;
    }
  else {
      Napi::TypeError::New(env, "No such file found").ThrowAsJavaScriptException();
      return env.Null();
  }
}
