/* -
 * Copyright (c) 2012 by itopia.pl team.
 * Author: Lukasz Marcin Podkalicki <lukasz@podkalicki.com>
 */

#include <linux/errno.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/if.h>
#include <linux/skbuff.h>
#include <net/addrconf.h>
#include <linux/netdevice.h>
#include <linux/inetdevice.h>
#include <linux/netfilter.h>
#include <linux/netfilter_ipv4.h>
#include <linux/netfilter_ipv6.h>
#include <linux/in.h>
#include <linux/ip.h>
#include <linux/ipv6.h>
#include <linux/udp.h>
#include <linux/tcp.h>
#include <net/ip.h>
#include <net/dst.h>
#include <net/tcp.h>
#include <net/route.h>
#include <net/ip6_route.h>

#include "misc.h"
#include "log.h"
#include "errcode.h"

static unsigned int knpa_hook(unsigned int hooknum, struct sk_buff *skb,
	const struct net_device *in, const struct net_device *out,
	int (*okfn) (struct sk_buff *));

static unsigned int knpa6_hook(unsigned int hooknum, struct sk_buff *skb,
	const struct net_device *in, const struct net_device *out,
	int (*okfn) (struct sk_buff *));

/**
 * Static array of nf_hook_ops.
 */
static struct nf_hook_ops knpa_ops[] = {
	{ .hook = knpa_hook, .owner = THIS_MODULE, .pf = PF_INET, .hooknum = NF_IP_PRE_ROUTING, .priority = NF_IP6_PRI_FIRST },
        { .hook = knpa_hook, .owner = THIS_MODULE, .pf = PF_INET, .hooknum = NF_IP_POST_ROUTING, .priority = NF_IP6_PRI_FIRST },
        { .hook = knpa_hook, .owner = THIS_MODULE, .pf = PF_INET, .hooknum = NF_IP_LOCAL_OUT, .priority = NF_IP6_PRI_FIRST },	
	{ .hook = knpa6_hook, .owner = THIS_MODULE, .pf = PF_INET6, .hooknum = NF_IP6_PRE_ROUTING, .priority = NF_IP6_PRI_FIRST },
	{ .hook = knpa6_hook, .owner = THIS_MODULE, .pf = PF_INET6, .hooknum = NF_IP6_POST_ROUTING, .priority = NF_IP6_PRI_FIRST },
	{ .hook = knpa6_hook, .owner = THIS_MODULE, .pf = PF_INET6, .hooknum = NF_IP6_LOCAL_OUT, .priority = NF_IP6_PRI_FIRST }
};

/**
 * Register NPA netfilter hooks.
 */
static int
knpa_register_netfilter_hooks(void)
{
	int i, j;
	
	for (i = 0; i < sizeof(knpa_ops) / sizeof(struct nf_hook_ops); i++) {
		if (nf_register_hook(&knpa_ops[i]) < 0) {				
			for (j = 0; j < i; j++)
				nf_unregister_hook(&knpa_ops[j]);
			return EKNPA_NFHOOKREGISTER;
		}
	}
	
	return EKNPA_OK;
}

/**
 * Unregister NPA netfilter hooks.
 */
static void
knpa_unregister_netfilter_hooks(void)
{
	int i;
	
	for (i = 0; i < sizeof(knpa_ops) / sizeof(struct nf_hook_ops); i++)
		nf_unregister_hook(&knpa_ops[i]);
}

/**
 * Initialize NPA module.
 */
static int __init
knpa_init(void)
{
	int err;
	
	if ((err = knpa_register_netfilter_hooks()) != EKNPA_OK) {
		knpa_error("NPA module not inited - netfilter hooks registration has failed!\n");
		return err;
	}
		
	knpa_info("Module NPA inited successfuly\n");
	
	return EKNPA_OK;
}

/**
 * Finalize NPA module.
 */
static void __exit
knpa_exit(void)
{
	
	knpa_unregister_netfilter_hooks();
	knpa_info("Module NPA exited successfuly\n");
}

/**
 * NP netfiter hook for IPv4 packets.
 */
unsigned int
knpa_hook(unsigned int hooknum, struct sk_buff *skb, const struct net_device *in,
		       const struct net_device *out, int (*okfn) (struct sk_buff *))
{	

	knpa_debug("############# RECEIVED IPv4 PACKET ##############");
	return NF_ACCEPT;
}

/**
 * NP netfiter hook for IPv6 packets.
 */
unsigned int
knpa6_hook(unsigned int hooknum, struct sk_buff *skb, const struct net_device *in,
                       const struct net_device *out, int (*okfn) (struct sk_buff *))
{

        knpa_debug("############# RECEIVED IPv6 PACKET ##############");
        return NF_ACCEPT;
}


module_init(knpa_init);
module_exit(knpa_exit);

MODULE_AUTHOR("Lukasz Marcin Podkalicki <lukasz@podkalicki.com>");
MODULE_DESCRIPTION("Linux kernel module for NPA (Netwok Packet Analyzer)");
MODULE_LICENSE("LGPL");
