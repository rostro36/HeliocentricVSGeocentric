//from https://nssdc.gsfc.nasa.gov/planetary/factsheet/index.html
//Dia->diameter (km)
//Dist->distance from sun (10^6 km)
//Per->orbital period (days)
//from https://www.schemecolor.com/tag/solar-system
//RGB->RGB value of color of planet

typedef struct color {
	float R;
	float G;
	float B;
};

typedef struct planet {
	float Dia;// Diameter
	float Dist;//Distance to the sun
	float Per;//Period around the sun
	struct color RGB; //colour
};

struct planet planets[10] = {
//sun
//https://www.space.com/17001-how-big-is-the-sun-size-of-the-sun.html
{ 1392000,0,1,{ 209, 64, 9 } },
//merc
{4879,57.9,88.0,{ 181, 167, 167 }},
//ven
{ 12104,108.2,224.7,{ 239, 239, 239 } },
//ear
{ 12756,149.6,365.2, { 140, 177, 222 } },
//mars
{ 6792,227.9,687.0, { 142, 106, 90 } },
//jup
{ 142984,778.6,4331, { 200, 139, 58 } },
//sat
{ 120536,1433.5,10747, { 195, 161, 113 } },
//ur
{ 51118,2872.5,30589, { 101, 134, 139 } },
//nep
{ 49528,4495.1,59800, { 137, 243, 255 } },
//https://www.color-hex.com/color-palette/13090
//plut
{ 2370,5906.4,90560, { 204,186,153 } } };

/*
const float
sunDia= 1392000,
//https://www.space.com/17001-how-big-is-the-sun-size-of-the-sun.html
mercDia = 4879,
venDia = 12104,
earDia = 12756,
marsDia = 6792,
jupDia = 142984,
satDia = 120536,
urDia = 51118,
nepDia = 49528,
plutDia = 2370;

const float 
mercDist = 57.9,
venDist = 108.2,
earDist = 149.6,
marsDist = 227.9,
jupDist = 778.6,
satDist = 1433.5,
urDist = 2872.5,
nepDist = 4495.1,
plutDist = 5906.4;

const float
mercPer = 88.0,
venPer = 224.7,
earPer = 365.2,
marsPer = 687.0,
jupPer = 4331,
satPer = 10747,
urPer = 30589,
nepPer = 59800,
plutPer = 90560;

const struct color
sunRGB= { 209, 64, 9 },
mercRGB = { 181, 167, 167 },
venRGB = { 239, 239, 239 },
earRGB = { 140, 177, 222 },
marsRGB = { 142, 106, 90 },
jupRGB = { 200, 139, 58 },
satRGB = { 195, 161, 113 },
urRGB = { 101, 134, 139 },
nepRGB = { 137, 243, 255 },
//https://www.color-hex.com/color-palette/13090
plutRGB={ 204,186,153 };
*/