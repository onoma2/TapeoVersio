#include "TapeoVersio_2dworking.h"

namespace TapeoVersio_2dworking {

/*******************************************************************************************************************
Cycling '74 License for Max-Generated Code for Export
Copyright (c) 2016 Cycling '74
The code that Max generates automatically and that end users are capable of exporting and using, and any
  associated documentation files (the “Software”) is a work of authorship for which Cycling '74 is the author
  and owner for copyright purposes.  A license is hereby granted, free of charge, to any person obtaining a
  copy of the Software (“Licensee”) to use, copy, modify, merge, publish, and distribute copies of the Software,
  and to permit persons to whom the Software is furnished to do so, subject to the following conditions:
The Software is licensed to Licensee only for non-commercial use. Users who wish to make commercial use of the
  Software must contact the copyright owner to determine if a license for commercial use is available, and the
  terms and conditions for same, which may include fees or royalties. For commercial use, please send inquiries
  to licensing (at) cycling74.com.  The determination of whether a use is commercial use or non-commercial use is based
  upon the use, not the user. The Software may be used by individuals, institutions, governments, corporations, or
  other business whether for-profit or non-profit so long as the use itself is not a commercialization of the
  materials or a use that generates or is intended to generate income, revenue, sales or profit.
The above copyright notice and this license shall be included in all copies or substantial portions of the Software.
THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO
  THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT. IN NO EVENT SHALL
  THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF
  CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
  DEALINGS IN THE SOFTWARE.
*******************************************************************************************************************/

// global noise generator
Noise noise;
static const int GENLIB_LOOPCOUNT_BAIL = 100000;


// The State struct contains all the state and procedures for the gendsp kernel
typedef struct State {
	CommonState __commonstate;
	DCBlock __m_dcblock_98;
	DCBlock __m_dcblock_86;
	Delay m_delay_4;
	Delay m_delay_3;
	Delta __m_delta_64;
	Phasor __m_phasor_81;
	Phasor __m_phasor_93;
	Phasor __m_phasor_74;
	PlusEquals __m_pluseq_65;
	Rate __m_rate_75;
	SineCycle __m_cycle_76;
	SineData __sinedata;
	int __exception;
	int vectorsize;
	t_sample __m_slide_55;
	t_sample m_history_11;
	t_sample __m_slide_52;
	t_sample __m_slide_58;
	t_sample __m_slide_61;
	t_sample __m_slide_49;
	t_sample __m_slide_46;
	t_sample __m_count_45;
	t_sample __m_count_42;
	t_sample m_history_9;
	t_sample __m_count_43;
	t_sample __m_count_44;
	t_sample m_history_8;
	t_sample __m_count_66;
	t_sample __m_latch_67;
	t_sample m_history_1;
	t_sample m_history_2;
	t_sample __m_slide_83;
	t_sample samplerate;
	t_sample m_gate_39;
	t_sample m_history_5;
	t_sample m_history_7;
	t_sample __m_slide_68;
	t_sample m_history_6;
	t_sample __m_slide_71;
	t_sample samples_to_seconds;
	t_sample m_history_10;
	t_sample m_ctrl_38;
	t_sample m_ctrl_36;
	t_sample m_history_19;
	t_sample m_history_18;
	t_sample m_history_20;
	t_sample m_history_21;
	t_sample m_history_22;
	t_sample m_history_17;
	t_sample m_history_15;
	t_sample m_history_12;
	t_sample m_history_16;
	t_sample m_history_13;
	t_sample m_history_14;
	t_sample m_ctrl_37;
	t_sample m_history_23;
	t_sample m_history_25;
	t_sample m_ctrl_33;
	t_sample __m_slide_95;
	t_sample m_ctrl_34;
	t_sample m_ctrl_35;
	t_sample m_history_24;
	t_sample m_sw_31;
	t_sample m_button_29;
	t_sample m_history_26;
	t_sample m_ctrl_30;
	t_sample m_history_27;
	t_sample m_history_28;
	t_sample m_sw_32;
	// re-initialize all member variables;
	inline void reset(t_param __sr, int __vs) {
		__exception = 0;
		vectorsize = __vs;
		samplerate = __sr;
		m_history_1 = ((int)0);
		m_history_2 = ((int)0);
		m_delay_3.reset("m_delay_3", ((int)192000));
		m_delay_4.reset("m_delay_4", ((int)192000));
		m_history_5 = ((int)0);
		m_history_6 = ((int)0);
		m_history_7 = ((int)0);
		m_history_8 = ((int)0);
		m_history_9 = ((int)0);
		m_history_10 = ((int)0);
		m_history_11 = ((int)0);
		m_history_12 = ((int)0);
		m_history_13 = ((int)0);
		m_history_14 = ((int)0);
		m_history_15 = ((int)0);
		m_history_16 = ((int)0);
		m_history_17 = ((int)0);
		m_history_18 = ((int)0);
		m_history_19 = ((int)0);
		m_history_20 = ((int)0);
		m_history_21 = ((int)0);
		m_history_22 = ((int)0);
		m_history_23 = ((int)0);
		m_history_24 = ((int)0);
		m_history_25 = ((int)0);
		m_history_26 = ((int)0);
		m_history_27 = ((int)0);
		m_history_28 = ((int)0);
		m_button_29 = ((int)0);
		m_ctrl_30 = ((int)0);
		m_sw_31 = ((int)0);
		m_sw_32 = ((int)0);
		m_ctrl_33 = ((int)0);
		m_ctrl_34 = ((int)0);
		m_ctrl_35 = ((int)0);
		m_ctrl_36 = ((int)0);
		m_ctrl_37 = ((int)0);
		m_ctrl_38 = ((int)0);
		m_gate_39 = ((int)0);
		__m_count_42 = 0;
		__m_count_43 = 0;
		__m_count_44 = 0;
		__m_count_45 = 0;
		__m_slide_46 = 0;
		__m_slide_49 = 0;
		__m_slide_52 = 0;
		__m_slide_55 = 0;
		__m_slide_58 = 0;
		__m_slide_61 = 0;
		__m_delta_64.reset(0);
		__m_pluseq_65.reset(0);
		__m_count_66 = 0;
		__m_latch_67 = 0;
		__m_slide_68 = 0;
		__m_slide_71 = 0;
		samples_to_seconds = (1 / samplerate);
		__m_phasor_74.reset(0);
		__m_rate_75.reset();
		__m_cycle_76.reset(samplerate, 0);
		__m_phasor_81.reset(0);
		__m_slide_83 = 0;
		__m_dcblock_86.reset();
		__m_phasor_93.reset(0);
		__m_slide_95 = 0;
		__m_dcblock_98.reset();
		genlib_reset_complete(this);
		
	};
	// the signal processing routine;
	inline int perform(t_sample ** __ins, t_sample ** __outs, int __n) {
		vectorsize = __n;
		const t_sample * __in1 = __ins[0];
		const t_sample * __in2 = __ins[1];
		t_sample * __out1 = __outs[0];
		t_sample * __out2 = __outs[1];
		t_sample * __out3 = __outs[2];
		t_sample * __out4 = __outs[3];
		t_sample * __out5 = __outs[4];
		t_sample * __out6 = __outs[5];
		t_sample * __out7 = __outs[6];
		t_sample * __out8 = __outs[7];
		t_sample * __out9 = __outs[8];
		if (__exception) {
			return __exception;
			
		} else if (( (__in1 == 0) || (__in2 == 0) || (__out1 == 0) || (__out2 == 0) || (__out3 == 0) || (__out4 == 0) || (__out5 == 0) || (__out6 == 0) || (__out7 == 0) || (__out8 == 0) || (__out9 == 0) )) {
			__exception = GENLIB_ERR_NULL_BUFFER;
			return __exception;
			
		};
		t_sample sub_2750 = (m_sw_31 - ((int)0));
		t_sample scale_2747 = ((safepow((sub_2750 * ((t_sample)1)), ((int)1)) * ((int)2)) + ((int)1));
		t_sample choice_40 = int(scale_2747);
		t_sample choice_41 = int(scale_2747);
		t_sample iup_47 = (1 / maximum(1, abs(((int)4000))));
		t_sample idown_48 = (1 / maximum(1, abs(((int)4000))));
		t_sample sub_2764 = (m_sw_32 - ((int)0));
		t_sample scale_2761 = ((safepow((sub_2764 * ((t_sample)1)), ((int)1)) * ((int)2)) + ((int)1));
		t_sample iup_50 = (1 / maximum(1, abs(((int)4000))));
		t_sample idown_51 = (1 / maximum(1, abs(((int)4000))));
		t_sample iup_53 = (1 / maximum(1, abs(((int)4000))));
		t_sample idown_54 = (1 / maximum(1, abs(((int)4000))));
		t_sample iup_56 = (1 / maximum(1, abs(((int)4000))));
		t_sample idown_57 = (1 / maximum(1, abs(((int)4000))));
		t_sample iup_59 = (1 / maximum(1, abs(((int)4000))));
		t_sample idown_60 = (1 / maximum(1, abs(((int)4000))));
		t_sample iup_62 = (1 / maximum(1, abs(((int)3000))));
		t_sample idown_63 = (1 / maximum(1, abs(((int)3000))));
		int or_2365 = (m_gate_39 || m_button_29);
		t_sample iup_69 = (1 / maximum(1, abs(((int)4000))));
		t_sample idown_70 = (1 / maximum(1, abs(((int)4000))));
		t_sample iup_72 = (1 / maximum(1, abs(((int)3000))));
		t_sample idown_73 = (1 / maximum(1, abs(((int)3000))));
		samples_to_seconds = (1 / samplerate);
		t_sample choice_77 = int(scale_2747);
		t_sample choice_78 = int(scale_2747);
		t_sample choice_79 = int(scale_2747);
		t_sample choice_80 = int(scale_2747);
		t_sample choice_82 = int(scale_2761);
		t_sample iup_84 = (1 / maximum(1, abs(((int)3000))));
		t_sample idown_85 = (1 / maximum(1, abs(((int)3000))));
		t_sample min_87 = (-0.9);
		t_sample choice_88 = int(scale_2747);
		int min_89 = (-1);
		t_sample choice_90 = int(scale_2747);
		t_sample choice_91 = int(scale_2747);
		int min_92 = (-1);
		t_sample choice_94 = int(scale_2761);
		t_sample iup_96 = (1 / maximum(1, abs(((int)3000))));
		t_sample idown_97 = (1 / maximum(1, abs(((int)3000))));
		t_sample min_99 = (-0.9);
		t_sample choice_100 = int(scale_2747);
		int min_101 = (-1);
		t_sample choice_102 = int(scale_2747);
		t_sample choice_103 = int(scale_2747);
		int min_104 = (-1);
		// the main sample loop;
		while ((__n--)) {
			const t_sample in1 = (*(__in1++));
			const t_sample in2 = (*(__in2++));
			t_sample out7 = ((int)0);
			t_sample out8 = ((int)0);
			t_sample gate_2213 = (((choice_40 >= 1) && (choice_40 < 2)) ? in1 : 0);
			t_sample gate_2214 = (((choice_40 >= 2) && (choice_40 < 3)) ? in1 : 0);
			t_sample gate_2215 = ((choice_40 >= 3) ? in1 : 0);
			t_sample gate_2175 = (((choice_41 >= 1) && (choice_41 < 2)) ? in2 : 0);
			t_sample gate_2176 = (((choice_41 >= 2) && (choice_41 < 3)) ? in2 : 0);
			t_sample gate_2177 = ((choice_41 >= 3) ? in2 : 0);
			__m_count_42 = (((int)0) ? 0 : (fixdenorm(__m_count_42 + ((int)1))));
			int counter_2245 = __m_count_42;
			int counter_2246 = ((int)0);
			int counter_2247 = ((int)0);
			int lt_2244 = (counter_2245 < ((int)300000));
			__m_count_43 = (((int)0) ? 0 : (fixdenorm(__m_count_43 + ((int)1))));
			int counter_2239 = __m_count_43;
			int counter_2240 = ((int)0);
			int counter_2241 = ((int)0);
			int lt_2238 = (counter_2239 < ((int)300000));
			__m_count_44 = (((int)0) ? 0 : (fixdenorm(__m_count_44 + ((int)1))));
			int counter_2227 = __m_count_44;
			int counter_2228 = ((int)0);
			int counter_2229 = ((int)0);
			int lt_2226 = (counter_2227 < ((int)300000));
			t_sample abs_2221 = fabs(in2);
			t_sample rsub_2220 = (((int)0) - abs_2221);
			t_sample switch_2225 = (lt_2226 ? ((t_sample)-0.99) : rsub_2220);
			t_sample out4 = switch_2225;
			__m_count_45 = (((int)0) ? 0 : (fixdenorm(__m_count_45 + ((int)1))));
			int counter_2233 = __m_count_45;
			int counter_2234 = ((int)0);
			int counter_2235 = ((int)0);
			int lt_2232 = (counter_2233 < ((int)300000));
			t_sample abs_2223 = fabs(in1);
			t_sample rsub_2222 = (((int)0) - abs_2223);
			t_sample switch_2231 = (lt_2232 ? ((int)0) : rsub_2222);
			t_sample out3 = switch_2231;
			t_sample mix_2751 = (m_history_28 + (((t_sample)0.0042742627044161) * (m_ctrl_30 - m_history_28)));
			t_sample mix_534 = mix_2751;
			t_sample mix_2752 = (m_history_27 + (((t_sample)0.0042742627044161) * (mix_534 - m_history_27)));
			t_sample mix_532 = mix_2752;
			t_sample mix_2753 = (m_history_26 + (((t_sample)0.0042742627044161) * (mix_532 - m_history_26)));
			t_sample mix_530 = mix_2753;
			t_sample gen_2341 = mix_530;
			t_sample history_535_next_537 = fixdenorm(mix_534);
			t_sample history_533_next_538 = fixdenorm(mix_532);
			t_sample history_531_next_539 = fixdenorm(mix_530);
			__m_slide_46 = fixdenorm((__m_slide_46 + (((gen_2341 > __m_slide_46) ? iup_47 : idown_48) * (gen_2341 - __m_slide_46))));
			t_sample slide_2205 = __m_slide_46;
			t_sample mix_2754 = (m_history_25 + (((t_sample)0.0042742627044161) * (m_ctrl_35 - m_history_25)));
			t_sample mix_2371 = mix_2754;
			t_sample mix_2755 = (m_history_24 + (((t_sample)0.0042742627044161) * (mix_2371 - m_history_24)));
			t_sample mix_2369 = mix_2755;
			t_sample mix_2756 = (m_history_23 + (((t_sample)0.0042742627044161) * (mix_2369 - m_history_23)));
			t_sample mix_2374 = mix_2756;
			t_sample gen_2336 = mix_2374;
			t_sample history_535_next_2375 = fixdenorm(mix_2371);
			t_sample history_533_next_2370 = fixdenorm(mix_2369);
			t_sample history_531_next_2377 = fixdenorm(mix_2374);
			t_sample sub_2760 = (gen_2336 - ((int)0));
			t_sample scale_2757 = ((safepow((sub_2760 * ((t_sample)1)), ((int)1)) * ((int)50)) + ((int)0));
			t_sample mix_2765 = (m_history_22 + (((t_sample)0.0042742627044161) * (m_ctrl_36 - m_history_22)));
			t_sample mix_2390 = mix_2765;
			t_sample mix_2766 = (m_history_21 + (((t_sample)0.0042742627044161) * (mix_2390 - m_history_21)));
			t_sample mix_2382 = mix_2766;
			t_sample mix_2767 = (m_history_20 + (((t_sample)0.0042742627044161) * (mix_2382 - m_history_20)));
			t_sample mix_2389 = mix_2767;
			t_sample gen_2338 = mix_2389;
			t_sample history_535_next_2386 = fixdenorm(mix_2390);
			t_sample history_533_next_2383 = fixdenorm(mix_2382);
			t_sample history_531_next_2391 = fixdenorm(mix_2389);
			t_sample TIME_2324 = gen_2338;
			t_sample sub_2771 = (TIME_2324 - ((int)0));
			t_sample scale_2768 = ((safepow((sub_2771 * ((t_sample)1)), ((int)1)) * ((int)2)) + (-1));
			t_sample scale_2291 = scale_2768;
			int gte_2290 = (scale_2291 >= ((int)0));
			t_sample abs_2289 = fabs(scale_2291);
			t_sample add_2310 = (abs_2289 + ((t_sample)0.001));
			t_sample mul_2312 = (add_2310 * ((int)3));
			t_sample ceil_2311 = ceil(mul_2312);
			t_sample div_2294 = safediv(((int)1), ceil_2311);
			t_sample switch_2292 = (gte_2290 ? ceil_2311 : div_2294);
			t_sample NR_2350 = switch_2292;
			t_sample out9 = NR_2350;
			t_sample mix_2772 = (m_history_19 + (((t_sample)0.0042742627044161) * (m_ctrl_38 - m_history_19)));
			t_sample mix_2403 = mix_2772;
			t_sample mix_2773 = (m_history_18 + (((t_sample)0.0042742627044161) * (mix_2403 - m_history_18)));
			t_sample mix_2395 = mix_2773;
			t_sample mix_2774 = (m_history_17 + (((t_sample)0.0042742627044161) * (mix_2395 - m_history_17)));
			t_sample mix_2402 = mix_2774;
			t_sample gen_2340 = mix_2402;
			t_sample history_535_next_2399 = fixdenorm(mix_2403);
			t_sample history_533_next_2396 = fixdenorm(mix_2395);
			t_sample history_531_next_2404 = fixdenorm(mix_2402);
			t_sample TONE_2307 = gen_2340;
			__m_slide_49 = fixdenorm((__m_slide_49 + (((TONE_2307 > __m_slide_49) ? iup_50 : idown_51) * (TONE_2307 - __m_slide_49))));
			t_sample slide_2203 = __m_slide_49;
			t_sample sub_2778 = (TONE_2307 - ((int)0));
			t_sample scale_2775 = ((safepow((sub_2778 * ((t_sample)1)), ((int)1)) * ((int)2)) + (-1));
			t_sample scale_2208 = scale_2775;
			t_sample sub_2782 = (scale_2208 - (-1));
			t_sample scale_2779 = ((safepow((sub_2782 * ((t_sample)1)), ((int)1)) * ((t_sample)-0.99)) + ((t_sample)0.99));
			t_sample scale_2304 = scale_2779;
			__m_slide_52 = fixdenorm((__m_slide_52 + (((scale_2304 > __m_slide_52) ? iup_53 : idown_54) * (scale_2304 - __m_slide_52))));
			t_sample slide_2204 = __m_slide_52;
			t_sample clamp_2318 = ((slide_2204 <= ((int)0)) ? ((int)0) : ((slide_2204 >= ((t_sample)0.99)) ? ((t_sample)0.99) : slide_2204));
			t_sample clamp_2197 = ((slide_2204 <= ((int)0)) ? ((int)0) : ((slide_2204 >= ((t_sample)0.99)) ? ((t_sample)0.99) : slide_2204));
			__m_slide_55 = fixdenorm((__m_slide_55 + (((TONE_2307 > __m_slide_55) ? iup_56 : idown_57) * (TONE_2307 - __m_slide_55))));
			t_sample slide_2167 = __m_slide_55;
			t_sample mix_2783 = (m_history_16 + (((t_sample)0.0042742627044161) * (m_ctrl_33 - m_history_16)));
			t_sample mix_2413 = mix_2783;
			t_sample mix_2784 = (m_history_15 + (((t_sample)0.0042742627044161) * (mix_2413 - m_history_15)));
			t_sample mix_2408 = mix_2784;
			t_sample mix_2785 = (m_history_14 + (((t_sample)0.0042742627044161) * (mix_2408 - m_history_14)));
			t_sample mix_2417 = mix_2785;
			t_sample gen_2342 = mix_2417;
			t_sample history_535_next_2412 = fixdenorm(mix_2413);
			t_sample history_533_next_2409 = fixdenorm(mix_2408);
			t_sample history_531_next_2416 = fixdenorm(mix_2417);
			t_sample sub_2789 = (gen_2342 - ((int)0));
			t_sample scale_2786 = ((safepow((sub_2789 * ((t_sample)1)), ((int)1)) * ((t_sample)0.998)) + ((t_sample)0.001));
			__m_slide_58 = fixdenorm((__m_slide_58 + (((scale_2786 > __m_slide_58) ? iup_59 : idown_60) * (scale_2786 - __m_slide_58))));
			t_sample slide_2202 = __m_slide_58;
			t_sample mul_2258 = (in1 * ((int)2));
			t_sample abs_2263 = fabs(mul_2258);
			int gt_2262 = (abs_2263 > ((t_sample)0.85));
			int gt_2272 = (gt_2262 > m_history_13);
			t_sample sub_2269 = (gt_2262 - m_history_13);
			t_sample mul_2268 = (sub_2269 * ((t_sample)0.005));
			t_sample mul_2267 = (sub_2269 * ((t_sample)0.001));
			t_sample switch_2270 = (gt_2272 ? mul_2268 : mul_2267);
			t_sample add_2271 = (m_history_13 + switch_2270);
			t_sample rsub_2260 = (((int)1) - add_2271);
			t_sample mix_2790 = (add_2271 + (((int)0) * (rsub_2260 - add_2271)));
			t_sample history_2273_next_2275 = fixdenorm(add_2271);
			t_sample sub_2794 = (mix_2790 - ((int)0));
			t_sample scale_2791 = ((safepow((sub_2794 * ((t_sample)1)), ((int)1)) * ((int)-1)) + ((int)1));
			t_sample sub_2798 = (mix_2790 - ((int)0));
			t_sample scale_2795 = ((safepow((sub_2798 * ((t_sample)1)), ((int)1)) * ((t_sample)0.7)) + ((t_sample)0.3));
			t_sample mul_2146 = (in2 * ((int)2));
			t_sample abs_2151 = fabs(mul_2146);
			int gt_2150 = (abs_2151 > ((t_sample)0.85));
			int gt_2160 = (gt_2150 > m_history_12);
			t_sample sub_2157 = (gt_2150 - m_history_12);
			t_sample mul_2156 = (sub_2157 * ((t_sample)0.005));
			t_sample mul_2155 = (sub_2157 * ((t_sample)0.001));
			t_sample switch_2158 = (gt_2160 ? mul_2156 : mul_2155);
			t_sample add_2159 = (m_history_12 + switch_2158);
			t_sample rsub_2148 = (((int)1) - add_2159);
			t_sample mix_2799 = (add_2159 + (((int)0) * (rsub_2148 - add_2159)));
			t_sample history_2161_next_2163 = fixdenorm(add_2159);
			t_sample sub_2803 = (mix_2799 - ((int)0));
			t_sample scale_2800 = ((safepow((sub_2803 * ((t_sample)1)), ((int)1)) * ((int)-1)) + ((int)1));
			t_sample sub_2807 = (mix_2799 - ((int)0));
			t_sample scale_2804 = ((safepow((sub_2807 * ((t_sample)1)), ((int)1)) * ((t_sample)0.7)) + ((t_sample)0.3));
			t_sample mix_2808 = (m_history_11 + (((t_sample)0.0042742627044161) * (m_ctrl_34 - m_history_11)));
			t_sample mix_2430 = mix_2808;
			t_sample mix_2809 = (m_history_10 + (((t_sample)0.0042742627044161) * (mix_2430 - m_history_10)));
			t_sample mix_2421 = mix_2809;
			t_sample mix_2810 = (m_history_9 + (((t_sample)0.0042742627044161) * (mix_2421 - m_history_9)));
			t_sample mix_2429 = mix_2810;
			t_sample gen_2337 = mix_2429;
			t_sample history_535_next_2424 = fixdenorm(mix_2430);
			t_sample history_533_next_2422 = fixdenorm(mix_2421);
			t_sample history_531_next_2425 = fixdenorm(mix_2429);
			t_sample sub_2814 = (gen_2337 - ((int)0));
			t_sample scale_2811 = ((safepow((sub_2814 * ((t_sample)1)), ((t_sample)1.5)) * ((t_sample)0.5)) + ((int)0));
			__m_slide_61 = fixdenorm((__m_slide_61 + (((scale_2811 > __m_slide_61) ? iup_62 : idown_63) * (scale_2811 - __m_slide_61))));
			t_sample slide_2297 = __m_slide_61;
			int delta_2361 = __m_delta_64(or_2365);
			int gtep_2360 = ((delta_2361 >= ((int)1)) ? delta_2361 : 0);
			t_sample plusequals_2359 = __m_pluseq_65.post(gtep_2360, m_history_8, 0);
			int eq_2357 = (plusequals_2359 == ((int)2));
			__m_count_66 = (m_history_8 ? 0 : (fixdenorm(__m_count_66 + plusequals_2359)));
			t_sample counter_2354 = __m_count_66;
			int counter_2355 = ((int)0);
			int counter_2356 = ((int)0);
			__m_latch_67 = ((eq_2357 != 0) ? counter_2354 : __m_latch_67);
			t_sample latch_2353 = __m_latch_67;
			t_sample gen_2363 = latch_2353;
			t_sample history_2358_next_2362 = fixdenorm(eq_2357);
			t_sample CLOCK_2323 = gen_2363;
			t_sample div_2313 = safediv(CLOCK_2323, switch_2292);
			__m_slide_68 = fixdenorm((__m_slide_68 + (((div_2313 > __m_slide_68) ? iup_69 : idown_70) * (div_2313 - __m_slide_68))));
			t_sample slide_2320 = __m_slide_68;
			t_sample div_2251 = (div_2313 * ((t_sample)2.0833333333333e-05));
			t_sample div_2140 = (div_2313 * ((t_sample)2.0833333333333e-05));
			t_sample mix_2815 = (m_history_7 + (((t_sample)0.0042742627044161) * (m_ctrl_37 - m_history_7)));
			t_sample mix_2438 = mix_2815;
			t_sample mix_2816 = (m_history_6 + (((t_sample)0.0042742627044161) * (mix_2438 - m_history_6)));
			t_sample mix_2434 = mix_2816;
			t_sample mix_2817 = (m_history_5 + (((t_sample)0.0042742627044161) * (mix_2434 - m_history_5)));
			t_sample mix_2443 = mix_2817;
			t_sample gen_2339 = mix_2443;
			t_sample history_535_next_2441 = fixdenorm(mix_2438);
			t_sample history_533_next_2435 = fixdenorm(mix_2434);
			t_sample history_531_next_2442 = fixdenorm(mix_2443);
			t_sample MOD_2325 = gen_2339;
			t_sample sub_2821 = (MOD_2325 - ((int)0));
			t_sample scale_2818 = ((safepow((sub_2821 * ((t_sample)1)), ((int)1)) * ((t_sample)0.44)) + ((t_sample)0.55));
			t_sample scale_2327 = scale_2818;
			t_sample sub_2825 = (scale_2327 - ((t_sample)0.55));
			t_sample scale_2822 = ((safepow((sub_2825 * ((t_sample)2.2727272727273)), ((int)1)) * ((t_sample)-0.44)) + ((t_sample)0.99));
			t_sample scale_2326 = scale_2822;
			__m_slide_71 = fixdenorm((__m_slide_71 + (((scale_2326 > __m_slide_71) ? iup_72 : idown_73) * (scale_2326 - __m_slide_71))));
			t_sample slide_2306 = __m_slide_71;
			t_sample sub_2829 = (TIME_2324 - ((int)0));
			t_sample scale_2826 = ((safepow((sub_2829 * ((t_sample)1)), ((int)1)) * ((t_sample)0.499)) + ((t_sample)0.001));
			t_sample scale_2331 = scale_2826;
			t_sample phasor_2334 = __m_phasor_74(scale_2331, samples_to_seconds);
			t_sample rate_2335 = __m_rate_75.perform_off(phasor_2334, ((int)1));
			__m_cycle_76.phase(rate_2335);
			t_sample cycle_2332 = __m_cycle_76(__sinedata);
			t_sample cycleindex_2333 = __m_cycle_76.phase();
			t_sample div_2329 = (cycle_2332 * ((t_sample)0.125));
			t_sample add_2328 = (div_2329 + ((t_sample)0.5));
			t_sample mix_2830 = (add_2328 + (slide_2306 * (((int)1) - add_2328)));
			t_sample mix_2330 = mix_2830;
			t_sample modulation_2248 = mix_2330;
			t_sample modulation_2315 = modulation_2248;
			t_sample div_2316 = safediv(slide_2320, modulation_2315);
			t_sample tap_2322 = m_delay_4.read_linear(div_2316);
			t_sample mix_2831 = (tap_2322 + (clamp_2318 * (m_history_2 - tap_2322)));
			t_sample mix_2319 = mix_2831;
			t_sample mul_2309 = (mix_2319 * slide_2205);
			t_sample sub_2207 = (tap_2322 - mix_2319);
			t_sample mix_2832 = (mix_2319 + (slide_2203 * (sub_2207 - mix_2319)));
			t_sample add_2834 = (gate_2213 + gate_2215);
			t_sample mix_2833 = (add_2834 + (slide_2202 * (mix_2832 - add_2834)));
			t_sample gate_2281 = (((choice_77 >= 1) && (choice_77 < 2)) ? mix_2833 : 0);
			t_sample gate_2282 = (((choice_77 >= 2) && (choice_77 < 3)) ? mix_2833 : 0);
			t_sample gate_2283 = ((choice_77 >= 3) ? mix_2833 : 0);
			t_sample selector_2285 = ((choice_78 >= 3) ? gate_2283 : ((choice_78 >= 2) ? gate_2214 : ((choice_78 >= 1) ? mul_2309 : 0)));
			t_sample modulation_2194 = modulation_2248;
			t_sample div_2195 = safediv(slide_2320, modulation_2194);
			t_sample tap_2200 = m_delay_3.read_linear(div_2195);
			t_sample mix_2835 = (tap_2200 + (clamp_2197 * (m_history_1 - tap_2200)));
			t_sample mix_2198 = mix_2835;
			t_sample mul_2192 = (mix_2198 * slide_2205);
			t_sample sub_2171 = (tap_2200 - mix_2198);
			t_sample mix_2836 = (mix_2198 + (slide_2167 * (sub_2171 - mix_2198)));
			t_sample add_2838 = (gate_2175 + gate_2177);
			t_sample mix_2837 = (add_2838 + (slide_2202 * (mix_2836 - add_2838)));
			t_sample gate_2181 = (((choice_79 >= 1) && (choice_79 < 2)) ? mix_2837 : 0);
			t_sample gate_2182 = (((choice_79 >= 2) && (choice_79 < 3)) ? mix_2837 : 0);
			t_sample gate_2183 = ((choice_79 >= 3) ? mix_2837 : 0);
			t_sample selector_2185 = ((choice_80 >= 3) ? gate_2183 : ((choice_80 >= 2) ? gate_2176 : ((choice_80 >= 1) ? mul_2192 : 0)));
			t_sample mul_2249 = (div_2251 * modulation_2248);
			t_sample phasor_2250 = __m_phasor_81(mul_2249, samples_to_seconds);
			t_sample triangle_2252 = triangle(phasor_2250, ((t_sample)0.5));
			t_sample selector_2254 = ((choice_82 >= 3) ? scale_2795 : ((choice_82 >= 2) ? triangle_2252 : ((choice_82 >= 1) ? scale_2791 : 0)));
			t_sample clamp_2257 = ((selector_2254 <= ((t_sample)0.01)) ? ((t_sample)0.01) : ((selector_2254 >= ((int)1)) ? ((int)1) : selector_2254));
			t_sample mul_2256 = (scale_2757 * clamp_2257);
			__m_slide_83 = fixdenorm((__m_slide_83 + (((mul_2256 > __m_slide_83) ? iup_84 : idown_85) * (mul_2256 - __m_slide_83))));
			t_sample slide_2299 = __m_slide_83;
			t_sample expr_2368 = gloubiBoulga_d_d(selector_2285, slide_2299);
			t_sample clamp_2301 = ((expr_2368 <= min_87) ? min_87 : ((expr_2368 >= ((t_sample)0.9)) ? ((t_sample)0.9) : expr_2368));
			t_sample gate_2286 = (((choice_88 >= 1) && (choice_88 < 2)) ? clamp_2301 : 0);
			t_sample gate_2287 = (((choice_88 >= 2) && (choice_88 < 3)) ? clamp_2301 : 0);
			t_sample gate_2288 = ((choice_88 >= 3) ? clamp_2301 : 0);
			t_sample mix_2839 = (mul_2309 + (slide_2297 * (gate_2286 - mul_2309)));
			t_sample clamp_2314 = ((mix_2839 <= min_89) ? min_89 : ((mix_2839 >= ((int)1)) ? ((int)1) : mix_2839));
			t_sample mix_2840 = (gate_2283 + (slide_2297 * (gate_2288 - gate_2283)));
			t_sample selector_2212 = ((choice_90 >= 3) ? ((int)0) : ((choice_90 >= 2) ? gate_2287 : ((choice_90 >= 1) ? ((int)0) : 0)));
			t_sample mix_2841 = (gate_2282 + (slide_2297 * (selector_2212 - gate_2282)));
			t_sample selector_2280 = ((choice_91 >= 3) ? mix_2840 : ((choice_91 >= 2) ? mix_2841 : ((choice_91 >= 1) ? gate_2281 : 0)));
			t_sample mul_2305 = (selector_2280 * ((int)1));
			t_sample clamp_2345 = ((mul_2305 <= min_92) ? min_92 : ((mul_2305 >= ((int)1)) ? ((int)1) : mul_2305));
			t_sample out1 = clamp_2345;
			t_sample abs_2219 = fabs(clamp_2345);
			t_sample rsub_2218 = (((int)0) - abs_2219);
			t_sample switch_2243 = (lt_2244 ? ((t_sample)-0.99) : rsub_2218);
			t_sample out5 = switch_2243;
			t_sample mul_2138 = (div_2140 * modulation_2248);
			t_sample phasor_2139 = __m_phasor_93(mul_2138, samples_to_seconds);
			t_sample triangle_2141 = triangle(phasor_2139, ((t_sample)0.5));
			t_sample selector_2143 = ((choice_94 >= 3) ? scale_2804 : ((choice_94 >= 2) ? triangle_2141 : ((choice_94 >= 1) ? scale_2800 : 0)));
			t_sample clamp_2145 = ((selector_2143 <= ((t_sample)0.01)) ? ((t_sample)0.01) : ((selector_2143 >= ((int)1)) ? ((int)1) : selector_2143));
			t_sample mul_2178 = (scale_2757 * clamp_2145);
			__m_slide_95 = fixdenorm((__m_slide_95 + (((mul_2178 > __m_slide_95) ? iup_96 : idown_97) * (mul_2178 - __m_slide_95))));
			t_sample slide_2169 = __m_slide_95;
			t_sample expr_2367 = gloubiBoulga_2447_d_d(selector_2185, slide_2169);
			t_sample clamp_2191 = ((expr_2367 <= min_99) ? min_99 : ((expr_2367 >= ((t_sample)0.9)) ? ((t_sample)0.9) : expr_2367));
			t_sample gate_2186 = (((choice_100 >= 1) && (choice_100 < 2)) ? clamp_2191 : 0);
			t_sample gate_2187 = (((choice_100 >= 2) && (choice_100 < 3)) ? clamp_2191 : 0);
			t_sample gate_2188 = ((choice_100 >= 3) ? clamp_2191 : 0);
			t_sample mix_2842 = (gate_2183 + (slide_2297 * (gate_2188 - gate_2183)));
			t_sample mix_2843 = (mul_2192 + (slide_2297 * (gate_2186 - mul_2192)));
			t_sample clamp_2193 = ((mix_2843 <= min_101) ? min_101 : ((mix_2843 >= ((int)1)) ? ((int)1) : mix_2843));
			t_sample selector_2174 = ((choice_102 >= 3) ? ((int)0) : ((choice_102 >= 2) ? gate_2187 : ((choice_102 >= 1) ? ((int)0) : 0)));
			t_sample mix_2844 = (gate_2182 + (slide_2297 * (selector_2174 - gate_2182)));
			t_sample selector_2180 = ((choice_103 >= 3) ? mix_2842 : ((choice_103 >= 2) ? mix_2844 : ((choice_103 >= 1) ? gate_2181 : 0)));
			t_sample mul_2168 = (selector_2180 * ((int)1));
			t_sample clamp_2343 = ((mul_2168 <= min_104) ? min_104 : ((mul_2168 >= ((int)1)) ? ((int)1) : mul_2168));
			t_sample out2 = clamp_2343;
			t_sample abs_2217 = fabs(clamp_2343);
			t_sample rsub_2216 = (((int)0) - abs_2217);
			t_sample switch_2237 = (lt_2238 ? ((t_sample)-0.99) : rsub_2216);
			t_sample out6 = switch_2237;
			t_sample history_2317_next_2448 = fixdenorm(mix_2319);
			t_sample history_2196_next_2449 = fixdenorm(mix_2198);
			m_history_28 = history_535_next_537;
			m_history_26 = history_531_next_539;
			m_history_27 = history_533_next_538;
			m_history_25 = history_535_next_2375;
			m_history_23 = history_531_next_2377;
			m_history_24 = history_533_next_2370;
			m_history_22 = history_535_next_2386;
			m_history_20 = history_531_next_2391;
			m_history_21 = history_533_next_2383;
			m_history_19 = history_535_next_2399;
			m_history_17 = history_531_next_2404;
			m_history_18 = history_533_next_2396;
			m_history_16 = history_535_next_2412;
			m_history_14 = history_531_next_2416;
			m_history_15 = history_533_next_2409;
			m_history_13 = history_2273_next_2275;
			m_history_12 = history_2161_next_2163;
			m_history_11 = history_535_next_2424;
			m_history_9 = history_531_next_2425;
			m_history_10 = history_533_next_2422;
			m_history_8 = history_2358_next_2362;
			m_history_7 = history_535_next_2441;
			m_history_5 = history_531_next_2442;
			m_history_6 = history_533_next_2435;
			m_delay_4.write((((gate_2213 + gate_2214) + gate_2215) + clamp_2314));
			m_delay_3.write((((clamp_2193 + gate_2175) + gate_2176) + gate_2177));
			m_history_2 = history_2317_next_2448;
			m_history_1 = history_2196_next_2449;
			m_delay_3.step();
			m_delay_4.step();
			// assign results to output buffer;
			(*(__out1++)) = out1;
			(*(__out2++)) = out2;
			(*(__out3++)) = out3;
			(*(__out4++)) = out4;
			(*(__out5++)) = out5;
			(*(__out6++)) = out6;
			(*(__out7++)) = out7;
			(*(__out8++)) = out8;
			(*(__out9++)) = out9;
			
		};
		return __exception;
		
	};
	inline void set_button(t_param _value) {
		m_button_29 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_ctrl5(t_param _value) {
		m_ctrl_30 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw1(t_param _value) {
		m_sw_31 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw2(t_param _value) {
		m_sw_32 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_ctrl1(t_param _value) {
		m_ctrl_33 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_ctrl4(t_param _value) {
		m_ctrl_34 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_ctrl7(t_param _value) {
		m_ctrl_35 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_ctrl6(t_param _value) {
		m_ctrl_36 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_ctrl2(t_param _value) {
		m_ctrl_37 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_ctrl3(t_param _value) {
		m_ctrl_38 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_gate(t_param _value) {
		m_gate_39 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline t_sample gloubiBoulga_d_d(t_sample xin, t_sample drive) {
		drive = ((drive < ((int)1)) ? ((int)1) : drive);
		t_sample x = ((xin * drive) * ((t_sample)0.686306));
		t_sample a = (((int)1) + exp((sqrt(fabs(x)) * (-((t_sample)0.75)))));
		t_sample y = safediv((exp(x) - exp(((-x) * a))), (exp(x) + exp((-x))));
		return __m_dcblock_86(y);
		
	};
	inline t_sample gloubiBoulga_2447_d_d(t_sample xin, t_sample drive) {
		drive = ((drive < ((int)1)) ? ((int)1) : drive);
		t_sample x = ((xin * drive) * ((t_sample)0.686306));
		t_sample a = (((int)1) + exp((sqrt(fabs(x)) * (-((t_sample)0.75)))));
		t_sample y = safediv((exp(x) - exp(((-x) * a))), (exp(x) + exp((-x))));
		return __m_dcblock_98(y);
		
	};
	
} State;


///
///	Configuration for the genlib API
///

/// Number of signal inputs and outputs

int gen_kernel_numins = 2;
int gen_kernel_numouts = 9;

int num_inputs() { return gen_kernel_numins; }
int num_outputs() { return gen_kernel_numouts; }
int num_params() { return 11; }

/// Assistive lables for the signal inputs and outputs

const char *gen_kernel_innames[] = { "in1", "in2" };
const char *gen_kernel_outnames[] = { "out1", "out2", "led1", "led2", "led3", "led4", "out7", "out8", "out9" };

/// Invoke the signal process of a State object

int perform(CommonState *cself, t_sample **ins, long numins, t_sample **outs, long numouts, long n) {
	State* self = (State *)cself;
	return self->perform(ins, outs, n);
}

/// Reset all parameters and stateful operators of a State object

void reset(CommonState *cself) {
	State* self = (State *)cself;
	self->reset(cself->sr, cself->vs);
}

/// Set a parameter of a State object

void setparameter(CommonState *cself, long index, t_param value, void *ref) {
	State *self = (State *)cself;
	switch (index) {
		case 0: self->set_button(value); break;
		case 1: self->set_ctrl1(value); break;
		case 2: self->set_ctrl2(value); break;
		case 3: self->set_ctrl3(value); break;
		case 4: self->set_ctrl4(value); break;
		case 5: self->set_ctrl5(value); break;
		case 6: self->set_ctrl6(value); break;
		case 7: self->set_ctrl7(value); break;
		case 8: self->set_gate(value); break;
		case 9: self->set_sw1(value); break;
		case 10: self->set_sw2(value); break;
		
		default: break;
	}
}

/// Get the value of a parameter of a State object

void getparameter(CommonState *cself, long index, t_param *value) {
	State *self = (State *)cself;
	switch (index) {
		case 0: *value = self->m_button_29; break;
		case 1: *value = self->m_ctrl_33; break;
		case 2: *value = self->m_ctrl_37; break;
		case 3: *value = self->m_ctrl_38; break;
		case 4: *value = self->m_ctrl_34; break;
		case 5: *value = self->m_ctrl_30; break;
		case 6: *value = self->m_ctrl_36; break;
		case 7: *value = self->m_ctrl_35; break;
		case 8: *value = self->m_gate_39; break;
		case 9: *value = self->m_sw_31; break;
		case 10: *value = self->m_sw_32; break;
		
		default: break;
	}
}

/// Get the name of a parameter of a State object

const char *getparametername(CommonState *cself, long index) {
	if (index >= 0 && index < cself->numparams) {
		return cself->params[index].name;
	}
	return 0;
}

/// Get the minimum value of a parameter of a State object

t_param getparametermin(CommonState *cself, long index) {
	if (index >= 0 && index < cself->numparams) {
		return cself->params[index].outputmin;
	}
	return 0;
}

/// Get the maximum value of a parameter of a State object

t_param getparametermax(CommonState *cself, long index) {
	if (index >= 0 && index < cself->numparams) {
		return cself->params[index].outputmax;
	}
	return 0;
}

/// Get parameter of a State object has a minimum and maximum value

char getparameterhasminmax(CommonState *cself, long index) {
	if (index >= 0 && index < cself->numparams) {
		return cself->params[index].hasminmax;
	}
	return 0;
}

/// Get the units of a parameter of a State object

const char *getparameterunits(CommonState *cself, long index) {
	if (index >= 0 && index < cself->numparams) {
		return cself->params[index].units;
	}
	return 0;
}

/// Get the size of the state of all parameters of a State object

size_t getstatesize(CommonState *cself) {
	return genlib_getstatesize(cself, &getparameter);
}

/// Get the state of all parameters of a State object

short getstate(CommonState *cself, char *state) {
	return genlib_getstate(cself, state, &getparameter);
}

/// set the state of all parameters of a State object

short setstate(CommonState *cself, const char *state) {
	return genlib_setstate(cself, state, &setparameter);
}

/// Allocate and configure a new State object and it's internal CommonState:

void *create(t_param sr, long vs) {
	State *self = new State;
	self->reset(sr, vs);
	ParamInfo *pi;
	self->__commonstate.inputnames = gen_kernel_innames;
	self->__commonstate.outputnames = gen_kernel_outnames;
	self->__commonstate.numins = gen_kernel_numins;
	self->__commonstate.numouts = gen_kernel_numouts;
	self->__commonstate.sr = sr;
	self->__commonstate.vs = vs;
	self->__commonstate.params = (ParamInfo *)genlib_sysmem_newptr(11 * sizeof(ParamInfo));
	self->__commonstate.numparams = 11;
	// initialize parameter 0 ("m_button_29")
	pi = self->__commonstate.params + 0;
	pi->name = "button";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_button_29;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 1 ("m_ctrl_33")
	pi = self->__commonstate.params + 1;
	pi->name = "ctrl1";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_ctrl_33;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 2 ("m_ctrl_37")
	pi = self->__commonstate.params + 2;
	pi->name = "ctrl2";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_ctrl_37;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 3 ("m_ctrl_38")
	pi = self->__commonstate.params + 3;
	pi->name = "ctrl3";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_ctrl_38;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 4 ("m_ctrl_34")
	pi = self->__commonstate.params + 4;
	pi->name = "ctrl4";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_ctrl_34;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 5 ("m_ctrl_30")
	pi = self->__commonstate.params + 5;
	pi->name = "ctrl5";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_ctrl_30;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 6 ("m_ctrl_36")
	pi = self->__commonstate.params + 6;
	pi->name = "ctrl6";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_ctrl_36;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 7 ("m_ctrl_35")
	pi = self->__commonstate.params + 7;
	pi->name = "ctrl7";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_ctrl_35;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 8 ("m_gate_39")
	pi = self->__commonstate.params + 8;
	pi->name = "gate";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_gate_39;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 9 ("m_sw_31")
	pi = self->__commonstate.params + 9;
	pi->name = "sw1";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_sw_31;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 10 ("m_sw_32")
	pi = self->__commonstate.params + 10;
	pi->name = "sw2";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_sw_32;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	
	return self;
}

/// Release all resources and memory used by a State object:

void destroy(CommonState *cself) {
	State *self = (State *)cself;
	genlib_sysmem_freeptr(cself->params);
		
	delete self;
}


} // TapeoVersio_2dworking::
