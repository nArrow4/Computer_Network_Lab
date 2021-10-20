#pragma once
#include <winsock2.h>
#include <string>
#include <iostream>
#include <fstream>
#include <thread>
#include <regex>

#include "Winsock.h"
#include "Config.h"

using namespace std;

typedef int STATUS;

typedef enum {
	HTML,
	IMAGE,
} FILETYPE;

//������
class Server
{
private:
	// ����socket
	SOCKET listening_socket;
	// server address
	sockaddr_in server_addr;

	//fd_set rfds;				//���ڼ��socket�Ƿ������ݵ����ĵ��ļ�������������socket������ģʽ�µȴ������¼�֪ͨ�������ݵ�����
	//fd_set wfds;				//���ڼ��socket�Ƿ���Է��͵��ļ�������������socket������ģʽ�µȴ������¼�֪ͨ�����Է������ݣ�

	string LF = "\r\n";
	string root = "C:\\Users\\acer\\source\\repos\\Lab1\\utils";

protected:
	

public:
	Server();
	~Server();
	int WinsockStartup();		//��ʼ��Winsock
	int ServerStartup();		//��ʼ��Server����������SOCKET���󶨵�IP��PORT
	int ListenStartup();		//��ʼ�����ͻ�������
	int Loop();					//ѭ��ִ��"�ȴ��ͻ�������"->���������ͻ�ת����Ϣ��->"�ȴ��ͻ�����Ϣ"
};

class Client {
public:
	// �ỰSocket
	SOCKET session_socket;
	// client address
	sockaddr_in client_addr;

	// client session
	void session(SOCKET );

	Client();
	~Client();

private:

	string LF = "\r\n";
	string OK = "HTTP/1.1 200 OK" + LF;
	string NOTFOUND = "HTTP/1.1 404 Not Found" + LF;
	string BADREQ = "HTTP/1.1 400 Bad Request" + LF;
	
	ifstream file_to_send;
	/*
	regex reg_file_name;
	regex reg_file_type;

	string msg_get;
	string msg_url;

	smatch req_msg;
	smatch filetype;
	*/

	char* buf;
	char* data_to_send;

	string getHeaderLine(const string& content_type, int content_length);
	int getFileLength(ifstream& file);
};