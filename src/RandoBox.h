//========================================================================
//	RandoBox.h
//	
//	Copyright 2005 Sergey Kazenyuk, All Rights Reserved.
//	Distributed under the terms of the MIT License.
//========================================================================

#ifndef RANDOBOX_H
#define RANDOBOX_H

#include <Box.h>

//====================================================================

class RandoBox : public BBox
{
	public:
						RandoBox(BRect frame, const char *name,
							const char *label,
							uint32 resizeMask=B_FOLLOW_LEFT | B_FOLLOW_TOP,
							uint32 flags=B_WILL_DRAW | B_NAVIGABLE,
							border_style style=B_FANCY_BORDER);			
};

#endif
