#ifndef	PIXEL_H
#define	PIXEL_H

	#include	<stdint.h>

		#pragma	pack(push, 1)

			typedef	struct
			{
				uint8_t	_blue;
				uint8_t	_green;
				uint8_t	_red;
				uint8_t	_alpha;
			}	Pixel;

		#pragma	pack(pop)

			int8_t	pixelInit(Pixel*	pixel, uint8_t	red, uint8_t	green, uint8_t	blue, uint8_t	alpha);

			int8_t	pixelSetRed(Pixel*	pixel, uint8_t	red);
			int8_t	pixelSetGreen(Pixel*	pixel, uint8_t	green);
			int8_t	pixelSetBlue(Pixel*	pixel, uint8_t	blue);
			int8_t	pixelSetAlpha(Pixel*	pixel, uint8_t	alpha);

			uint8_t	pixelGetRed(Pixel*	pixel);
			uint8_t	pixelGetGreen(Pixel*	pixel);
			uint8_t	pixelGetBlue(Pixel*	pixel);
			uint8_t	pixelGetAlpha(Pixel*	pixel);

#endif
