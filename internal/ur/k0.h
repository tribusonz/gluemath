/*******************************************************************************
	GLUE-Math Library: Modified Bessel Function (the 2nd kind)

	Author:
	  Takuya Ooura (Algorithm)
	  Hironobu Inatsuka aka tribusonz (ABI modify)
	License:
	  GPL + X11(MIT)
	Reference:
	  Ooura's Mathematical Software Packages
*******************************************************************************/
#ifndef GML_BESSEL_K0_DBL_INTERNAL
#define GML_BESSEL_K0_DBL_INTERNAL

#if defined(__cplusplus)
extern "C" {
#endif

#include "../../sys/float/huge_val_nan.h"
#include "../../sys/float/fpclassify.h"
#include "../sys/primitive/float/fpclassify.h"
#include "sqrt.h"
#include "exp.h"
#include "log.h"

static inline double ur_bessel_k0(double);

static inline double
k0_core(double x)
{
	switch (fpclassify(x)) {
	case FP_NAN:
		return NAN;
		break;
	case FP_INFINITE:
		return x < 0 ? NAN : 0.0;  // K_1(-Infinity) = (-0.0-Infinity*i)
		break;
	case FP_ZERO:
	case FP_SUBNORMAL:
		return HUGE_VAL;
		break;
	default:
		if (x >= 0)  return ur_bessel_k0(x);
		break;
	}
	return NAN;
}

/* Bessel K_0(x) function in double precision */
static inline double
ur_bessel_k0(double x)
{
	int k;
	double t, y;
	static double a[16] =
	{
		2.4307270476772195953e-12, 4.709166636378530437e-10, 
		6.7816861334344265568e-8,  6.7816840204737508252e-6, 
		4.3402777777915334676e-4,  0.015624999999999872796, 
		0.25000000000000000448,    0.99999999999999999997, 
		6.5878327432224993071e-12, 1.2083308769932888218e-9, 
		1.6271062073716412046e-7,  1.4914719278555277887e-5, 
		8.4603509071212245667e-4,  0.02524892993216233391, 
		0.27898287891460312491,    0.11593151565841244874
	};
	static double b[112] =
	{
		-4.6430702971053162197e-13,  1.037793605956372823e-11, 
		-1.0298475936392057807e-10,  5.3632747492333959219e-10, 
		-2.1674628861036068105e-10, -2.3316071545820437669e-8, 
		 2.2557819578691704059e-7,  -9.2325694638587080009e-7, 
		-3.3569097781613661759e-6,   8.7355061305812582974e-5, 
		-6.8021202111645760475e-4,   2.7434654781323362319e-4, 
		 0.10031787169953909561,     0.42102443824070833334, 
		 4.1447451117883103686e-12, -3.4026589638576604315e-11, 
		 9.3398790624638977468e-12,  1.518418175079985263e-9, 
		-1.1364911665083029464e-8,   2.0619457602095915719e-8, 
		 3.043101803757224363e-7,   -2.974973626447455551e-6, 
		 8.0143661611467038568e-6,   8.0937525149549218398e-5, 
		-0.0010356346549612699886,   0.0028534806627578638795, 
		 0.097369634474060441807,    0.32175066577856452683, 
		 1.117088257074072752e-13,  -8.2865909408297066068e-11, 
		 9.4656678749191182763e-10, -3.583201984184788338e-9, 
		-9.5017955656904252761e-9,   1.5200595674883329093e-7, 
		-3.866326257135605998e-7,   -3.3350340828235103499e-6, 
		 2.9359886663960844231e-5,  -1.1266401822556801563e-5, 
		-0.0012113572742435576205,   0.0063158973673701376253, 
		 0.088291790250128171341,    0.22833982383240512262, 
		-3.2880638807053948433e-11,  4.3194884830465283512e-10, 
		-1.7455089683104033093e-9,  -3.2437330799994764516e-9, 
		 4.7393655539139519778e-8,  -1.1929265603456272466e-8, 
		-1.3177845881013419388e-6,   3.3873375636197969526e-6, 
		 3.2729835880668256625e-5,  -1.8367283883002494561e-4, 
		-8.2830996454188084408e-4,   0.0095512732229514251931, 
		 0.072233832113719266702,    0.14753187103603405298, 
		 7.9998492614150860098e-11, -7.025734670268613949e-10, 
		 7.889882162708458627e-10,   1.1294796399671507085e-8, 
		-1.1360539648638059137e-8,  -3.0346309115270564487e-7, 
		 3.2235585426189451721e-7,   8.3575612102298214948e-6, 
		-8.5169628089198208211e-6,  -2.5740175232173357342e-4, 
		 1.246273401468915277e-4,    0.01068323286919220345, 
		 0.051515690033637395779,    0.085465862953544883657, 
		-8.6111506537356531608e-11,  5.1862926131024597823e-10, 
		 7.5884324949371110022e-10, -6.4011975813006767417e-9, 
		-4.1966181325111763156e-8,   9.1306285446881485314e-8, 
		 1.3573638315827954034e-6,   4.8683213252735694701e-7, 
		-3.8805424608710197066e-5,  -1.183898646868898061e-4, 
		 9.2796213947750964945e-4,   0.0089611057737319027776, 
		 0.031464453915862785606,    0.04426764808753663078, 
		 4.4400123834164610288e-11, -1.1411233140911074336e-10, 
		-8.820067070246705983e-10,  -1.9686735373323381456e-9, 
		 1.9921120728941773855e-8,   1.454397441858483474e-7, 
		 1.8238418041265854754e-8,  -4.5363700392899066037e-6, 
		-2.1688068222527688542e-5,   4.54960621666870347e-5, 
		 0.0010435238076080528284,   0.0058374528996419979931, 
		 0.01661121071042545585,     0.020756008367065750538, 
		-6.5166519951106397214e-12, -5.857218285878853958e-11, 
		 1.5550375065815375404e-10,  1.9526509484993563229e-9, 
		 9.2637123346818426594e-9,  -1.4136471501812055943e-8, 
		-4.3024895710889717172e-7,  -2.3235612243330592076e-6, 
		 4.0380616133862188804e-7,   9.2783767992909743602e-5, 
		 7.2964887597817095035e-4,   0.0031316245282223273413, 
		 0.0078028233022066428316,   0.0090014807263791058095
	};
	static double c[135] =
	{
		 4.5161032649342790231e-11, -4.2774336988557091369e-11, 
		 6.0998467173896677777e-10,  1.9845167242599996944e-9, 
		 1.3097678767280215271e-8,   7.4505822268382641286e-8, 
		 4.2893920879106814989e-7,   2.3900851955655303104e-6, 
		 1.2533473009382380357e-5,   5.9693359063879871983e-5, 
		 2.477507066108730458e-4,    8.5106703131389516508e-4, 
		 0.0022500105115665788755,   0.00404461344545216346, 
		 0.0036910983340425942762,   3.5732826433251464989e-12,
		-3.2906649482312266258e-12,  7.0873811190464760555e-11,
		 2.955132058048417712e-10,   2.2776940472505079894e-9,
		 1.5175463612815010036e-8,   9.9462487812170164133e-8,
		 6.14487577978539011e-7,     3.486953188290736075e-6,
		 1.7615836644757657443e-5,   7.6373536037879531886e-5,
		 2.7098571871205999668e-4,   7.3399047381788927036e-4,
		 0.0013439197177355085297,   0.0012439943280131230863, 
		 3.6343547836242523646e-13,  9.7997961751276137602e-14, 
		 1.0184692699811569047e-11,  6.1495184828957652064e-11, 
		 5.0238328349302602543e-10,  3.7498626376004337661e-9, 
		 2.6689445483857236307e-8,   1.7591899737346368084e-7, 
		 1.0486448307010701679e-6,   5.4986458466257148573e-6, 
		 2.4521456351751345323e-5,   8.8900942259143832228e-5, 
		 2.448394771406830019e-4,    4.5418248688489693045e-4, 
		 4.2479574186923180694e-4,   5.2460389348163395857e-14,
		 7.480206302650350354e-14,   2.0012201610651998417e-12,
		 1.4887306044735163359e-11,  1.294670541423294035e-10,
		 1.0391628915892803144e-9,   7.8091180499677328456e-9,
		 5.3694223626907660084e-8,   3.3063914804658509029e-7,
		 1.7776972424421486506e-6,   8.0833148098458320202e-6,
		 2.975555630444881778e-5,    8.2945928349220642178e-5,
		 1.5536921180500112883e-4,   1.4647070522281538711e-4, 
		 9.7531436733955514559e-15,  2.4084291220447154982e-14, 
		 4.7654956400897494468e-13,  4.0200949504810597783e-12, 
		 3.6726577109162191533e-11,  3.0939005665422637601e-10, 
		 2.4122848979784500179e-9,   1.7071884462645525505e-8, 
		 1.0752238955654933405e-7,   5.8844190041189462347e-7, 
		 2.7136083303224014597e-6,   1.0102477728604441135e-5, 
		 2.8420490721532571809e-5,   5.3637016379451944413e-5, 
		 5.0881312956459247572e-5,   2.173204986818937726e-15,
		 7.2720052142815590531e-15,  1.28030837955368201e-13,
		 1.1696825543787717167e-12,  1.1083298191597132094e-11,
		 9.6536661252658773139e-11,  7.7242553835198536397e-10,
		 5.579836626711057562e-9,    3.572134529654341437e-8,
		 1.9806931547193682466e-7,   9.2312964655319555313e-7,
		 3.4666258590861079959e-6,   9.8224698307751177077e-6,
		 1.8648773453825584428e-5,   1.7780062316167651812e-5, 
		 5.5012463763851934112e-16,  2.2254763392767319419e-15, 
		 3.7187669817701214965e-14,  3.5819585377733489628e-13, 
		 3.4866061263191556694e-12,  3.110163345062965291e-11, 
		 2.5358235662235617663e-10,  1.8597629779492599046e-9, 
		 1.2052654739462999992e-8,   6.7501417351172136833e-8, 
		 3.1720052198654584574e-7,   1.1993651363602981832e-6, 
		 3.4179130317623363474e-6,   6.5208606745808860158e-6, 
		 6.2430205476536771454e-6,   1.5225407517829491689e-16,
		 6.9834820025664405161e-16,  1.1380182837138781431e-14,
		 1.1369488761077196511e-13,  1.1291168681618466716e-12,
		 1.0250757630526871007e-11,  8.4765287317253141514e-11,
		 6.2886627779402596211e-10,  4.1142865598366029316e-9,
		 2.3223773435632014408e-8,   1.0985095234166396934e-7,
		 4.1766260951820336228e-7,   1.1958609263543792991e-6,
		 2.2907574647671878055e-6,   2.2008253973114914005e-6, 
		 4.4863058691420695911e-17,  2.2437356594371819978e-16, 
		 3.6107964803015652759e-15,  3.7031193629853392081e-14, 
		 3.7341552790439784371e-13,  3.4355950129497564468e-12, 
		 2.8719942600171304499e-11,  2.1499646844509516453e-10, 
		 1.4171810843455227171e-9,   8.0501118772875784153e-9, 
		 3.8281889106330295876e-8,   1.4621673458431979989e-7, 
		 4.2029868696411098586e-7,   8.0785884122023473025e-7, 
		 7.7845438614204963209e-7
	};
	static double d[40] =
	{
		-7.9737703860537066166e-14, 1.9543834380466766627e-12, 
		-4.7230794431646733538e-11, 1.4001773785771252004e-9, 
		-5.4864553020583098585e-8,  3.1601984250143742772e-6, 
		-3.3708783204090252161e-4,  0.16180215937964160437, 
		-5.2593898374798632343e-14, 1.7725913926973236457e-12, 
		-4.6672234858122387294e-11, 1.3991653503828889207e-9, 
		-5.4863400156413929639e-8,  3.1601976099900075541e-6, 
		-3.3708783171335864627e-4,  0.1618021593795843376, 
		-3.6135496189875398132e-14, 1.5466239429618130284e-12, 
		-4.5320259146602122624e-11, 1.3945974109459385552e-9, 
		-5.4853994841172088787e-8,  3.1601858228022739196e-6, 
		-3.370878233999830232e-4,   0.16180215937704286491, 
		-2.5640663123518180635e-14, 1.3288079339404032671e-12, 
		-4.3368537955908371563e-11, 1.3848103653102203186e-9, 
		-5.4824335664256344123e-8,  3.1601315173126153586e-6, 
		-3.370877677903569564e-4,   0.16180215935248373474, 
		-1.8678321325292127767e-14, 1.1354310934105733311e-12, 
		-4.1057197297998608931e-11, 1.369399096129635097e-9, 
		-5.4762428935047089835e-8,  3.1599817092775027963e-6, 
		-3.3708756559715893599e-4,  0.1618021592350814424
	};

	if (x < 0.86)
	{
		t = x * x;
		y = ((((((a[0] * t + a[1]) * t + 
			a[2]) * t + a[3]) * t + a[4]) * t + 
			a[5]) * t + a[6]) * t + a[7];
		y = ((((((a[8] * t + a[9]) * t + 
			a[10]) * t + a[11]) * t + a[12]) * t + 
			a[13]) * t + a[14]) * t + a[15] - y * log_core(x);
	}
	else if (x < 4.15)
	{
		t = x - 5 / x;
		k = (int) (t + 5);
		t = (k - 4) - t;
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
		t = (k + 1) - x;
		k = 15 * (k - 4);
		y = (((((((((((((c[k] * t + c[k + 1]) * t + 
			c[k + 2]) * t + c[k + 3]) * t + c[k + 4]) * t + 
			c[k + 5]) * t + c[k + 6]) * t + c[k + 7]) * t + 
			c[k + 8]) * t + c[k + 9]) * t + c[k + 10]) * t + 
			c[k + 11]) * t + c[k + 12]) * t + c[k + 13]) * t + 
			c[k + 14];
	}
	else
	{
		t = 60 / x;
		k = 8 * ((int) t);
		y = (((((((d[k] * t + d[k + 1]) * t + 
			d[k + 2]) * t + d[k + 3]) * t + d[k + 4]) * t + 
			d[k + 5]) * t + d[k + 6]) * t + d[k + 7]) * 
			sqrt_core(t) * exp_core(-x);
	}
	return y;
}

#if defined(__cplusplus)
}
#endif

#endif /* GML_BESSEL_K0_DBL_INTERNAL */
