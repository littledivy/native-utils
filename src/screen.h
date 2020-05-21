#include "utils/types.h"

Napi::Value ScreenSize(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  MMSize display = getMainDisplaySize();

  Napi::Object displayObj = Napi::Object::New(env);

  displayObj.Set("height", display.height);
  displayObj.Set("width", display.width);

  return displayObj;
}
