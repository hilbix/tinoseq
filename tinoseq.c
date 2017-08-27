/* $Header$
 *
 * An integer 'seq' replacement.
 *
 * Copyright (C)2007 Valentin Hilbig <webmaster@scylla-charybdis.com>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of the
 * License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307
 * USA
 *
 * $Log$
 * Revision 1.1  2007-04-08 10:42:36  tino
 * First Dist
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tinoseq_version.h"

long long
getll(const char *s)
{
  unsigned long long	u;
  char			*end;

  if (s)
    {
      u	= strtoll(s, &end, 0);
      if (end && !*end)
        return u;
    }
  fprintf(stderr, "wrong arg %s\n", s);
  exit(2);
}

void
out(long long v)
{
  printf("%lld\n", v);
  if (feof(stdout) || ferror(stdout))
    {
      perror("stdout");
      exit(4);
    }
}

int
main(int argc, char **argv)
{
  long long	a, b, c;

  if (argc!=3 && argc!=4)
    {
      fprintf(stderr, "Usage: %s a [step] b\n", argv[0]);
      return 1;
    }
  a	= getll(argv[1]);
  b	= getll(argv[2]);
  if (argc==3)
    {
      c	= b;
      b = 1;
    }
  else
    c	= getll(argv[3]);
  if (!b)
    {
      fprintf(stderr, "Step cannot be 0\n");
      return 3;
    }
  if (b<0)
    for (; a>=c; a+=b)
      out(a);
  else
    for (; a<=c; a+=b)
      out(a);
  return 0;
}
