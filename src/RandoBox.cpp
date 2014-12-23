//========================================================================
//	RandoBox.cpp
//	
//	Copyright 2005 Sergey Kazenyuk, All Rights Reserved.
//	Distributed under the terms of the MIT License.
//========================================================================

#include "RandoBox.h"

//====================================================================

RandoBox::RandoBox(BRect frame, const char *name, const char *label,
			uint32 resizeMask, uint32 flags, border_style style)
	:BBox(frame, name, resizeMask, flags, style)
{
	SetLabel(label);
}
