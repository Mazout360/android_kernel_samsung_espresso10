/*
 * Remote processor messaging
 *
 * Copyright(c) 2011 Texas Instruments. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * * Redistributions of source code must retain the above copyright
 *   notice, this list of conditions and the following disclaimer.
 * * Redistributions in binary form must reproduce the above copyright
 *   notice, this list of conditions and the following disclaimer in
 *   the documentation and/or other materials provided with the
 *   distribution.
 * * Neither the name Texas Instruments nor the names of its
 *   contributors may be used to endorse or promote products derived
 *   from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef _PLAT_RPMSG_H
#define _PLAT_RPMSG_H

/*
 * enum - Predefined Mailbox Messages
 *
 * @RP_MBOX_READY: informs the M3's that we're up and running. will be
 * followed by another mailbox message that carries the A9's virtual address
 * of the shared buffer. This would allow the A9's drivers to send virtual
 * addresses of the buffers.
 *
 * @RP_MBOX_PENDING_MSG: informs the receiver that there is an inbound
 * message waiting in its own receive-side vring. please note that currently
 * this message is optional: alternatively, one can explicitly send the index
 * of the triggered virtqueue itself. the preferred approach will be decided
 * as we progress and experiment with those design ideas.
 *
 * @RP_MBOX_CRASH: this message is sent upon a BIOS exception
 *
 * @RP_MBOX_ECHO_REQUEST: a mailbox-level "ping" message.
 *
 * @RP_MBOX_ECHO_REPLY: a mailbox-level reply to a "ping"
 *
 * @RP_MBOX_ABORT_REQUEST: a "please crash" request, used for testing the
 * recovery mechanism (to some extent). will trigger a @RP_MBOX_CRASH reply.
 *
 * @RP_MSG_BOOTINIT_DONE: this message is sent by remote processor once it has
 * completed some essential initialization during its boot. This notification
 * is used to relax any constraints put in to speed up the remote processor
 * boot.
 */
enum {
	RP_MBOX_READY		= 0xFFFFFF00,
	RP_MBOX_PENDING_MSG	= 0xFFFFFF01,
	RP_MBOX_CRASH		= 0xFFFFFF02,
	RP_MBOX_ECHO_REQUEST	= 0xFFFFFF03,
	RP_MBOX_ECHO_REPLY	= 0xFFFFFF04,
	RP_MBOX_ABORT_REQUEST	= 0xFFFFFF05,
	RP_MSG_BOOTINIT_DONE	= 0xFFFFFF08,
};

extern char *rpmsg_cam_regulator_name[];

#endif /* _PLAT_RPMSG_H */
