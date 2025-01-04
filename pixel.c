#include	"pixel.h"

	int8_t	pixelInit(Pixel*	pixel, uint8_t	blue, uint8_t	green, uint8_t	red, uint8_t	alpha)
	{
		if(!pixel){ return	-1; }

		pixel->_blue	=	blue;
		pixel->_green	=	green;
		pixel->_red	=	red;
		pixel->_alpha	=	alpha;

		return	0;
	}

	int8_t	pixelSetBlue(Pixel*	pixel, uint8_t	blue)
	{
		if(!pixel){ return	-1; }

		pixel->_blue	=	blue;

		return	0;
	}
	int8_t	pixelSetGreen(Pixel*	pixel, uint8_t	green)
	{
		if(!pixel){ return	-1; }

		pixel->_green	=	green;

		return	0;
	}
	int8_t	pixelSetRed(Pixel*	pixel, uint8_t	red)
	{
		if(!pixel){ return	-1; }

		pixel->_red	=	red;

		return	0;
	}
	int8_t	pixelSetAlpha(Pixel*	pixel, uint8_t	alpha)
	{
		if(!pixel){ return	-1; }

		pixel->_alpha	=	alpha;

		return	0;
	}

	uint8_t	pixelGetBlue(Pixel*	pixel)
	{
		if(!pixel){ return	-1; }

		return	pixel->_blue;
	}
	uint8_t	pixelGetGreen(Pixel*	pixel)
	{
		if(!pixel){ return	-1; }

		return	pixel->_green;
	}
	uint8_t	pixelGetRed(Pixel*	pixel)
	{
		if(!pixel){ return	-1; }

		return	pixel->_red;
	}
	uint8_t	pixelGetAlpha(Pixel*	pixel)
	{
		if(!pixel){ return	-1; }

		return	pixel->_alpha;
	}
