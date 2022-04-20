/*
 * ijkplayer_internal.h
 *
 * Copyright (c) 2013 Bilibili
 * Copyright (c) 2013 Zhang Rui <bbcallen@gmail.com>
 *
 * This file is part of ijkPlayer.
 *
 * ijkPlayer is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * ijkPlayer is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with ijkPlayer; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */

#ifndef IJKPLAYER_ANDROID__IJKPLAYER_INTERNAL_H
#define IJKPLAYER_ANDROID__IJKPLAYER_INTERNAL_H

#include <assert.h>
#include "ijksdl/ijksdl.h"
#include "ff_fferror.h"
#include "ff_ffplay.h"
#include "ijkplayer.h"

struct IjkMediaPlayer {
    /* IjkMediaPlayer创建一次则ref_count计数加一次 */
    volatile int ref_count;
    /* 保护接口调用的锁*/
    pthread_mutex_t mutex;
    /* FFPlayer是原ffplayer里面的结构体，有被ijk作者扩展 */
    FFPlayer *ffplayer;
    /* 用于ijkPlayer回调给应用层的一个消息循环函数 */
    int (*msg_loop)(void*);
    /* 消息线程 */
    SDL_Thread *msg_thread;
    SDL_Thread _msg_thread;
    /* 播放器状态 */
    int mp_state;
    /* 播放地址 */
    char *data_source;
    /* Java层IjkMediaPlayer对应弱引用对象 */
    void *weak_thiz;
    /* 是否重新播放 */
    int restart;
    /* restart是否从头开始 */
    int restart_from_beginning;
    /* 标识用户是不是seek了进度条 */
    int seek_req;
    /* seek的毫秒值 */
    long seek_msec;
};

#endif
