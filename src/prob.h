// calculates the probability of the events A or B for independent events
double addition_rule_independent(double A, double B) {
    return (A + B) - (A * B);
}

// calculates the probability of the events A or B for dependent events
// note that if value of B_given_A is unknown, use chainrule to find it
double addition_rule_dependent(double A, double B, double B_given_A) {
    return (A + B) - (A * B_given_A);
}

Napi::Value Probability(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() < 2) {
    Napi::TypeError::New(env, "At least 2 arguments needed")
        .ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[0].IsNumber() || !info[1].IsNumber()) {
    Napi::TypeError::New(env, "Arguments must be number").ThrowAsJavaScriptException();
    return env.Null();
  }
  double arg0 = info[0].As<Napi::Number>().DoubleValue();
  double arg1 = info[1].As<Napi::Number>().DoubleValue();

  if (info[2] && info[2].IsNumber()) {
    double arg2 = info[2].As<Napi::Number>().DoubleValue();
    Napi::Number num = Napi::Number::New(env, addition_rule_dependent(arg0, arg1, arg2));
    return num;
  }
  Napi::Number num = Napi::Number::New(env, addition_rule_independent(arg0, arg1));
  return num;
}
