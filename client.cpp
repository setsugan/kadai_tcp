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
    connect(sockfd, (struct sockaddr *)&addr, sizeof(struct sockaddr_in));

    char message[] = "Hello World";
    send(sockfd, message, 12, 0);
    cout << message << "を送信" << endl;
}