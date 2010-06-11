;/****************************************************************************
;**
;** Copyright (C) 2010 Nokia Corporation and/or its subsidiary(-ies).
;** All rights reserved.
;** Contact: Nokia Corporation (qt-info@nokia.com)
;**
;** This file is part of the QtGui module of the Qt Toolkit.
;**
;** $QT_BEGIN_LICENSE:LGPL$
;** No Commercial Usage
;** This file contains pre-release code and may not be distributed.
;** You may use this file in accordance with the terms and conditions
;** contained in the Technology Preview License Agreement accompanying
;** this package.
;**
;** GNU Lesser General Public License Usage
;** Alternatively, this file may be used under the terms of the GNU Lesser
;** General Public License version 2.1 as published by the Free Software
;** Foundation and appearing in the file LICENSE.LGPL included in the
;** packaging of this file.  Please review the following information to
;** ensure the GNU Lesser General Public License version 2.1 requirements
;** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
;**
;** In addition, as a special exception, Nokia gives you certain additional
;** rights.  These rights are described in the Nokia Qt LGPL Exception
;** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
;**
;** If you have questions regarding the use of this file, please contact
;** Nokia at qt-info@nokia.com.
;**
;**
;**
;**
;**
;**
;**
;**
;** $QT_END_LICENSE$
;**
;****************************************************************************/
	.SPACE $PRIVATE$
	.SUBSPA $DATA$,QUAD=1,ALIGN=8,ACCESS=31
	.SUBSPA $BSS$,QUAD=1,ALIGN=8,ACCESS=31,ZERO,SORT=82
	.SPACE $TEXT$
	.SUBSPA $LIT$,QUAD=0,ALIGN=8,ACCESS=44
	.SUBSPA $CODE$,QUAD=0,ALIGN=8,ACCESS=44,CODE_ONLY
	.IMPORT $global$,DATA
	.IMPORT $$dyncall,MILLICODE
	.SPACE $TEXT$
	.SUBSPA $CODE$

	.align 4
	.EXPORT q_ldcw,ENTRY,PRIV_LEV=3,ARGW0=GR,RTNVAL=GR
q_ldcw
	.PROC
	.CALLINFO FRAME=0,CALLS,SAVE_RP
	.ENTRY
	ldcw 0(%r26),%r1
	bv %r0(%r2)
	copy %r1,%r28
	.EXIT
	.PROCEND
