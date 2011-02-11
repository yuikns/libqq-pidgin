/**
 * file qq_base.h
 *
 * purple
 *
 * Purple is the legal property of its developers, whose names are too numerous
 * to list here.  Please refer to the COPYRIGHT file distributed with this
 * source distribution.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02111-1301  USA
 */

#ifndef _QQ_BASE_H_
#define _QQ_BASE_H_

#include <glib.h>
#include "connection.h"

#define QQ_LOGIN_REPLY_OK							0x00
#define QQ_TOUCH_REPLY_REDIRECT				0x01
/* defined by myself */
#define QQ_LOGIN_REPLY_CAPTCHA_DLG			0xfd
#define QQ_LOGIN_REPLY_NEXT_CAPTCHA		0xfe
#define QQ_LOGIN_REPLY_ERR							0xff

#define QQ_LOGIN_MODE_NORMAL		0x0a
#define QQ_LOGIN_MODE_AWAY	    	0x1e
#define QQ_LOGIN_MODE_HIDDEN		0x28

#define QQ_UPDATE_ONLINE_INTERVAL   300	/* in sec */

static guint8 header_fill[] = {
	0x02, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x00, 0x00, 0x64,
	0x1F	/* varies by versions */
};

static guint8 touch_fill[] = {
	0x00, 0x01,
	0x00, 0x00, 0x04, 0x09, 0x01, 0xE0,		/* touch Data1*/
	0x00, 0x00, 0x03, 0x30, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x0B, 0xC5		/* touch Data2 */
};

static guint8 auth_key[][16] = {
	{ 0x31, 0x84, 0xFD, 0x03, 0xDB, 0x59, 0x5A, 0x4A, 0xA6, 0x71, 0x1B, 0x11, 0x41, 0x3A, 0x87, 0x91 },
	{ 0xC5, 0xF6, 0xF7, 0xEC, 0x10, 0xCB, 0x98, 0xE2, 0xE2, 0x75, 0x77, 0xF3, 0xE7, 0x06, 0x28, 0xF3 },
	{ 0x7E, 0xD6, 0xF3, 0x98, 0xB1, 0x03, 0xE9, 0xC8, 0x96, 0x32, 0x72, 0x4F, 0x7E, 0x2E, 0x7B, 0xD0 }
};
guint8 qq_process_login( PurpleConnection *gc, guint8 *data, gint data_len);

void qq_request_logout(PurpleConnection *gc);

void qq_request_keep_alive(PurpleConnection *gc);
gboolean qq_process_keep_alive(guint8 *data, gint data_len, PurpleConnection *gc);

/* for QQ2010 */
void qq_request_touch_server(PurpleConnection *gc);
guint16 qq_process_touch_server(PurpleConnection *gc, guint8 *rcved, gint rcved_len);

void qq_request_captcha(PurpleConnection *gc);
void qq_request_captcha_next(PurpleConnection *gc);
guint8 qq_process_captcha(PurpleConnection *gc, guint8 *buf, gint buf_len);
void qq_captcha_input_dialog(PurpleConnection *gc,qq_captcha_data *captcha);

void qq_request_auth(PurpleConnection *gc);
guint8 qq_process_auth( PurpleConnection *gc, guint8 *data, gint data_len);

void qq_request_verify_E5(PurpleConnection *gc);
guint8 qq_process_verify_E5(PurpleConnection *gc, guint8 *data, guint8 data_len);

void qq_request_verify_E3(PurpleConnection *gc);
guint8 qq_process_verify_E3(PurpleConnection *gc, guint8 *data, guint8 data_len);

void qq_request_login(PurpleConnection *gc);
guint8 qq_process_login( PurpleConnection *gc, guint8 *data, gint data_len);

void qq_request_login_E9(PurpleConnection *gc);
void qq_request_login_EA(PurpleConnection *gc);
void qq_request_login_EB(PurpleConnection *gc);
void qq_request_login_EC(PurpleConnection *gc);
void qq_request_login_ED(PurpleConnection *gc);

#endif