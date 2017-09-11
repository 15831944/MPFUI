// ======================================================================
//
// Copyright (c) 2008-2022 ����(�ӵ�UI), Inc. All rights reserved.
//
// MPF�������ѭָ����ԴЭ�飬�����˾���������Э�鹺����Ȩ��
// �κθ��ˡ������˾���ܾ��ڴ˿������κ���ҵ���ʵĿ����롣
//
// ======================================================================

/////////////////////////////////////////////////////////////////////////
// VisualizePanel.cpp

#include <System/Tools/Debug.h>

#include <Framework/Controls/ScrollViewer.h>
#include <Framework/Controls/VisualizePanel.h>
//#include <Framework/Controls/ItemsElement.h>

namespace suic
{

//////////////////////////////////////////////////////////////
// VirtualizingPanel
//
ImplementRTTIOfClass(VirtualizingPanel, suic::Panel)

VirtualizingPanel::VirtualizingPanel()
{
}

VirtualizingPanel::~VirtualizingPanel()
{
}

void VirtualizingPanel::BringIndexIntoView(int index)
{

}

void VirtualizingPanel::GenerateChildren()
{
}

void VirtualizingPanel::ClearChildren()
{
}

VirtualizingPanel* VirtualizingPanel::Clone()
{
    VirtualizingPanel* pVp(DynamicCast<VirtualizingPanel>(suic::Panel::Clone()));
    return pVp;
}

void VirtualizingPanel::ClearAllContainers(ItemsControl* itemsControl)
{

}

void VirtualizingPanel::OnScrollChange(IScrollInfo* pScrollInfo)
{
    if (pScrollInfo->GetScrollOwner() != NULL)
    {
        pScrollInfo->GetScrollOwner()->InvalidateScrollInfo(true);
    }
}

void VirtualizingPanel::OnItemsChangedInternal(Object* sender, ItemsChangedEventArg* e)
{
}

}
