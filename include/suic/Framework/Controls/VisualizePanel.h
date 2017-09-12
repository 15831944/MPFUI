// ���ڿƼ���Ȩ���� 2008-2022
// 
// �ļ�����VisualizePanel.h
// ��  �ܣ�������岼�ֻ��ࡣ
// 
// ��  �ߣ�MPF������
// ʱ  �䣺2011-07-02
// 
// ============================================================================


#ifndef _UIVISUALIZEPANEL_H_
#define _UIVISUALIZEPANEL_H_

#include <System/Windows/ScrollInfo.h>
#include <Framework/Controls/Panel.h>

namespace suic
{

/// <summary>
/// VisualizePanel
/// </summary>
class SUICORE_API VirtualizingPanel : public Panel
{
public:

    VirtualizingPanel();
    virtual ~VirtualizingPanel();

    RTTIOfAbstractClass(VirtualizingPanel)

    void GenerateChildren();
    void ClearChildren();

    void BringIndexIntoView(int index);

    bool IsScrolling();

    IScrollInfo* GetScrollInfo();
    ScrollData* GetScrollData();

    VirtualizingPanel* Clone();

    virtual void ClearAllContainers(ItemsControl* itemsControl);

protected:

    void ClearRealizedContainer();
    void InsertContainer(int index, Element* conainer);
    Element* RecycleContainer(int index, ItemEntry* item);
    void SetAndVerifyScrollingData(Size viewport, Size extent, Point offset);

protected:

    virtual void OnScrollChange(IScrollInfo* pScrollInfo);
    virtual void OnViewportSizeChanged(Size oldViewportSize, Size newViewportSize);
    virtual void OnViewportOffsetChanged(Point oldViewportOffset, Point newViewportOffset);

    virtual void OnItemsChangedInternal(Object* sender, ItemsChangedEventArg* e);

protected:

    int _realedCount;
    ScrollInfo* _scrollInfo;    
};

}

#endif
