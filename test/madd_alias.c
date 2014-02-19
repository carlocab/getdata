/* Copyright (C) 2011, 2014 D. V. Wiebe
 *
 ***************************************************************************
 *
 * This file is part of the GetData project.
 *
 * GetData is free software; you can redistribute it and/or modify it under
 * the terms of the GNU Lesser General Public License as published by the
 * Free Software Foundation; either version 2.1 of the License, or (at your
 * option) any later version.
 *
 * GetData is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public
 * License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with GetData; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 */
#include "test.h"

int main(void)
{
  const char *filedir = "dirfile";
  const char *format = "dirfile/format";
  const char *data = "dirfile/data";
  int error, i, r = 0;
  DIRFILE *D;
  unsigned int n;
  const char *target;

  rmdirfile();

  D = gd_open(filedir, GD_RDWR | GD_CREAT | GD_VERBOSE);

  gd_add_raw(D, "data", GD_UINT8, 1, 0);
  gd_madd_alias(D, "data", "alias", "data");
  error = gd_error(D);

  /* check */
  target = gd_alias_target(D, "data/alias");
  CHECKS(target, "data");
  i = gd_fragment_index(D, "data/alias");
  n = gd_naliases(D, "data/alias");

  gd_discard(D);

  unlink(data);
  unlink(format);
  rmdir(filedir);

  CHECKI(error, GD_E_OK);
  CHECKI(i, 0);
  CHECKU(n, 2);

  return r;
}
