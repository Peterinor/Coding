
#pragma once
#include "stdafx.h"


#define IFR(hr) hr 

class CAeroButton :
    public CAeroControlImpl<CAeroButton,CButton>
{
public:
    DECLARE_WND_SUPERCLASS(_T("WTL Aero Button"),GetWndClassName())
    typedef CAeroControlImpl<CAeroButton,CButton> _baseAeroCtrl;
    BEGIN_MSG_MAP(CAeroButton)
        CHAIN_MSG_MAP(_baseAeroCtrl)
    END_MSG_MAP()
};
class CAeroStatic :
    public CAeroControlImpl<CAeroStatic,CStatic>
{
public:
    DECLARE_WND_SUPERCLASS(_T("WTL Aero Static"),GetWndClassName())
    typedef CAeroControlImpl<CAeroStatic,CStatic> _baseAeroCtrl;
    BEGIN_MSG_MAP(CAeroStatic)
        MSG_WM_CREATE(OnCreate)
        MSG_OCM_CTLCOLORSTATIC(OnCtlColorStatic)
        CHAIN_MSG_MAP(_baseAeroCtrl)
    END_MSG_MAP()
    int OnCreate(LPCREATESTRUCT /*lpCreateStruct*/)
    {
        m_BkgndBrush.CreateSysColorBrush(COLOR_WINDOW);
        return 0;
    }
    HBRUSH OnCtlColorStatic(CDCHandle /*dc*/, CStatic /*wndStatic*/)
    {
        return m_BkgndBrush;
    }
private:
    CBrush m_BkgndBrush;
};
class CAeroComboBox :
    public CAeroControlImpl<CAeroComboBox,CComboBox>
{
public:
    DECLARE_WND_SUPERCLASS(_T("WTL Aero ComboBox"),GetWndClassName())
    typedef CAeroControlImpl<CAeroComboBox,CComboBox> _baseAeroCtrl;
    BEGIN_MSG_MAP(CAeroComboBox)
        REFLECTED_COMMAND_CODE_HANDLER_EX(CBN_DROPDOWN,OnDropDown)
        CHAIN_MSG_MAP(_baseAeroCtrl)
    END_MSG_MAP()
    LRESULT OnDropDown(UINT /*uNotifyCode*/, int /*nID*/, CWindow /*wndCtl*/)
    {
        DefWindowProc();
        InvalidateRect(NULL,FALSE);
        return 0;
    }
};
enum
{
    IDC_AERO_BUTTON = 1001,
    IDC_AERO_STATIC,
    IDC_AERO_COMBOBOX
};
class CClientView :
    public CAeroControlImpl<CClientView>
{
public:
    DECLARE_WND_CLASS(_T("WTL client view"))
    typedef CAeroControlImpl<CClientView> _baseAeroCtrl;
    BEGIN_MSG_MAP(CClientView)
        MSG_WM_CREATE(OnCreate)
        REFLECT_NOTIFICATIONS_EX()
        CHAIN_MSG_MAP(_baseAeroCtrl)
    END_MSG_MAP()
public:
    int OnCreate(LPCREATESTRUCT /*lpCreateStruct*/)
    {
        CLogFont lf;
        TCHAR fontName[] = _T("Courier New");
        _tcscpy_s(lf.lfFaceName,fontName);
        lf.lfHeight = 40;
        m_TextFont.CreateFontIndirect(&lf);
        m_GuiFont = AtlGetDefaultGuiFont();
        CRect rc(10,10,130,50);
        m_Button.Create(m_hWnd,rc,_T("Aero Button Control"),
            WS_CHILD|WS_VISIBLE,0,IDC_AERO_BUTTON);
        m_Button.SetFont(m_GuiFont);
        rc.top += 50;
        rc.bottom = rc.top+30;
        m_Static.Create(m_hWnd,rc,_T("Aero Static Control"),
            WS_CHILD|WS_VISIBLE,0,IDC_AERO_STATIC);
        m_Static.SetFont(m_GuiFont);
        rc.top = 10;
        rc.bottom = rc.top+60;
        rc.left = 150;
        rc.right = rc.left+100;
        m_ComboBox.Create(m_hWnd,rc,NULL,
            WS_CHILD|WS_VISIBLE|CBS_DROPDOWNLIST,0,IDC_AERO_COMBOBOX);
        m_ComboBox.SetFont(m_GuiFont);
        m_ComboBox.AddString(_T("Apple"));
        m_ComboBox.AddString(_T("Banana"));
        m_ComboBox.AddString(_T("Orange"));
        //Allow the base class to initialize
        SetMsgHandled(FALSE);
        return 0;
    }
    void DoAeroPaint(HDC hDC, RECT& rcClient, RECT& rcPaint)
    {
        CDCHandle dc(hDC);
        //Do painting work...
        dc.FillRect(&rcPaint,(HBRUSH)(COLOR_WINDOW+1));
        CRect rc(rcPaint);
        rc.top = rc.Height()/2;
        CFont oldFont = dc.SelectFont(m_TextFont);
        dc.DrawText(_T("Aero-DWM-GDI"),-1,&rc,DT_CENTER|DT_VCENTER|DT_SINGLELINE);
        dc.SelectFont(oldFont);
        //Don't forget to call the base class's DoAeroPaint() method
        _baseAeroCtrl::DoAeroPaint(hDC,rcClient,rcPaint);
    }
private:
    CAeroButton m_Button;
    CAeroStatic m_Static;
    CAeroComboBox m_ComboBox;
    CFont m_GuiFont;
    CFont m_TextFont;
};
//Main window
typedef CWinTraits<WS_OVERLAPPEDWINDOW|WS_CLIPCHILDREN> CAeroWinTraits;
class CAeroWindow :
    public CWindowImpl<CAeroWindow,CWindow,CAeroWinTraits>,
    public CDwmImpl<CAeroWindow>
{
public:
    DECLARE_WND_CLASS(_T("WTL Aero window"))
    BEGIN_MSG_MAP(CAeroWindow)
        MSG_WM_CREATE(OnCreate)
        MSG_WM_DESTROY(OnDestroy)
        MSG_WM_SIZE(OnSize)
    END_MSG_MAP()
public:
    CAeroWindow()
    {
        ATLASSERT(IsDwmSupported());
        CWndClassInfo& wci = GetWndClassInfo();
        if (!wci.m_atom)
        {
            wci.m_wc.hbrBackground = AtlGetStockBrush(BLACK_BRUSH);
        }
    }
    
protected:
    int OnCreate(LPCREATESTRUCT /*lpCreateStruct*/)
    {
        IFR(DwmExtendFrameIntoEntireClientArea());
        /*
        DWM_BLURBEHIND bb = {0};
        bb.dwFlags = DWM_BB_ENABLE;
        bb.fEnable = TRUE;
        bb.hRgnBlur = NULL;
        IFR(DwmEnableBlurBehindWindow(&bb));
        */
        CRect clientRect;
        GetClientRect(&clientRect);
        CRect rc;
        rc.top = clientRect.top+5;
        rc.bottom = clientRect.Height()/2-5;
        rc.left = clientRect.left+5;
        rc.right = clientRect.Width()/2-5;
        HWND hClientWnd = m_ClientView1.Create(m_hWnd,rc,NULL,WS_CHILD|WS_VISIBLE);
        ATLASSERT(hClientWnd);
        rc.left = clientRect.Width()/2+5;
        rc.right = clientRect.right-5;
        hClientWnd = m_ClientView2.Create(m_hWnd,rc,NULL,WS_CHILD|WS_VISIBLE);
        ATLASSERT(hClientWnd);
        rc.top = clientRect.Height()/2+5;
        rc.bottom = clientRect.bottom-5;
        rc.left = clientRect.left+5;
        rc.right = clientRect.Width()/2-5;
        hClientWnd = m_ClientView3.Create(m_hWnd,rc,NULL,WS_CHILD|WS_VISIBLE);
        ATLASSERT(hClientWnd);
        return 0;
    }
    
    void OnDestroy()
    {
        PostQuitMessage(0);
    }
    void OnSize(UINT /*nType*/, CSize size)
    {
        CRect clientRect,rc;
        GetClientRect(&clientRect);
        if (m_ClientView1.m_hWnd)
        {
            rc.top = clientRect.top+5;
            rc.bottom = clientRect.Height()/2-5;
            rc.left = clientRect.left+5;
            rc.right = clientRect.Width()/2-5;
            m_ClientView1.SetWindowPos(m_hWnd,&rc,
                SWP_NOZORDER|SWP_NOACTIVATE);
        }
        if (m_ClientView2.m_hWnd)
        {
            rc.top = clientRect.top+5;
            rc.bottom = clientRect.Height()/2-5;
            rc.left = clientRect.Width()/2+5;
            rc.right = clientRect.right-5;
            m_ClientView2.SetWindowPos(m_hWnd,&rc,
                SWP_NOZORDER|SWP_NOACTIVATE);
        }
        if (m_ClientView3.m_hWnd)
        {
            rc.top = clientRect.Height()/2+5;
            rc.bottom = clientRect.bottom-5;
            rc.left = clientRect.left+5;
            rc.right = clientRect.Width()/2-5;
            m_ClientView3.SetWindowPos(m_hWnd,&rc,
                SWP_NOZORDER|SWP_NOACTIVATE);
        }
    }
private:
    CClientView m_ClientView1;
    CClientView m_ClientView2;
    CClientView m_ClientView3;
};