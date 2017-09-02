// ���ڿƼ���Ȩ���� 2008-2022
// 
// �ļ�����UIDrawing.h
// ��  �ܣ�������ƽӿ�
// 
// ��  �ߣ�MPF������
// ʱ  �䣺2010-07-12
// 
// ============================================================================

#ifndef _UIDRAWIN_H_
#define _UIDRAWIN_H_

#include <System/Windows/Effect.h>
#include <System/Graphics/Bitmap.h>
#include <System/Graphics/Geometry.h>
#include <System/Animation/Transform.h>
#include <System/Graphics/FormattedText.h>

namespace suic
{

class WeakRef;

/// <summary>
///  ���ƽӿ��࣬���һ��Ļ��ƣ��ߵ���ɫ���ñ�׼����ɫ��ʾ
/// </summary>
class SUICORE_API NOVTABLE Drawing
{
public:

    virtual ~Drawing() {};

    virtual Bitmap* GetBitmap() = 0;
    virtual fPoint GetOffset() = 0;
    virtual void* GetCanvas(int type) = 0;

    virtual bool IsLayeredMode() = 0;

    virtual int Save() = 0;
    virtual void Restore() = 0;

    virtual void SetMatrix(const Matrix* m) = 0;
    virtual void ConcatMatrix(const Matrix* m) = 0;
    virtual void ResetMatrix() = 0;

    virtual int PushOffset(const fPoint& pt) = 0;
    virtual void PopOffset() = 0;

    virtual fRect GetClipBound() = 0;
    virtual fRect GetTopClipBound() = 0;

    virtual bool ContainsClip(fRect* clip) = 0;
    virtual bool ContainsClip(fRRect* clip) = 0;
    virtual bool ContainsClip(Geometry* clip) = 0;

    virtual void PushEffect(const Effect* effect);
    virtual void PopEffect();

    virtual void ClipRect(const fRect* clip, ClipOp op) = 0;
    virtual void ClipRound(const fRRect* clip, ClipOp op, bool anti) = 0;
    virtual void ClipGeometry(Geometry* gmt, ClipOp op, bool anti) = 0;

    virtual void SetPixel(Int32 x, Int32 y, Color clr) = 0;
    virtual Color GetPixel(Int32 x, Int32 y) = 0;

    virtual void ReadPixels(Bitmap* dest, Point offset) = 0;
    virtual void WritePixels(Bitmap* dest, Point offset) = 0;

    virtual void EraseColor(DrawCtx* drawCtx, Color color) = 0;
    virtual void EraseRect(DrawCtx* drawCtx, Color color, const fRect* rc) = 0;
    virtual void EraseRect(DrawCtx* drawCtx, Bitmap* bmp, const fRect* rc) = 0;
    virtual void FillRect(DrawCtx* drawCtx, Color color, const fRect* rc) = 0;

    virtual void DrawLine(DrawCtx* drawCtx, Pen* pen, fPoint pt0, fPoint pt1) = 0;
    virtual void DrawRect(DrawCtx* drawCtx, Brush* brush, Pen* pen, const fRect* rc) = 0;
    virtual void DrawRRect(DrawCtx* drawCtx, Brush* brush, Pen* pen, const fRRect* rc) = 0;
    virtual void DrawRoundRect(DrawCtx* drawCtx, Brush* brush, Pen* pen, const fRect* rc, Float radiusX, Float radiusY) = 0;
    virtual void DrawCircle(DrawCtx* drawCtx, Brush* brush, Pen* pen, fPoint center, Float radius) = 0;
    virtual void DrawEllipse(DrawCtx* drawCtx, Brush* brush, Pen* pen, const fRect* rc) = 0;
    virtual void DrawPath(DrawCtx* drawCtx, Brush* brush, Pen* pen, PathFigure* path) = 0;
    virtual void DrawGeometry(DrawCtx* drawCtx, Brush* brush, Pen* pen, Geometry* regm) = 0;
    virtual void DrawArc(DrawCtx* drawCtx, Brush* brush, Pen* pen, fRect* oval, Float starta, Float sweepa, bool usecenter) = 0;

    virtual void DrawSprite(DrawCtx* drawCtx, Bitmap* bmp, int x, int y) = 0;

    virtual void DrawImage(DrawCtx* drawCtx, Bitmap* bmp, int x, int y) = 0;
    virtual void DrawImage(DrawCtx* drawCtx, Bitmap* bmp, const Matrix* m) = 0;
    virtual void DrawImage(DrawCtx* drawCtx, Bitmap* bmp, const fRect* rcdc, const fRect* rcimg) = 0;
    virtual void DrawImage(DrawCtx* drawCtx, Bitmap* bmp, const fRect* rcdc, const fRect* rcimg, Color trans) = 0;

    virtual void DrawString(FormattedText* fmtText, const Char* text, int size, const fRect* rc) = 0;
    virtual void MeasureString(TmParam& tm, FormattedText* formattedText, const Char* text, int size) = 0;
};

struct SUICORE_API RenderContext
{
    Bitmap* bitmap;
    Drawing* drawing;

    RenderContext();
    ~RenderContext();
    
    Drawing* Open(int w, int h, int iType);
    Drawing* Open(Bitmap* bitmap, int iType);

    void Close();
};

}

#endif
