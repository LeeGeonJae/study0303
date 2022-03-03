#define _WINSOCK_DEPRECATED_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <WinSock2.h>

#pragma comment (lib, "ws2_32.lib")

using namespace std;

int main()
{
	//read
	FILE* fp = fopen("test.txt", "r");

	//socket bind list accept send fileread send
	fseek(fp, 0, SEEK_END);
	int Size = ftell(fp);
	fseek(fp, 0, SEEK_SET);
	char* Buffer = new char[Size + 1];
	fread(Buffer, sizeof(char), Size, fp);
	fclose(fp);

	//socket connect recv filewrite
	//write
	FILE* ofp = fopen("test2.txt", "w");
	fwrite(Buffer, sizeof(char), Size, ofp);
	fclose(ofp);

	cout << Buffer << endl;

	delete Buffer;

	/*WSAData wsaData;

	WSAStartup(MAKEWORD(2, 2), 0);

	SOCKET ServerSocket;
	ServerSocket = socket(AF_INET, SOCK_STREAM, 0);

	SOCKADDR_IN ServerAddr;
	memset(&ServerAddr, 0, sizeof(ServerAddr));
	ServerAddr.sin_family = AF_INET;
	ServerAddr.sin_port = htons(50000);
	ServerAddr.sin_addr.s_addr = htonl(INADDR_ANY);

	bind(ServerSocket, (SOCKADDR*)&ServerAddr, sizeof(ServerAddr));

	listen(ServerSocket, 0);

	SOCKADDR_IN ClientAddr;
	int ClientAddrSize = sizeof(ClientAddr);
	SOCKET ClientSocket = 0;
	ClientSocket = accept(ServerSocket, (SOCKADDR*)&ClientAddr, &ClientAddrSize);

	

	closesocket(ClientSocket);
	closesocket(ServerSocket);

	WSACleanup();*/

	return 0;
}