#pragma once
#include "thread.h"
void dowork(THREADPASSDATA* pD, LPCTSTR pNext=NULL);
void processResult(THREADPASSDATA* pD);
void clearwork();