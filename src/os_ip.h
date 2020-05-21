#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

void IPInfo(const Napi::CallbackInfo& info) {
 int sock = socket(PF_INET, SOCK_DGRAM, 0);
 sockaddr_in loopback;

 if (sock == -1) {
  printf("Could not socket\n");
 }

 std::memset(&loopback, 0, sizeof(loopback));
 loopback.sin_family = AF_INET;
 loopback.sin_addr.s_addr = INADDR_LOOPBACK;   // using loopback ip address
 loopback.sin_port = htons(9);                 // using debug port

 if (connect(sock, reinterpret_cast<sockaddr*>(&loopback), sizeof(loopback)) == -1) {
     close(sock);
     printf("Could not connect\n");
 }

 socklen_t addrlen = sizeof(loopback);
 if (getsockname(sock, reinterpret_cast<sockaddr*>(&loopback), &addrlen) == -1) {
     close(sock);
     printf("Could not getsockname\n");
 }

 close(sock);

 char buf[INET_ADDRSTRLEN];
 if (inet_ntop(AF_INET, &loopback.sin_addr, buf, INET_ADDRSTRLEN) == 0x0) {
  printf("Could not inet_ntop\n");
 } else {
  printf("%s\n", buf);
 }
}
