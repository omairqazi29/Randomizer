//========================================================================
//	RandoMenuBar.h
//	
//	Copyright 2005 Sergey Kazenyuk, All Rights Reserved.
//	Distributed under the terms of the MIT License.
//========================================================================

#ifndef RANDOMENUBAR_H
#define RANDOMENUBAR_H

#include <MenuBar.h>

//====================================================================

class RandoMenuBar : public BMenuBar
{
	public:
							RandoMenuBar(BRect frame, const char *name,
								uint32 resizingMode, menu_layout layout,
								bool resizeToFit);
};

#endif
