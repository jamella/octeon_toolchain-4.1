// $Id: converters.h,v 1.1.1.1 2006/04/11 21:46:36 cchavva Exp $
// Own converters

// Copyright (C) 1995 Technische Universitaet Braunschweig, Germany.
// Written by Andreas Zeller <zeller@gnu.org>.
// 
// This file is part of DDD.
// 
// DDD is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public
// License as published by the Free Software Foundation; either
// version 2 of the License, or (at your option) any later version.
// 
// DDD is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
// See the GNU General Public License for more details.
// 
// You should have received a copy of the GNU General Public
// License along with DDD -- see the file COPYING.
// If not, write to the Free Software Foundation, Inc.,
// 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
// 
// DDD is the data display debugger.
// For details, see the DDD World-Wide-Web page, 
// `http://www.gnu.org/software/ddd/',
// or send a mail to the DDD developers <ddd@gnu.org>.

#ifndef _DDD_converters_h
#define _DDD_converters_h

#include <X11/Intrinsic.h>

// Convert String to OnOff
Boolean CvtStringToOnOff(Display *display, 
			 XrmValue *args, Cardinal *num_args, 
			 XrmValue *fromVal, XrmValue *toVal,
			 XtPointer *converter_data);

// Register all converters
extern void registerOwnConverters();

// Define a macro: @NAME@ will be replaced by VALUE in CvtStringToXmString
void defineConversionMacro(const _XtString name, const _XtString value);

#endif // _DDD_converters_h
// DON'T ADD ANYTHING BEHIND THIS #endif
