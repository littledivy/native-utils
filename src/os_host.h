#include <unistd.h>

Napi::Value HostName(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  char hostbuffer[256];
  int hostname;

    // To retrieve hostname
    hostname = gethostname(hostbuffer, sizeof(hostbuffer));
    if (hostname == -1)
    {
        perror("gethostname");
        exit(1);
    }

  Napi::String nodeHostBuffer = Napi::String::New(env, hostbuffer);
  return nodeHostBuffer;
}
