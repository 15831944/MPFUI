// ���ڿƼ���Ȩ���� 2010-2022
// 
// �ļ�����VisualizeWrapPanel.h
// ��  �ܣ�ʵ������Ļ��Ʋ�����塣
// 
// ��  �ߣ�MPF������
// ʱ  �䣺2017-09-02
// 
// ============================================================================

#ifndef _VISUALIZEWRAPPANEL_H_
#define _VISUALIZEWRAPPANEL_H_

#include <Extend/suiwgxconfig.h>
#include <Framework/Controls/VisualizePanel.h>

namespace suic
{

class SUIWGX_API VirtualizingWrapPanel : public suic::VirtualizingPanel
{
public:

    static suic::DpProperty* OrientationProperty;

    static void StaticInit();

    RTTIOfClass(VirtualizingWrapPanel)

    VirtualizingWrapPanel();
    ~VirtualizingWrapPanel();

    int GetItemWidth();
    void SetItemWidth(int wid);

    int GetItemHeight();
    void SetItemHeight(int hei);

    suic::Orientation GetOrientation();
    void SetOrientation(suic::Orientation val);
    int GetLogicalOrientation();

protected:

    int GetVisibleChildrenCount();
    int GetVisibleStart() const;
    void InvalidateChildrenResourceReference();

    suic::Size OnMeasure(const suic::Size& constraintSize);
    void OnArrange(const suic::Size& arrangesize);

    void OnKeyDown(suic::KeyboardEventArg* e);

    int ComputeOffsetFromItem(suic::Object* item, int& offset, int& itemSize);
    int ComputeOffsetFromIndex(int index, int& offset, int& itemSize);

    void OnItemsChangedInternal(suic::Object* sender, suic::ItemsChangedEventArg* e);

    void ResetChildMeasureData(suic::MeasureData* childMeasureData, const suic::MeasureData& measureData, suic::Size layoutSize);

protected:

    int _itemWid;
    int _itemHei;

    int _visibleCount;
    int _visibleStart;
    int _visibleOffset;
    int _countPerShow;
};

inline int VirtualizingWrapPanel::GetVisibleChildrenCount()
{
    return _visibleCount;
}

inline int VirtualizingWrapPanel::GetVisibleStart() const
{
    return _visibleStart;
}

}

#endif
