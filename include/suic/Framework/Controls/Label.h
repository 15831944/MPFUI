// ���ڿƼ���Ȩ���� 2008-2022
// 
// �ļ�����Label.h
// ��  �ܣ���ǩ�ؼ���֧����Ϸ�ʽʵ�֡�
// 
// ��  �ߣ�MPF������
// ʱ  �䣺2011-07-02
// 
// ============================================================================

#ifndef _UILABEL_H_
#define _UILABEL_H_

#include <Framework/Controls/Content.h>
   
namespace suic
{

class SUICORE_API Label : public ContentControl
{
public:

    RTTIOfClass(Label)

    Label();
    virtual ~Label();

    static void StaticInit();

    Label* Clone();
};

}

#endif
