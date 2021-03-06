#pragma once

#include "resource.h"

class SnapshotWizardPage1 : public CPropertyPageImpl<SnapshotWizardPage1>
{
public:
	enum
	{
		IDD = IDD_SCWIZARD1
	};

	explicit SnapshotWizardPage1(_U_STRINGorID title = static_cast<LPCTSTR>(nullptr)) : CPropertyPageImpl<SnapshotWizardPage1>(title) { }

	BEGIN_MSG_MAP(SnapshotWizardPage1)
	MSG_WM_INITDIALOG(OnInitDialog)
	CHAIN_MSG_MAP(CPropertyPageImpl<SnapshotWizardPage1>)
	END_MSG_MAP()

	BOOL OnInitDialog(CWindow wndFocus, LPARAM lInitParam);
	LRESULT OnWizardNext();

	void SetSharedString(wchar_t* sharedStringPage1);

private:
	CEdit sourceEdit_;
	CEdit destinationEdit_;
	wchar_t* sharedStringPage1_;

	BOOL InvokeEsentutilP(const wchar_t* targetDbPath) const;
};

class SnapshotWizardPage2 : public CPropertyPageImpl<SnapshotWizardPage2>
{
public:
	enum
	{
		IDD = IDD_SCWIZARD2
	};

	explicit SnapshotWizardPage2(_U_STRINGorID title = static_cast<LPCTSTR>(nullptr)) : CPropertyPageImpl<SnapshotWizardPage2>(title) { }

	BEGIN_MSG_MAP(SnapshotWizardPage2)
		CHAIN_MSG_MAP(CPropertyPageImpl<SnapshotWizardPage2>)
		END_MSG_MAP()

	BOOL OnSetActive();

	void SetSharedString(wchar_t* sharedStringPage2) {
		sharedStringPage2_ = sharedStringPage2;
	}

private:
	wchar_t* sharedStringPage2_;
};

class CSnapshotWizard : public CPropertySheetImpl<CSnapshotWizard>
{
public:
	CSnapshotWizard(_U_STRINGorID title = static_cast<LPCTSTR>(nullptr),
	                UINT uStartPage = 0, HWND hWndParent = nullptr);

	~CSnapshotWizard() {
		delete sharedString_;
	}

	BEGIN_MSG_MAP(CSnapshotWizard)
		CHAIN_MSG_MAP(CPropertySheetImpl<CSnapshotWizard>)
		END_MSG_MAP()

	//It is the client's responsibility that the return string should be deleted.
	wchar_t* GetSnapshotFilePath() const {
		return sharedString_;
	}

private:
	SnapshotWizardPage1 page1_;
	SnapshotWizardPage2 page2_;
	wchar_t* sharedString_;
};
