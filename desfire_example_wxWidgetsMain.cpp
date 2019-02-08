/***************************************************************
 * Name:      desfire_example_wxWidgetsMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    Bojan Rajkovic (bojan.rajkovic@d-logic.rs)
 * Created:   2019-02-04
 * Copyright: Bojan Rajkovic (www.d-logic.net)
 * License:
 **************************************************************/

#include "desfire_example_wxWidgetsMain.h"
#include <wx/msgdlg.h>

#include "lib/include/uFCoder.h"
#include <iostream>   // std::cout
#include <fstream>
#include <vector>
#include <string>

#define BUFFER_SIZE 192

//(*InternalHeaders(desfire_example_wxWidgetsFrame)
#include <wx/settings.h>
#include <wx/intl.h>
#include <wx/string.h>
//*)

//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}

//(*IdInit(desfire_example_wxWidgetsFrame)
const long desfire_example_wxWidgetsFrame::ID_STATICBOX1 = wxNewId();
const long desfire_example_wxWidgetsFrame::ID_STATICTEXT1 = wxNewId();
const long desfire_example_wxWidgetsFrame::ID_TEXTCTRL1 = wxNewId();
const long desfire_example_wxWidgetsFrame::ID_CHECKBOX1 = wxNewId();
const long desfire_example_wxWidgetsFrame::ID_STATICTEXT2 = wxNewId();
const long desfire_example_wxWidgetsFrame::ID_TEXTCTRL2 = wxNewId();
const long desfire_example_wxWidgetsFrame::ID_STATICTEXT3 = wxNewId();
const long desfire_example_wxWidgetsFrame::ID_STATICTEXT4 = wxNewId();
const long desfire_example_wxWidgetsFrame::ID_COMBOBOX1 = wxNewId();
const long desfire_example_wxWidgetsFrame::ID_STATICTEXT5 = wxNewId();
const long desfire_example_wxWidgetsFrame::ID_CHECKBOX2 = wxNewId();
const long desfire_example_wxWidgetsFrame::ID_COMBOBOX2 = wxNewId();
const long desfire_example_wxWidgetsFrame::ID_COMBOBOX3 = wxNewId();
const long desfire_example_wxWidgetsFrame::ID_STATICBOX2 = wxNewId();
const long desfire_example_wxWidgetsFrame::ID_STATICTEXT6 = wxNewId();
const long desfire_example_wxWidgetsFrame::ID_TEXTCTRL3 = wxNewId();
const long desfire_example_wxWidgetsFrame::ID_STATICTEXT7 = wxNewId();
const long desfire_example_wxWidgetsFrame::ID_COMBOBOX4 = wxNewId();
const long desfire_example_wxWidgetsFrame::ID_BUTTON1 = wxNewId();
const long desfire_example_wxWidgetsFrame::ID_STATICTEXT8 = wxNewId();
const long desfire_example_wxWidgetsFrame::ID_TEXTCTRL4 = wxNewId();
const long desfire_example_wxWidgetsFrame::ID_BUTTON2 = wxNewId();
const long desfire_example_wxWidgetsFrame::ID_BUTTON3 = wxNewId();
const long desfire_example_wxWidgetsFrame::ID_STATICBOX3 = wxNewId();
const long desfire_example_wxWidgetsFrame::ID_STATICTEXT9 = wxNewId();
const long desfire_example_wxWidgetsFrame::ID_COMBOBOX5 = wxNewId();
const long desfire_example_wxWidgetsFrame::ID_STATICTEXT10 = wxNewId();
const long desfire_example_wxWidgetsFrame::ID_COMBOBOX6 = wxNewId();
const long desfire_example_wxWidgetsFrame::ID_BUTTON4 = wxNewId();
const long desfire_example_wxWidgetsFrame::ID_BUTTON5 = wxNewId();
const long desfire_example_wxWidgetsFrame::ID_STATICTEXT11 = wxNewId();
const long desfire_example_wxWidgetsFrame::ID_STATICBOX4 = wxNewId();
const long desfire_example_wxWidgetsFrame::ID_STATICTEXT12 = wxNewId();
const long desfire_example_wxWidgetsFrame::ID_STATICTEXT13 = wxNewId();
const long desfire_example_wxWidgetsFrame::ID_TEXTCTRL5 = wxNewId();
const long desfire_example_wxWidgetsFrame::ID_TEXTCTRL6 = wxNewId();
const long desfire_example_wxWidgetsFrame::ID_STATICTEXT14 = wxNewId();
const long desfire_example_wxWidgetsFrame::ID_COMBOBOX7 = wxNewId();
const long desfire_example_wxWidgetsFrame::ID_BUTTON6 = wxNewId();
const long desfire_example_wxWidgetsFrame::ID_BUTTON7 = wxNewId();
const long desfire_example_wxWidgetsFrame::ID_CHECKBOX3 = wxNewId();
const long desfire_example_wxWidgetsFrame::ID_CHECKBOX4 = wxNewId();
const long desfire_example_wxWidgetsFrame::ID_CHECKBOX5 = wxNewId();
const long desfire_example_wxWidgetsFrame::ID_BUTTON8 = wxNewId();
const long desfire_example_wxWidgetsFrame::ID_STATICBOX5 = wxNewId();
const long desfire_example_wxWidgetsFrame::ID_STATICTEXT15 = wxNewId();
const long desfire_example_wxWidgetsFrame::ID_STATICTEXT16 = wxNewId();
const long desfire_example_wxWidgetsFrame::ID_COMBOBOX8 = wxNewId();
const long desfire_example_wxWidgetsFrame::ID_TEXTCTRL7 = wxNewId();
const long desfire_example_wxWidgetsFrame::ID_BUTTON9 = wxNewId();
const long desfire_example_wxWidgetsFrame::ID_BUTTON10 = wxNewId();
const long desfire_example_wxWidgetsFrame::ID_STATICTEXT17 = wxNewId();
const long desfire_example_wxWidgetsFrame::ID_CHECKBOX6 = wxNewId();
const long desfire_example_wxWidgetsFrame::ID_CHECKBOX7 = wxNewId();
const long desfire_example_wxWidgetsFrame::ID_CHECKBOX8 = wxNewId();
const long desfire_example_wxWidgetsFrame::ID_STATICBOX6 = wxNewId();
const long desfire_example_wxWidgetsFrame::ID_STATICTEXT18 = wxNewId();
const long desfire_example_wxWidgetsFrame::ID_COMBOBOX9 = wxNewId();
const long desfire_example_wxWidgetsFrame::ID_STATICTEXT19 = wxNewId();
const long desfire_example_wxWidgetsFrame::ID_TEXTCTRL8 = wxNewId();
const long desfire_example_wxWidgetsFrame::ID_STATICBOX7 = wxNewId();
const long desfire_example_wxWidgetsFrame::ID_STATICTEXT20 = wxNewId();
const long desfire_example_wxWidgetsFrame::ID_BUTTON11 = wxNewId();
const long desfire_example_wxWidgetsFrame::ID_BUTTON12 = wxNewId();
const long desfire_example_wxWidgetsFrame::ID_STATICBOX8 = wxNewId();
const long desfire_example_wxWidgetsFrame::ID_STATICTEXT21 = wxNewId();
const long desfire_example_wxWidgetsFrame::ID_COMBOBOX10 = wxNewId();
const long desfire_example_wxWidgetsFrame::ID_BUTTON13 = wxNewId();
const long desfire_example_wxWidgetsFrame::ID_BUTTON14 = wxNewId();
const long desfire_example_wxWidgetsFrame::ID_BUTTON15 = wxNewId();
const long desfire_example_wxWidgetsFrame::ID_TEXTCTRL9 = wxNewId();
const long desfire_example_wxWidgetsFrame::ID_STATICTEXT22 = wxNewId();
const long desfire_example_wxWidgetsFrame::ID_STATICBOX9 = wxNewId();
const long desfire_example_wxWidgetsFrame::ID_BUTTON16 = wxNewId();
const long desfire_example_wxWidgetsFrame::ID_BUTTON17 = wxNewId();
const long desfire_example_wxWidgetsFrame::ID_BUTTON18 = wxNewId();
const long desfire_example_wxWidgetsFrame::ID_BUTTON19 = wxNewId();
const long desfire_example_wxWidgetsFrame::ID_BUTTON20 = wxNewId();
const long desfire_example_wxWidgetsFrame::ID_COMBOBOX11 = wxNewId();
const long desfire_example_wxWidgetsFrame::ID_STATICBOX10 = wxNewId();
const long desfire_example_wxWidgetsFrame::ID_RADIOBUTTON1 = wxNewId();
const long desfire_example_wxWidgetsFrame::ID_RADIOBUTTON2 = wxNewId();
const long desfire_example_wxWidgetsFrame::ID_BUTTON21 = wxNewId();
const long desfire_example_wxWidgetsFrame::ID_BUTTON22 = wxNewId();
const long desfire_example_wxWidgetsFrame::ID_STATICTEXT23 = wxNewId();
const long desfire_example_wxWidgetsFrame::ID_COMBOBOX12 = wxNewId();
const long desfire_example_wxWidgetsFrame::ID_STATICTEXT24 = wxNewId();
const long desfire_example_wxWidgetsFrame::ID_TEXTCTRL10 = wxNewId();
const long desfire_example_wxWidgetsFrame::ID_STATICTEXT25 = wxNewId();
const long desfire_example_wxWidgetsFrame::ID_TEXTCTRL11 = wxNewId();
const long desfire_example_wxWidgetsFrame::ID_STATICTEXT26 = wxNewId();
const long desfire_example_wxWidgetsFrame::ID_TEXTCTRL12 = wxNewId();
const long desfire_example_wxWidgetsFrame::ID_TEXTCTRL13 = wxNewId();
const long desfire_example_wxWidgetsFrame::ID_STATICTEXT27 = wxNewId();
const long desfire_example_wxWidgetsFrame::ID_COMBOBOX13 = wxNewId();
const long desfire_example_wxWidgetsFrame::ID_COMBOBOX14 = wxNewId();
const long desfire_example_wxWidgetsFrame::ID_COMBOBOX15 = wxNewId();
const long desfire_example_wxWidgetsFrame::ID_COMBOBOX16 = wxNewId();
const long desfire_example_wxWidgetsFrame::ID_STATICTEXT28 = wxNewId();
const long desfire_example_wxWidgetsFrame::ID_STATICTEXT29 = wxNewId();
const long desfire_example_wxWidgetsFrame::ID_STATICTEXT30 = wxNewId();
const long desfire_example_wxWidgetsFrame::ID_STATICTEXT31 = wxNewId();
const long desfire_example_wxWidgetsFrame::ID_TEXTCTRL14 = wxNewId();
const long desfire_example_wxWidgetsFrame::ID_STATICTEXT32 = wxNewId();
const long desfire_example_wxWidgetsFrame::ID_TEXTCTRL15 = wxNewId();
const long desfire_example_wxWidgetsFrame::ID_CHECKBOX9 = wxNewId();
const long desfire_example_wxWidgetsFrame::ID_CHECKBOX10 = wxNewId();
const long desfire_example_wxWidgetsFrame::ID_BUTTON23 = wxNewId();
const long desfire_example_wxWidgetsFrame::idMenuQuit = wxNewId();
const long desfire_example_wxWidgetsFrame::idMenuAbout = wxNewId();
const long desfire_example_wxWidgetsFrame::ID_STATUSBAR1 = wxNewId();
const long desfire_example_wxWidgetsFrame::ID_TIMER1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(desfire_example_wxWidgetsFrame,wxFrame)
    //(*EventTable(desfire_example_wxWidgetsFrame)
    //*)
END_EVENT_TABLE()

