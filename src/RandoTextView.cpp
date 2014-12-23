//========================================================================
//	RandoTextView.cpp
//	
//	Copyright 2005 Sergey Kazenyuk, All Rights Reserved.
//	Distributed under the terms of the MIT License.
//========================================================================

#include "RandoTextView.h"

//====================================================================

RandoTextView::RandoTextView(BRect frame, const char *name,
				BRect textRect, const BFont *font,
				const rgb_color *color, uint32 resizingMode, uint32 flags)
	:BTextView(frame, name, textRect, font, color, resizingMode, flags)
{
	
}
