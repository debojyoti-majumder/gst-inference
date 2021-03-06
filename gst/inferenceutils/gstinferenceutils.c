/*
 * GStreamer
 * Copyright (C) 2018-2020 RidgeRun <support@ridgerun.com>
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

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "gstinferencebin.h"
#include "gstinferencecrop.h"
#include "gstinferencedebug.h"
#include "gstinferencefilter.h"

static gboolean
plugin_init (GstPlugin * plugin)
{
  gboolean ret = TRUE;

  ret =
      gst_element_register (plugin, "inferencebin", GST_RANK_NONE,
      GST_TYPE_INFERENCE_BIN);
  if (!ret) {
    goto out;
  }

  ret =
      gst_element_register (plugin, "inferencecrop", GST_RANK_NONE,
      GST_TYPE_INFERENCE_CROP);
  if (!ret) {
    goto out;
  }

  ret =
      gst_element_register (plugin, "inferencedebug", GST_RANK_NONE,
      GST_TYPE_INFERENCE_DEBUG);
  if (!ret) {
    goto out;
  }

  ret =
      gst_element_register (plugin, "inferencefilter", GST_RANK_NONE,
      GST_TYPE_INFERENCE_FILTER);
  if (!ret) {
    goto out;
  }

out:
  return ret;
}

GST_PLUGIN_DEFINE (GST_VERSION_MAJOR,
    GST_VERSION_MINOR,
    inferenceutils,
    "Utils to process inferencemeta information",
    plugin_init, VERSION, "LGPL", PACKAGE_NAME, GST_PACKAGE_ORIGIN)
