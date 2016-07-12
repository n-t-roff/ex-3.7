/*
 * CDDL HEADER START
 *
 * The contents of this file are subject to the terms of the
 * Common Development and Distribution License, Version 1.0 only
 * (the "License").  You may not use this file except in compliance
 * with the License.
 *
 * You can obtain a copy of the license at usr/src/OPENSOLARIS.LICENSE
 * or http://www.opensolaris.org/os/licensing.
 * See the License for the specific language governing permissions
 * and limitations under the License.
 *
 * When distributing Covered Code, include this CDDL HEADER in each
 * file and include the License file at usr/src/OPENSOLARIS.LICENSE.
 * If applicable, add the following below this CDDL HEADER, with the
 * fields enclosed by brackets "[]" replaced with your own identifying
 * information: Portions Copyright [yyyy] [name of copyright owner]
 *
 * CDDL HEADER END
 */
/*
 * Copyright 2004 Sun Microsystems, Inc.  All rights reserved.
 * Use is subject to license terms.
 */

/*
#pragma ident	"%Z%%M%	%I%	%E% SMI"
*/

/*LINTLIBRARY*/
#include <sys/types.h>
#include <malloc.h>

#ifdef HAVE_MALLINFO
struct  mallinfo __mallinfo;
#endif

/*
 * mallopt -- Do nothing
 */
/*ARGSUSED*/
int
mallopt(int cmd, int value)
{
	(void)cmd;
	(void)value;
	return (0);
}


/*
 * mallinfo -- Do nothing
 */
#ifdef HAVE_MALLINFO
struct mallinfo
mallinfo(void)
{
	return (__mallinfo);
}
#endif