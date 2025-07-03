#include <iostream>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h> // これないとmemsetつかえない
#include <string>

using namespace std;

int main(void)
{
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(struct sockaddr_in)); // 初期化
    addr.sin_family = AF_INET;
    addr.sin_port = htons(1234);
    addr.sin_addr.s_addr = inet_addr("127.0.0.1"); // ip
    bind(sockfd, (struct sockaddr *)&addr, sizeof(addr));
    listen(sockfd, SOMAXCONN);

    struct sockaddr_in get_addr;
    socklen_t len = sizeof(struct sockaddr_in);
    int connect = accept(sockfd, (struct sockaddr *)&get_addr, &len);

    char str[12];
    recv(connect, str, 12, 0);
    cout << str << "を受信" << endl;

    close(connect);
    close(sockfd);

    return 0;
}