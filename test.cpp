// test.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include "zmsg.hpp"
//#include "ThostFtdcMdApi.h"
//#include "MdSpi.h"


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
	Carbon() {
		m_context	= zmq_ctx_new();
		m_socket	= zmq_socket(m_context, ZMQ_REQ);

		std::string address = "tcp://192.168.1.234:5555";
		zmq_connect(m_socket,address.c_str());

		std::cout << "===���ӷ������ɹ�===" << std::endl;
		requestID = 0;
	}
	~Carbon() {
		if (m_socket != NULL) {
			zmq_close(m_socket);
			m_socket = NULL;
		}
	}

	int init() {
		std::cout << "===��ȡ�����ַ===" << std::endl;
		md_front = msg("md_front");
		std::cout << md_front << std::endl;
		std::cout << "===��ȡ���׵�ַ===" << std::endl;
		td_front = msg("td_front");
		std::cout << td_front << std::endl;
		std::cout << "===��ȡ�˺�===" << std::endl;
		accountNum = msg("accountnum");
		std::cout << accountNum << std::endl;
		std::cout << "===��ȡ����===" << std::endl;
		accountPwd = msg("accountpwd");
		std::cout << "ok!" << std::endl;
		std::cout << "===�趨��Լ===" << std::endl;
		symbol = msg("symbol");
		std::cout << symbol << std::endl;
		return 0;
	}
	std::string msg(std::string s) {
		zmsg msg(s.c_str());
		msg.send((zmq::socket_t &)m_socket);
		msg.recv((zmq::socket_t &)m_socket);
		return msg.body();
	}


	int get_id() {
		return requestID;
	}

};

int main()
{
	SetConsoleTitle(_T("CTP�����ն� [qq:129769]"));


	Carbon *pC = new Carbon();
	pC->init();
	std::cout << "ok..." << std::endl;
	system("pause");
    return 0;
}

