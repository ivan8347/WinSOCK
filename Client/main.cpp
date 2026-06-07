#ifndef WIN32_LEAN_AND_MEAN 
#define WIN32_LEAN_AND_MEAN 
//Это нужно когда к проекту одновременно подключаются <WinSock2.h> и <Windows.h>
#endif // !#define WIN32_LEAN_AND_MEAN 

#include<iostream>
#include<Windows.h>
#include<WinSock2.h>
#include<WS2tcpip.h>
#include<iphlpapi.h>

using namespace std;
#pragma comment(lib, "WS2_32.lib")//подгружает реализации фукций из статической библиотеки для <WS2TCPIP.h>

void main()
{
	setlocale(LC_ALL, "");

	INT iResult = 0; //эта переменная нужна для отслеживания результатов выполнения функций.
	//1) Инициализация WinSOCK:
	WSADATA wsaData;
	 iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);//MAKEWORD(2,2) - выбираем версию WinSOCK
	 if (iResult != 0)
	 {
		 cout << "WSAStartup failed with error: " << iResult << endl;
		 return;
	 }
	 //2) Определяем параметры подключения:
	 addrinfo hints;
	 addrinfo* target;
	 ZeroMemory(&hints, sizeof(hints));
	 hints.ai_family = AF_INET;          //Family - семейство протоколов (стек протоколов) INET - TCP/IPv4
	 hints.ai_socktype = SOCK_STREAM;
	 hints.ai_protocol = IPPROTO_TCP;

	 iResult = getaddrinfo("127.0.0.1", "27015", &hints, &target);//По символьному имени получает числовой адрес целевого узла (IP-адрес)
	 if (iResult != 0)
	 if (iResult != 0)
	 {
		 cout << "getaddrinfo failed with error " << iResult << endl;
		 WSACleanup();
		 return;
	 }





	 //?) Освобождаем ресурсы WinSOCK:
	 WSACleanup();
}