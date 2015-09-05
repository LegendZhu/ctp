// test.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include <sstream>
#include "zmsg.hpp"
#include <vector>
#include <string>
#include <map>
#include "ThostFtdcMdApi.h"
#include "ThostFtdcTraderApi.h"

std::string CoreServer = "tcp://192.168.1.234:5555";

using std::string;

class MD : public CThostFtdcMdSpi
{
public:

	///����Ӧ��
	void OnRspError(CThostFtdcRspInfoField *pRspInfo,
		int nRequestID, bool bIsLast) {
		std::cout << "===#" << __FUNCTION__ << "#===" << std::endl;
		IsErrorRspInfo(pRspInfo);
	}

	///���ͻ����뽻�׺�̨ͨ�����ӶϿ�ʱ���÷��������á���������������API���Զ��������ӣ��ͻ��˿ɲ�������
	///@param nReason ����ԭ��
	///        0x1001 �����ʧ��
	///        0x1002 ����дʧ��
	///        0x2001 ����������ʱ
	///        0x2002 ��������ʧ��
	///        0x2003 �յ�������
	void OnFrontDisconnected(int nReason) {
		std::cout << "===#" << __FUNCTION__ << "#===" << std::endl;
	}

	///������ʱ���档����ʱ��δ�յ�����ʱ���÷��������á�
	///@param nTimeLapse �����ϴν��ձ��ĵ�ʱ��
	void OnHeartBeatWarning(int nTimeLapse) {
		std::cout << "===#" << __FUNCTION__ << "#===" << std::endl;
	}

	///���ͻ����뽻�׺�̨������ͨ������ʱ����δ��¼ǰ�����÷��������á�
	void OnFrontConnected() {
	std::cout << "===#" << __FUNCTION__ << "#===" << std::endl;
	}

	///��¼������Ӧ
	void OnRspUserLogin(CThostFtdcRspUserLoginField *pRspUserLogin, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
		std::cout << "===#" << __FUNCTION__ << "#===" << std::endl;
	}

	///��������Ӧ��
	void OnRspSubMarketData(CThostFtdcSpecificInstrumentField *pSpecificInstrument, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
		std::cout << "===#" << __FUNCTION__ << "#===" << std::endl;
	}

	///ȡ����������Ӧ��
	void OnRspUnSubMarketData(CThostFtdcSpecificInstrumentField *pSpecificInstrument, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
		std::cout << "===#" << __FUNCTION__ << "#===" << std::endl;
	}

	///�������֪ͨ
	void OnRtnDepthMarketData(CThostFtdcDepthMarketDataField *pDepthMarketData) {
		std::cout << "===#" << __FUNCTION__ << "#===" << std::endl;
	}



public:

	///	�û���¼
	void	ReqUserLogin() {
		std::cout << "===#" << __FUNCTION__ << "#===" << std::endl;
	}
	///	���ĺ�Լ
	void	SubscribeMarketData() {
		std::cout << "===#" << __FUNCTION__ << "#===" << std::endl;
	}
	///	��ȡ������Ϣ
	bool	IsErrorRspInfo(CThostFtdcRspInfoField *pRspInfo) {
		std::cout << "===#" << __FUNCTION__ << "#===" << std::endl;
		return true;
	}

};

class TD : public CThostFtdcTraderSpi
{
public:

	///���ͻ����뽻�׺�̨������ͨ������ʱ����δ��¼ǰ�����÷��������á�
	void OnFrontConnected() {
		std::cout << "===#" << __FUNCTION__ << "#===" << std::endl;
	}

	///��¼������Ӧ
	void OnRspUserLogin(CThostFtdcRspUserLoginField *pRspUserLogin, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
		std::cout << "===#" << __FUNCTION__ << "#===" << std::endl;
	}

	///Ͷ���߽�����ȷ����Ӧ
	void OnRspSettlementInfoConfirm(CThostFtdcSettlementInfoConfirmField *pSettlementInfoConfirm, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
		std::cout << "===#" << __FUNCTION__ << "#===" << std::endl;
	}

