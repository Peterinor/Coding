// WTLTestView.h : interface of the CWTLTestView class
//
/////////////////////////////////////////////////////////////////////////////

#pragma once

#define IDB_BUTTON_1 1001
class CWTLTestView : public CWindowImpl<CWTLTestView>
{
public:
	DECLARE_WND_CLASS(NULL)

	CButton btn;

	BOOL PreTranslateMessage(MSG* pMsg);

	BEGIN_MSG_MAP(CWTLTestView)
		MESSAGE_HANDLER(WM_CREATE, OnCreate)
		MESSAGE_HANDLER(WM_DESTROY, OnDestroy)	
		MESSAGE_HANDLER(WM_PAINT, OnPaint)
		MESSAGE_HANDLER(WM_TIMER, OnTimer);

		COMMAND_HANDLER(IDB_BUTTON_1, BN_CLICKED, OnButton1_Click);
	END_MSG_MAP()

// Handler prototypes (uncomment arguments if needed):
//	LRESULT MessageHandler(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/)
//	LRESULT CommandHandler(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
//	LRESULT NotifyHandler(int /*idCtrl*/, LPNMHDR /*pnmh*/, BOOL& /*bHandled*/)

	LRESULT OnCreate(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/);
	LRESULT OnDestroy(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& bHandled);

	LRESULT OnPaint(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/);

	LRESULT OnTimer(UINT msg, WPARAM wparam, LPARAM lparam, BOOL & bHandled);



	LRESULT OnButton1_Click(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled);

};
