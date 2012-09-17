/* -
 * Copyright (c) 2012 by itopia.pl team.
 * Author: Lukasz Marcin Podkalicki <lukasz@podkalicki.com>
 */

#ifndef	_KNPA_MISC_H_
#define	_KNPA_MISC_H_

/* Netfilter constatns if not defined */
#ifndef	NF_IP_PRE_ROUTING
# define	NF_IP_PRE_ROUTING	(0)
#endif

#ifndef	NF_IP_LOCAL_IN
# define	NF_IP_LOCAL_IN		(1)
#endif

#ifndef	NF_IP_FORWARD
# define	NF_IP_FORWARD		(2)
#endif

#ifndef	NF_IP_LOCAL_OUT
# define	NF_IP_LOCAL_OUT		(3)
#endif

#ifndef	NF_IP_POST_ROUTING
# define	NF_IP_POST_ROUTING	(4)
#endif

#ifndef	NF_IP6_PRE_ROUTING
# define	NF_IP6_PRE_ROUTING	(0)
#endif

#ifndef	NF_IP6_LOCAL_IN
# define	NF_IP6_LOCAL_IN		(1)
#endif

#ifndef	NF_IP6_FORWARD
# define	NF_IP6_FORWARD		(2)
#endif

#ifndef	NF_IP6_LOCAL_OUT
# define	NF_IP6_LOCAL_OUT	(3)
#endif

#ifndef	NF_IP6_POST_ROUTING
# define	NF_IP6_POST_ROUTING	(4)
#endif

#endif	/* !_KNPA_MISC_H_ */
