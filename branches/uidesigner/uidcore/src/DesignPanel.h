
#ifndef _DESIGNPANEL_H_
#define _DESIGNPANEL_H_

#include "DElement.h"
#include "DragMetaTool.h"
#include <sui/ScrollPresenter.h>

class DesignPanel : public ui::ScrollPresenter
{
public:

    DesignPanel();
    virtual ~DesignPanel();

    void OnInitialized();

    void OnLoaded(suic::LoadedEventArg& e);
    void OnRender(suic::Drawing* drawing);

    void OnMouseMove(suic::MouseEventArg& e);

    void OnMouseLeftButtonDown(suic::MouseEventArg& e);
    void OnMouseLeftButtonUp(suic::MouseEventArg& e);

    void OnMouseRightButtonDown(suic::MouseEventArg& e);

    void OnTextInput(suic::KeyboardEventArg& e);

public:

    // �϶����
    void OnDragLeft(DragMeta& meta, int iAction);

    // �϶����Ͻ�
    void OnDragLeftTop(DragMeta& meta, int iAction);

    // �϶��ϱ�
    void OnDragTop(DragMeta& meta, int iAction);

    // �϶����Ͻ�
    void OnDragRightTop(DragMeta& meta, int iAction);

    // �϶��ұ�
    void OnDragRight(DragMeta& meta, int iAction);

    // �϶����½�
    void OnDragRightBottom(DragMeta& meta, int iAction);

    // �϶��±�
    void OnDragBottom(DragMeta& meta, int iAction);

    // �϶����½�
    void OnDragLeftBottom(DragMeta& meta, int iAction);

    // �ƶ�
    void OnDragMove(DragMeta& meta, int iAction);

protected:

    bool IsMain() const;
    void LinkDragMetaEvent();
    DragMeta* HittestDragMeta(suic::Point pt);
    void HandleDragRect(suic::Rect& rect);
    void InternalHandleDrag(suic::Rect& rect, int* pNori, int* pVert);

protected:

    suic::Vector<DragMeta> _dragMetas;

    // ��ǰ������϶���(���ѹ����Ч)
    DragMeta* _dragMeta;

    // ��ǰ��Ƶĸ�Ԫ��
    DElement* _root;

    // ����������Ԫ��
    suic::Rect _mouseOverRc;
    // ��ʼ�϶�ʱ�ĵ�
    suic::Point _startDragPt;
    // ��ʼ�϶�ʱԪ�������С
    suic::Rect _startDragRc;
    suic::Rect _startDragMgr;

    // ��ǰ����
    suic::Point _trackDragPt;
};

bool InitUIDCore(suic::Element* main);

#endif
