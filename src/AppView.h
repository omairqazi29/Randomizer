//========================================================================
//	AppView.h
//	
//	Copyright 2005 Sergey Kazenyuk, All Rights Reserved.
//	Distributed under the terms of the MIT License.
//========================================================================

#ifndef APPVIEW_H
#define APPVIEW_H

#include <View.h>

//====================================================================

class AppView : public BView
{
	public:
						AppView(BRect frame);
		virtual void	Draw(BRect updateRect);
		//virtual void	MessageReceived(BMessage* message);
	private:
		
};
	
#endif

