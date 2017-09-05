// ���ڿƼ���Ȩ���� 2010-2011
// 
// �ļ�����MainWindow.h
// ��  �ܣ������洰�ڡ�
// 
// ��  �ߣ�MPF������
// ʱ  �䣺2013-01-02
// 
// ============================================================================

#ifndef _MAINWINDOW_H_
#define _MAINWINDOW_H_

#include "PlayManager.h"

class MainWindow : public suic::Window
{
public:

    // �¼�ӳ��
    BeginRoutedEvent(MainWindow, suic::Window)
        MemberRouted(OnClickButton)
        MemberRouted(OnClickOpenButton)
        MemberRouted(OnClickStopButton)
        MemberRouted(OnClickFullButton)
        MemberRouted(OnClickBrowserButton)
        MemberRouted(OnClickPrevButton)
        MemberRouted(OnClickNextButton)
    EndRoutedEvent()

    MainWindow();
    ~MainWindow();

    void SetFullScreenMode(bool bFull);

    void OnLoaded(suic::LoadedEventArg* e);

    void OnClickButton(suic::DpObject* sender, suic::RoutedEventArg* e);
    void OnClickOpenButton(suic::DpObject* sender, suic::RoutedEventArg* e);
    void OnClickStopButton(suic::DpObject* sender, suic::RoutedEventArg* e);
    void OnClickFullButton(suic::DpObject* sender, suic::RoutedEventArg* e);
    void OnClickBrowserButton(suic::DpObject* sender, suic::RoutedEventArg* e);
    void OnClickPrevButton(suic::DpObject* sender, suic::RoutedEventArg* e);
    void OnClickNextButton(suic::DpObject* sender, suic::RoutedEventArg* e);

    void OnVolumeChanged(suic::Element*, suic::FloatPropChangedEventArg* e);
    void OnPlayProgressChanged(suic::Element*, suic::FloatPropChangedEventArg* e);
    void OnDblPlayListClick(suic::Element* sender, suic::MouseButtonEventArg* e);
    void OnPlayListSelectionChanged(suic::Element* sender, suic::SelectionChangedEventArg* e);

protected:

    void OnRenderSizeChanged(suic::SizeChangedInfo& sizeInfo);
    void OnPreviewMouseMove(suic::MouseButtonEventArg* e);
    void OnKeyDown(suic::KeyboardEventArg* e);
    void OnPreviewMouseLeftButtonDown(suic::MouseButtonEventArg* e);

    void OnCheckMouseMove(suic::Object* sender, suic::EventArg* e);

    void Dispose();
    void UpdateLayBottomPos();
    void PlayCallback(bool start, int index);

protected:

    // �����Լ��Ŀؼ�����
    bool OnBuild(suic::IXamlNode* pNode, suic::ObjectPtr& obj);
    void OnConnect(suic::IXamlNode* pNode, suic::Object* target);

private:

    PlayManager* _playManager;
    suic::Element* _layBottom;
    suic::Element* _playArea;
    suic::ListBox* _playListBox;

    suic::Point _lastMousePt;
    // ��ʱ�������������ȫ��״̬ʱ���ͣ��ʱ��
    // ����ͣ��ʱ�䳤����ʾ״̬��
    suic::AssignerTimer* _timer;
};

#endif
