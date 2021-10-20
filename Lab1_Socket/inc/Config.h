#pragma once
#include <string>
#include <winsock2.h>
#include <fstream>
#include <cassert>

#include "json/json.h"

using namespace std;

//����������Ϣ
class Config
{
public:
	static const int MAX_CONNECTION;		//���������
	static const int BUFFER_LENGTH;			//��������С
	static string SERVER_ADDRESS;				//��������ַ
	static int PORT;							//�������˿�
	static const u_long BLOCK_MODE;			//SOCKET����ģʽ
	static string ROOT;

	typedef enum MODE {
		Non_Blocking = 0,
		Blocking = 1,
	} MODE;

	Config();
	~Config() = default;

private:
};
