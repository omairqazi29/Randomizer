//========================================================================
//	RandoTextView.h
//	
//	Copyright 2005 Sergey Kazenyuk, All Rights Reserved.
//	Distributed under the terms of the MIT License.
//========================================================================

#ifndef RANDOTEXTVIEW_H
#define RANDOTEXTVIEW_H

#include <TextView.h>

//====================================================================

class RandoTextView : public BTextView
{
	public:
							RandoTextView(BRect frame, const char *name,
								BRect textRect,
								const BFont *font, const rgb_color *color,
								uint32 resizingMode,
								uint32 flags);
};

#endif
