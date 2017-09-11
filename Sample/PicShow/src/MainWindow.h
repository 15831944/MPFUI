// ���ڿƼ���Ȩ���� 2010-2022
// 
// �ļ�����MainWindow.h
// ��  �ܣ������洰�ڡ�
// 
// ��  �ߣ�MPF������
// ʱ  �䣺2017-09-02
// 
// ============================================================================

#ifndef _MAINWINDOW_H_
#define _MAINWINDOW_H_

#include "DriverItem.h"

class MainWindow : public suic::Window
{
public:

    MainWindow();
    ~MainWindow();

    void OnLoaded(suic::LoadedEventArg* e);

protected:

    // �����Լ��Ŀؼ�����
    bool OnBuild(suic::IXamlNode* pNode, suic::ObjectPtr& obj);
    void OnConnect(suic::IXamlNode* pNode, suic::Object* target);

private:

    void OnRefleshTimer(suic::Object* sender, suic::EventArg* e);

private:

    DriverGroup* _driverGrp;
    suic::TreeView* _tvDrivers;

    // DriverLevel* _driverLevel;

    // ��ʱ��������ˢ�½����б�
    suic::AssignerTimer* _timer;
};

#endif
