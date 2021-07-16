#pragma once

#include "FA2PP.h"

// For Temperory Use
class CWndView : public CView
{
protected:
    virtual void OnDraw(CDC* pDC) override
    {
        JMP_THIS(0x460E30); //fs
    }
};