#include "keypress.h"

void Type(const Napi::CallbackInfo& info) {
  //Napi::Env env = info.Env();

  typeStringDelayed("hello", 0);
}
