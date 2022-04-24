/*******************************************************************************
	GLUE-Math Library: Bessel Function (the 2nd kind)

	Author:
	  Takuya Ooura (Algorithm)
	  Hironobu Inatsuka aka tribusonz (ABI modify)
	License:
	  GPL + X11(MIT)
	Reference:
	  Ooura's Mathematical Software Packages
*******************************************************************************/
#ifndef GML_BESSEL_Y0_DBL_INTERNAL
#define GML_BESSEL_Y0_DBL_INTERNAL

#if defined(__cplusplus)
extern "C" {
#endif

#include "sqrt.h"
#include "log.h"
#include "sin.h"

static inline double ur_bessel_y0(double);

static inline double
y0_core(double x)
{
	if (x != x)
		return x;
	else if (x < 0)
		return ur_bessel_y0(-x);
	else
		return ur_bessel_y0(x);
}

/* Bessel Y_0(x) function in double precision */
static inline double
ur_bessel_y0(double x)
{
	int k;
	double t, y, v, theta;
	static double a[16] =
	{
		-1.51249795e-12,          2.9979612902e-10, 
		-4.317352912436e-8,       4.31735413787068e-6, 
		-2.763106650893309e-4,    0.0099471839432433894, 
		-0.15915494309189533339,  0.63661977236758134306, 
		 4.09490035e-12,         -7.6925095943e-10, 
		1.0358472550303e-7,      -9.49500519343105e-6, 
		5.3860266685948738e-4,   -0.01607396802593822992, 
		0.17760601686906713536,  -0.07380429510868722524
	};
	static double b[112] =
	{
		-2.958527319e-11,        -4.799424787e-11, 
		 7.0761365903e-10,        7.86916310954e-9, 
		 4.40632174633e-8,        1.047420705431e-7, 
		-7.0359581447993e-7,     -1.068225180236166e-5, 
		-7.636033201484949e-5,   -3.4318294473105478e-4, 
		-5.0019381740765567e-4,   0.00898034680285547482, 
		 0.14783488851798565262,  0.01218096458136948754, 
		-3.790394288e-11,        -8.3012324083e-10, 
		-4.16344143065e-9,       -1.59750317942e-9, 
		 1.1897479804282e-7,      8.9462034665663e-7, 
		 2.7927785508031e-6,     -7.10267818373816e-6, 
		-1.4158631248747538e-4,  -8.9512296835766028e-4, 
		-0.00286419212921734238,  0.00448696141199596815, 
		 0.16247276853497028694,  0.16806523426268420517, 
		 4.9508820408e-10,        2.40256475451e-9, 
		-3.4128702476e-9,        -7.926555593644e-8, 
		-2.7510687602104e-7,      8.2850014912691e-7, 
		 1.202838962100801e-5,    4.446440998573947e-5, 
		-6.345799532264893e-5,   -0.00153636349657759957, 
		-0.00784582749467635199, -0.01091113270659651752, 
		 0.15855078058220179592,  0.33112075987570150227, 
		-1.21381163034e-9,       -1.85252445637e-9, 
		 2.782181715752e-8,       9.983716245339e-8, 
		-5.1382328105461e-7,     -4.13045112612025e-6, 
		 6.9219807212556e-7,      1.1346881914173059e-4, 
		 4.485714262231131e-4,   -7.5862241142011713e-4, 
		-0.01330170710405210993, -0.04337207915110066583, 
		 0.10708263075506099964,  0.46937172516119821029, 
		 1.23954313286e-9,       -1.3150647347e-9, 
		-3.208158247443e-8,       6.936208476862e-8, 
		 9.6326321605564e-7,     -1.86813677726279e-6, 
		-3.296596487362508e-5,   -1.027532398838717e-5, 
		 8.8296805857821394e-4,   0.00288502916411875494, 
		-0.00981551522729451135, -0.08175499367255420548, 
		-0.0197090243242566078,   0.51958016003260732459, 
		-5.0293922567e-10,        2.5905819115e-9, 
		 3.80069015768e-9,       -1.257928760583e-7, 
		 2.9666593806065e-7,      5.32199410651341e-6, 
		-1.466013674557952e-5,   -2.1196179800800308e-4, 
		 1.488907515797525e-4,    0.00598670133725335804, 
		 0.00917434640154761191, -0.08592436550224288681, 
		-0.1970089491453584694,   0.41202451505149651586, 
		 2.689416111e-11,        -6.0225798842e-10, 
		 7.16632287642e-9,       -3.038834206093e-8, 
		-4.9829955736697e-7,      3.6467866107985e-6, 
		 2.599276311771812e-5,   -1.6374249229498868e-4, 
		-0.00112385259950125883,  0.00342431039748960465, 
		 0.03016663018029814938, -0.02432512430353342927, 
		-0.31797371916576712163,  0.14418001571733803493, 
		 1.9463221e-12,          -1.3451327719e-10, 
		 3.36581427068e-9,        2.163920016772e-8, 
		-5.0868502638387e-7,     -1.26562372408989e-6, 
		 3.554054033687039e-5,    7.490048474688881e-5, 
		-0.0014238004200886133,  -0.00355314274445060456, 
		 0.03042001885994619102,  0.07365497405664882878, 
		-0.26882214651298246524, -0.16578636480856581212
	};
	static double c[126] =
	{
		 1.4133441141e-10,       -1.16239182574e-9, 
		 5.60813675548e-9,        4.361111919906e-8, 
		-1.9980743680592e-7,     -6.23828267379045e-6, 
		 2.659779111113435e-5,    3.4429768949740887e-4, 
		-0.00128058451746064875, -0.01165906901727504569, 
		 0.03800023545011044967,  0.13079665132249175616, 
		-0.30099732306965462304, -0.19470500862950453349, 
		 2.985070388e-11,        -4.3935370028e-10, 
		-2.70094988368e-9,        5.27013936718e-8, 
		 3.5596645009533e-7,     -5.5939305510166e-6, 
		-2.415386269153308e-5,    3.4989509210648774e-4, 
		 9.8204687587121096e-4,  -0.01241793885175385487, 
		-0.0139851984097438996,   0.16758045653582919005, 
		 0.02375823895638961834, -0.33948059288191103829, 
		 3.440543098e-11,        -1.492311224e-11, 
		-5.50307983816e-9,        2.88861169685e-9, 
		 6.5975576340131e-7,     -6.4253433004282e-7, 
		-5.095354686815779e-5,    6.35545499385876e-5, 
		 0.00231750171436134067, -0.00344140664586595266, 
		-0.04796153689875432703,  0.06553727330877767204, 
		 0.27409127395927545297, -0.17324243491898233567, 
		 1.869953108e-11,         3.5678205287e-10, 
		-3.23369443017e-9,       -4.932837601739e-8, 
		 4.0636932259569e-7,      4.55294558480472e-6, 
		-3.376596464782138e-5,   -2.5758322585307069e-4, 
		 0.00167416927479443727,  0.00735300543429220468, 
		-0.03904554680817849396, -0.07593187710651205994, 
		 0.25912851048611625179,  0.11731328614820863082, 
		-1.168499781e-11,         4.049157062e-10, 
		 1.76042185153e-9,       -5.796810963324e-8, 
		-1.7664264701199e-7,      5.65232278687159e-6, 
		 1.060939366068237e-5,   -3.4382320897779425e-4, 
		-2.8786871040915476e-4,   0.0110369660250104046, 
		 0.00105742483935856071, -0.13664188676516064192, 
		 0.02616867939853747003,  0.27020510536578747599, 
		-3.09714065e-11,          1.0275535029e-10, 
		 5.07546062007e-9,       -1.697584561546e-8, 
		-5.8222618994516e-7,      1.92483899143098e-6, 
		 4.3388818054202e-5,     -1.3714074807064326e-4, 
		-0.00184722933402281351,  0.0051736071998208299, 
		 0.03611657815299529568, -0.07491163418624572802, 
		-0.20317989938720766824,  0.17121062620272384486, 
		-2.289344046e-11,        -2.7762757821e-10, 
		 3.9133021423e-9,         3.673304032817e-8, 
		-4.7258696909223e-7,     -3.23109113206792e-6, 
		 3.749284946160478e-5,    1.7039067180362504e-4, 
		-0.00172637004639815403, -0.00454152531086626043, 
		 0.03717220530377418124,  0.04489395902785574534, 
		-0.23370422835726857839, -0.06753037249787639679, 
		 4.73299038e-12,         -4.0489249115e-10, 
		-5.6747261733e-10,        5.656135976496e-8, 
		 3.564150059329e-8,      -5.34821220288168e-6, 
		 7.581385461348e-8,       3.1190256463318867e-4, 
		-1.4634564376714538e-4,  -0.0095821355155047985, 
		 0.00624681472076521329,  0.11513529702572439703, 
		-0.05794254714300082167, -0.22523211169118786537, 
		 2.732444065e-11,        -1.7726475495e-10, 
		-4.37562701999e-9,        2.68153688556e-8, 
		 4.8799100503315e-7,     -2.76490187540644e-6, 
		-3.513357925824063e-5,    1.7693155138571443e-4, 
		 0.00144533233498513085, -0.00599106092630544975, 
		-0.02759437856689911694,  0.07945362316083459396, 
		 0.15383825653750118008, -0.17121430684466928734
	};
	static double d[52] =
	{
		 1.059601355592185731e-14,  -2.71150591218550377e-13, 
		 8.6514809056201638e-12,    -4.6264028554286627e-10, 
		 5.0815403835647104e-8,     -1.76722552048141208e-5, 
		 0.16286750396763997378,     2.949651820598278873e-13, 
		-8.818215611676125741e-12,   3.571119876162253451e-10, 
		-2.63192412099371706e-8,     4.709502795656698909e-6, 
		-0.005208333333333283282,    7.18344107717531977e-15,
		-2.51623725588410308e-13,    8.6017784918920604e-12,
		-4.6256876614290359e-10,     5.0815343220437937e-8,
		-1.7672255176494197e-5,      0.16286750396763433767,
		 2.2327570859680094777e-13, -8.464594853517051292e-12,
		 3.563766464349055183e-10,  -2.631843986737892965e-8,
		 4.70950234228865941e-6,    -0.0052083333332278466225, 
		 5.15413392842889366e-15,   -2.27740238380640162e-13, 
		 8.4827767197609014e-12,    -4.6224753682737618e-10, 
		 5.0814848128929134e-8,     -1.7672254763876748e-5, 
		 0.16286750396748926663,     1.7316195320192170887e-13, 
		-7.971122772293919646e-12,   3.544039469911895749e-10, 
		-2.631443902081701081e-8,    4.709498228695400603e-6, 
		-0.005208333331514365361,    3.84653681453798517e-15,
		-2.04464520778789011e-13,    8.3089298605177838e-12,
		-4.6155016158412096e-10,     5.081326369646665e-8,
		-1.76722528311426167e-5,     0.1628675039665006593,
		 1.3797879972460878797e-13, -7.448089381011684812e-12,
		 3.51273379710695978e-10,   -2.630500895563592722e-8,
		 4.709483934775839193e-6,   -0.0052083333227940760113
	};

	if (x < 0.85)
	{
		t = x * x;
		y = ((((((a[0] * t + a[1]) * t + 
			a[2]) * t + a[3]) * t + a[4]) * t + 
			a[5]) * t + a[6]) * t + a[7];
		y = ((((((a[8] * t + a[9]) * t + 
			a[10]) * t + a[11]) * t + a[12]) * t + 
			a[13]) * t + a[14]) * t + a[15] + y * log_core(x);
	}
	else if (x < 4.5)
	{
		t = x - 4 / x;
		k = (int) (t + 4);
		t -= k - 3.5;
		k *= 14;
		y = ((((((((((((b[k] * t + b[k + 1]) * t + 
			b[k + 2]) * t + b[k + 3]) * t + b[k + 4]) * t + 
			b[k + 5]) * t + b[k + 6]) * t + b[k + 7]) * t + 
			b[k + 8]) * t + b[k + 9]) * t + b[k + 10]) * t + 
			b[k + 11]) * t + b[k + 12]) * t + b[k + 13];
	}
	else if (x < 12.5)
	{
		k = (int) x;
		t = x - (k + 0.5);
		k = 14 * (k - 4);
		y = ((((((((((((c[k] * t + c[k + 1]) * t + 
			c[k + 2]) * t + c[k + 3]) * t + c[k + 4]) * t + 
			c[k + 5]) * t + c[k + 6]) * t + c[k + 7]) * t + 
			c[k + 8]) * t + c[k + 9]) * t + c[k + 10]) * t + 
			c[k + 11]) * t + c[k + 12]) * t + c[k + 13];
	}
	else
	{
		v = 24 / x;
		t = v * v;
		k = 13 * ((int) t);
		y = ((((((d[k] * t + d[k + 1]) * t + 
			d[k + 2]) * t + d[k + 3]) * t + d[k + 4]) * t + 
			d[k + 5]) * t + d[k + 6]) * sqrt_core(v);
		theta = (((((d[k + 7] * t + d[k + 8]) * t + 
			d[k + 9]) * t + d[k + 10]) * t + d[k + 11]) * t + 
			d[k + 12]) * v - 0.78539816339744830962;
		y *= sin_core(x + theta);
	}
	return y;
}

#if defined(__cplusplus)
}
#endif

#endif /* GML_BESSEL_Y0_DBL_INTERNAL */
