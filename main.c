#include	<linux/fb.h>

#include	<sys/ioctl.h>
#include	<sys/mman.h>
#include	<sys/fcntl.h>
#include	<sys/unistd.h>

#include	<stdio.h>
#include	<string.h>
#include	<errno.h>
#include	<stdint.h>

	#define	FILEIMG	"test"

	#define	FRAMEBUFFDEV	"/dev/fb0"

		int	main(void)
		{
			struct fb_var_screeninfo	varScreenInfo;

			uint8_t*	frameBuffer	=	0x00;

			int32_t	result	=	0;
			int32_t	frameBufferDescriptor	=	0;
			int32_t	fileTest	=	0;

			memset(&varScreenInfo, 0, sizeof(struct fb_var_screeninfo));

			fileTest	=	open(FILEIMG, O_WRONLY | O_CREAT);
			if(fileTest < 0)
			{
				fprintf(stderr, "%s:%i - %s\n", __FILE__, __LINE__, strerror(errno));

				return	-1;
			}

			frameBufferDescriptor	=	open(FRAMEBUFFDEV, O_RDONLY);
			if(frameBufferDescriptor < 0)
			{
				fprintf(stderr, "%s:%i - %s\n", __FILE__, __LINE__, strerror(errno));

				close(fileTest);

				return	-1;
			}

			result	=	ioctl(frameBufferDescriptor, FBIOGET_VSCREENINFO, &varScreenInfo);
			if(result < 0)
			{
				fprintf(stderr, "%s:%i - %s\n", __FILE__, __LINE__, strerror(errno));

				close(fileTest);

				close(frameBufferDescriptor);

				return	-1;
			}

			frameBuffer	=	(uint8_t*)mmap(0x00, varScreenInfo.xres * varScreenInfo.yres * (varScreenInfo.bits_per_pixel / 8), PROT_READ, MAP_SHARED, frameBufferDescriptor, 0);
			if(frameBuffer ==(void*)-1)
			{
				fprintf(stderr, "%s:%i - %s\n", __FILE__, __LINE__, strerror(errno));

				close(fileTest);

				close(frameBufferDescriptor);

				return	-1;
			}

			result	=	write(fileTest, frameBuffer, varScreenInfo.xres * varScreenInfo.yres * (varScreenInfo.bits_per_pixel / 8));
			if(result != varScreenInfo.xres * varScreenInfo.yres * (varScreenInfo.bits_per_pixel / 8))
			{
				fprintf(stderr, "%s:%i - %s\n", __FILE__, __LINE__, strerror(errno));

				close(fileTest);

				close(frameBufferDescriptor);

				return	-1;
			}

			result	=	munmap(frameBuffer, varScreenInfo.xres * varScreenInfo.yres * (varScreenInfo.bits_per_pixel / 8));
			if(result < 0)
			{
				fprintf(stderr, "%s:%i - %s\n", __FILE__, __LINE__, strerror(errno));

				close(fileTest);

				close(frameBufferDescriptor);

				return	-1;
			}

			frameBuffer	=	0x00;

			result	=	close(frameBufferDescriptor);
			if(result < 0)
			{
				fprintf(stderr, "%s:%i - %s\n", __FILE__, __LINE__, strerror(errno));

				close(fileTest);

				return	-1;
			}

			result	=	close(fileTest);
			if(result < 0)
			{
				fprintf(stderr, "%s:%i - %s\n", __FILE__, __LINE__, strerror(errno));

				return	-1;
			}

			return	0;
		}