desfire_example_wxWidgetsFrame::desfire_example_wxWidgetsFrame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(desfire_example_wxWidgetsFrame)
    wxMenuItem* MenuItem2;
    wxMenuItem* MenuItem1;
    wxMenu* Menu1;
    wxMenuBar* MenuBar1;
    wxMenu* Menu2;

    Create(parent, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("wxID_ANY"));
    SetClientSize(wxSize(1006,773));
    SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_INACTIVEBORDER));
    StaticBox1 = new wxStaticBox(this, ID_STATICBOX1, _("Card authentication"), wxPoint(8,8), wxSize(472,192), 0, _T("ID_STATICBOX1"));
    StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("AES key:"), wxPoint(32,35), wxDefaultSize, 0, _T("ID_STATICTEXT1"));
    txtCardAutAESKey = new wxTextCtrl(this, ID_TEXTCTRL1, _("000102030405060708090A0B0C0D0E0F"), wxPoint(96,32), wxSize(222,22), 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
    txtCardAutAESKey->SetMaxLength(32);
    chkInternalKeyUsed = new wxCheckBox(this, ID_CHECKBOX1, _("Internal key used"), wxPoint(368,32), wxSize(104,22), 0, wxDefaultValidator, _T("ID_CHECKBOX1"));
    chkInternalKeyUsed->SetValue(false);
    StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("AID 3 bytes hex"), wxPoint(32,70), wxDefaultSize, 0, _T("ID_STATICTEXT2"));
    txtCardAutAIDBytes = new wxTextCtrl(this, ID_TEXTCTRL2, _("000000"), wxPoint(144,64), wxSize(80,22), 0, wxDefaultValidator, _T("ID_TEXTCTRL2"));
    StaticText3 = new wxStaticText(this, ID_STATICTEXT3, _("Internal key number"), wxPoint(368,64), wxDefaultSize, 0, _T("ID_STATICTEXT3"));
    StaticText4 = new wxStaticText(this, ID_STATICTEXT4, _("AID key number auth"), wxPoint(32,100), wxDefaultSize, 0, _T("ID_STATICTEXT4"));
    cmbCardAutAidKeyNrAuth = new wxComboBox(this, ID_COMBOBOX1, wxEmptyString, wxPoint(144,96), wxSize(80,21), 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX1"));
    cmbCardAutAidKeyNrAuth->SetSelection( cmbCardAutAidKeyNrAuth->Append(_("0")) );
    cmbCardAutAidKeyNrAuth->Append(_("1"));
    cmbCardAutAidKeyNrAuth->Append(_("2"));
    cmbCardAutAidKeyNrAuth->Append(_("3"));
    cmbCardAutAidKeyNrAuth->Append(_("4"));
    cmbCardAutAidKeyNrAuth->Append(_("5"));
    cmbCardAutAidKeyNrAuth->Append(_("6"));
    cmbCardAutAidKeyNrAuth->Append(_("7"));
    cmbCardAutAidKeyNrAuth->Append(_("8"));
    cmbCardAutAidKeyNrAuth->Append(_("9"));
    cmbCardAutAidKeyNrAuth->Append(_("10"));
    cmbCardAutAidKeyNrAuth->Append(_("11"));
    cmbCardAutAidKeyNrAuth->Append(_("12"));
    cmbCardAutAidKeyNrAuth->Append(_("13"));
    StaticText5 = new wxStaticText(this, ID_STATICTEXT5, _("File ID"), wxPoint(32,140), wxDefaultSize, 0, _T("ID_STATICTEXT5"));
    chkCardAutMasterKeyAuthenticationReq = new wxCheckBox(this, ID_CHECKBOX2, _("Master key authentication required"), wxPoint(32,176), wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX2"));
    chkCardAutMasterKeyAuthenticationReq->SetValue(false);
    cmbCardAutFileID = new wxComboBox(this, ID_COMBOBOX2, wxEmptyString, wxPoint(144,136), wxSize(80,21), 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX2"));
    cmbCardAutFileID->SetSelection( cmbCardAutFileID->Append(_("0")) );
    cmbCardAutFileID->Append(_("1"));
    cmbCardAutFileID->Append(_("2"));
    cmbCardAutFileID->Append(_("3"));
    cmbCardAutFileID->Append(_("4"));
    cmbCardAutFileID->Append(_("5"));
    cmbCardAutFileID->Append(_("6"));
    cmbCardAutFileID->Append(_("7"));
    cmbCardAutFileID->Append(_("8"));
    cmbCardAutFileID->Append(_("9"));
    cmbCardAutFileID->Append(_("10"));
    cmbCardAutFileID->Append(_("11"));
    cmbCardAutFileID->Append(_("12"));
    cmbCardAutFileID->Append(_("13"));
    cmbCardAutFileID->Append(_("14"));
    cmbCardAutFileID->Append(_("15"));
    cmbCardAutFileID->Append(_("16"));
    cmbCardAutFileID->Append(_("17"));
    cmbCardAutFileID->Append(_("18"));
    cmbCardAutFileID->Append(_("19"));
    cmbCardAutFileID->Append(_("20"));
    cmbCardAutFileID->Append(_("21"));
    cmbCardAutFileID->Append(_("22"));
    cmbCardAutFileID->Append(_("23"));
    cmbCardAutFileID->Append(_("24"));
    cmbCardAutFileID->Append(_("25"));
    cmbCardAutFileID->Append(_("26"));
    cmbCardAutFileID->Append(_("27"));
    cmbCardAutFileID->Append(_("28"));
    cmbCardAutFileID->Append(_("29"));
    cmbCardAutFileID->Append(_("30"));
    cmbCardAutFileID->Append(_("31"));
    cmbCardAutInternalKeyNr = new wxComboBox(this, ID_COMBOBOX3, wxEmptyString, wxPoint(368,80), wxSize(72,21), 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX3"));
    cmbCardAutInternalKeyNr->SetSelection( cmbCardAutInternalKeyNr->Append(_("0")) );
    cmbCardAutInternalKeyNr->Append(_("1"));
    cmbCardAutInternalKeyNr->Append(_("2"));
    cmbCardAutInternalKeyNr->Append(_("3"));
    cmbCardAutInternalKeyNr->Append(_("4"));
    cmbCardAutInternalKeyNr->Append(_("5"));
    cmbCardAutInternalKeyNr->Append(_("6"));
    cmbCardAutInternalKeyNr->Append(_("7"));
    cmbCardAutInternalKeyNr->Append(_("8"));
    cmbCardAutInternalKeyNr->Append(_("9"));
    cmbCardAutInternalKeyNr->Append(_("10"));
    cmbCardAutInternalKeyNr->Append(_("11"));
    cmbCardAutInternalKeyNr->Append(_("12"));
    cmbCardAutInternalKeyNr->Append(_("13"));
    cmbCardAutInternalKeyNr->Append(_("14"));
    cmbCardAutInternalKeyNr->Append(_("15"));
    StaticBox2 = new wxStaticBox(this, ID_STATICBOX2, _("Internal keys operations"), wxPoint(484,8), wxSize(380,192), 0, _T("ID_STATICBOX2"));
    StaticText6 = new wxStaticText(this, ID_STATICTEXT6, _("AES key:"), wxPoint(505,35), wxDefaultSize, 0, _T("ID_STATICTEXT6"));
    txtInternKeysOpsAESKey = new wxTextCtrl(this, ID_TEXTCTRL3, _("000102030405060708090A0B0C0D0E0F"), wxPoint(608,32), wxSize(222,22), 0, wxDefaultValidator, _T("ID_TEXTCTRL3"));
    StaticText7 = new wxStaticText(this, ID_STATICTEXT7, _("Internal key number"), wxPoint(496,72), wxDefaultSize, 0, _T("ID_STATICTEXT7"));
    cmbInternKeysOpsIntKeyNr = new wxComboBox(this, ID_COMBOBOX4, wxEmptyString, wxPoint(608,64), wxSize(80,21), 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX4"));
    cmbInternKeysOpsIntKeyNr->SetSelection( cmbInternKeysOpsIntKeyNr->Append(_("0")) );
    cmbInternKeysOpsIntKeyNr->Append(_("1"));
    cmbInternKeysOpsIntKeyNr->Append(_("2"));
    cmbInternKeysOpsIntKeyNr->Append(_("3"));
    cmbInternKeysOpsIntKeyNr->Append(_("4"));
    cmbInternKeysOpsIntKeyNr->Append(_("5"));
    cmbInternKeysOpsIntKeyNr->Append(_("6"));
    cmbInternKeysOpsIntKeyNr->Append(_("7"));
    cmbInternKeysOpsIntKeyNr->Append(_("8"));
    cmbInternKeysOpsIntKeyNr->Append(_("9"));
    cmbInternKeysOpsIntKeyNr->Append(_("10"));
    cmbInternKeysOpsIntKeyNr->Append(_("11"));
    cmbInternKeysOpsIntKeyNr->Append(_("12"));
    cmbInternKeysOpsIntKeyNr->Append(_("13"));
    cmbInternKeysOpsIntKeyNr->Append(_("14"));
    cmbInternKeysOpsIntKeyNr->Append(_("15"));
    btnStoreAESKeyIntoReader = new wxButton(this, ID_BUTTON1, _("Store AES key into reader"), wxPoint(712,64), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
    btnStoreAESKeyIntoReader->Disable();
    StaticText8 = new wxStaticText(this, ID_STATICTEXT8, _("Internal key lock password"), wxPoint(495,110), wxDefaultSize, 0, _T("ID_STATICTEXT8"));
    txtInternKeysPassword = new wxTextCtrl(this, ID_TEXTCTRL4, _("111111"), wxPoint(650,104), wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL4"));
    btnInternalKeyLock = new wxButton(this, ID_BUTTON2, _("Internal Key Lock"), wxPoint(496,144), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
    btnInternalKeyUnlock = new wxButton(this, ID_BUTTON3, _("Internal Key Unlock"), wxPoint(632,144), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON3"));
    StaticBox3 = new wxStaticBox(this, ID_STATICBOX3, _("Baud rate"), wxPoint(870,8), wxSize(114,632), 0, _T("ID_STATICBOX3"));
    StaticText9 = new wxStaticText(this, ID_STATICTEXT9, _("Transmit baud rate:"), wxPoint(880,32), wxDefaultSize, 0, _T("ID_STATICTEXT9"));
    cmbTxSpeed = new wxComboBox(this, ID_COMBOBOX5, wxEmptyString, wxPoint(880,48), wxSize(100,21), 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX5"));
    cmbTxSpeed->SetSelection( cmbTxSpeed->Append(_("106 kbps")) );
    cmbTxSpeed->Append(_("212 kbps"));
    cmbTxSpeed->Append(_("424 kbps"));
    cmbTxSpeed->Append(_("848 kbps"));
    StaticText10 = new wxStaticText(this, ID_STATICTEXT10, _("Receive baud rate:"), wxPoint(880,80), wxDefaultSize, 0, _T("ID_STATICTEXT10"));
    cmbRxSpeed = new wxComboBox(this, ID_COMBOBOX6, wxEmptyString, wxPoint(880,96), wxSize(100,21), 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX6"));
    cmbRxSpeed->SetSelection( cmbRxSpeed->Append(_("106 kbps")) );
    cmbRxSpeed->Append(_("212 kbps"));
    cmbRxSpeed->Append(_("424 kbps"));
    cmbRxSpeed->Append(_("848 kbps"));
    btnSetBaudRate = new wxButton(this, ID_BUTTON4, _("Set baud rate"), wxPoint(880,136), wxSize(100,23), 0, wxDefaultValidator, _T("ID_BUTTON4"));
    btnGetBaudRate = new wxButton(this, ID_BUTTON5, _("Get baud rate"), wxPoint(880,176), wxSize(100,23), 0, wxDefaultValidator, _T("ID_BUTTON5"));
    StaticText11 = new wxStaticText(this, ID_STATICTEXT11, _("Required baud rates are stored permanently in the reader."), wxPoint(880,552), wxSize(100,72), 0, _T("ID_STATICTEXT11"));
    StaticBox4 = new wxStaticBox(this, ID_STATICBOX4, _("Keys operations"), wxPoint(8,192), wxSize(472,240), 0, _T("ID_STATICBOX4"));
    StaticText12 = new wxStaticText(this, ID_STATICTEXT12, _("Old key"), wxPoint(32,223), wxDefaultSize, 0, _T("ID_STATICTEXT12"));
    StaticText13 = new wxStaticText(this, ID_STATICTEXT13, _("New key"), wxPoint(32,255), wxDefaultSize, 0, _T("ID_STATICTEXT13"));
    txtKeyOpsOldKey = new wxTextCtrl(this, ID_TEXTCTRL5, _("000102030405060708090A0B0C0D0E0F"), wxPoint(88,220), wxSize(222,22), 0, wxDefaultValidator, _T("ID_TEXTCTRL5"));
    txtKeyOpsNewKey = new wxTextCtrl(this, ID_TEXTCTRL6, _("000102030405060708090A0B0C0D0E0F"), wxPoint(88,252), wxSize(222,22), 0, wxDefaultValidator, _T("ID_TEXTCTRL6"));
    StaticText14 = new wxStaticText(this, ID_STATICTEXT14, _("AID key number"), wxPoint(32,290), wxDefaultSize, 0, _T("ID_STATICTEXT14"));
    cmbKeysOpsAidKeyNr = new wxComboBox(this, ID_COMBOBOX7, wxEmptyString, wxPoint(128,285), wxSize(80,21), 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX7"));
    cmbKeysOpsAidKeyNr->SetSelection( cmbKeysOpsAidKeyNr->Append(_("0")) );
    cmbKeysOpsAidKeyNr->Append(_("1"));
    cmbKeysOpsAidKeyNr->Append(_("2"));
    cmbKeysOpsAidKeyNr->Append(_("3"));
    cmbKeysOpsAidKeyNr->Append(_("4"));
    cmbKeysOpsAidKeyNr->Append(_("5"));
    cmbKeysOpsAidKeyNr->Append(_("6"));
    cmbKeysOpsAidKeyNr->Append(_("7"));
    cmbKeysOpsAidKeyNr->Append(_("8"));
    cmbKeysOpsAidKeyNr->Append(_("9"));
    cmbKeysOpsAidKeyNr->Append(_("10"));
    cmbKeysOpsAidKeyNr->Append(_("11"));
    cmbKeysOpsAidKeyNr->Append(_("12"));
    cmbKeysOpsAidKeyNr->Append(_("13"));
    btnGetKeySettings = new wxButton(this, ID_BUTTON6, _("Get Key Settings"), wxPoint(32,325), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON6"));
    btnChangeKeySettings = new wxButton(this, ID_BUTTON7, _("Change Key Settings"), wxPoint(152,325), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON7"));
    chkKeyOpsSettingsNotChangeable = new wxCheckBox(this, ID_CHECKBOX3, _("Settings not changeable anymore"), wxPoint(40,360), wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX3"));
    chkKeyOpsSettingsNotChangeable->SetValue(false);
    chkKeysOpsCreateDeleteWithMasterKeyAuth = new wxCheckBox(this, ID_CHECKBOX4, _("Create or delete application with master key authentication"), wxPoint(40,380), wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX4"));
    chkKeysOpsCreateDeleteWithMasterKeyAuth->SetValue(false);
    chkKeysOpsMasterNotChangeable = new wxCheckBox(this, ID_CHECKBOX5, _("Master key not changeable anymore"), wxPoint(40,400), wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX5"));
    chkKeysOpsMasterNotChangeable->SetValue(false);
    btnChangeAESkey = new wxButton(this, ID_BUTTON8, _("Change AES key"), wxPoint(360,220), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON8"));
    StaticBox5 = new wxStaticBox(this, ID_STATICBOX5, _("Application"), wxPoint(484,208), wxSize(380,160), 0, _T("ID_STATICBOX5"));
    StaticText15 = new wxStaticText(this, ID_STATICTEXT15, _("AID 3 bytes hex"), wxPoint(505,240), wxDefaultSize, 0, _T("ID_STATICTEXT15"));
    StaticText16 = new wxStaticText(this, ID_STATICTEXT16, _("Maximal key number"), wxPoint(504,264), wxDefaultSize, 0, _T("ID_STATICTEXT16"));
    cmbApplicationMaxKeyNr = new wxComboBox(this, ID_COMBOBOX8, wxEmptyString, wxPoint(608,264), wxSize(80,21), 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX8"));
    cmbApplicationMaxKeyNr->SetSelection( cmbApplicationMaxKeyNr->Append(_("0")) );
    cmbApplicationMaxKeyNr->Append(_("1"));
    cmbApplicationMaxKeyNr->Append(_("2"));
    cmbApplicationMaxKeyNr->Append(_("3"));
    cmbApplicationMaxKeyNr->Append(_("4"));
    cmbApplicationMaxKeyNr->Append(_("5"));
    cmbApplicationMaxKeyNr->Append(_("6"));
    cmbApplicationMaxKeyNr->Append(_("7"));
    cmbApplicationMaxKeyNr->Append(_("8"));
    cmbApplicationMaxKeyNr->Append(_("9"));
    cmbApplicationMaxKeyNr->Append(_("10"));
    cmbApplicationMaxKeyNr->Append(_("11"));
    cmbApplicationMaxKeyNr->Append(_("12"));
    cmbApplicationMaxKeyNr->Append(_("13"));
    txtApplicationAIDBytes = new wxTextCtrl(this, ID_TEXTCTRL7, _("000000"), wxPoint(604,232), wxSize(80,21), 0, wxDefaultValidator, _T("ID_TEXTCTRL7"));
    btnMakeApplication = new wxButton(this, ID_BUTTON9, _("Make Application"), wxPoint(704,232), wxSize(110,23), 0, wxDefaultValidator, _T("ID_BUTTON9"));
    btnDeleteApplication = new wxButton(this, ID_BUTTON10, _("Delete Application"), wxPoint(704,264), wxSize(110,23), 0, wxDefaultValidator, _T("ID_BUTTON10"));
    StaticText17 = new wxStaticText(this, ID_STATICTEXT17, _("Application\'s keys settings"), wxPoint(504,292), wxDefaultSize, 0, _T("ID_STATICTEXT17"));
    chkApplicationSettingsNotChangeable = new wxCheckBox(this, ID_CHECKBOX6, _("Settings not changeable anymore"), wxPoint(504,310), wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX6"));
    chkApplicationSettingsNotChangeable->SetValue(false);
    chkApplicationCreateDeleteWithMasterKey = new wxCheckBox(this, ID_CHECKBOX7, _("Create or delete application with master key settings"), wxPoint(504,330), wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX7"));
    chkApplicationCreateDeleteWithMasterKey->SetValue(false);
    chkApplicationMasterNotChangeable = new wxCheckBox(this, ID_CHECKBOX8, _("Master key not changeable anymore"), wxPoint(504,350), wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX8"));
    chkApplicationMasterNotChangeable->SetValue(false);
    StaticBox6 = new wxStaticBox(this, ID_STATICBOX6, _("Standard Data File Read and Write"), wxPoint(484,368), wxSize(380,96), 0, _T("ID_STATICBOX6"));
    StaticText18 = new wxStaticText(this, ID_STATICTEXT18, _("Communication mode"), wxPoint(490,400), wxDefaultSize, 0, _T("ID_STATICTEXT18"));
    chkStdFileReadWriteCommMode = new wxComboBox(this, ID_COMBOBOX9, wxEmptyString, wxPoint(616,400), wxSize(100,21), 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX9"));
    chkStdFileReadWriteCommMode->SetSelection( chkStdFileReadWriteCommMode->Append(_("PLAIN")) );
    chkStdFileReadWriteCommMode->Append(_("MACKED"));
    chkStdFileReadWriteCommMode->Append(_("ENCIPHERED"));
    StaticText19 = new wxStaticText(this, ID_STATICTEXT19, _("Size of file"), wxPoint(496,433), wxDefaultSize, 0, _T("ID_STATICTEXT19"));
    txtStdFileReadWriteSizeOfFile = new wxTextCtrl(this, ID_TEXTCTRL8, _("20"), wxPoint(616,430), wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL8"));
    StaticBox7 = new wxStaticBox(this, ID_STATICBOX7, _("File"), wxPoint(8,432), wxSize(472,208), 0, _T("ID_STATICBOX7"));
    StaticText20 = new wxStaticText(this, ID_STATICTEXT20, _("File ID"), wxPoint(16,460), wxDefaultSize, 0, _T("ID_STATICTEXT20"));
    btnFileWriting = new wxButton(this, ID_BUTTON11, _("File Writing"), wxPoint(744,400), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON11"));
    btnFileReading = new wxButton(this, ID_BUTTON12, _("File Reading"), wxPoint(744,432), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON12"));
    StaticBox8 = new wxStaticBox(this, ID_STATICBOX8, _("Value File Operation"), wxPoint(484,464), wxSize(380,88), 0, _T("ID_STATICBOX8"));
    StaticText21 = new wxStaticText(this, ID_STATICTEXT21, _("Communication mode"), wxPoint(490,488), wxDefaultSize, 0, _T("ID_STATICTEXT21"));
    cmbValueFileOpsCommMode = new wxComboBox(this, ID_COMBOBOX10, wxEmptyString, wxPoint(620,480), wxSize(100,21), 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX10"));
    cmbValueFileOpsCommMode->SetSelection( cmbValueFileOpsCommMode->Append(_("PLAIN")) );
    cmbValueFileOpsCommMode->Append(_("MACKED"));
    cmbValueFileOpsCommMode->Append(_("ENCIPHERED"));
    btnReadValue = new wxButton(this, ID_BUTTON13, _("Read Value"), wxPoint(488,512), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON13"));
    btnIncreaseValue = new wxButton(this, ID_BUTTON14, _("Increase Value"), wxPoint(584,512), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON14"));
    btnDecreaseValue = new wxButton(this, ID_BUTTON15, _("Decrease Value"), wxPoint(688,512), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON15"));
    txtValueFileOpsValue = new wxTextCtrl(this, ID_TEXTCTRL9, _("0"), wxPoint(800,512), wxSize(64,23), 0, wxDefaultValidator, _T("ID_TEXTCTRL9"));
    StaticText22 = new wxStaticText(this, ID_STATICTEXT22, _("Value"), wxPoint(800,496), wxDefaultSize, 0, _T("ID_STATICTEXT22"));
    btnFormatCard = new wxStaticBox(this, ID_STATICBOX9, _("Card operations"), wxPoint(488,552), wxSize(376,96), 0, _T("ID_STATICBOX9"));
    btnGetCardUID = new wxButton(this, ID_BUTTON16, _("Get Card UID"), wxPoint(512,568), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON16"));
    btnGetCardUID->Disable();
    Button17 = new wxButton(this, ID_BUTTON17, _("Format card"), wxPoint(616,568), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON17"));
    btnDEStoAES = new wxButton(this, ID_BUTTON18, _("DES to AES"), wxPoint(712,568), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON18"));
    btnGetFreeMemory = new wxButton(this, ID_BUTTON19, _("Get free memory"), wxPoint(512,600), wxSize(100,23), 0, wxDefaultValidator, _T("ID_BUTTON19"));
    btnSetRandomID = new wxButton(this, ID_BUTTON20, _("Set Random ID"), wxPoint(630,600), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON20"));
    cmbFileFileID = new wxComboBox(this, ID_COMBOBOX11, wxEmptyString, wxPoint(64,456), wxSize(80,21), 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX11"));
    cmbFileFileID->SetSelection( cmbFileFileID->Append(_("0")) );
    cmbFileFileID->Append(_("1"));
    cmbFileFileID->Append(_("2"));
    cmbFileFileID->Append(_("3"));
    cmbFileFileID->Append(_("4"));
    cmbFileFileID->Append(_("5"));
    cmbFileFileID->Append(_("6"));
    cmbFileFileID->Append(_("7"));
    cmbFileFileID->Append(_("8"));
    cmbFileFileID->Append(_("9"));
    cmbFileFileID->Append(_("10"));
    cmbFileFileID->Append(_("11"));
    cmbFileFileID->Append(_("12"));
    cmbFileFileID->Append(_("13"));
    cmbFileFileID->Append(_("14"));
    cmbFileFileID->Append(_("15"));
    cmbFileFileID->Append(_("16"));
    cmbFileFileID->Append(_("17"));
    cmbFileFileID->Append(_("18"));
    cmbFileFileID->Append(_("19"));
    cmbFileFileID->Append(_("20"));
    cmbFileFileID->Append(_("21"));
    cmbFileFileID->Append(_("22"));
    cmbFileFileID->Append(_("23"));
    cmbFileFileID->Append(_("24"));
    cmbFileFileID->Append(_("25"));
    cmbFileFileID->Append(_("26"));
    cmbFileFileID->Append(_("27"));
    cmbFileFileID->Append(_("28"));
    cmbFileFileID->Append(_("29"));
    cmbFileFileID->Append(_("30"));
    cmbFileFileID->Append(_("31"));
    StaticBox10 = new wxStaticBox(this, ID_STATICBOX10, _("RGFileType"), wxPoint(200,448), wxSize(128,64), 0, _T("ID_STATICBOX10"));
    radioSTD = new wxRadioButton(this, ID_RADIOBUTTON1, _("Standard data file"), wxPoint(208,464), wxDefaultSize, 0, wxDefaultValidator, _T("ID_RADIOBUTTON1"));
    radioSTD->SetValue(true);
    radioValue = new wxRadioButton(this, ID_RADIOBUTTON2, _("Value file"), wxPoint(208,488), wxDefaultSize, 0, wxDefaultValidator, _T("ID_RADIOBUTTON2"));
    btnMakeFile = new wxButton(this, ID_BUTTON21, _("Make File"), wxPoint(376,456), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON21"));
    btnDeleteFile = new wxButton(this, ID_BUTTON22, _("Delete File"), wxPoint(376,488), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON22"));
    StaticText23 = new wxStaticText(this, ID_STATICTEXT23, _("Comm mode"), wxPoint(16,493), wxDefaultSize, 0, _T("ID_STATICTEXT23"));
    cmbFileCommMode = new wxComboBox(this, ID_COMBOBOX12, wxEmptyString, wxPoint(88,490), wxSize(80,21), 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX12"));
    cmbFileCommMode->SetSelection( cmbFileCommMode->Append(_("PLAIN")) );
    cmbFileCommMode->Append(_("MACKED"));
    cmbFileCommMode->Append(_("ENCIPHERED"));
    StaticText24 = new wxStaticText(this, ID_STATICTEXT24, _("Size of file"), wxPoint(16,523), wxDefaultSize, 0, _T("ID_STATICTEXT24"));
    txtFileSizeOfFile = new wxTextCtrl(this, ID_TEXTCTRL10, _("20"), wxPoint(88,520), wxSize(72,21), 0, wxDefaultValidator, _T("ID_TEXTCTRL10"));
    StaticText25 = new wxStaticText(this, ID_STATICTEXT25, _("Lower limit"), wxPoint(24,552), wxDefaultSize, 0, _T("ID_STATICTEXT25"));
    txtFileLowerLimit = new wxTextCtrl(this, ID_TEXTCTRL11, _("0"), wxPoint(24,568), wxSize(64,21), 0, wxDefaultValidator, _T("ID_TEXTCTRL11"));
    txtFileLowerLimit->Disable();
    StaticText26 = new wxStaticText(this, ID_STATICTEXT26, _("Upper limit"), wxPoint(104,552), wxDefaultSize, 0, _T("ID_STATICTEXT26"));
    txtFileUpperLimit = new wxTextCtrl(this, ID_TEXTCTRL12, _("0"), wxPoint(104,568), wxSize(64,21), 0, wxDefaultValidator, _T("ID_TEXTCTRL12"));
    txtFileUpperLimit->Disable();
    txtFileValue = new wxTextCtrl(this, ID_TEXTCTRL13, _("0"), wxPoint(184,568), wxSize(64,21), 0, wxDefaultValidator, _T("ID_TEXTCTRL13"));
    txtFileValue->Disable();
    StaticText27 = new wxStaticText(this, ID_STATICTEXT27, _("Value"), wxPoint(184,552), wxDefaultSize, 0, _T("ID_STATICTEXT27"));
    cmbFileReadKey = new wxComboBox(this, ID_COMBOBOX13, wxEmptyString, wxPoint(24,613), wxSize(64,21), 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX13"));
    cmbFileReadKey->SetSelection( cmbFileReadKey->Append(_("0")) );
    cmbFileReadKey->Append(_("1"));
    cmbFileReadKey->Append(_("2"));
    cmbFileReadKey->Append(_("3"));
    cmbFileReadKey->Append(_("4"));
    cmbFileReadKey->Append(_("5"));
    cmbFileReadKey->Append(_("6"));
    cmbFileReadKey->Append(_("7"));
    cmbFileReadKey->Append(_("8"));
    cmbFileReadKey->Append(_("9"));
    cmbFileReadKey->Append(_("10"));
    cmbFileReadKey->Append(_("11"));
    cmbFileReadKey->Append(_("12"));
    cmbFileReadKey->Append(_("13"));
    cmbFileReadKey->Append(_("14"));
    cmbFileReadKey->Append(_("15"));
    cmbFileWriteKey = new wxComboBox(this, ID_COMBOBOX14, wxEmptyString, wxPoint(112,613), wxSize(64,21), 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX14"));
    cmbFileWriteKey->SetSelection( cmbFileWriteKey->Append(_("0")) );
    cmbFileWriteKey->Append(_("1"));
    cmbFileWriteKey->Append(_("2"));
    cmbFileWriteKey->Append(_("3"));
    cmbFileWriteKey->Append(_("4"));
    cmbFileWriteKey->Append(_("5"));
    cmbFileWriteKey->Append(_("6"));
    cmbFileWriteKey->Append(_("7"));
    cmbFileWriteKey->Append(_("8"));
    cmbFileWriteKey->Append(_("9"));
    cmbFileWriteKey->Append(_("10"));
    cmbFileWriteKey->Append(_("11"));
    cmbFileWriteKey->Append(_("12"));
    cmbFileWriteKey->Append(_("13"));
    cmbFileWriteKey->Append(_("14"));
    cmbFileWriteKey->Append(_("15"));
    cmbFileReadWrite = new wxComboBox(this, ID_COMBOBOX15, wxEmptyString, wxPoint(192,613), wxSize(64,21), 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX15"));
    cmbFileReadWrite->SetSelection( cmbFileReadWrite->Append(_("0")) );
    cmbFileReadWrite->Append(_("1"));
    cmbFileReadWrite->Append(_("2"));
    cmbFileReadWrite->Append(_("3"));
    cmbFileReadWrite->Append(_("4"));
    cmbFileReadWrite->Append(_("5"));
    cmbFileReadWrite->Append(_("6"));
    cmbFileReadWrite->Append(_("7"));
    cmbFileReadWrite->Append(_("8"));
    cmbFileReadWrite->Append(_("9"));
    cmbFileReadWrite->Append(_("10"));
    cmbFileReadWrite->Append(_("11"));
    cmbFileReadWrite->Append(_("12"));
    cmbFileReadWrite->Append(_("13"));
    cmbFileReadWrite->Append(_("14"));
    cmbFileReadWrite->Append(_("15"));
    cmbFileChangeKey = new wxComboBox(this, ID_COMBOBOX16, wxEmptyString, wxPoint(280,613), wxSize(64,21), 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX16"));
    cmbFileChangeKey->SetSelection( cmbFileChangeKey->Append(_("0")) );
    cmbFileChangeKey->Append(_("1"));
    cmbFileChangeKey->Append(_("2"));
    cmbFileChangeKey->Append(_("3"));
    cmbFileChangeKey->Append(_("4"));
    cmbFileChangeKey->Append(_("5"));
    cmbFileChangeKey->Append(_("6"));
    cmbFileChangeKey->Append(_("7"));
    cmbFileChangeKey->Append(_("8"));
    cmbFileChangeKey->Append(_("9"));
    cmbFileChangeKey->Append(_("10"));
    cmbFileChangeKey->Append(_("11"));
    cmbFileChangeKey->Append(_("12"));
    cmbFileChangeKey->Append(_("13"));
    cmbFileChangeKey->Append(_("14"));
    cmbFileChangeKey->Append(_("15"));
    StaticText28 = new wxStaticText(this, ID_STATICTEXT28, _("Read key"), wxPoint(24,595), wxDefaultSize, 0, _T("ID_STATICTEXT28"));
    StaticText29 = new wxStaticText(this, ID_STATICTEXT29, _("Write key"), wxPoint(112,595), wxDefaultSize, 0, _T("ID_STATICTEXT29"));
    StaticText30 = new wxStaticText(this, ID_STATICTEXT30, _("Read_Write"), wxPoint(194,595), wxDefaultSize, 0, _T("ID_STATICTEXT30"));
    StaticText31 = new wxStaticText(this, ID_STATICTEXT31, _("Change key"), wxPoint(280,595), wxDefaultSize, 0, _T("ID_STATICTEXT31"));
    txtPrintOut = new wxTextCtrl(this, ID_TEXTCTRL14, wxEmptyString, wxPoint(8,648), wxSize(992,88), wxTE_MULTILINE, wxDefaultValidator, _T("ID_TEXTCTRL14"));
    static_ctrl_status = new wxStaticText(this, ID_STATICTEXT32, _("Status"), wxPoint(16,748), wxDefaultSize, 0, _T("ID_STATICTEXT32"));
    txtStatus = new wxTextCtrl(this, ID_TEXTCTRL15, _("status"), wxPoint(56,745), wxSize(224,21), 0, wxDefaultValidator, _T("ID_TEXTCTRL15"));
    chkLimitedCredit = new wxCheckBox(this, ID_CHECKBOX9, _("Limited credit"), wxPoint(264,528), wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX9"));
    chkLimitedCredit->SetValue(false);
    chkLimitedCredit->Disable();
    chkFreeGetValue = new wxCheckBox(this, ID_CHECKBOX10, _("Free get value"), wxPoint(264,552), wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX10"));
    chkFreeGetValue->SetValue(false);
    chkFreeGetValue->Disable();
    btnAEStoDES = new wxButton(this, ID_BUTTON23, _("AES to DES"), wxPoint(736,600), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON23"));
    MenuBar1 = new wxMenuBar();
    Menu1 = new wxMenu();
    MenuItem1 = new wxMenuItem(Menu1, idMenuQuit, _("Quit\tAlt-F4"), _("Quit the application"), wxITEM_NORMAL);
    Menu1->Append(MenuItem1);
    MenuBar1->Append(Menu1, _("&File"));
    Menu2 = new wxMenu();
    MenuItem2 = new wxMenuItem(Menu2, idMenuAbout, _("About\tF1"), _("Show info about this application"), wxITEM_NORMAL);
    Menu2->Append(MenuItem2);
    MenuBar1->Append(Menu2, _("Help"));
    SetMenuBar(MenuBar1);
    StatusBar1 = new wxStatusBar(this, ID_STATUSBAR1, 0, _T("ID_STATUSBAR1"));
    int __wxStatusBarWidths_1[1] = { -1 };
    int __wxStatusBarStyles_1[1] = { wxSB_NORMAL };
    StatusBar1->SetFieldsCount(1,__wxStatusBarWidths_1);
    StatusBar1->SetStatusStyles(1,__wxStatusBarStyles_1);
    SetStatusBar(StatusBar1);
    Timer1.SetOwner(this, ID_TIMER1);
    Timer1.Start(200, false);
    stdFileWriteDialog = new wxFileDialog(this, _("Select file"), wxEmptyString, wxEmptyString, wxFileSelectorDefaultWildcardStr, wxFD_DEFAULT_STYLE, wxDefaultPosition, wxDefaultSize, _T("wxFileDialog"));

    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&desfire_example_wxWidgetsFrame::OnbtnStoreAESKeyIntoReaderClick);
    Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&desfire_example_wxWidgetsFrame::OnbtnInternalKeyLockClick);
    Connect(ID_BUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&desfire_example_wxWidgetsFrame::OnbtnInternalKeyUnlockClick);
    Connect(ID_BUTTON4,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&desfire_example_wxWidgetsFrame::OnbtnSetBaudRateClick);
    Connect(ID_BUTTON5,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&desfire_example_wxWidgetsFrame::OnbtnGetBaudRateClick);
    Connect(ID_BUTTON6,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&desfire_example_wxWidgetsFrame::OnbtnGetKeySettingsClick);
    Connect(ID_BUTTON7,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&desfire_example_wxWidgetsFrame::OnbtnChangeKeySettingsClick);
    Connect(ID_BUTTON8,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&desfire_example_wxWidgetsFrame::OnbtnChangeAESkeyClick);
    Connect(ID_BUTTON9,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&desfire_example_wxWidgetsFrame::OnbtnMakeApplicationClick);
    Connect(ID_BUTTON10,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&desfire_example_wxWidgetsFrame::OnbtnDeleteApplicationClick);
    Connect(ID_BUTTON11,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&desfire_example_wxWidgetsFrame::OnbtnFileWritingClick);
    Connect(ID_BUTTON12,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&desfire_example_wxWidgetsFrame::OnbtnFileReadingClick);
    Connect(ID_BUTTON13,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&desfire_example_wxWidgetsFrame::OnbtnReadValueClick);
    Connect(ID_BUTTON14,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&desfire_example_wxWidgetsFrame::OnbtnIncreaseValueClick);
    Connect(ID_BUTTON15,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&desfire_example_wxWidgetsFrame::OnbtnDecreaseValueClick);
    Connect(ID_BUTTON16,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&desfire_example_wxWidgetsFrame::OnbtnGetCardUIDClick);
    Connect(ID_BUTTON17,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&desfire_example_wxWidgetsFrame::OnButton17Click);
    Connect(ID_BUTTON18,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&desfire_example_wxWidgetsFrame::OnbtnDEStoAESClick);
    Connect(ID_BUTTON19,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&desfire_example_wxWidgetsFrame::OnbtnGetFreeMemoryClick);
    Connect(ID_BUTTON20,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&desfire_example_wxWidgetsFrame::OnbtnSetRandomIDClick);
    Connect(ID_RADIOBUTTON1,wxEVT_COMMAND_RADIOBUTTON_SELECTED,(wxObjectEventFunction)&desfire_example_wxWidgetsFrame::OnradioSTDSelect);
    Connect(ID_RADIOBUTTON2,wxEVT_COMMAND_RADIOBUTTON_SELECTED,(wxObjectEventFunction)&desfire_example_wxWidgetsFrame::OnradioValueSelect);
    Connect(ID_BUTTON21,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&desfire_example_wxWidgetsFrame::OnbtnMakeFileClick);
    Connect(ID_BUTTON22,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&desfire_example_wxWidgetsFrame::OnbtnDeleteFileClick);
    Connect(ID_BUTTON23,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&desfire_example_wxWidgetsFrame::OnbtnAEStoDESClick);
    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&desfire_example_wxWidgetsFrame::OnQuit);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&desfire_example_wxWidgetsFrame::OnAbout);
    Connect(ID_TIMER1,wxEVT_TIMER,(wxObjectEventFunction)&desfire_example_wxWidgetsFrame::OnTimer1Trigger);
    //*)
}

desfire_example_wxWidgetsFrame::~desfire_example_wxWidgetsFrame()
{
    //(*Destroy(desfire_example_wxWidgetsFrame)
    //*)
}

void desfire_example_wxWidgetsFrame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void desfire_example_wxWidgetsFrame::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}
char* get_result_str(unsigned short card_status, unsigned short exec_time)
{
	static char retstr[4096] = "";
	const char eol[] = "\r\n";
	const char line_separtor[] = "=============";
	char tmpstr[4096];
	bool prn_time;

//	retstr[0] = 0;
	strcpy(retstr, line_separtor);
	strcat(retstr, eol);

	switch (card_status)
	{
	case READER_ERROR:
		strcat(retstr, "Reader error");
		prn_time = false;
		break;

	case NO_CARD_DETECTED:
		strcat(retstr, "Card is not detected");
		prn_time = false;
		break;

	case CARD_OPERATION_OK:
		strcat(retstr, "OK");
		prn_time = true;
		break;

	case DESFIRE_CARD_APPLICATION_NOT_FOUND:
		strcat(retstr, "AID not found");
		prn_time = true;
		break;

	case WRONG_KEY_TYPE:
		strcat(retstr, "Wrong type of key (is not AES)");
		prn_time = true;
		break;

	case KEY_AUTH_ERROR:
		strcat(retstr, "Wrong key");
		prn_time = true;
		break;

	case DESFIRE_CARD_NO_SUCH_KEY:
		strcat(retstr, "Invalid key number");
		prn_time = true;
		break;

	case DESFIRE_CARD_DUPLICATE_ERROR:
		strcat(retstr, "This AID or File ID already exists");
		prn_time = true;
		break;

	case DESFIRE_CARD_PERMISSION_DENIED:
	case DESFIRE_CARD_AUTHENTICATION_ERROR:
		strcat(retstr, "Permission denied");
		prn_time = true;
		break;

	case DESFIRE_CARD_BOUNDARY_ERROR:
		strcat(retstr, "File boundary error");
		prn_time = false;
		break;

	case DESFIRE_CARD_OUT_OF_EEPROM_ERROR:
		strcat(retstr, "Insufficient card memory");
		prn_time = false;
		break;

	case DESFIRE_CARD_NO_CHANGES:
		strcat(retstr, "No changes");
		prn_time = false;
		break;

	case DESFIRE_CARD_ILLEGAL_COMMAND_CODE:
		strcat(retstr, "Not supported command");
		prn_time = false;
		break;

	case DESFIRE_CARD_INTEGRITY_ERROR:
		strcat(retstr, "Not valid crypto data");
		prn_time = false;
		break;

	case DESFIRE_CARD_LENGTH_ERROR:
		strcat(retstr, "Length of command error");
		prn_time = false;
		break;

	case DESFIRE_CARD_PARAMETER_ERROR:
		strcat(retstr, "Command parameter error");
		prn_time = false;
		break;

	case DESFIRE_CARD_APPL_INTEGRITY_ERROR:
		strcat(retstr, "Application structure is not valid");
		prn_time = false;
		break;

	case DESFIRE_CARD_ADDITIONAL_FRAME:
		strcat(retstr, "Additional frame expected");
		prn_time = false;
		break;

	case DESFIRE_CARD_PICC_INTEGRITY_ERROR:
		strcat(retstr, "Card error");
		prn_time = false;
		break;

	case DESFIRE_CARD_COMMAND_ABORTED:
		strcat(retstr, "Command not fully completed");
		prn_time = false;
		break;

	case DESFIRE_CARD_PICC_DISABLED_ERROR:
		strcat(retstr, "Card disabled");
		prn_time = false;
		break;

	case DESFIRE_CARD_COUNT_ERROR:
		strcat(retstr, "Maximal number of applications is reached");
		prn_time = false;
		break;

	case DESFIRE_CARD_EEPROM_ERROR_DES:
		strcat(retstr, "Card internal EEPROM error");
		prn_time = false;
		break;

	case DESFIRE_CARD_FILE_NOT_FOUND:
		strcat(retstr, "File ID not found");
		prn_time = false;
		break;

	case DESFIRE_CARD_FILE_INTEGRITY_ERROR:
		strcat(retstr, "File integrity error");
		prn_time = false;
		break;

     case COMMIT_TRANSACTION_NO_REPLY:
          strcat(retstr, "Response to the commit transaction was not received");
		prn_time = false;
		break;

     case COMMIT_TRANSACTION_ERROR:
          strcat(retstr, "Error occured during the commit transaction");
		prn_time = false;
		break;

	default:
		strcat(retstr, "Unknown status");

		prn_time = false;

		break;
	}

	strcat(retstr, eol);

	// patch
	prn_time = true;
	if (prn_time)
	{
		sprintf(tmpstr, "Execution time of operation = %d ms", (int) exec_time);
		strcat(retstr, tmpstr);
		strcat(retstr, eol);
	}

	return retstr;
}


void convert_str_to_key(std::string key_str, unsigned char *aes_key)
{
    char aes_key_part[8];
	unsigned long key_nr;
	unsigned char temp[4];
	unsigned char i;

       	char *aes_str = (char*)key_str.c_str();

	memset(aes_key_part, 0, 8);
	memcpy(aes_key_part, aes_str, 6);
	key_nr = strtol(aes_key_part, NULL, 16);
	memcpy(temp, (void *) &key_nr, 3);
	for (i = 0; i < 3; i++)
		aes_key[i] = temp[2 - i];

	memset(aes_key_part, 0, 8);
	memcpy(aes_key_part, &aes_str[6], 6);
	key_nr = strtol(aes_key_part, NULL, 16);
	memcpy(temp, (void *) &key_nr, 3);
	for (i = 0; i < 3; i++)
		aes_key[3 + i] = temp[2 - i];

	memset(aes_key_part, 0, 8);
	memcpy(aes_key_part, &aes_str[12], 6);
	key_nr = strtol(aes_key_part, NULL, 16);
	memcpy(temp, (void *) &key_nr, 3);
	for (i = 0; i < 3; i++)
		aes_key[6 + i] = temp[2 - i];

	memset(aes_key_part, 0, 8);
	memcpy(aes_key_part, &aes_str[18], 6);
	key_nr = strtol(aes_key_part, NULL, 16);
	memcpy(temp, (void *) &key_nr, 3);
	for (i = 0; i < 3; i++)
		aes_key[9 + i] = temp[2 - i];

	memcpy(aes_key_part, &aes_str[24], 6);
	key_nr = strtol(aes_key_part, NULL, 16);
	memcpy(temp, (void *) &key_nr, 3);
	for (i = 0; i < 3; i++)
		aes_key[12 + i] = temp[2 - i];

	memset(aes_key_part, 0, 8);
	memcpy(aes_key_part, &aes_str[30], 2);
	key_nr = strtol(aes_key_part, NULL, 16);
	aes_key[15] = key_nr;

}

void desfire_example_wxWidgetsFrame::port_open()
{
UFR_STATUS status;

unsigned char tx_speed, rx_speed;

txtStatus->SetValue("Searching for reader...");

Update();

status = ReaderOpen();

    if (status)
    {
        as = "";
        txtPrintOut->SetValue("");
        txtStatus->SetValue("Communication port is not open");
        as += "ufr_open(): ";
        as += UFR_Status2String(status);
       PRN();
        return;
    }

  txtStatus->SetValue("Communication port is open");

  Timer1.Stop();

  as = GetReaderDescription();

  PRN();

  btnStoreAESKeyIntoReader->Enable(true);

  btnGetCardUID->Enable(true);

  status = GetSpeedParameters(&tx_speed,&rx_speed);

    if (!status)
    {
    cmbTxSpeed->SetSelection(tx_speed);
    cmbRxSpeed->SetSelection(rx_speed);
    }

}

void desfire_example_wxWidgetsFrame::OnTimer1Trigger(wxTimerEvent& event)
{
    port_open();
}

bool desfire_example_wxWidgetsFrame::prepare_key(unsigned char *aes_key)
{

    int aes_key_length;
    std::string key_text;

    txtCardAutAESKey->Refresh();

    key_text = txtCardAutAESKey->GetValue();
    aes_key_length = key_text.length();
    if (aes_key_length != 32)
    {
        txtStatus->SetValue("Key length must be 16 bytes");
        return false;
    }

    convert_str_to_key(key_text,aes_key);

    return true;
}

bool desfire_example_wxWidgetsFrame::prepare_old_key(unsigned char *aes_key)
{

    int aes_key_length;
    std::string key_text;

    txtCardAutAESKey->Refresh();

    key_text = txtKeyOpsOldKey->GetValue();
    aes_key_length = key_text.length();
    if (aes_key_length != 32)
    {
        txtStatus->SetValue("Key length must be 16 bytes");
        return false;
    }

    convert_str_to_key(key_text,aes_key);

    return true;
}

bool desfire_example_wxWidgetsFrame::prepare_new_key(unsigned char *aes_key)
{

    int aes_key_length;
    std::string key_text;

    txtCardAutAESKey->Refresh();

    key_text = txtKeyOpsNewKey->GetValue();
    aes_key_length = key_text.length();
    if (aes_key_length != 32)
    {
        txtStatus->SetValue("Key length must be 16 bytes");
        return false;
    }

    convert_str_to_key(key_text,aes_key);

    return true;
}

bool desfire_example_wxWidgetsFrame::prepare_int_key(unsigned char *aes_key)
{

    int aes_key_length;
    std::string key_text;

    txtCardAutAESKey->Refresh();

    key_text = txtInternKeysOpsAESKey->GetValue();
    aes_key_length = key_text.length();
    if (aes_key_length != 32)
    {
        txtStatus->SetValue("Key length must be 16 bytes");
        return false;
    }

    convert_str_to_key(key_text,aes_key);

    return true;
}


void desfire_example_wxWidgetsFrame::OnbtnChangeAESkeyClick(wxCommandEvent& event)
{

    UFR_STATUS status;

    unsigned short card_status;
	unsigned short exec_time;

	unsigned char aes_key_ext[16];
	unsigned char internal_key, aes_key_nr;
	unsigned long aid;
	unsigned char aid_key_nr_auth, aid_key_nr;
	unsigned char new_aes_key[16];
	unsigned char old_aes_key[16];

	txtPrintOut->Clear();
	txtStatus->SetValue("Operation in progress...");
	Update();

	aid = strtol(txtCardAutAIDBytes->GetValue(),NULL,16);

	aid_key_nr_auth = cmbCardAutAidKeyNrAuth->GetSelection();

    aid_key_nr = cmbKeysOpsAidKeyNr->GetSelection();


    if (chkInternalKeyUsed->IsChecked())
    {
        internal_key = 1;
    } else
    {
        internal_key = 0;
    }

    if (internal_key == 0)
    {
        if (!prepare_key(aes_key_ext))
            {
                return;
            }
    } else
    {
        aes_key_nr = cmbCardAutInternalKeyNr->GetSelection();
    }

    if (!prepare_new_key(new_aes_key))
    {
        return;
    }

    if (aid_key_nr_auth != aid_key_nr)
    {
        if (!prepare_old_key(old_aes_key))
        {
            return;
        }
    }

   if (internal_key)
	{
		status =
				uFR_int_DesfireChangeAesKey(aes_key_nr, aid, aid_key_nr_auth, new_aes_key, aid_key_nr, old_aes_key, &card_status, &exec_time);
	}
	else
	{
		status =
				uFR_int_DesfireChangeAesKey_PK(aes_key_ext, aid, aid_key_nr_auth, new_aes_key, aid_key_nr, old_aes_key, &card_status, &exec_time);
	}

 if (status)
    {
        txtStatus->SetValue("Communication error");
        as += "uFR_int_DesfireCreateAesKey(): ";
        as += UFR_Status2String(status);
        PRN();
        return;
    }
    txtStatus->SetValue("Operation completed");
    as = get_result_str(card_status, exec_time);
    PRN();

    if (card_status==3001)
    {
        txtPrintOut->SetValue("Key stored into card");
    }
}

void desfire_example_wxWidgetsFrame::OnbtnInternalKeyLockClick(wxCommandEvent& event)
{
    unsigned long status;
    std::string pass_text;

    txtPrintOut->Clear();

    pass_text =txtInternKeysPassword->GetValue();

    char *pass_array = new char[pass_text.length()+1];
    strcpy(pass_array,pass_text.c_str());



    status = ReaderKeysLock((const uint8_t*)pass_array);

    if (status == 0)
    {
        txtPrintOut->AppendText("\nInternal keys are locked");
        txtStatus->SetValue("Operation success");
    } else
    {
        if (status == UFR_KEYS_LOCKED)
        {
            txtPrintOut->AppendText("\nInternal keys are already locked");
        } else if (status == UFR_CAN_NOT_LOCK_DEVICE || status == UFR_DEVICE_EEPROM_BUSY)
        {
            txtPrintOut->AppendText("\nInternal keys did not lock");
        }
        txtStatus->SetValue("Operation failed");
    }
}

void desfire_example_wxWidgetsFrame::OnbtnInternalKeyUnlockClick(wxCommandEvent& event)
{
    unsigned long status;
    std::string pass_text;

    txtPrintOut->Clear();

    pass_text =txtInternKeysPassword->GetValue();

    char *pass_array = new char[pass_text.length()+1];
    strcpy(pass_array,pass_text.c_str());



    status = ReaderKeysUnlock((const uint8_t*)pass_array);

    if (status == 0)
    {
        txtPrintOut->AppendText("\nInternal keys are unlocked");
        txtStatus->SetValue("Operation success");
    } else
    {
        if (status == UFR_KEYS_UNLOCKED)
        {
            txtPrintOut->AppendText("\nInternal keys are already unlocked");
        } else if (status == UFR_CAN_NOT_UNLOCK_DEVICE || status == UFR_DEVICE_EEPROM_BUSY)
        {
            txtPrintOut->AppendText("\nInternal keys did not lock");
        }
        txtStatus->SetValue("Operation failed");
    }
}

void desfire_example_wxWidgetsFrame::OnbtnStoreAESKeyIntoReaderClick(wxCommandEvent& event)
{
    UFR_STATUS status;

	unsigned char key_no;
	unsigned char aes_key[16];

	txtPrintOut->Clear();

	key_no = cmbInternKeysOpsIntKeyNr->GetSelection();

	if (!prepare_int_key(aes_key))
    {
        return;
    }

	status = uFR_int_DesfireWriteAesKey(key_no, aes_key);

	if (status)
	{
		if (status == UFR_KEYS_LOCKED)
			txtPrintOut->SetValue("Internal keys are locked");
		txtStatus->SetValue("AES key did not store into reader");
	}
	else
	{
		txtPrintOut->SetValue("OK\n");
		txtStatus->SetValue("AES key stored into reader");
	}

}

void desfire_example_wxWidgetsFrame::OnbtnGetCardUIDClick(wxCommandEvent& event)
{

    UFR_STATUS status;

    unsigned short card_status;
	unsigned short exec_time;

	unsigned char data[BUFFER_SIZE];
	unsigned char data_length;

	unsigned long aid;
	unsigned char aid_key_nr;
	unsigned char aes_key_ext[16];
	unsigned char internal_key, aes_key_nr;

	std::string memory_size;

    txtPrintOut->Clear();
    txtStatus->SetValue("Checking card...");
    Update();

    aid = strtol(txtCardAutAIDBytes->GetValue().c_str(),NULL,16);


    aid_key_nr = cmbCardAutAidKeyNrAuth->GetSelection();


    if (chkInternalKeyUsed->IsChecked())
    {
          internal_key = 1;
    }

    else
    {
        internal_key = 0;
    }

    if (internal_key == 0)
    {
        if (!prepare_key(aes_key_ext));
        {

        }

    } else
    {
        aes_key_nr =cmbCardAutInternalKeyNr->GetSelection();
    }

    if (internal_key)
    {
        status = uFR_int_GetDesfireUid(aes_key_nr, aid, aid_key_nr, data, &data_length, &card_status, &exec_time);

    } else
    {
        status = uFR_int_GetDesfireUid_PK(aes_key_ext, aid, aid_key_nr, data, &data_length, &card_status, &exec_time);
    }

    if (status)
    {
        txtStatus->SetValue("Communication error");

        as += "uFR_int_GetDesfireUid(): ";
        as += UFR_Status2String(status);

        PRN();
        return;

    }

    txtStatus->SetValue("Operation completed");

    txtPrintOut->Clear();
    char hex_data[data_length];
    wxString uid_data = "";
    if (data_length == 11)
    {
        for (int a = 0; a < 7; a++)
        {
        strcpy(hex_data, "");
        sprintf(hex_data,"%02X",data[a]);
        uid_data << hex_data;
        }

        txtPrintOut->AppendText("FACTORY CARD UID = ");
        txtPrintOut->AppendText(uid_data);
        txtPrintOut->AppendText("\n");
    }

    as = get_result_str(card_status, exec_time);

	PRN();

}

void desfire_example_wxWidgetsFrame::OnbtnMakeApplicationClick(wxCommandEvent& event)
{
    UFR_STATUS status;
	unsigned short card_status;
	unsigned short exec_time;

	unsigned char setting, set_temp;
	unsigned long aid;
	unsigned char max_key_no;
	unsigned char authent_req;

	unsigned char aes_key_ext[16];
	unsigned char internal_key, aes_key_nr;

    set_temp = 0;

    if (chkApplicationSettingsNotChangeable->IsChecked())
    {
        set_temp |= 0x04;
    }

    if (chkApplicationCreateDeleteWithMasterKey->IsChecked())
    {
        set_temp |= 0x02;
    }

    if (chkApplicationMasterNotChangeable->IsChecked())
    {
        set_temp |= 0x01;
    }


    switch (set_temp)
	{
	case 0:
		setting = DESFIRE_KEY_SET_CREATE_WITHOUT_AUTH_SET_CHANGE_KEY_CHANGE;
		break;
	case 1:
		setting = DESFIRE_KEY_SET_CREATE_WITHOUT_AUTH_SET_CHANGE_KEY_NOT_CHANGE;
		break;
	case 2:
		setting = DESFIRE_KEY_SET_CREATE_WITH_AUTH_SET_CHANGE_KEY_CHANGE;
		break;
	case 3:
		setting = DESFIRE_KEY_SET_CREATE_WITH_AUTH_SET_CHANGE_KEY_NOT_CHANGE;
		break;
	case 4:
		setting = DESFIRE_KEY_SET_CREATE_WITHOUT_AUTH_SET_NOT_CHANGE_KEY_CHANGE;
		break;
	case 5:
		setting = DESFIRE_KEY_SET_CREATE_WITHOUT_AUTH_SET_NOT_CHANGE_KEY_NOT_CHANGE;
		break;
	case 6:
		setting = DESFIRE_KEY_SET_CREATE_WITH_AUTH_SET_NOT_CHANGE_KEY_CHANGE;
		break;
	case 7:
		setting = DESFIRE_KEY_SET_CREATE_WITH_AUTH_SET_NOT_CHANGE_KEY_NOT_CHANGE;
		break;
	}

    aid = strtol(txtApplicationAIDBytes->GetValue(), NULL, 16);

    max_key_no = cmbApplicationMaxKeyNr->GetSelection();

    if (chkCardAutMasterKeyAuthenticationReq->IsChecked())
    {
        authent_req = 1;
    } else
    {
        authent_req = 0;
    }

    if (chkInternalKeyUsed->IsChecked())
    {
        internal_key = 1;
    } else
    {
        internal_key = 0;
    }

    if (internal_key == 0)
    {

    if (!prepare_key(aes_key_ext))
    {
        return;

    }

    } else
    {
        aes_key_nr =  cmbCardAutInternalKeyNr->GetSelection();
    }

    txtPrintOut->Clear();
    txtStatus->SetValue("Operation in progress..");
    Update();

    if (authent_req)
	{
		if (internal_key)
		{
			status = uFR_int_DesfireCreateAesApplication(aes_key_nr, aid, setting, max_key_no, &card_status, &exec_time);
		}
		else
		{
			status = uFR_int_DesfireCreateAesApplication_PK(aes_key_ext, aid, setting, max_key_no, &card_status, &exec_time);
		}
	} else
	{
		status = uFR_int_DesfireCreateAesApplication_no_auth(aid, setting, max_key_no, &card_status, &exec_time);
	}

	if (status)
    {
        txtStatus->SetValue("Communication error");

       as += "uFR_int_DesfireCreateApplication(): ";
       as += UFR_Status2String(status);

        return;
    }

    txtStatus->SetValue("Operation completed");
    as = get_result_str(card_status,exec_time);
    PRN();

    if (card_status == 3001)
    {
        txtPrintOut->AppendText("\nApplication created");
    }
}

void desfire_example_wxWidgetsFrame::OnbtnDeleteApplicationClick(wxCommandEvent& event)
{
    UFR_STATUS status;
	unsigned short card_status;
	unsigned short exec_time;

	unsigned long aid;

	unsigned char aes_key_ext[16];
	unsigned char internal_key, aes_key_nr;

	aid = strtol(cmbApplicationMaxKeyNr->GetValue(),NULL,16);

    if (chkInternalKeyUsed->IsChecked())
    {
        internal_key = 1;
    } else
    {
        internal_key = 0;
    }

    if (internal_key == 0)
    {
        if (!prepare_key(aes_key_ext))
        {
            return;
        }
    } else
    {
        aes_key_nr =cmbCardAutInternalKeyNr->GetSelection();
    }

    txtPrintOut->Clear();
    txtStatus->SetValue("Operation in progres...");
    Update();

    if (internal_key)
	{
		status = uFR_int_DesfireDeleteApplication(aes_key_nr, aid, &card_status, &exec_time);
	}
	else
	{
		status = uFR_int_DesfireDeleteApplication_PK(aes_key_ext, aid, &card_status, &exec_time);
	}

	if (status)
	{
		txtStatus->SetValue("Communication error");

		as += "uFR_int_DesfireDeleteApplication(): ";
        as += UFR_Status2String(status);

		PRN();
		return;
	}

	txtStatus->SetValue("Operation completed");
	Update();

	as = get_result_str(card_status,exec_time);
	PRN();

	if (card_status == 3001)
    {
        txtPrintOut->SetValue("Application deleted");
        PRN();
    }
}

void desfire_example_wxWidgetsFrame::OnbtnMakeFileClick(wxCommandEvent& event)
{
    UFR_STATUS status;
	unsigned short card_status;
	unsigned short exec_time;

	unsigned long aid;
	unsigned long file_size;
	unsigned char auth_req;
	int temp_int;
	unsigned char communication_settings;
	unsigned char file_id;
	unsigned char read_key_nr, write_key_nr, read_write_key_nr, change_key_nr;

	unsigned char aes_key_ext[16];
	unsigned char internal_key, aes_key_nr;
     long lower_limit, upper_limit, value;
     unsigned char limited_credit_enabled;

     aid = strtol(txtCardAutAIDBytes->GetValue(), NULL, 16);

     read_key_nr = cmbFileReadKey->GetSelection();
     write_key_nr = cmbFileWriteKey->GetSelection();
     read_write_key_nr = cmbFileReadWrite->GetSelection();
     change_key_nr = cmbFileChangeKey->GetSelection();

     file_id = cmbFileFileID->GetSelection();

     file_size = strtol(txtFileSizeOfFile->GetValue(),NULL,10);

     lower_limit = strtol(txtFileLowerLimit->GetValue(),NULL,10);

     upper_limit = strtol(txtFileUpperLimit->GetValue(),NULL,10);

     value = strtol(txtFileValue->GetValue(),NULL,10);

     if (chkLimitedCredit->IsChecked())
     {
         limited_credit_enabled = 1;
     }
     else
     {
          limited_credit_enabled = 0;
     }

     if (chkFreeGetValue->IsChecked())
     {
         limited_credit_enabled |= 0x02;
     }

     if (chkCardAutMasterKeyAuthenticationReq->IsChecked())
     {
         auth_req = 1;
     } else
     {
         auth_req = 0;
     }

     temp_int = cmbFileCommMode->GetSelection();

     switch (temp_int)
	{
	case 0:
		communication_settings = 0;
		break;
	case 1:
		communication_settings = 1;
		break;
	case 2:
		communication_settings = 3;
		break;
	default:
		communication_settings = 0;
		break;
	}

	if (chkInternalKeyUsed->IsChecked())
    {
        internal_key = 1;
    } else
    {
        internal_key = 0;
    }
    if (internal_key == 0)
    {
        if (!prepare_key(aes_key_ext))
    {
        return;
    }
    } else
    {
        aes_key_nr = cmbCardAutInternalKeyNr->GetSelection();
    }


    txtPrintOut->Clear();
    txtStatus->SetValue("Operation in progress...");
    Update();

    if (auth_req)
	{
		if (internal_key)
		{
               if(radioSTD->GetValue())
			     status = uFR_int_DesfireCreateStdDataFile(aes_key_nr, aid, file_id, file_size, read_key_nr, write_key_nr, read_write_key_nr, change_key_nr, communication_settings, &card_status, &exec_time);
               else
        {
                status = uFR_int_DesfireCreateValueFile(aes_key_nr, aid, file_id,
                         lower_limit, upper_limit, value, limited_credit_enabled,
                         read_key_nr, write_key_nr, read_write_key_nr, change_key_nr,
                         communication_settings, &card_status, &exec_time);
               }

		}
		else
		{
               if(radioSTD->GetValue())
			     status = uFR_int_DesfireCreateStdDataFile_PK(aes_key_ext, aid, file_id, file_size, read_key_nr, write_key_nr, read_write_key_nr, change_key_nr, communication_settings, &card_status, &exec_time);
               else
               {
                   status = uFR_int_DesfireCreateValueFile_PK(aes_key_ext, aid, file_id,
                         lower_limit, upper_limit, value, limited_credit_enabled,
                         read_key_nr, write_key_nr, read_write_key_nr, change_key_nr,
                         communication_settings, &card_status, &exec_time);
                }
		}
	} else
	{
          if(radioSTD->GetValue())
		     status = uFR_int_DesfireCreateStdDataFile_no_auth(aid, file_id, file_size, read_key_nr, write_key_nr, read_write_key_nr, change_key_nr, communication_settings, &card_status, &exec_time);
          else {
               status = uFR_int_DesfireCreateValueFile_no_auth(aid, file_id,
                    lower_limit, upper_limit, value, limited_credit_enabled,
                    read_key_nr, write_key_nr, read_write_key_nr, change_key_nr,
                    communication_settings, &card_status, &exec_time);
                }
	}

	if (status)
    {
        txtStatus->SetValue("Communication error");
        as = "";
        as += "uFR_int_DesfireCreateFile(): ";
        as += UFR_Status2String(status);

		PRN();
		return;

    }
    txtStatus->SetValue("Operation completed");

    as = get_result_str(card_status, exec_time);
	PRN();

    if (card_status == 3001)
    {
        txtPrintOut->AppendText("File created");
    }


}



void desfire_example_wxWidgetsFrame::OnbtnDeleteFileClick(wxCommandEvent& event)
{

    UFR_STATUS status;
	unsigned short card_status;
	unsigned short exec_time;

	unsigned char auth_req, file_no;

	unsigned char aes_key_ext[16];
	unsigned char internal_key, aes_key_nr;
	unsigned long aid;

    file_no = cmbFileFileID->GetSelection();

    if (chkCardAutMasterKeyAuthenticationReq->IsChecked())
    {
        auth_req = 1;
    } else
    {
        auth_req = 0;
    }

    if(chkInternalKeyUsed->IsChecked())
    {
        internal_key = 1;
    } else
    {
        internal_key = 0;
    }

    if(internal_key == 0)
    {
    if (!prepare_key(aes_key_ext))
    {
        return;
    }

    } else
    {
        aes_key_nr = cmbCardAutInternalKeyNr->GetSelection();
    }

    aid = strtol(txtCardAutAIDBytes->GetValue(), NULL, 16);

    txtPrintOut->Clear();
    txtStatus->SetValue("");
    Update();

    if (auth_req)
	{
		if (internal_key)
		{
			status = uFR_int_DesfireDeleteFile(aes_key_nr, aid, file_no, &card_status, &exec_time);
		}
		else
		{
			status = uFR_int_DesfireDeleteFile_PK(aes_key_ext, aid, file_no, &card_status, &exec_time);
		}
	}
	else
	{
		status = uFR_int_DesfireDeleteFile_no_auth(aid, file_no, &card_status, &exec_time);
	}

	if (status)
    {
        txtStatus->SetValue("Communication error");

        as = "";
        as += "uFR_int_DesfireCreateStdDataFile_no_auth(): ";
        as += UFR_Status2String(status);

		PRN();
		return;

    }

    txtStatus->SetValue("Operation completed");
    Update();

    as = get_result_str(card_status,exec_time);
    PRN();

    if(card_status == 3001)
    {
        txtPrintOut->SetValue("File deleted");
        PRN();
    }

}

void desfire_example_wxWidgetsFrame::OnbtnGetKeySettingsClick(wxCommandEvent& event)
{

    UFR_STATUS status;
	unsigned short card_status;
	unsigned short exec_time;

	unsigned char setting, set_temp = 0;
	unsigned char max_key_no;

	unsigned char aes_key_ext[16];
	unsigned char internal_key, aes_key_nr;
	unsigned long aid;

    txtPrintOut->Clear();
    txtStatus->SetValue("Operation in progress...");
    Update();

    aid = strtol(cmbKeysOpsAidKeyNr->GetStringSelection(), NULL, 16);

    if (chkInternalKeyUsed->IsChecked())
    {
        internal_key = 1;
    } else
    {
        internal_key = 0;
    }

    if (internal_key == 0)
	{
		if (!prepare_key(aes_key_ext))
        {
            return;
            //return;
        }

	}
	else
	{
		aes_key_nr = cmbCardAutInternalKeyNr->GetSelection();
	}

	if (internal_key)
	{
		status = uFR_int_DesfireGetKeySettings(aes_key_nr, aid, &setting, &max_key_no, &card_status, &exec_time);
	}
	else
	{
		status = uFR_int_DesfireGetKeySettings_PK(aes_key_ext, aid, &setting, &max_key_no, &card_status, &exec_time);
	}

	if (status)
	{
		txtStatus->SetValue("Communication error");

		as += "uFR_int_DesfireGetKeySettings(): ";
        as += UFR_Status2String(status);

		PRN();
		return;
	}

	txtStatus->SetValue("Operation completed");
	Update();

	as = get_result_str(card_status,exec_time);
	PRN();

	if (card_status == 3001)
    {
        txtPrintOut->AppendText("Read out key settings\n");
        txtPrintOut->AppendText("Maximal number of keys into application:");
        txtPrintOut->AppendText(std::to_string(max_key_no));
        PRN();


        setting &= 0x0F;

		switch (setting)
		{
		case DESFIRE_KEY_SET_CREATE_WITHOUT_AUTH_SET_CHANGE_KEY_CHANGE:
			set_temp = 0;
			break;
		case DESFIRE_KEY_SET_CREATE_WITHOUT_AUTH_SET_CHANGE_KEY_NOT_CHANGE:
			set_temp = 1;
			break;
		case DESFIRE_KEY_SET_CREATE_WITH_AUTH_SET_CHANGE_KEY_CHANGE:
			set_temp = 2;
			break;
		case DESFIRE_KEY_SET_CREATE_WITH_AUTH_SET_CHANGE_KEY_NOT_CHANGE:
			set_temp = 3;
			break;
		case DESFIRE_KEY_SET_CREATE_WITHOUT_AUTH_SET_NOT_CHANGE_KEY_CHANGE:
			set_temp = 4;
			break;
		case DESFIRE_KEY_SET_CREATE_WITHOUT_AUTH_SET_NOT_CHANGE_KEY_NOT_CHANGE:
			set_temp = 5;
			break;
		case DESFIRE_KEY_SET_CREATE_WITH_AUTH_SET_NOT_CHANGE_KEY_CHANGE:
			set_temp = 6;
			break;
		case DESFIRE_KEY_SET_CREATE_WITH_AUTH_SET_NOT_CHANGE_KEY_NOT_CHANGE:
			set_temp = 7;
			break;
		}
        if (set_temp & 0x04)
			chkKeyOpsSettingsNotChangeable->SetValue(true);
		else
			chkKeyOpsSettingsNotChangeable->SetValue(false);
		if (set_temp & 0x02)
			chkKeysOpsCreateDeleteWithMasterKeyAuth->SetValue(true);
		else
			chkKeysOpsCreateDeleteWithMasterKeyAuth->SetValue(false);
		if (set_temp & 0x01)
			chkKeysOpsMasterNotChangeable->SetValue(true);
		else
			chkKeysOpsMasterNotChangeable->SetValue(false);

    }
}

void desfire_example_wxWidgetsFrame::OnbtnChangeKeySettingsClick(wxCommandEvent& event)
{
    UFR_STATUS status;
	unsigned short card_status;
	unsigned short exec_time;

	unsigned char setting;

	unsigned char aes_key_ext[16];
	unsigned char internal_key, aes_key_nr, set_temp;
	unsigned long aid;

    txtPrintOut->SetValue("");

    txtStatus->SetValue("Operation in progress...");
    Update();

    set_temp = 0;

    if (chkKeyOpsSettingsNotChangeable->IsChecked())
    {
        set_temp |= 0x04;
    }

    if (chkKeysOpsCreateDeleteWithMasterKeyAuth->IsChecked())
    {
        set_temp |= 0x02;
    }

    if (chkKeysOpsMasterNotChangeable->IsChecked())
    {
        set_temp |= 0x01;
    }

    switch (set_temp)
	{
	case 0:
		setting = DESFIRE_KEY_SET_CREATE_WITHOUT_AUTH_SET_CHANGE_KEY_CHANGE;
		break;
	case 1:
		setting = DESFIRE_KEY_SET_CREATE_WITHOUT_AUTH_SET_CHANGE_KEY_NOT_CHANGE;
		break;
	case 2:
		setting = DESFIRE_KEY_SET_CREATE_WITH_AUTH_SET_CHANGE_KEY_CHANGE;
		break;
	case 3:
		setting = DESFIRE_KEY_SET_CREATE_WITH_AUTH_SET_CHANGE_KEY_NOT_CHANGE;
		break;
	case 4:
		setting = DESFIRE_KEY_SET_CREATE_WITHOUT_AUTH_SET_NOT_CHANGE_KEY_CHANGE;
		break;
	case 5:
		setting = DESFIRE_KEY_SET_CREATE_WITHOUT_AUTH_SET_NOT_CHANGE_KEY_NOT_CHANGE;
		break;
	case 6:
		setting = DESFIRE_KEY_SET_CREATE_WITH_AUTH_SET_NOT_CHANGE_KEY_CHANGE;
		break;
	case 7:
		setting = DESFIRE_KEY_SET_CREATE_WITH_AUTH_SET_NOT_CHANGE_KEY_NOT_CHANGE;
		break;
	}

    aid = strtol(cmbKeysOpsAidKeyNr->GetStringSelection(), NULL, 16);

    if (chkInternalKeyUsed->IsChecked())
    {
        internal_key = 1;
    } else
    {
        internal_key = 0;
    }

    if (internal_key == 0)
	{
		if (!prepare_key(aes_key_ext))
        {
            return;
        }

	}
	else
	{
		aes_key_nr = cmbCardAutInternalKeyNr->GetSelection();
	}

	if (internal_key)
	{
		status = uFR_int_DesfireChangeKeySettings(aes_key_nr, aid, setting, &card_status, &exec_time);
	}
	else
	{
		status = uFR_int_DesfireChangeKeySettings_PK(aes_key_ext, aid, setting, &card_status, &exec_time);
	}

    if (status)
    {
        txtStatus->SetValue("Communication error");

       as += "uFR_int_DesfireChangeKeySettings(): ";
       as += UFR_Status2String(status);

       PRN();

        return;
    }

    txtStatus->SetValue("Operation completed");

    as = get_result_str(card_status,exec_time);

    if (card_status == 3001)
    {
        txtPrintOut->SetValue("Key settings stored into card");
    }

}

void desfire_example_wxWidgetsFrame::OnbtnReadValueClick(wxCommandEvent& event)
{

    UFR_STATUS status;
	unsigned short card_status = 0;
	unsigned short exec_time;

	unsigned char communication_settings;
	unsigned char aes_key_ext[16];
	unsigned char internal_key, aes_key_nr;
	unsigned long aid;
	unsigned char file_id, auth_req, aid_key_nr;
    int file_value;

    txtPrintOut->Clear();
    txtStatus->SetValue("Operation in progress...");
    Update();

    switch(cmbValueFileOpsCommMode->GetSelection())
    {
    case 0:
        communication_settings = 0;
        break;
    case 1:
        communication_settings = 1;
        break;
    case 2:
        communication_settings = 3;
        break;
    default:
        communication_settings = 0;
    }

    aid = strtol(txtCardAutAIDBytes->GetValue(), NULL, 16);

    aid_key_nr = cmbCardAutAidKeyNrAuth->GetSelection();

    file_id = cmbCardAutFileID->GetSelection();

    if(chkInternalKeyUsed->IsChecked())
    {
        internal_key = 1;
    } else
    {
        internal_key = 0;
    }

    if (internal_key == 0)
    {
        if (!prepare_key(aes_key_ext))
        {
            return;
        }

        } else
        {
            aes_key_nr =cmbCardAutInternalKeyNr->GetSelection();
        }

    if (chkCardAutMasterKeyAuthenticationReq->IsChecked())
    {
        auth_req = 1;
    } else
    {
        auth_req = 0;
    }

    if (auth_req)
	{
		if (internal_key)
		{
			status =  uFR_int_DesfireReadValueFile(aes_key_nr, aid, aid_key_nr, file_id,
                              communication_settings, &file_value, &card_status, &exec_time);
		}
		else
		{
			status = 	uFR_int_DesfireReadValueFile_PK(aes_key_ext, aid, aid_key_nr, file_id,
                              communication_settings, &file_value, &card_status, &exec_time);
		}
	}
	else
	{
		status =  uFR_int_DesfireReadValueFile_no_auth(aid, aid_key_nr, file_id,
                              communication_settings, &file_value, &card_status, &exec_time);
	}

    txtValueFileOpsValue->SetValue("");

    if (status)
    {
        txtStatus->SetValue("Communication error");

       as += "uFR_int_DesfireReadValueFile(): ";
       as += UFR_Status2String(status);

       PRN();

        return;

    }

    txtStatus->SetValue("Operation completed");

    as = get_result_str(card_status,exec_time);
    PRN();

    if (card_status == 3001)
    {
        txtPrintOut->SetValue("File value was read");
        txtValueFileOpsValue->SetValue(std::to_string(file_value));
    } else
    {
        txtPrintOut->SetValue("File value was not read");
    }

}

void desfire_example_wxWidgetsFrame::OnbtnIncreaseValueClick(wxCommandEvent& event)
{

    UFR_STATUS status;
	unsigned short card_status = 0;
	unsigned short exec_time;

	unsigned char communication_settings;
	unsigned char aes_key_ext[16];
	unsigned char internal_key, aes_key_nr;
	unsigned long aid;
	unsigned char file_id = 0, auth_req, aid_key_nr;
    unsigned int file_value;

    txtPrintOut->Clear();
    txtStatus->SetValue("Operation in progress...");
    Update();

    switch(cmbValueFileOpsCommMode->GetSelection())
    {
    case 0:
        communication_settings = 0;
        break;
    case 1:
        communication_settings = 1;
        break;
    case 2:
        communication_settings = 3;
        break;
    default:
        communication_settings = 0;
    }

    aid = strtol(txtCardAutAIDBytes->GetValue().c_str(), NULL, 16);

    aid_key_nr = cmbCardAutAidKeyNrAuth->GetSelection();

    file_value = strtol(txtValueFileOpsValue->GetValue().c_str(), NULL, 10);

    if(chkInternalKeyUsed->IsChecked())
    {
        internal_key = 1;
    } else
    {
        internal_key = 0;
    }

    if (internal_key == 0)
    {
        if(!prepare_key(aes_key_ext))
        {
            return;
        }
    } else
    {
        aes_key_nr = cmbCardAutInternalKeyNr->GetSelection();
    }

    if(chkCardAutMasterKeyAuthenticationReq->IsChecked())
    {
        auth_req = 1;
    } else
    {
        auth_req = 0;
    }

        if (auth_req)
	{
		if (internal_key)
		{
			status =  uFR_int_DesfireIncreaseValueFile(aes_key_nr, aid, aid_key_nr, file_id,
                              communication_settings, file_value, &card_status, &exec_time);
		}
		else
		{
			status = 	uFR_int_DesfireIncreaseValueFile_PK(aes_key_ext, aid, aid_key_nr, file_id,
                              communication_settings, file_value, &card_status, &exec_time);
		}
	}
	else
	{
		status =  uFR_int_DesfireIncreaseValueFile_no_auth(aid, aid_key_nr, file_id,
                              communication_settings, file_value, &card_status, &exec_time);
	}

	if (status)
    {
        txtStatus->SetValue("Communication error");

       as += "uFR_int_DesfireIncreaseValueFile(): ";
       as += UFR_Status2String(status);

       PRN();

        return;

    }

    txtStatus->SetValue("Operation completed");

    as = get_result_str(card_status,exec_time);
    PRN();

    if (card_status == 3001)
    {
        txtPrintOut->SetValue("File value was increased");
        txtValueFileOpsValue->SetValue(std::to_string(file_value));
    } else
    {
        txtPrintOut->SetValue("File value was not increased");
    }

}

void desfire_example_wxWidgetsFrame::OnbtnDecreaseValueClick(wxCommandEvent& event)
{
    UFR_STATUS status;
	unsigned short card_status = 0;
	unsigned short exec_time;

	unsigned char communication_settings;
	unsigned char aes_key_ext[16];
	unsigned char internal_key, aes_key_nr;
	unsigned long aid;
	unsigned char file_id = 0, auth_req, aid_key_nr;
    unsigned int file_value;

    txtPrintOut->Clear();
    txtStatus->SetValue("Operation in progress...");
    Update();

    switch(cmbValueFileOpsCommMode->GetSelection())
    {
    case 0:
        communication_settings = 0;
        break;
    case 1:
        communication_settings = 1;
        break;
    case 2:
        communication_settings = 3;
        break;
    default:
        communication_settings = 0;
    }

    aid = strtol(txtCardAutAIDBytes->GetValue().c_str(), NULL, 16);

    aid_key_nr = cmbCardAutAidKeyNrAuth->GetSelection();

    file_value = strtol(txtValueFileOpsValue->GetValue().c_str(), NULL, 10);

    if(chkInternalKeyUsed->IsChecked())
    {
        internal_key = 1;
    } else
    {
        internal_key = 0;
    }

    if (internal_key == 0)
    {
        if(!prepare_key(aes_key_ext))
        {
            return;
        }
    } else
    {
        aes_key_nr = cmbCardAutInternalKeyNr->GetSelection();
    }

    if(chkCardAutMasterKeyAuthenticationReq->IsChecked())
    {
        auth_req = 1;
    } else
    {
        auth_req = 0;
    }

        if (auth_req)
	{
		if (internal_key)
		{
			status =  uFR_int_DesfireDecreaseValueFile(aes_key_nr, aid, aid_key_nr, file_id,
                              communication_settings, file_value, &card_status, &exec_time);
		}
		else
		{
			status = 	uFR_int_DesfireDecreaseValueFile_PK(aes_key_ext, aid, aid_key_nr, file_id,
                              communication_settings, file_value, &card_status, &exec_time);
		}
	}
	else
	{
		status =  uFR_int_DesfireDecreaseValueFile_no_auth(aid, aid_key_nr, file_id,
                              communication_settings, file_value, &card_status, &exec_time);
	}

	if (status)
    {
        txtStatus->SetValue("Communication error");

       as += "uFR_int_DesfireDecreaseValueFile(): ";
       as += UFR_Status2String(status);

       PRN();

        return;

    }

    txtStatus->SetValue("Operation completed");

    as = get_result_str(card_status,exec_time);
    PRN();

    if (card_status == 3001)
    {
        txtPrintOut->SetValue("File value was decreased");
        txtValueFileOpsValue->SetValue(std::to_string(file_value));
    } else
    {
        txtPrintOut->SetValue("File value was not decreased");
    }
}

void desfire_example_wxWidgetsFrame::OnradioSTDSelect(wxCommandEvent& event)
{
chkLimitedCredit->Disable();
chkFreeGetValue->Disable();
txtFileLowerLimit->Disable();
txtFileUpperLimit->Disable();
txtFileValue->Disable();
txtFileSizeOfFile->Enable();
}

void desfire_example_wxWidgetsFrame::OnradioValueSelect(wxCommandEvent& event)
{
chkLimitedCredit->Enable();
chkFreeGetValue->Enable();
txtFileLowerLimit->Enable();
txtFileUpperLimit->Enable();
txtFileValue->Enable();
txtFileSizeOfFile->Disable();
}



void desfire_example_wxWidgetsFrame::OnButton17Click(wxCommandEvent& event)
{
    UFR_STATUS status;
	unsigned short card_status;
	unsigned short exec_time;

	unsigned char internal_key, aes_key_nr;
	unsigned char aes_key_ext[16];

	if(chkInternalKeyUsed->IsChecked())
    {
        internal_key = 1;
    } else
    {
        internal_key = 0;
    }

    if (internal_key == 0)
    {
        if(!prepare_key(aes_key_ext))
        {
            return;
        }
    } else
    {
        aes_key_nr = cmbCardAutInternalKeyNr->GetSelection();
    }

    txtPrintOut->Clear();
    txtStatus->SetValue("Operation in progress...");
    Update();

    if (internal_key)
	{
		status = uFR_int_DesfireFormatCard(aes_key_nr, &card_status, &exec_time);
	}
	else
	{
		status = uFR_int_DesfireFormatCard_PK(aes_key_ext, &card_status, &exec_time);
	}

	if(status)
    {
        txtStatus->SetValue("Command was not redceived || Confirmation was not received");
        as += "uFR_int_DesfireDecreaseValueFile(): ";
        as += UFR_Status2String(status);

        PRN();

        return;
    }

    txtStatus->SetValue("Operation is completed");

    as = get_result_str(card_status,exec_time);
    PRN();

    if (card_status == 3001)
    {
        txtPrintOut->AppendText("Card is formatted");
    }

}

void desfire_example_wxWidgetsFrame::OnbtnGetFreeMemoryClick(wxCommandEvent& event)
{
    UFR_STATUS status;
	unsigned short card_status;
	unsigned short exec_time;

	uint32_t mem_size;

    txtPrintOut->Clear();
    txtStatus->SetValue("Operation in progress...");
    Update();

    status = uFR_int_DesfireFreeMem(&mem_size, &card_status, &exec_time);

    if(status)
    {
        txtStatus->SetValue("Communication error");
        as += "uFR_int_DesfireFreeMem(): ";
        as += UFR_Status2String(status);
        PRN();

        return;
    }

    txtStatus->SetValue("Operation is completed");
    Update();

    as = get_result_str(card_status, exec_time);
	PRN();

    if(card_status == 3001)
    {
        as+="Free memory in card is: " + std::to_string(mem_size) + " bytes";
        PRN();

    }

}

void desfire_example_wxWidgetsFrame::OnbtnDEStoAESClick(wxCommandEvent& event)
{
    unsigned long status;
    unsigned char i, res;

    txtPrintOut->Clear();
    txtStatus->SetValue("Card operation in progress...");
    Update();

    res = 0;


    for (i=0; i<10; i++)
    {
        status = DES_to_AES_key_type();

            if (!status)
            {
                txtStatus->SetValue("Operation succesful");
                txtPrintOut->AppendText("Key type is changed to AES");
                txtPrintOut->AppendText("New AES key is 00000000000000000000000000000000");
                res = 1;
                ReaderUISignal(1,3);
                break;
            }
    }

    if (res == 0)
    {
        txtStatus->SetValue("operation failed");
        txtPrintOut->AppendText("Key type has not been changed");
    }

}

void desfire_example_wxWidgetsFrame::OnbtnSetRandomIDClick(wxCommandEvent& event)
{
    UFR_STATUS status;
	unsigned short card_status;
	unsigned short exec_time;

	unsigned char internal_key, aes_key_nr;
	unsigned char aes_key_ext[16];

	if(chkInternalKeyUsed->IsChecked())
    {
        internal_key = 1;
    } else
    {
        internal_key = 0;
    }

    if (internal_key == 0)
    {
        if(!prepare_key(aes_key_ext))
        {
            return;
        }
    } else
    {
        aes_key_nr = cmbCardAutInternalKeyNr->GetSelection();
    }

    txtPrintOut->Clear();
    txtStatus->SetValue("Operation in progress");
    Update();

    if (internal_key)
	{
		status = uFR_int_DesfireSetConfiguration(aes_key_nr, 1, 0, &card_status, &exec_time);
	}else
	{
		status = uFR_int_DesfireSetConfiguration_PK(aes_key_ext, 1, 0, &card_status, &exec_time);
	}

	if(status)
    {
        txtStatus->SetValue("Communication error");
        as+="\nuFR_int_DesfireSetConfiguration(): ";
        as+=UFR_Status2String(status);
        PRN();

        return;
    }

    txtStatus->SetValue("Operation completed");

    as = get_result_str(card_status,exec_time);
    PRN();

    if(card_status == 3001)
    {
        txtPrintOut->AppendText("\nRandom ID is set");
    }
}

void desfire_example_wxWidgetsFrame::OnbtnGetBaudRateClick(wxCommandEvent& event)
{
    unsigned char tx_speed, rx_speed;
    GetSpeedParameters(&tx_speed,&rx_speed);
    cmbTxSpeed->SetSelection(tx_speed);
    cmbRxSpeed->SetSelection(rx_speed);
}

void desfire_example_wxWidgetsFrame::OnbtnSetBaudRateClick(wxCommandEvent& event)
{
    SetSpeedPermanently(cmbTxSpeed->GetSelection(),cmbRxSpeed->GetSelection());
}

void desfire_example_wxWidgetsFrame::OnbtnFileWritingClick(wxCommandEvent& event)
{
    UFR_STATUS status;
	unsigned short card_status = 0;
	unsigned short exec_time;

	unsigned char file_data[10000];
	unsigned short file_length;
	unsigned char communication_settings;
	int temp;

	unsigned char aes_key_ext[16];
	unsigned char internal_key, aes_key_nr;
	unsigned long aid;
	unsigned char file_id, auth_req, aid_key_nr;

    stdFileWriteDialog->ShowModal();

    FILE *stream;

    stream = fopen(stdFileWriteDialog->GetPath().c_str(), "rb");

    long curpos, length;

    curpos = ftell(stream);
	fseek(stream, 0L, SEEK_END);
	length = ftell(stream);
	fseek(stream, curpos, SEEK_SET);

    wxString wxFileLen = "";
    wxFileLen << length;

    txtStdFileReadWriteSizeOfFile->SetValue(wxFileLen);

    wxFileLen = "";

    txtPrintOut->Clear();
    txtStatus->SetValue("Operation in progress...");
    Update();

    wxFileLen = txtStdFileReadWriteSizeOfFile->GetValue();

    file_length = wxAtoi(wxFileLen);

    wxFileLen = "";

    temp = chkStdFileReadWriteCommMode->GetSelection();

    switch (temp)
	{
    case 0:
		communication_settings = 0;
		break;
	case 1:
		communication_settings = 1;
		break;
	case 2:
		communication_settings = 3;
		break;
	default:
		communication_settings = 0;
		break;
	}

    aid = strtol(txtCardAutAIDBytes->GetValue().c_str(),NULL,16);

    aid_key_nr = cmbCardAutAidKeyNrAuth->GetSelection();

    file_id = cmbCardAutFileID->GetSelection();

    if(chkInternalKeyUsed->IsChecked())
    {
        internal_key = 1;
    } else
    {
        internal_key = 0;
    }

    if (internal_key == 0)
    {
        if(!prepare_key(aes_key_ext))
        {
            return;
        }
    } else
    {
        aes_key_nr = cmbCardAutInternalKeyNr->GetSelection();
    }

    if (chkCardAutMasterKeyAuthenticationReq->IsChecked())
    {
        auth_req = 1;
    } else
    {
        auth_req = 0;
    }

    fread(file_data,file_length,1,stream);
    fclose(stream);

    if (auth_req)
	{
		if (internal_key)
		{
			status = uFR_int_DesfireWriteStdDataFile(aes_key_nr, aid, aid_key_nr, file_id, 0, file_length, communication_settings, file_data, &card_status, &exec_time);
		}
		else
		{
			status = uFR_int_DesfireWriteStdDataFile_PK(aes_key_ext, aid, aid_key_nr, file_id, 0, file_length, communication_settings,file_data, &card_status, &exec_time);
		}
        }
        else
        {
            status = uFR_int_DesfireWriteStdDataFile_no_auth(aid, aid_key_nr, file_id, 0, file_length, communication_settings, file_data, &card_status, &exec_time);
        }


	if(status)
    {
        txtStatus->SetValue("Communication error");

        as += "\nuFR_int_DesfireWriteData(): ";
        as += UFR_Status2String(status);
        PRN();

        return;
    }

    txtStatus->SetValue("Operation completed");

    as = get_result_str(card_status, exec_time);
    PRN();

    if(card_status == 3001)
    {
        txtPrintOut->AppendText("\nFile stored into card");
    } else
    {
        txtPrintOut->AppendText("\nFile was not stored into card");
    }
}

void desfire_example_wxWidgetsFrame::OnbtnFileReadingClick(wxCommandEvent& event)
{

    UFR_STATUS status;
	unsigned short card_status = 0;
	unsigned short exec_time;

	unsigned short file_length;
	unsigned char communication_settings;
	FILE *stream;
	unsigned char file_data[10000];

	unsigned char aes_key_ext[16];
	unsigned char internal_key, aes_key_nr;
	unsigned long aid;
	unsigned char file_id, auth_req, aid_key_nr;

    stdFileWriteDialog->ShowModal();
    stream = fopen(stdFileWriteDialog->GetPath().c_str(), "wb");


    txtPrintOut->Clear();
    txtStatus->SetValue("Operation in progress...");
    Update();

    wxString wxFileLen = txtStdFileReadWriteSizeOfFile->GetValue();

    file_length = wxAtoi(wxFileLen);

    switch (chkStdFileReadWriteCommMode->GetSelection())
	{
	case 0:
		communication_settings = 0;
		break;
	case 1:
		communication_settings = 1;
		break;
	case 2:
		communication_settings = 3;
		break;
	default:
		communication_settings = 0;
		break;
	}

	aid = strtol(txtCardAutAIDBytes->GetValue(),NULL,16);

	aid_key_nr = cmbCardAutAidKeyNrAuth->GetSelection();

	file_id = cmbCardAutFileID->GetSelection();

	if(chkInternalKeyUsed->IsChecked())
    {
        internal_key = 1;
    } else
    {
        internal_key = 0;
    }

    if (internal_key == 0)
    {
        if(!prepare_key(aes_key_ext))
        {
            return;
        }
    } else
    {
        aes_key_nr = cmbCardAutInternalKeyNr->GetSelection();
    }

    if (chkCardAutMasterKeyAuthenticationReq->IsChecked())
    {
        auth_req = 1;
    }

	else
    {
        auth_req = 0;
    }

	if (auth_req)
	{
		if (internal_key)
		{
			status =
					uFR_int_DesfireReadStdDataFile(aes_key_nr, aid, aid_key_nr, file_id, 0, file_length, communication_settings, file_data, &card_status, &exec_time);
		}
		else
		{
			status =
					uFR_int_DesfireReadStdDataFile_PK(aes_key_ext, aid, aid_key_nr, file_id, 0, file_length, communication_settings, file_data, &card_status, &exec_time);
		}
	}
	else
	{
		status =
				uFR_int_DesfireReadStdDataFile_no_auth(aid, aid_key_nr, file_id, 0, file_length, communication_settings, file_data, &card_status, &exec_time);
	}

	if(status)
    {
        txtStatus->SetValue("Communication error");

        as += "\n uFR_int_DesfireReadData(): ";
        as += UFR_Status2String(status);
        PRN();

        return;
    }

    fwrite(file_data, file_length, 1, stream);
    fclose(stream);

    txtStatus->SetValue("Operation completed");

    as = get_result_str(card_status, exec_time);
    PRN();

    if(card_status == 3001)
    {
        txtPrintOut->AppendText("\nFile was read");
    } else
    {
        txtPrintOut->AppendText("\nFile was not read");
    }







}


void desfire_example_wxWidgetsFrame::OnbtnAEStoDESClick(wxCommandEvent& event)
{
    unsigned long status;
    unsigned char i, res;

    txtPrintOut->Clear();
    txtStatus->SetValue("Card operation in progress...");
    Update();

    res = 0;


    for (i=0; i<10; i++)
    {
        status = AES_to_DES_key_type();

            if (!status)
            {
                txtStatus->SetValue("Operation succesful");
                txtPrintOut->AppendText("Key type is changed to DES");
                txtPrintOut->AppendText("New AES key is 0000000000000000 ");
                res = 1;
                ReaderUISignal(1,3);
                break;
            }
    }

    if (res == 0)
    {
        txtStatus->SetValue("operation failed");
        txtPrintOut->AppendText("Key type has not been changed");
    }

}
