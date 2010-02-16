/* Attempt to write little-endian COMPLEX64 */
#include "../src/getdata.h"

#include <complex.h>
#include <inttypes.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>

int main(void)
{
  const char* filedir = __TEST__ "dirfile";
  const char* format = __TEST__ "dirfile/format";
  const char* data = __TEST__ "dirfile/data";
  const char* format_data = "data RAW COMPLEX64 1\nENDIAN little\n";
  int fd, i, r = 0;
  const float complex c = 1.5 + _Complex_I * 2.25;
  unsigned char x[sizeof(float complex)] = {
    0x00, 0x00, 0xC0, 0x3F, 0x00, 0x00, 0x10, 0x40
  };
  unsigned char u[sizeof(float complex)];

  mkdir(filedir, 0777); 

  fd = open(format, O_CREAT | O_EXCL | O_WRONLY, 0666);
  write(fd, format_data, strlen(format_data));
  close(fd);

  DIRFILE* D = dirfile_open(filedir, GD_RDWR | GD_UNENCODED | GD_VERBOSE);
  int n = putdata(D, "data", 5, 0, 1, 0, GD_COMPLEX64, &c);
  int error = get_error(D);

  dirfile_close(D);

  fd = open(data, O_RDONLY);
  lseek(fd, 5 * sizeof(float complex), SEEK_SET);
  read(fd, u, sizeof(float complex));
  close(fd);

  unlink(data);
  unlink(format);
  rmdir(filedir);

  if (n != 1) {
    printf("n = %i\n", n);
    r = 1;
  }
  if (error) {
    printf("error = %i\n", error);
    r = 1;
  }
  
  for (i = 0; i < sizeof(float complex); ++i)
    if (x[i] != u[i]) {
      printf("%i=%x (%x)\n", i, x[i], u[i]);
      r = 1;
    }

  return r;
}
