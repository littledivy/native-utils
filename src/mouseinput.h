#include "mouse.h"
#include "utils/types.h"

void MoveMouse(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() < 2) {
    Napi::TypeError::New(env, "2 arguments needed")
        .ThrowAsJavaScriptException();
    //return env.Null();
  }
  /**
    if (!info[0].IsString() || !info[1].IsString()) {
      Napi::TypeError::New(env, "Arguments must be strings").ThrowAsJavaScriptException();
      return env.Null();
    }
  **/
  double arg0 = info[0].As<Napi::Number>().DoubleValue();
  double arg1 = info[1].As<Napi::Number>().DoubleValue();

  MMSignedPoint coords = { arg0, arg1 };

  moveMouse(coords);
}

Napi::Value SmoothMouse(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() < 2) {
    Napi::TypeError::New(env, "2 arguments needed")
        .ThrowAsJavaScriptException();
    return env.Null();
  }
  if (!info[0].IsNumber() || !info[1].IsNumber()) {
    Napi::TypeError::New(env, "Arguments must be number").ThrowAsJavaScriptException();
    return env.Null();
  }
  double arg0 = info[0].As<Napi::Number>().DoubleValue();
  double arg1 = info[1].As<Napi::Number>().DoubleValue();

  MMPoint coords = { arg0, arg1 };

  double speed = 10;

  smoothlyMoveMouse(coords, speed);
}
