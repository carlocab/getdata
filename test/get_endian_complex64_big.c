/* Attempt to read big-endian COMPLEX64 */
#include "../src/getdata.h"

#include <complex.h>
#include <inttypes.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <math.h>
#include <string.h>
#include <errno.h>
#include <stdio.h>
#include <unistd.h>

int main(void)
{
  const char* filedir = __TEST__ "dirfile";
  const char* format = __TEST__ "dirfile/format";
  const char* data = __TEST__ "dirfile/data";
  const char* format_data = "data RAW COMPLEX64 1\nENDIAN big\n";
  float complex u[10];
  float complex v[20];
  const unsigned char data_data[64 * 8] = {
    0x3F, 0xC0, 0x00, 0x00,  0x40, 0x10, 0x00, 0x00,
    0x40, 0x58, 0x00, 0x00,  0x40, 0xA2, 0x00, 0x00,
    0x40, 0xF3, 0x00, 0x00,  0x41, 0x36, 0x40, 0x00,
    0x41, 0x88, 0xB0, 0x00,  0x41, 0xCD, 0x08, 0x00,
    0x42, 0x19, 0xC6, 0x00,  0x42, 0x66, 0xA9, 0x00,
    0x42, 0xAC, 0xFE, 0xC0,  0x43, 0x01, 0xBF, 0x10,
    0x43, 0x42, 0x9E, 0x98,  0x43, 0x91, 0xF6, 0xF2,
    0x43, 0xDA, 0xF2, 0x6B,  0x44, 0x24, 0x35, 0xD0,
    0x44, 0x76, 0x50, 0xB8,  0x44, 0xB8, 0xBC, 0x8A,
    0x45, 0x0A, 0x8D, 0x68,  0x45, 0x4F, 0xD4, 0x1C,
    0x45, 0x9B, 0xDF, 0x15,  0x45, 0xE9, 0xCE, 0xA0,
    0x46, 0x2F, 0x5A, 0xF8,  0x46, 0x83, 0x84, 0x3A,
    0x46, 0xC5, 0x46, 0x57,  0x47, 0x13, 0xF4, 0xC1,
    0x47, 0x5D, 0xEF, 0x22,  0x47, 0xA6, 0x73, 0x5A,
    0x47, 0xF9, 0xAD, 0x07,  0x48, 0x3B, 0x41, 0xC5,
    0x48, 0x8C, 0x71, 0x54,  0x48, 0xD2, 0xA9, 0xFE,
    0x49, 0x1D, 0xFF, 0x7E,  0x49, 0x6C, 0xFF, 0x3D,
    0x49, 0xB1, 0xBF, 0x6E,  0x4A, 0x05, 0x4F, 0x92,
    0x4A, 0x47, 0xF7, 0x5B,  0x4A, 0x95, 0xF9, 0x84,
    0x4A, 0xE0, 0xF6, 0x46,  0x4B, 0x28, 0xB8, 0xB4,
    0x4B, 0x7D, 0x15, 0x0E,  0x4B, 0xBD, 0xCF, 0xCA,
    0x4C, 0x0E, 0x5B, 0xD8,  0x4C, 0x55, 0x89, 0xC4,
    0x4C, 0xA0, 0x27, 0x53,  0x4C, 0xF0, 0x3A, 0xFC,
    0x4D, 0x34, 0x2C, 0x3D,  0x4D, 0x87, 0x21, 0x2E,
    0x4D, 0xCA, 0xB1, 0xC5,  0x4E, 0x18, 0x05, 0x54,
    0x4E, 0x64, 0x07, 0xFE,  0x4E, 0xAB, 0x05, 0xFE,
    0x4F, 0x00, 0x44, 0x7E,  0x4F, 0x40, 0x66, 0xBD,
    0x4F, 0x90, 0x4D, 0x0E,  0x4F, 0xD8, 0x73, 0x95,
    0x50, 0x22, 0x56, 0xB0,  0x50, 0x73, 0x82, 0x08,
    0x50, 0xB6, 0xA1, 0x86,  0x51, 0x08, 0xF9, 0x24,
    0x51, 0x4D, 0x75, 0xB6,  0x51, 0x9A, 0x18, 0x48,
    0x51, 0xE7, 0x24, 0x6C,  0x52, 0x2D, 0x5B, 0x51,
    0x52, 0x82, 0x04, 0x7D,  0x52, 0xC3, 0x06, 0xBC,
    0x53, 0x12, 0x45, 0x0D,  0x53, 0x5B, 0x67, 0x94,
    0x53, 0xA4, 0x8D, 0xAF,  0x53, 0xF6, 0xD4, 0x86,
    0x54, 0x39, 0x1F, 0x64,  0x54, 0x8A, 0xD7, 0x8B,
    0x54, 0xD0, 0x43, 0x50,  0x55, 0x1C, 0x32, 0x7C,
    0x55, 0x6A, 0x4B, 0xBA,  0x55, 0xAF, 0xB8, 0xCC,
    0x56, 0x03, 0xCA, 0x99,  0x56, 0x45, 0xAF, 0xE6,
    0x56, 0x94, 0x43, 0xEC,  0x56, 0xDE, 0x65, 0xE2,
    0x57, 0x26, 0xCC, 0x6A,  0x57, 0x7A, 0x32, 0x9F,
    0x57, 0xBB, 0xA5, 0xF7,  0x58, 0x0C, 0xBC, 0x79,
    0x58, 0x53, 0x1A, 0xB6,  0x58, 0x9E, 0x54, 0x08,
    0x58, 0xED, 0x7E, 0x0C,  0x59, 0x32, 0x1E, 0x89,
    0x59, 0x85, 0x96, 0xE7,  0x59, 0xC8, 0x62, 0x5A,
    0x5A, 0x16, 0x49, 0xC4,  0x5A, 0x61, 0x6E, 0xA6,
    0x5A, 0xA9, 0x12, 0xFC,  0x5A, 0xFD, 0x9C, 0x7A,
    0x5B, 0x3E, 0x35, 0x5C,  0x5B, 0x8E, 0xA8, 0x05,
    0x5B, 0xD5, 0xFC, 0x08,  0x5C, 0x20, 0x7D, 0x06,
    0x5C, 0x70, 0xBB, 0x89,  0x5C, 0xB4, 0x8C, 0xA7,
    0x5D, 0x07, 0x69, 0x7D,  0x5D, 0x4B, 0x1E, 0x3C,
    0x5D, 0x98, 0x56, 0xAD,  0x5D, 0xE4, 0x82, 0x04,
    0x5E, 0x2B, 0x61, 0x83,  0x5E, 0x80, 0x89, 0x22,
    0x5E, 0xC0, 0xCD, 0xB3,  0x5F, 0x10, 0x9A, 0x46,
    0x5F, 0x58, 0xE7, 0x69,  0x5F, 0xA2, 0xAD, 0x8F,
    0x5F, 0xF4, 0x04, 0x56,  0x60, 0x37, 0x03, 0x40,
    0x60, 0x89, 0x42, 0x70,  0x60, 0xCD, 0xE3, 0xA8,
    0x61, 0x1A, 0x6A, 0xBE,  0x61, 0x67, 0xA0, 0x1D,
    0x61, 0xAD, 0xB8, 0x16,  0x62, 0x02, 0x4A, 0x10,
    0x62, 0x43, 0x6F, 0x18,  0x62, 0x92, 0x93, 0x52,
    0x62, 0xDB, 0xDC, 0xFB,  0x63, 0x24, 0xE5, 0xBC,
    0x63, 0x77, 0x58, 0x9A,  0x63, 0xB9, 0x82, 0x74,
    0x64, 0x0B, 0x21, 0xD7,  0x64, 0x50, 0xB2, 0xC2,
    0x64, 0x9C, 0x86, 0x12,  0x64, 0xEA, 0xC9, 0x1B
  };
  int fd, i, r = 0;

  mkdir(filedir, 0777); 

  v[0] = 1.5 + _Complex_I * 2.25;
  for (i = 1; i < 20; ++i)
    v[i] = v[i - 1] * 2.25;

  fd = open(format, O_CREAT | O_EXCL | O_WRONLY, 0666);
  write(fd, format_data, strlen(format_data));
  close(fd);

  fd = open(data, O_CREAT | O_EXCL | O_WRONLY, 0666);
  write(fd, data_data, 64 * sizeof(float complex));
  close(fd);

  DIRFILE* D = dirfile_open(filedir, GD_RDONLY | GD_VERBOSE);
  int n = getdata(D, "data", 5, 0, 0, 10, GD_COMPLEX64, u);
  int error = get_error(D);

  dirfile_close(D);

  unlink(data);
  unlink(format);
  rmdir(filedir);

  if (error) {
    fprintf(stderr, "error = %i\n", error);
    r = 1;
  }
  if (n != 10) {
    fprintf(stderr, "n = %i\n", n);
    r = 1;
  }

  for (i = 0; i < 10; ++i)
    if (cabs(u[i] - v[i + 5]) / cabs(v[i + 5]) > 2e-7) {
      printf("u[%i] = %g;%g -> %g\n", i, creal(u[i]), cimag(u[i]),
          cabs(u[i] - v[i + 5]) / cabs(v[i + 5]));
      r = 1;
    }

  return r;
}
