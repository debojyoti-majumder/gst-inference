/*
 * GStreamer
 * Copyright (C) 2018 RidgeRun
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 *
 */

#ifndef __GST_BACKEND_H__
#define __GST_BACKEND_H__

#include <gst/gst.h>
#include <r2i/r2i.h>

G_BEGIN_DECLS

#define GST_TYPE_BACKEND gst_backend_get_type ()
G_DECLARE_DERIVABLE_TYPE (GstBackend, gst_backend, GST, BACKEND, GstObject);

struct _GstBackendClass
{
  GstObjectClass parent_class;

  r2i::FrameworkCode backend;
  GHashTable *props;
};

gboolean gst_backend_configure (GstBackend *self,
    std::shared_ptr<r2i::IEngine> engine, std::shared_ptr<r2i::IModel> model);

G_END_DECLS

#endif //__GST_BACKEND_H__