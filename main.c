#include <netinet/in.h>
#include <stdio.h>
#include <net/ethernet.h>
#include <string.h>



int main(void){
  int sock;
  unsigned char buffer[1024];
  int frame_len;

  struct ether_header *ether;

  memset(&buffer, 0, sizeof(buffer));

  if((sock = socket(PF_PACKET, SOCK_RAW, htons(ETH_P_ALL))) < 0 ){
    perror("socket");
    return 1;
  }
  while(1){
    if(frame_len=recv(sock, &buffer, sizeof(buffer),0)<0){
      perror("recvfrom");
      return 2;
    }
    ether =(struct ether_header*)buffer;
    for (int i = 0; i < sizeof(buffer); i++) {
      printf("%02x",buffer[i]);
    }
    printf("\n-------------------\n");
  }
  return 0;
}
