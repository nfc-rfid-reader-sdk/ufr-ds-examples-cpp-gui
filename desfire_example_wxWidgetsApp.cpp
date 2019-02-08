/***************************************************************
 * Name:      desfire_example_wxWidgetsApp.cpp
 * Purpose:   Code for Application Class
 * Author:    Bojan Rajkovic (bojan.rajkovic@d-logic.rs)
 * Created:   2019-02-04
 * Copyright: Bojan Rajkovic (www.d-logic.net)
 * License:
 **************************************************************/

#include "desfire_example_wxWidgetsApp.h"

//(*AppHeaders
#include "desfire_example_wxWidgetsMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(desfire_example_wxWidgetsApp);

bool desfire_example_wxWidgetsApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	desfire_example_wxWidgetsFrame* Frame = new desfire_example_wxWidgetsFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
