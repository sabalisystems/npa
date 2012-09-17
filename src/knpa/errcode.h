/* -
 * Copyright (c) 2012 by itopia.pl team.
 * Author: Lukasz Marcin Podkalicki <lukasz@podkalicki.com>
 */

#ifndef	_KNPA_ERRCODE_H_
#define	_KNPA_ERRCODE_H_

#define	EKNPA_OK		(0)
#define	EKNPA_MEMORY		(1)
#define	EKNPA_PARAM		(2)
#define	EKNPA_NFHOOKREGISTER	(3)

const char *knpa_strerror(int err);

#endif	/* !_KNPA_ERRCODE_H_ */