	///�����ѯ��Լ��Ӧ
	void OnRspQryInstrument(CThostFtdcInstrumentField *pInstrument, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
		std::cout << "===#" << __FUNCTION__ << "#===" << std::endl;
	}

	///�����ѯ�ʽ��˻���Ӧ
	void OnRspQryTradingAccount(CThostFtdcTradingAccountField *pTradingAccount, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
		std::cout << "===#" << __FUNCTION__ << "#===" << std::endl;
	}

	///�����ѯͶ���ֲ߳���Ӧ
	void OnRspQryInvestorPosition(CThostFtdcInvestorPositionField *pInvestorPosition, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
		std::cout << "===#" << __FUNCTION__ << "#===" << std::endl;
	}

	///����¼��������Ӧ
	void OnRspOrderInsert(CThostFtdcInputOrderField *pInputOrder, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
		std::cout << "===#" << __FUNCTION__ << "#===" << std::endl;
	}

	///��������������Ӧ
	void OnRspOrderAction(CThostFtdcInputOrderActionField *pInputOrderAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
		std::cout << "===#" << __FUNCTION__ << "#===" << std::endl;
	}

	///����Ӧ��
	void OnRspError(CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
		std::cout << "===#" << __FUNCTION__ << "#===" << std::endl;
	}

	///���ͻ����뽻�׺�̨ͨ�����ӶϿ�ʱ���÷��������á���������������API���Զ��������ӣ��ͻ��˿ɲ�������
	void OnFrontDisconnected(int nReason) {
		std::cout << "===#" << __FUNCTION__ << "#===" << std::endl;
	}

	///������ʱ���档����ʱ��δ�յ�����ʱ���÷��������á�
	void OnHeartBeatWarning(int nTimeLapse) {
		std::cout << "===#" << __FUNCTION__ << "#===" << std::endl;
	}

	///����֪ͨ
	void OnRtnOrder(CThostFtdcOrderField *pOrder) {
		std::cout << "===#" << __FUNCTION__ << "#===" << std::endl;
	}

	///�ɽ�֪ͨ
	void OnRtnTrade(CThostFtdcTradeField *pTrade) {
		std::cout << "===#" << __FUNCTION__ << "#===" << std::endl;
	}

	///�����ѯ������Ӧ
	void OnRspQryOrder(CThostFtdcOrderField *pOrder, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
		std::cout << "===#" << __FUNCTION__ << "#===" << std::endl;
	}

	///�����ѯ�ɽ���Ӧ
	void OnRspQryTrade(CThostFtdcTradeField *pTrade, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
		std::cout << "===#" << __FUNCTION__ << "#===" << std::endl;
	}

	///�����ѯͶ���ֲ߳���ϸ��Ӧ
	void OnRspQryInvestorPositionDetail(CThostFtdcInvestorPositionDetailField *pInvestorPositionDetail, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
		std::cout << "===#" << __FUNCTION__ << "#===" << std::endl;
	}

public:
	///�û���¼����
	void ReqUserLogin() {
		std::cout << "===#" << __FUNCTION__ << "#===" << std::endl;
	}

	///Ͷ���߽�����ȷ��
	void ReqSettlementInfoConfirm() {
		std::cout << "===#" << __FUNCTION__ << "#===" << std::endl;
	}

	///�����ѯ��Լ
	void ReqQryInstrument() {
		std::cout << "===#" << __FUNCTION__ << "#===" << std::endl;
	}

	///�����ѯ�ʽ��˻�
	void ReqQryTradingAccount() {
		std::cout << "===#" << __FUNCTION__ << "#===" << std::endl;
	}

	///�����ѯͶ���ֲ߳�
	void ReqQryInvestorPosition() {
		std::cout << "===#" << __FUNCTION__ << "#===" << std::endl;
	}

	///����¼������
	void ReqOrderInsert() {
		std::cout << "===#" << __FUNCTION__ << "#===" << std::endl;
	}

	///������������
	void ReqOrderAction(CThostFtdcRspInfoField *pRspInfo) {
		std::cout << "===#" << __FUNCTION__ << "#===" << std::endl;
	}

