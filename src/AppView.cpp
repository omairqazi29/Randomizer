//========================================================================
//	AppView.cpp
//	
//	Copyright 2005 Sergey Kazenyuk, All Rights Reserved.
//	Distributed under the terms of the MIT License.
//========================================================================

#include "AppView.h"

//====================================================================

AppView::AppView(BRect frame)
	: BView(frame, "AppView", B_FOLLOW_ALL_SIDES, B_WILL_DRAW)
{
	SetViewColor(ui_color(B_PANEL_BACKGROUND_COLOR));
}

//--------------------------------------------------------------------
	
void AppView::Draw(BRect updateRect)
{
	
}

