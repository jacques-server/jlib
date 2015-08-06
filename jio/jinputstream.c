/*
 * Copyright (C) 2015  Wiky L
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with the package; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor Boston, MA 02110-1301,  USA
 */
#include "jinputstream.h"
#include <jlib/jlib.h>

void j_input_stream_init(JInputStream * stream,
                         JInputStreamInterface * interface)
{
    J_OBJECT_INIT(stream, j_input_stream_close);
    stream->iface = interface;
    stream->closed = FALSE;
}

jboolean j_input_stream_is_closed(JInputStream * input_stream)
{
    return input_stream->closed;
}

jint j_input_stream_read(JInputStream * stream, void *buffer, juint size)
{
    if (stream->iface->read) {
        return stream->iface->read(stream, buffer, size);
    }
    return -1;
}

// jchar *j_input_stream_readline(JInputStream * stream)
// {
//     if (stream->iface->readline) {
//         return stream->iface->readline(stream);
//     }
//     return NULL;
// }

void j_input_stream_close(JInputStream * stream)
{
    if (stream->closed == FALSE && stream->iface->close) {
        stream->iface->close(stream);
        stream->closed = TRUE;
    }
}
