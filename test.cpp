// test.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include "zmsg.hpp"
//#include "ThostFtdcMdApi.h"
//#include "MdSpi.h"

std::string CoreServer = "tcp://192.168.1.234:5555";

class Carbon {
private:
	int				requestID;
	void			*m_socket;
	void			*m_context;
	std::string		md_front,td_front;
	std::string		brokerid;
	std::string		accountNum;
	std::string		accountPwd;
	std::string		symbol;

public:
	Carbon(std::string _Server) {
		m_context	= zmq_ctx_new();
		m_socket	= zmq_socket(m_context, ZMQ_REQ);

		std::string address = _Server;
		zmq_connect(m_socket,address.c_str());
		requestID = 0;
		init();
	}

	~Carbon() {
		if (m_socket != NULL) {
			zmq_close(m_socket);
			m_socket = NULL;
		}
	}

	int init() {
		md_front = msg("md_front");
		std::cout << "===��ȡ�����ַ===" << std::endl;
		std::cout << md_front << std::endl;
		td_front = msg("td_front");
		std::cout << "===��ȡ���׵�ַ===" << std::endl;
		std::cout << td_front << std::endl;
		accountNum = msg("accountnum");
		std::cout << "===��ȡ�˺�===" << std::endl;
		std::cout << accountNum << std::endl;
		accountPwd = msg("accountpwd");
		std::cout << "===��ȡ����===" << std::endl;
		std::cout << "ok!" << std::endl;
		symbol = msg("symbol");
		std::cout << "===�趨��Լ===" << std::endl;
		std::cout << symbol << std::endl;
		return 0;
	}

	int getID() {
		return ++requestID;
	}

	std::string msg(std::string s) {
		zmsg msg(s.c_str());
		msg.send((zmq::socket_t &)m_socket);
		msg.recv((zmq::socket_t &)m_socket);
		return msg.body();
	}


};

Carbon *pC;

int main(int argc,const char* argv[])
{
	SetConsoleTitle(_T("CTP�����ն� [qq:129769]"));
	if ( argc > 1) {
		std::cout << ">>>�����Զ��������: " <<argv[1] << std::endl;
		pC = new Carbon(argv[1]);
	}
	else{
		std::cout << ">>>����Ĭ�Ϸ�����: " << CoreServer << std::endl;
		pC = new Carbon(CoreServer);
	}


	std::cout << pC->getID() << std::endl;
	std::cout << pC->getID() << std::endl;
	system("pause");
    return 0;
}

