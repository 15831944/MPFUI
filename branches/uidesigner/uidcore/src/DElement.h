
#ifndef _DELEMENT_H_
#define _DELEMENT_H_

class DElement : public suic::RefBase
{
public:

    DElement();
    virtual ~DElement();

protected:

    // Ԫ����Դ

    // Ԫ����ʽ

    // ��Ԫ��
    suic::Vector<DElement*> _child;
};

#endif
