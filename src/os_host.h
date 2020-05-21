#include <unistd.h>

void HostName(const Napi::CallbackInfo& info) {
  char hostbuffer[256];
  int hostname;

    // To retrieve hostname
    hostname = gethostname(hostbuffer, sizeof(hostbuffer));
    if (hostname == -1)
    {
        perror("gethostname");
        exit(1);
    }
  printf("%s\n", hostbuffer);
}
