/*
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 *
 * The Original Code is Copyright (C) 2016 by Mike Erwin.
 * All rights reserved.
 */

/** \file
 * \ingroup gpu
 *
 * GPU vertex format
 */

#ifndef __GPU_VERTEX_FORMAT_PRIVATE_H__
#define __GPU_VERTEX_FORMAT_PRIVATE_H__

void VertexFormat_pack(GPUVertFormat *format);
void VertexFormat_deinterleave(GPUVertFormat *format, uint vertex_len);
uint padding(uint offset, uint alignment);
uint vertex_buffer_size(const GPUVertFormat *format, uint vertex_len);

#endif /* __GPU_VERTEX_FORMAT_PRIVATE_H__ */