	////������Ӧ
	bool IsErrorRspInfo(CThostFtdcRspInfoField *pRspInfo) {
		std::cout << "===#" << __FUNCTION__ << "#===" << std::endl;
		return true;
	}

	///������ѯ����
	void ReqQryOrder() {
		std::cout << "===#" << __FUNCTION__ << "#===" << std::endl;
	}

	///�ɽ���ѯ����
	void ReqQryTrade() {
		std::cout << "===#" << __FUNCTION__ << "#===" << std::endl;
	}

	//�����ѯͶ���ֲ߳���ϸ
	void ReqQryInvestorPositionDetail() {
		std::cout << "===#" << __FUNCTION__ << "#===" << std::endl;
	}

};


class Carbon {
private:
	int				requestID;
	void			*m_socket;
	void			*m_context;
	MD				*pmds;
	TD				*ptds;
	CThostFtdcMdApi	*pmda;
	CThostFtdcTraderApi		*ptda;
	std::string		md_front,td_front;
	std::string		brokerid;
	std::string		accountNum;
	std::string		accountPwd;
	std::string		symbol;

public:
	Carbon(std::string _Server) {
		m_context	= zmq_ctx_new();
		m_socket	= zmq_socket(m_context, ZMQ_REQ);
		zmq_connect(m_socket, _Server.c_str());
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
		brokerid = msg("broker_id");
		std::cout << "===��ȡ��ϯ���===" << std::endl;
		std::cout << brokerid << std::endl;
		accountNum = msg("account_num");
		std::cout << "===��ȡ�˺�===" << std::endl;
		std::cout << accountNum << std::endl;
		accountPwd = msg("account_pwd");
		std::cout << "===��ȡ����===" << std::endl;
		std::cout << "ok!" << std::endl;
		symbol = msg("this_symbol");
		std::cout << "===�趨��Լ===" << std::endl;
		std::cout << symbol << std::endl;

		char *md_buf = new char[strlen(md_front.c_str()) + 1];
		strcpy(md_buf, md_front.c_str());

		char *td_buf = new char[strlen(td_front.c_str()) + 1];
		strcpy(td_buf, td_front.c_str());

		ptda = CThostFtdcTraderApi::CreateFtdcTraderApi(".\\tdflow\\");
		ptds = new TD();
		ptda->RegisterSpi((CThostFtdcTraderSpi*)ptds);
		ptda->SubscribePublicTopic(THOST_TERT_QUICK);
		ptda->SubscribePrivateTopic(THOST_TERT_QUICK);
		ptda->RegisterFront(td_buf);
		pmda = CThostFtdcMdApi::CreateFtdcMdApi(".\\mdflow\\");
		pmds = new MD();
		pmda->RegisterSpi(pmds);
		pmda->RegisterFront(md_buf);
		//  ������ʼ��
		ptda->Init();
		std::cout << "ptda->init()" << std::endl;
		ptda->Join();
		std::cout << "ptda->join()" << std::endl;
		return 0;
	}

	int getID() {
		return ++requestID;
	}

	std::string log(std::string s) {
		msg("log_" + s);
		return "logged:"+s;
	}

	std::string error(int err) {
		std::stringstream ss;
		std::string sto;
		ss << err;
		ss >> sto;
		return msg("error_" + sto);
	}

	std::string msg(std::string s) {
		zmsg _msg(s.c_str());
		_msg.send((zmq::socket_t &)m_socket);
		_msg.recv((zmq::socket_t &)m_socket);
		return _msg.body();
	}


};

Carbon*					pC;

int main(int argc,const char* argv[])
{
	SetConsoleTitle(_T("CTP�����ն� [qq:129769]"));
	if ( argc > 1) {
		std::cout << ">>>�����Զ��������: " << argv[1] << std::endl;
		pC = new Carbon(argv[1]);
	}
	else{
		std::cout << ">>>����Ĭ�Ϸ�����: " << CoreServer << std::endl;
		pC = new Carbon(CoreServer);
	}


	system("pause");
    return 0;
}

