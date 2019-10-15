
// Timer8View.cpp: CTimer8View 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "Timer8.h"
#endif

#include "Timer8Doc.h"
#include "Timer8View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CTimer8View

IMPLEMENT_DYNCREATE(CTimer8View, CView)

BEGIN_MESSAGE_MAP(CTimer8View, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_TIMER()
END_MESSAGE_MAP()

// CTimer8View 생성/소멸

CTimer8View::CTimer8View() noexcept
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CTimer8View::~CTimer8View()
{
}

BOOL CTimer8View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CTimer8View 그리기

void CTimer8View::OnDraw(CDC* /*pDC*/)
{
	CTimer8Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}


// CTimer8View 인쇄

BOOL CTimer8View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CTimer8View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CTimer8View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// CTimer8View 진단

#ifdef _DEBUG
void CTimer8View::AssertValid() const
{
	CView::AssertValid();
}

void CTimer8View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CTimer8Doc* CTimer8View::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTimer8Doc)));
	return (CTimer8Doc*)m_pDocument;
}
#endif //_DEBUG


// CTimer8View 메시지 처리기


void CTimer8View::OnInitialUpdate()
{
	CView::OnInitialUpdate();
	SetTimer(1, 500, NULL);
	SetTimer(2, 100, NULL);
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
}


void CTimer8View::OnTimer(UINT_PTR nIDEvent)
{
	CClientDC dc(this);
	CFont f;
	f.CreatePointFont(500, L"굴림");
	dc.SelectObject(&f);
	if (nIDEvent == 1) {
		static int n1;
		CString str;
		str.Format(L"%d", ++n1);
		dc.TextOut(10, 100, str);
	}
	if (nIDEvent == 2) {
		static int n2;
		CString str;
		str.Format(L"%d", ++n2);
		dc.TextOut(200, 100, str);
	}
	CView::OnTimer(nIDEvent);
}
