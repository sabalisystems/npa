/* -
 * Copyright (c) 2012 by itopia.pl team.
 * Author: Lukasz Marcin Podkalicki <lukasz@podkalicki.com>
 */

#ifndef	_KNPA_LOG_H_
#define	_KNPA_LOG_H_

#ifndef	__GNUC__
# define	__attribute__(x) /*NOTHING*/
#endif

#define	knpa_log(...)		printk(KERN_INFO  __VA_ARGS__)
#define	knpa_error(...)		printk(KERN_ERR "[ KNPA_ERROR ] " __VA_ARGS__)
#define	knpa_warning(...)	printk(KERN_WARNING "[ KNPA_WARN  ] " __VA_ARGS__)
#define	knpa_info(...)		printk(KERN_INFO "[ KNPA_INFO  ] " __VA_ARGS__)
#define	knpa_debug(...)		printk(KERN_DEBUG "[ KNPA_DEBUG ] " __VA_ARGS__)

#endif	/* !_KNPA_LOG_H_ */
