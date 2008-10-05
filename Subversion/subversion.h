//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//
// copyright            : (C) 2008 by Eran Ifrah                            
// file name            : subversion.h              
//                                                                          
// -------------------------------------------------------------------------
// A                                                                        
//              _____           _      _     _ _                            
//             /  __ \         | |    | |   (_) |                           
//             | /  \/ ___   __| | ___| |    _| |_ ___                      
//             | |    / _ \ / _  |/ _ \ |   | | __/ _ )                     
//             | \__/\ (_) | (_| |  __/ |___| | ||  __/                     
//              \____/\___/ \__,_|\___\_____/_|\__\___|                     
//                                                                          
//                                                  F i l e                 
//                                                                          
//    This program is free software; you can redistribute it and/or modify  
//    it under the terms of the GNU General Public License as published by  
//    the Free Software Foundation; either version 2 of the License, or     
//    (at your option) any later version.                                   
//                                                                          
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
 #ifndef SUBVERSION_H
#define SUBVERSION_H

#include "svnxmlparser.h"
#include "project.h"
#include "plugin.h"
#include "wx/html/htmlwin.h"
#include "map"
#include "list"
#include "wx/timer.h"
#include "wx/treectrl.h"
#include "svnoptions.h"

class SvnDriver;
class VdtcTreeItemBase;

class SubversionPlugin : public IPlugin
{
	wxMenu *m_svnMenu;
	SvnDriver *m_svn;
	wxEvtHandler *topWin;
	SvnOptions m_options;	
	friend class SvnDriver;
	bool m_isValid;
	bool m_initIsDone;
	wxMenuItem *m_explorerSepItem;
	wxMenuItem *m_editorSepItem;
	wxMenuItem *m_workspaceSepItem;
	wxMenuItem *m_projectSepItem;
	
	
protected:
	void SendSvnMenuEvent(int id);
	bool SanityCheck();
	
public:
	SubversionPlugin(IManager *manager);
	virtual ~SubversionPlugin();
	const SvnOptions& GetOptions() const{return m_options;}
	bool IsWorkspaceUnderSvn();
	
	//--------------------------------------------
	//Abstract methods
	//--------------------------------------------
	virtual wxToolBar *CreateToolBar(wxWindow *parent);
	virtual void CreatePluginMenu(wxMenu *pluginsMenu);
	virtual void HookPopupMenu(wxMenu *menu, MenuType type);
	virtual void UnHookPopupMenu(wxMenu *menu, MenuType type);
	virtual void UnPlug();
	
protected:
	wxMenu *CreatePopMenu();
	wxMenu *CreateEditorPopMenu();
	wxMenu *CreateWorkspacePopMenu();
	wxMenu *CreateProjectPopMenu();
	
	//
	//Helper functions
	///////////////////////////////////////////////////////
	wxString FormatRaws(const wxArrayString &lines, const wxString &basePath, SvnXmlParser::FileState state);
	void DoMakeHTML(const wxArrayString &outpout, const wxString &basePath);
	ProjectPtr GetSelectedProject();
	
	void DoGetSvnStatus(const wxString &basePath, wxArrayString &output);
	void DoGenerateReport(const wxString &basePath);
	
	void DoGenerateWspReport();
	void DoGetWspSvnStatus(wxArrayString &output);
	
	void DoGetPrjSvnStatus(wxArrayString &output);
	void DoGeneratePrjReport();
	
	// event handlers
	///////////////////////////////////////////////////////
	void OnUpdate(wxCommandEvent &event);
	void OnCommit(wxCommandEvent &event);
	void OnDiff(wxCommandEvent &event);
	void OnCleanup(wxCommandEvent &event);
	void OnFileSaved(wxCommandEvent &event);
	void OnShowSvnStatus_FileExplorer(wxCommandEvent &event);
	void OnFileExplorerInitDone(wxCommandEvent &event);
	void OnOptions(wxCommandEvent &event);
	void OnChangeLog(wxCommandEvent &event);
	void OnSvnAbort(wxCommandEvent &event);
	void OnSvnAdd(wxCommandEvent &event);
	void OnDelete(wxCommandEvent &event);
	void OnRevert(wxCommandEvent &event);
	void OnProjectFileAdded(wxCommandEvent &event);
	void OnAppInitDone(wxCommandEvent &event);
	void OnCommitFile(wxCommandEvent &e);
	void OnUpdateFile(wxCommandEvent &e);
	void OnDiffFile(wxCommandEvent &e);
	void OnRevertFile(wxCommandEvent &e);
	void OnLinkClicked(wxHtmlLinkEvent &e);
	void OnRefrshIconsStatus(wxCommandEvent &e);
	void OnRefreshIconsCond(wxCommandEvent &e);
	void OnShowReportWsp(wxCommandEvent &e);
	void OnUpdateWsp(wxCommandEvent &e);
	void OnCommitWsp(wxCommandEvent &e);
	void OnShowReportPrj(wxCommandEvent &e);
	void OnUpdatePrj(wxCommandEvent &e);
	void OnCommitPrj(wxCommandEvent &e);
	void OnResolveConflictFile(wxCommandEvent &e);
	void OnResolveConflict(wxCommandEvent &e);
	void OnPatch(wxCommandEvent &e);
};

#endif //SUBVERSION_H

