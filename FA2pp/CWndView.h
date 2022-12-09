#pragma once

#include "FA2PP.h"

// CMinimap
class CWndView : public FA2CView
{
protected:
    virtual void OnDraw(CDC* pDC) override
    {
        JMP_THIS(0x460E30); //fs
    }
};