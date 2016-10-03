#include <string.h>
#include <assert.h>
#include <errno.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <linux/fb.h>

int main()
{

  // Get palette information
  unsigned short r[256];
  unsigned short g[256];
  unsigned short b[256];
  unsigned short a[256];
  memset(r, 0, 256 * sizeof(unsigned short));
  memset(g, 0, 256 * sizeof(unsigned short));
  memset(b, 0, 256 * sizeof(unsigned short));
  memset(a, 0, 256 * sizeof(unsigned short));
  struct fb_cmap pal;
  pal.start = 0;
  pal.len = 0;
  pal.red = r;
  pal.green = g;
  pal.blue = b;
  pal.transp = a;

   /* open the framebuffer device */
   int fbfd = open("/dev/fb0", O_RDWR);
   if (fbfd< 0) {
      fprintf(stderr, "Error opening /dev/fb0: %s\n", strerror(errno));
      exit(1);
   }
printf("%d\n", fbfd );

  if (ioctl(fbfd, FBIOGETCMAP, &pal)) {
    printf("Error reading palette.\n");
  }
}
