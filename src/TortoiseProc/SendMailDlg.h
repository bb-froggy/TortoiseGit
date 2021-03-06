// TortoiseGit - a Windows shell extension for easy version control

// Copyright (C) 2008-2011 - TortoiseGit

// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License
// as published by the Free Software Foundation; either version 2
// of the License, or (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software Foundation,
// 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
//
#pragma once
#include "afxcmn.h"
#include "StandAloneDlg.h"
#include "HyperLink.h"
// CSendMailDlg dialog
#include "ACEdit.h"
#include "RegHistory.h"
#include "TGitPath.h"
#include "patch.h"
#include "Registry.h"
#include "PatchListCtrl.h"

class CSendMailDlg : public CResizableStandAloneDialog
{
	DECLARE_DYNAMIC(CSendMailDlg)

public:
	CSendMailDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~CSendMailDlg();

// Dialog Data
	enum { IDD = IDD_SENDMAIL };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL OnInitDialog();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	DECLARE_MESSAGE_MAP()

	void UpdateSubject();

	CHyperLink		m_SmtpSetup;

	CACEdit			m_ctrlCC;
	CACEdit			m_ctrlTO;
	CRegHistory		m_AddressReg;
	CToolTipCtrl	m_ToolTip;

public:
	CString			m_To;
	CString			m_CC;
	CString			m_Subject;
	BOOL			m_bAttachment;
	BOOL			m_bCombine;
	BOOL			m_bUseMAPI;
	CTGitPathList	m_PathList;

private:
	CPatchListCtrl	m_ctrlList;

	CRegDWORD		m_regAttach;
	CRegDWORD		m_regCombine;
	CRegDWORD		m_regUseMAPI;

	std::map<int,CPatch> m_MapPatch;

	afx_msg void OnBnClickedSendmailCombine();
	afx_msg void OnBnClickedOk();
	afx_msg void OnLvnItemchangedSendmailPatchs(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMDblclkSendmailPatchs(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnEnChangeSendmailSubject();
	afx_msg void OnBnClickedSendmailMapi();
};
