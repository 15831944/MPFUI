// ���ڿƼ���Ȩ���� 2008-2022
// 
// �ļ�����uiinvokerpriorityqueue.h
// ��  �ܣ�ʵ�ִ������ȼ��Ķ��С�
// 
// ��  �ߣ�MPF������
// ʱ  �䣺2010-07-02
// 
// ============================================================================

#ifndef _UIINVOKERPRIORITYQUEUE_H_
#define _UIINVOKERPRIORITYQUEUE_H_

#include <System/Windows/AssignerInvoker.h>
#include <System/Types/Structure.h>
#include <System/Tools/Locker.h>

namespace suic
{

typedef Array<AssignerInvoker*, false> AssignerInvokerArray;

class SUICORE_API InvokerPriorityQueue  : public Object
{
public:

    InvokerPriorityQueue();
    ~InvokerPriorityQueue();

    // ȡ�������ݵ�������ȼ�
    int GetMaxPriority();

    // �������ȼ���ߵĲ�����
    AssignerInvoker* Dequeue();
    AssignerInvoker* GetSenderItem();

    void Enqueue(AssignerInvoker*, int Priority);
    void RemoveItem(AssignerInvoker* item);

protected:

    void CalculateMaxPriority();

protected:

    Array<AssignerInvoker*, false> _sendQueue;
    Array<AssignerInvokerArray*, false> _queue;

    int _maxPriority;
    Mutex _queueLock;
};

}

#endif
