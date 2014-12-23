//========================================================================
//	AppWindow.cpp
//	
//	Copyright 2005-2009 Sergey Kazenyuk, All Rights Reserved.
//	Distributed under the terms of the MIT License.
//========================================================================
//	$Id: AppWindow.cpp 12 2009-02-02 08:51:09Z sergey.kazenyuk $
//	$Rev: 12 $
//	$Author: sergey.kazenyuk $
//	$Date: 2009-02-02 10:51:09 +0200 (Mon, 02 Feb 2009) $
//========================================================================

#include <string>

#include "AppWindow.h"
#include "App.h"

//====================================================================

void Generator(char* password, const int &num, const char* symbols);

//====================================================================

AppWindow::AppWindow(BRect frame)
	: BWindow(frame, App_Name, B_TITLED_WINDOW,
		B_NOT_RESIZABLE|B_NOT_ZOOMABLE)
{
	MainView = new AppView(Bounds());
	AddChild(MainView);
	
	PassOut = new RandoTextView(BRect(5,25,200,40), "PassOut",
		BRect(0,0,200,30), be_bold_font, NULL, B_FOLLOW_LEFT|B_FOLLOW_TOP,
		B_WILL_DRAW|B_NAVIGABLE);
	PassOut->MakeEditable(false);
	MainView->AddChild(PassOut);
			
	ParamsBox = new RandoBox(BRect(5,50,200,146), "ParamsBox", "", B_FOLLOW_LEFT|B_FOLLOW_TOP,
		B_WILL_DRAW|B_NAVIGABLE, B_FANCY_BORDER);
	MainView->AddChild(ParamsBox);
	
	PassLength = new BTextControl(BRect(5,5,189,40), "PassLength", "Password length", NULL,
		new BMessage(SEQ_LEN_MSG), B_FOLLOW_LEFT|B_FOLLOW_TOP, B_NAVIGABLE);
	ParamsBox->AddChild(PassLength);
	PassLength->SetText("11");
	//PassLength->AttachedToWindow();
	//PassLength->ResizeToPreferred();
	
	UpperCaseCB = new BCheckBox(BRect(5,30,85,30), "UpperCaseCB", "Upper case",
		new BMessage(UCASE_CB_MSG), B_FOLLOW_LEFT|B_FOLLOW_TOP, B_WILL_DRAW | B_NAVIGABLE);
	UpperCaseCB->SetValue(B_CONTROL_ON);
	ParamsBox->AddChild(UpperCaseCB);
	
	LowerCaseCB = new BCheckBox(BRect(5,50,85,30), "LowerCaseCB", "Lower case",
		new BMessage(LCASE_CB_MSG), B_FOLLOW_LEFT|B_FOLLOW_TOP, B_WILL_DRAW | B_NAVIGABLE);
	LowerCaseCB->SetValue(B_CONTROL_ON);
	ParamsBox->AddChild(LowerCaseCB);
	
	NumCB = new BCheckBox(BRect(5,70,85,30), "NumCB", "Numbers",
		new BMessage(NUMBERS_CB_MSG), B_FOLLOW_LEFT|B_FOLLOW_TOP, B_WILL_DRAW | B_NAVIGABLE);
	NumCB->SetValue(B_CONTROL_ON);
	ParamsBox->AddChild(NumCB);
	
	SpecSymbCB = new BCheckBox(BRect(105,30,185,30), "SpecSymbCB", "Special",
		new BMessage(SPEC_SYMB_CB_MSG), B_FOLLOW_LEFT|B_FOLLOW_TOP, B_WILL_DRAW | B_NAVIGABLE);
	ParamsBox->AddChild(SpecSymbCB);
	
	//Custom symbols checkbox
	CustSymbCB = new BCheckBox(BRect(105,50,185,30), "CustSymbCB", "Custom:",
		new BMessage(CUST_SYMB_CB_MSG), B_FOLLOW_LEFT|B_FOLLOW_TOP, B_WILL_DRAW | B_NAVIGABLE);
	ParamsBox->AddChild(CustSymbCB);
	
	//Custom symbols input field
	CustSymb = new BTextControl(BRect(110,70,189,40), "CustSymb", "", NULL,
		new BMessage(CUST_SYMB_MSG), B_FOLLOW_LEFT|B_FOLLOW_TOP, B_NAVIGABLE);
	CustSymb->SetDivider(0);
	CustSymb->SetEnabled(false);
	ParamsBox->AddChild(CustSymb);	
			
	GenerateBtn = new BButton(BRect(70,151,65,30), "GenBtn", "Generate",
		new BMessage(GEN_BTN_MSG), B_NAVIGABLE);
	GenerateBtn->MakeDefault(true);
	GenerateBtn->ResizeToPreferred();
	MainView->AddChild(GenerateBtn);
	
	SetupMenuBar();
}

//--------------------------------------------------------------------

bool AppWindow::QuitRequested()
{
	be_app->PostMessage(B_QUIT_REQUESTED);
	return true;
}

//--------------------------------------------------------------------

void AppWindow::MessageReceived(BMessage* message)
{
#ifdef DEBUG	
	printf("AppWindow::MessageReceived: \n"); 
	message->PrintToStream();
#endif
	switch(message->what)
	{
		case GEN_BTN_MSG:
		{
			const char en_upsymbols[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
			const char en_lowsymbols[] = "abcdefghijklmnopqrstuvwxyz";
			const char num_symbols[] = "0123456789";
			const char spec_symbols[] = "!@#$%^&*";	//<-------
			
			PassOut->SetText("");
			
			string* symbols = new string;
			if (UpperCaseCB->Value() == B_CONTROL_ON)
				*symbols += en_upsymbols;
			if (LowerCaseCB->Value() == B_CONTROL_ON)
				*symbols += en_lowsymbols;
			if (NumCB->Value() == B_CONTROL_ON)
				*symbols += num_symbols;
			if (SpecSymbCB->Value() == B_CONTROL_ON)
				*symbols += spec_symbols;
			if (CustSymbCB->Value() == B_CONTROL_ON)
				*symbols += CustSymb->Text();
			int pass_length = atoi(PassLength->Text());
			char* password = new char [pass_length];			
			Generator(password, pass_length, symbols->c_str());
			delete symbols;
			PassOut->SetText(password);
			delete[] password;
		}
		break;
		case CUST_SYMB_CB_MSG:	//Custom symbols checkbox set/unset
			if (CustSymbCB->Value() == B_CONTROL_ON)
				CustSymb->SetEnabled(true);
			else
				CustSymb->SetEnabled(false);
		break;
		case B_ABOUT_REQUESTED:
			be_app->PostMessage(B_ABOUT_REQUESTED);
		break;
		default:
			BWindow::MessageReceived(message);
	}
}

//--------------------------------------------------------------------

void AppWindow::SetupMenuBar()
{
	MenuBar = new RandoMenuBar(BRect(0,0,0,0), "menubar",
		B_FOLLOW_LEFT_RIGHT|B_FOLLOW_TOP, B_ITEMS_IN_ROW, true);
	MainView->AddChild(MenuBar);
	
	FileMenu = new BMenu("File");
	MenuBar->AddItem(FileMenu);
	
	AboutFileMenuItem = new BMenuItem("About", new BMessage(B_ABOUT_REQUESTED),
		0, 0);
	FileMenu->AddItem(AboutFileMenuItem);
	
	FileMenu->AddSeparatorItem();
	
	QuitFileMenuItem = new BMenuItem("Quit", new BMessage(B_QUIT_REQUESTED),
		'Q', 0);
	FileMenu->AddItem(QuitFileMenuItem);
}

