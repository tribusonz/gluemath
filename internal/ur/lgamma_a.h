/*******************************************************************************
	GLUE-Math Library: Logarithm of Gamma Function

	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
	Reference:
		Ooura's Mathematical Software Packages
		- Takuya Ooura
*******************************************************************************/
#ifndef GML_LGAMMA_APPROX_DBL_INTERNAL
#define GML_LGAMMA_APPROX_DBL_INTERNAL

#if defined(__cplusplus)
extern "C" {
#endif

// uses math library: fabs(), log(), sin()
#include "../../sys/float/absolute.h"
#include "log.h"
#include "sin.h"

static inline double
loggamma_a(register double x, int *signp)
{
	register int k;
	register double w, t, y, v;
	static const double a[22] =
	{
		 9.967270908702825e-5,   -1.9831672170162227e-4, 
		-0.00117085315349625822,  0.00722012810948319552, 
		-0.0096221300936780297,  -0.04219772092994235254, 
		 0.16653861065243609743, -0.04200263501129018037, 
		-0.65587807152061930091,  0.57721566490153514421, 
		 0.99999999999999999764, 
		 4.67209725901142e-5,    -6.812300803992063e-5, 
		-0.00132531159076610073,  0.0073352117810720277, 
		-0.00968095666383935949, -0.0421764281187354028, 
		 0.16653313644244428256, -0.04200165481709274859, 
		-0.65587818792782740945,  0.57721567315209190522, 
		 0.99999999973565236061
	};
	static const double b[98] = {
		-4.587497028e-11,         1.902363396e-10, 
		 8.6377323367e-10,        1.15513678861e-8, 
		-2.556403058605e-8,      -1.5236723372486e-7, 
		-3.1680510638574e-6,      1.22903704923381e-6, 
		 2.334372474572637e-5,    0.00111544038088797696, 
		 0.00344717051723468982,  0.03198287045148788384, 
		-0.32705333652955399526,  0.40120442440953927615, 
		-5.184290387e-11,        -8.3355121068e-10, 
		-2.56167239813e-9,        1.455875381397e-8, 
		 1.3512178394703e-7,      2.9898826810905e-7, 
		-3.58107254612779e-6,    -2.445260816156224e-5, 
		-4.417127762011821e-5,    0.00112859455189416567, 
		 0.00804694454346728197,  0.04919775747126691372, 
		-0.24818372840948854178,  0.11071780856646862561, 
		 3.0279161576e-10,        1.60742167357e-9, 
		-4.05596009522e-9,       -5.089259920266e-8, 
		-2.029496209743e-8,       1.35130272477793e-6, 
		 3.91430041115376e-6,    -2.871505678061895e-5, 
		-2.3052137536922035e-4,   4.5534656385400747e-4, 
		 0.01153444585593040046,  0.07924014651650476036, 
		-0.12152192626936502982, -0.07916438300260539592, 
		-5.091914958e-10,        -1.15274986907e-9, 
		 1.237873512188e-8,       2.937383549209e-8, 
		-3.0621450667958e-7,     -7.7409414949954e-7, 
		 8.16753874325579e-6,     2.412433382517375e-5, 
		-2.60612176060637e-4,    -9.1000087658659231e-4, 
		 0.01068093850598380797,  0.11395654404408482305, 
		 0.07209569059984075595, -0.10971041451764266684, 
		 4.0119897187e-10,       -1.3224526679e-10, 
		-1.002723190355e-8,       2.569249716518e-8, 
		 2.0336011868466e-7,     -1.1809768272606e-6, 
		-3.00660303810663e-6,     4.402212897757763e-5, 
		-1.462405876235375e-5,   -0.0016487379559600128, 
		 0.00513927520866443706,  0.13843580753590579416, 
		 0.32730190978254056722,  0.08588339725978624973, 
		-1.5413428348e-10,        6.4905779353e-10, 
		 1.60702811151e-9,       -2.655645793815e-8, 
		 7.619544277956e-8,       4.7604380765353e-7, 
		-4.90748870866195e-6,     8.21513040821212e-6, 
		 1.4804944070262948e-4,  -0.00122152255762163238, 
		-8.7425289205498532e-4,   0.1443870369965796831, 
		 0.61315889733595543766,  0.55513708159976477557, 
		 1.049740243e-11,        -2.5832017855e-10, 
		 1.39591845075e-9,       -2.1177278325e-10, 
		-5.082950464905e-8,       3.7801785193343e-7, 
		-7.3982266659145e-7,     -1.088918441519888e-5, 
		 1.2491810452478905e-4,  -4.9171790705139895e-4, 
		-0.0042570708944826646,   0.13595080378472757216, 
		 0.89518356003149514744,  1.31073912535196238583
	};
	static const double c[65] = {
		 1.16333640008e-8,       -8.33156123568e-8, 
		 3.832869977018e-7,      -1.5814047847688e-6, 
		 6.50106723241e-6,       -2.74514060128677e-5, 
		 1.209015360925566e-4,   -5.666333178228163e-4, 
		 0.0029294103665559733,  -0.0180340086069185819, 
		 0.1651788780501166204,   1.1031566406452431944, 
		 1.2009736023470742248, 
		 1.3842760642e-9,        -6.9417501176e-9, 
		 3.42976459827e-8,       -1.785317236779e-7, 
		 9.525947257118e-7,      -5.2483007560905e-6, 
		 3.02364659535708e-5,    -1.858396115473822e-4, 
		 0.0012634378559425382,  -0.0102594702201954322, 
		 0.1243625515195050218,   1.3888709263595291174, 
		 2.4537365708424422209, 
		 1.298977078e-10,        -8.02957489e-10, 
		 4.945484615e-9,         -3.17563534834e-8, 
		 2.092136698089e-7,      -1.4252023958462e-6, 
		 1.01652510114008e-5,    -7.74550502862323e-5, 
		 6.537746948291078e-4,   -0.006601491253552183, 
		 0.0996711934948138193,   1.6110931485817511402, 
		 3.9578139676187162939, 
		 1.83995642e-11,         -1.353537034e-10, 
		 9.984676809e-10,        -7.6346363974e-9, 
		 5.99311464148e-8,       -4.868554120177e-7, 
		 4.1441957716669e-6,     -3.77160856623282e-5, 
		 3.805693126824884e-4,   -0.0045979851178130194, 
		 0.0831422678749791178,   1.7929113303999329439, 
		 5.6625620598571415285, 
		 3.4858778e-12,          -2.97587783e-11, 
		 2.557677575e-10,        -2.2705728282e-9, 
		 2.0702499245e-8,        -1.954426390917e-7, 
		 1.9343161886722e-6,     -2.0479024910257e-5, 
		 2.405181940241215e-4,   -0.0033842087561074799, 
		 0.0713079483483518997,   1.9467574842460867884, 
		 7.5343642367587329552
	};
	static const double d[7] = {
		-0.00163312359200500807,  8.3644533703385956e-4, 
		-5.9518947575728181e-4,   7.9365057505415415e-4, 
		-0.00277777777735463043,  0.08333333333333309869, 
		 0.91893853320467274178
	};

	w = x;
	if (x < 0)  w = 1 - x;
	
	if (w < 0.5)
	{
		k = w < 0.25 ? 0 : 11;
		y = ((((((((((a[k] * w + a[k + 1]) * w + 
			a[k + 2]) * w + a[k + 3]) * w + a[k + 4]) * w + 
			a[k + 5]) * w + a[k + 6]) * w + a[k + 7]) * w + 
			a[k + 8]) * w + a[k + 9]) * w + a[k + 10]) * w;
		y = -log_core(y);
	}
	else if (w < 3.5)
	{
		t = w - 4.5 / (w + 0.5);
		k = (int) (t + 4);
		t -= k - 3.5;
		k *= 14;
		y = ((((((((((((b[k] * t + b[k + 1]) * t + 
			b[k + 2]) * t + b[k + 3]) * t + b[k + 4]) * t + 
			b[k + 5]) * t + b[k + 6]) * t + b[k + 7]) * t + 
			b[k + 8]) * t + b[k + 9]) * t + b[k + 10]) * t + 
			b[k + 11]) * t + b[k + 12]) * t + b[k + 13];
	}
	else if (w < 8)
	{
		k = ((int) w) - 3;
		t = w - (k + 3.5);
		k *= 13;
		y = (((((((((((c[k] * t + c[k + 1]) * t + 
			c[k + 2]) * t + c[k + 3]) * t + c[k + 4]) * t + 
			c[k + 5]) * t + c[k + 6]) * t + c[k + 7]) * t + 
			c[k + 8]) * t + c[k + 9]) * t + c[k + 10]) * t + 
			c[k + 11]) * t + c[k + 12];
	}
	else
	{
		v = 1 / w;
		t = v * v;
		y = (((((d[0] * t + d[1]) * t + d[2]) * t + 
			d[3]) * t + d[4]) * t + d[5]) * v + d[6];
		y += (w - 0.5) * log_core(w) - w;
	}

	if (x < 0)
	{
		w = 3.141592653589793238 / sin_core(x * 3.141592653589793238);

		if (w < 0)  *signp = -1;
		else        *signp =  1;

		y = log_core(fabs(w)) - y;
	}
	else
		*signp = 1;

	return y;
}

#if defined(__cplusplus)
}
#endif

#endif /* GML_LGAMMA_APPROX_DBL_INTERNAL */
