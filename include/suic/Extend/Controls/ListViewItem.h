// ���ڿƼ���Ȩ���� 2008-2022
// 
// �ļ�����ListViewItem.h
// ��  �ܣ��б���ͼ�ؼ��
// 
// ��  �ߣ�MPF������
// ʱ  �䣺2010-11-02
// 
// ============================================================================

#ifndef _UILISTVIEWITEM_H_
#define _UILISTVIEWITEM_H_

#include <Extend/suiwgxconfig.h>
#include <Extend/Controls/ListBoxItem.h>

namespace suic
{

class SUIWGX_API ListViewItem : public ListBoxItem
{
public:

    RTTIOfClass(ListViewItem)

    static void StaticInit();

    ListViewItem();
    ~ListViewItem();
};

}

#endif
