
// Timer8View.h: CTimer8View 클래스의 인터페이스
//

#pragma once


class CTimer8View : public CView
{
protected: // serialization에서만 만들어집니다.
	CTimer8View() noexcept;
	DECLARE_DYNCREATE(CTimer8View)

// 특성입니다.
public:
	CTimer8Doc* GetDocument() const;

// 작업입니다.
public:

// 재정의입니다.
public:
	virtual void OnDraw(CDC* pDC);  // 이 뷰를 그리기 위해 재정의되었습니다.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 구현입니다.
public:
	virtual ~CTimer8View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()
public:
	virtual void OnInitialUpdate();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};

#ifndef _DEBUG  // Timer8View.cpp의 디버그 버전
inline CTimer8Doc* CTimer8View::GetDocument() const
   { return reinterpret_cast<CTimer8Doc*>(m_pDocument); }
#endif

