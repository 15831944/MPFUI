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

#include "ZipWindow.h"
#include "UnzipWindow.h"

#include "UpdateWindow.h"
#include "SettingWindow.h"

#include <Framework/Controls/Menu.h>

class ZipListView : public suic::ListView
{
public:

    RTTIOfClass(ZipListView)

    void RenderChildren(suic::Drawing* drawing);
};

class ZipInfo : public  suic::NotifyPropChanged
{
public:

    BeginMember(ZipInfo, suic::NotifyPropChanged)
        MemberInt(FileCount)
        MemberGetString(ZipSize)
        MemberGetString(FileSize)
        MemberGetString(ZipRate)
        MemberString(ZipType)
    EndMember()

    RTTIOfClass(ZipInfo)

    ZipInfo()
    {
        _zipSize = 0;
        _fileSize = 0;
        _zipRate = 0.1f;
        SetFileCount(0);
        SetZipSize(0);
        SetZipType("RAR");
    }

    DefineInt(FileCount);
    DefineString(ZipType);

    suic::String GetZipSize()
    {
        suic::String strVal;
        strVal.Format(_U("%.2f KB"), _zipSize / 1024.0f);
        return strVal;
    }

    void SetZipSize(int size)
    {
        _zipSize = size;
        NotifyChanged("ZipSize");
    }

    suic::String GetFileSize()
    {
        suic::String strVal;
        strVal.Format(_U("��%.2f KB��%d �ֽڣ�"), _fileSize / 1024.0f, _fileSize);
        return strVal;
    }

    void SetFileSize(int size)
    {
        _fileSize = size;
        NotifyChanged("FileSize");
    }

    suic::String GetZipRate()
    {
        suic::String strVal;
        strVal.Format(_U("%.2f"), _zipRate);
        return strVal;
    }

    void SetZipRate(suic::Float val)
    {
        _zipRate = val;
        NotifyChanged("ZipRate");
    }

private:

    int _zipSize;
    int _fileSize;
    suic::Float _zipRate;
};

class ZipEntry : public  suic::NotifyPropChanged
{
public:

    BeginMember(ZipEntry, suic::NotifyPropChanged)
        MemberString(Name)
        MemberString(ZipBefore)
        MemberString(ZipAfter)
        MemberString(ZipType)
        MemberString(Date)
        MemberObject(Icon)
    EndMember()

    RTTIOfClass(ZipEntry)

    DefineString(Name);
    DefineString(ZipBefore);
    DefineString(ZipAfter);
    DefineString(ZipType);
    DefineString(Date);
    DefineObject(Icon);
};

class CompareInfo : public suic::Object
{
public:

    int iDesc;
    int iColumn;
    suic::String name;

    CompareInfo() 
        : suic::Object(false)
    {
        iColumn = 0;
        iDesc = -1;
    }
};

class ZipEntryCompare
{
public:

    static int Compare(suic::ItemEntry* t1, suic::ItemEntry* t2, suic::Object* flag)
    {
        CompareInfo* ci = (CompareInfo*)flag;
        ZipEntry* zt1 = (ZipEntry*) t1->GetItem();
        ZipEntry* zt2 = (ZipEntry*) t2->GetItem();

        int iRet = 0;
        
        if (ci->name.Equals("����"))
        {
            iRet = zt1->GetName().Compare(zt2->GetName());
        }
        else if (ci->name.Equals("����"))
        {
            iRet = zt1->GetZipType().Compare(zt2->GetZipType());
        }

        return iRet * ci->iDesc;
    }
};

class ZipFileColl : public suic::ObservableCollection
{
public:

    ZipFileColl()
    {
    }
};

class MainWindow : public suic::Window
{
public:

    // �¼�ӳ��
    BeginRoutedEvent(MainWindow, suic::Window)
        MemberRouted(OnClickAddToButton)
        MemberRouted(OnClickUnzipButton)
        MemberRouted(OnClickOnOneUnzipButton)
        MemberRouted(OnClickDeleteButton)
        MemberRouted(OnClickPwdButton)
        MemberRouted(OnClickUpLevelButton)
        MemberRouted(OnClickIconModeButton)
        MemberRouted(OnClickListModeButton)
    EndRoutedEvent()

    MainWindow();
    ~MainWindow();

private:

    void OnClickAddToButton(suic::DpObject* sender, suic::RoutedEventArg* e);
    void OnClickUnzipButton(suic::DpObject* sender, suic::RoutedEventArg* e);
    void OnClickOnOneUnzipButton(suic::DpObject* sender, suic::RoutedEventArg* e);
    void OnClickDeleteButton(suic::DpObject* sender, suic::RoutedEventArg* e);
    void OnClickPwdButton(suic::DpObject* sender, suic::RoutedEventArg* e);
    void OnClickUpLevelButton(suic::DpObject* sender, suic::RoutedEventArg* e);
    void OnClickIconModeButton(suic::DpObject* sender, suic::RoutedEventArg* e);
    void OnClickListModeButton(suic::DpObject* sender, suic::RoutedEventArg* e);
    
    void OnListViewColomnClicked(suic::Element* sender, suic::RoutedEventArg* e);
    void OnListViewItemDbClck(suic::Element* sender, suic::MouseButtonEventArg* e);

protected:

    void OnLoaded(suic::LoadedEventArg* e);

    // �����Լ��Ŀؼ�����
    bool OnBuild(suic::IXamlNode* pNode, suic::ObjectPtr& obj);
    void OnConnect(suic::IXamlNode* pNode, suic::Object* target);

private:

    void AddTestData();

    void HideListViewSortIcon();
    void SortListViewColumn(suic::GridViewColumnHeader* colHeader);

    void UnzipFile(suic::String strPath);

    void OnRefleshTimer(suic::Object* sender, suic::EventArg* e);
    void OnMainMenuClick(suic::Element* sender, suic::RoutedEventArg* e);

private:

    ZipFileColl* _zipColl;
    ZipListView* _zipListView;

    suic::Menu* _mainMenu;
    suic::ListBox* _zipListBox;

    ZipInfo* _zipInfo;

    // ��ʱ��������ˢ�½����б�
    suic::AssignerTimer* _timer;
};

#endif
