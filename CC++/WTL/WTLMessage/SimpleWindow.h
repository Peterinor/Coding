#pragma once

#include "WTL.h"

class MessageBoundle : CMessageMap
{
    BEGIN_MSG_MAP(MessageBoundle)
        MESSAGE_HANDLER(WM_LBUTTONUP, OnLButtonUp);
        MESSAGE_HANDLER(WM_RBUTTONUP, OnRButtonUp);
        MESSAGE_HANDLER(WM_MBUTTONUP, OnMButtonUp);
    END_MSG_MAP()

    LRESULT OnLButtonUp(UINT msg, WPARAM wparam, LPARAM lparam, BOOL & handled){
        MessageBox(NULL, L"LBUP", L"Tips", 0);
        return 0;
    }
    LRESULT OnRButtonUp(UINT msg, WPARAM wparam, LPARAM lparam, BOOL & handled){
        MessageBox(NULL, L"RBUP", L"Tips", 0);
        return 0;
    }
    LRESULT OnMButtonUp(UINT msg, WPARAM wparam, LPARAM lparam, BOOL & handled){
        MessageBox(NULL, L"MBUP", L"Tips", 0);
        return 0;
    }
};

class SimpleWindow
    : public CWindowImpl<SimpleWindow, CWindow, CFrameWinTraits>
    , public MessageBoundle
{
public:

    DECLARE_WND_CLASS(_T("SimpleWTLWindow"));

    BEGIN_MSG_MAP(SimpleWindow)
        MESSAGE_HANDLER(WM_CLOSE, OnClose);
        MESSAGE_HANDLER(WM_DESTROY, OnDestory);
        CHAIN_MSG_MAP(MessageBoundle);
    END_MSG_MAP()

    LRESULT OnClose(UINT msg, WPARAM wparam, LPARAM lparam, BOOL & handled){

        DestroyWindow();
        return 0;
    }

    LRESULT OnDestory(UINT msg, WPARAM wparam, LPARAM lparam, BOOL & handled){
        PostQuitMessage(0);
        return 0;
    }
    //SimpleWindow(void);
    //~SimpleWindow(void);
};

