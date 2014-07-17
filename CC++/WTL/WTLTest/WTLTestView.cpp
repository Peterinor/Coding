// WTLTestView.cpp : implementation of the CWTLTestView class
//
/////////////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "resource.h"

#include "WTLTestView.h"

BOOL CWTLTestView::PreTranslateMessage(MSG* pMsg)
{
	pMsg;
	return FALSE;
}

LRESULT CWTLTestView::OnCreate(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/)
{
	SetTimer(1, 1000, NULL);
	CRect rc;
	rc.left = 100;
	rc.top = 100;
	rc.right = 300;
	rc.bottom = 200;
	this->btn.Create(this->m_hWnd, rc, _T("BUTTON"), WS_CHILD | WS_VISIBLE, 0, IDB_BUTTON_1);

	return 0;
}

LRESULT CWTLTestView::OnDestroy(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& bHandled)
{
	KillTimer(1);
	bHandled = FALSE;
	return 0;
}

LRESULT CWTLTestView::OnPaint(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/)
{
	CPaintDC dc(m_hWnd);

	//TODO: Add your drawing code here
	CRect rc;
	SYSTEMTIME st;
	CString Time;

	GetClientRect((&rc));

	GetLocalTime(&st);
	Time.Format(_T("This time is %d:%02d:%02d"), st.wHour, st.wMinute, st.wSecond);

	dc.SaveDC();

	CBrush br;
	br.Attach((HBRUSH)::GetStockObject(NULL_BRUSH));
	dc.SelectStockBrush(NULL_BRUSH);
	dc.SetBkColor(RGB(255,153,0));
	dc.SetTextColor(RGB(0,0,0));

	dc.ExtTextOut(10,10,ETO_OPAQUE, rc, Time, Time.GetLength(), NULL);

	dc.RestoreDC(-1);

	//MessageBox(L"SDFSD",L"SDFSDF", 0);
	return 0;
}

LRESULT CWTLTestView::OnTimer(UINT msg, WPARAM wparam, LPARAM lparam, BOOL & bHandled)
{
	RedrawWindow();

	return 0;
}



LRESULT CWTLTestView::OnButton1_Click(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled)
{
	::MessageBox(m_hWnd,_T("Yes,Play!"),_T("OK"),0);
	return 0;
}