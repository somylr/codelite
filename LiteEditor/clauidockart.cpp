#include "clauidockart.h"
#include <wx/image.h>
#include <wx/dc.h>

#include "tabicons.h"

CLAuiDockArt::CLAuiDockArt()
{
	wxImage img(closetab_xpm);
	img.SetAlpha(closetab_alpha, true);
	m_bmp_close = wxBitmap(img);

	wxImage img2(closetab_active_xpm);
	img2.SetAlpha(closetab_active_alpha, true);
	m_bmp_close_active = wxBitmap(img2);

}

CLAuiDockArt::~CLAuiDockArt()
{
}

void CLAuiDockArt::DrawPaneButton(wxDC& dc, wxWindow* window, int button, int button_state, const wxRect& rect, wxAuiPaneInfo& pane)
{
	switch(button){
	case wxAUI_BUTTON_CLOSE: {

		switch(button_state){
		case wxAUI_BUTTON_STATE_PRESSED:
			dc.DrawBitmap(m_bmp_close_active, rect.x, rect.y, true);
			break;
		case wxAUI_BUTTON_STATE_HIDDEN:
			break;
		case wxAUI_BUTTON_STATE_HOVER:
		case wxAUI_BUTTON_STATE_NORMAL:
		default:
			dc.DrawBitmap(m_bmp_close, rect.x, rect.y, true);
			break;
		}

		break;
	}
	default:
		wxAuiDefaultDockArt::DrawPaneButton(dc, window, button, button_state, rect, pane);
		break;
	}
}
