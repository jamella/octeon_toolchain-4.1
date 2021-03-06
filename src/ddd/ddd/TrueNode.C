// $Id: TrueNode.C,v 1.1.1.1 2006/04/11 21:46:36 cchavva Exp $
// Abbreviations for frequently used VSL nodes

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

char TrueNode_rcsid[] = 
    "$Id: TrueNode.C,v 1.1.1.1 2006/04/11 21:46:36 cchavva Exp $";

#include "TrueNode.h"

DEFINE_TYPE_INFO_1(EmptyListNode, ConstNode)
DEFINE_TYPE_INFO_1(FalseNode,     ConstNode)
DEFINE_TYPE_INFO_1(NullNode,      ConstNode)
DEFINE_TYPE_INFO_1(NumNode,       ConstNode)
DEFINE_TYPE_INFO_1(StringNode,    ConstNode)
DEFINE_TYPE_INFO_1(TrueNode,      ConstNode)
DEFINE_TYPE_INFO_1(FixListNode,   ListNode)

// FixListNode

// GCC 2.8.1 doesn't like these inlined, so we place them in the .C file
FixListNode::FixListNode(VSLNode *arg)
    : ListNode(arg, new EmptyListNode)
{}

FixListNode::FixListNode(VSLNode *arg1, VSLNode *arg2)
    : ListNode(arg1, new FixListNode(arg2))
{}

FixListNode::FixListNode(VSLNode *arg1, VSLNode *arg2, VSLNode *arg3)
    : ListNode(arg1, new FixListNode(arg2, arg3))
{}

FixListNode::FixListNode(VSLNode *arg1, VSLNode *arg2,
			 VSLNode *arg3, VSLNode *arg4)
    : ListNode(arg1, new FixListNode(arg2, arg3, arg4))
{}
