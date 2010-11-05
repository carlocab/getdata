#include "test.h"

#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>

int main(void)
{
  const char* filedir = __TEST__ "dirfile";
  const char* format = __TEST__ "dirfile/format";
  const char* format_data =
    "raw1 RAW UINT8 1\n"
    "META raw1 linterp1 LINTERP raw2 table\n"
    "META raw1 linterp2 LINTERP raw3 table\n"
    "META raw1 linterp3 LINTERP raw4 table\n"
    "META raw1 const CONST UINT8 1\n"
    "META raw1 string STRING value\n"
    "META raw1 string2 STRING value\n"
    "raw2 RAW UINT8 1\n"
    "raw3 RAW UINT8 1\n"
    "raw4 RAW UINT8 1\n"
    "const CONST UINT8 1\n"
    "string STRING value\n"
    "string2 STRING value\n";
  int fd, r = 0;

  mkdir(filedir, 0777);

  fd = open(format, O_CREAT | O_EXCL | O_WRONLY, 0666);
  write(fd, format_data, strlen(format_data));
  close(fd);

  DIRFILE* D = gd_open(filedir, GD_RDWR | GD_VERBOSE);
  unsigned int nvec = gd_nmvectors(D, "raw1");
  int error = gd_error(D);
  gd_delete(D, "raw1/linterp3", 0);
  unsigned int nvec2 = gd_nmvectors(D, "raw1");
  int error2 = gd_error(D);
  gd_delete(D, "raw1/string", 0);
  unsigned int nvec3 = gd_nmvectors(D, "raw1");
  int error3 = gd_error(D);
  gd_discard(D);

  unlink(format);
  rmdir(filedir);

  CHECKI(error,0);
  CHECKI(nvec,3);
  CHECKI(error2,0);
  CHECKI(nvec2,2);
  CHECKI(error3,0);
  CHECKI(nvec3,2);

  return r;
}
