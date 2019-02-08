/***************************************************************
 * Name:      desfire_example_wxWidgetsApp.h
 * Purpose:   Defines Application Class
 * Author:    Bojan Rajkovic (bojan.rajkovic@d-logic.rs)
 * Created:   2019-02-04
 * Copyright: Bojan Rajkovic (www.d-logic.net)
 * License:
 **************************************************************/

#ifndef DESFIRE_EXAMPLE_WXWIDGETSAPP_H
#define DESFIRE_EXAMPLE_WXWIDGETSAPP_H

#include <wx/app.h>

class desfire_example_wxWidgetsApp : public wxApp
{
    public:
        virtual bool OnInit();
};

#endif // DESFIRE_EXAMPLE_WXWIDGETSAPP_H
