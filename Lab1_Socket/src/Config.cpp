#include "Config.h"

using namespace std;

string Config::SERVER_ADDRESS = "127.0.0.1";			//������IP��ַ
const int Config::MAX_CONNECTION = 50;					//���������50
const int Config::BUFFER_LENGTH = 1024;					//��������С1024�ֽ�
int Config::PORT = 5050;								//�������˿�5050
const u_long Config::BLOCK_MODE = MODE::Non_Blocking;	//SOCKETΪ������ģʽ
string Config::ROOT = "";

Config::Config() {
	std::ifstream confg_file;
	confg_file.open("../../../utils/init.json");
	assert(confg_file.is_open());

	Json::Reader reader;
	Json::Value root;
	// ������root��root������Json��������Ԫ��
	if (!reader.parse(confg_file, root, false))
	{
		cerr << "parse failed \n";
		return;
	}
	Config::SERVER_ADDRESS = root["ip"].asString();
	Config::PORT = root["port"].asInt();
	Config::ROOT = root["root"].asString();
}