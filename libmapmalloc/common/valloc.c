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
 * Copyright (c) 1991-1997, Sun Microsytems, Inc.
 */

/*
#pragma ident	"%Z%%M%	%I%	%E% SMI"
*/

/*LINTLIBRARY*/
#include <sys/types.h>
#include <stdlib.h>
#include <errno.h>

/*
 * valloc(size) - do nothing
 */

/*ARGSUSED*/
void *
valloc(size_t size)
{
	(void)size;
	return (0);
}


/*
 * memalign(align,nbytes) - do nothing
 */

/*ARGSUSED*/
void *
memalign(size_t align, size_t nbytes)
{
	(void)align;
	(void)nbytes;
	errno = EINVAL;
	return (NULL);
}