// ���ڿƼ���Ȩ���� 2008-2022
// 
// �ļ�����Environment.h
// ��  �ܣ�������Ŀ⻷���࣬���ڻ�ȡ��Ļ���������ꡢ����ϵͳ����Ϣ��
// 
// ��  �ߣ�MPF������
// ʱ  �䣺2010-07-02
// 
// ============================================================================

#ifndef _UIENVIRONMENT_H_
#define _UIENVIRONMENT_H_

#include <System/Types/Const.h>

namespace suic 
{

typedef struct tagMonitorInfo
{
    Rect rcWork;
    Rect rcMonitor;
} MonitorInfo;

class SUICORE_API Environment
{
public:

    static OSType GetOSType();
    static Size GetScreenClient();
    static Size GetScreenBound();
    static Time_t GetSystemTick();
    static Time_t GetSystemTime();

    static MonitorInfo GetMonitorBoundByPoint(suic::Point* pt);
    static MonitorInfo GetMonitorBoundByWindow(HWND hwnd);
};

}

#endif
