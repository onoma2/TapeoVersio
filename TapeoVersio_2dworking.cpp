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
	DCBlock __m_dcblock_100;
	DCBlock __m_dcblock_88;
	Delay m_delay_6;
	Delay m_delay_5;
	Delta __m_delta_66;
	Phasor __m_phasor_95;
	Phasor __m_phasor_76;
	Phasor __m_phasor_83;
	PlusEquals __m_pluseq_67;
	Rate __m_rate_77;
	SineCycle __m_cycle_78;
	SineData __sinedata;
	int __exception;
	int vectorsize;
	t_sample __m_slide_54;
	t_sample m_history_11;
	t_sample __m_slide_57;
	t_sample __m_slide_60;
	t_sample __m_slide_63;
	t_sample __m_slide_51;
	t_sample m_history_9;
	t_sample __m_slide_48;
	t_sample __m_count_46;
	t_sample m_ctrl_41;
	t_sample __m_count_47;
	t_sample __m_count_44;
	t_sample __m_count_45;
	t_sample m_ctrl_40;
	t_sample m_history_8;
	t_sample __m_latch_69;
	t_sample m_history_1;
	t_sample m_history_2;
	t_sample __m_slide_85;
	t_sample samplerate;
	t_sample __m_count_68;
	t_sample m_history_3;
	t_sample m_history_7;
	t_sample __m_slide_70;
	t_sample m_history_4;
	t_sample __m_slide_73;
	t_sample samples_to_seconds;
	t_sample m_history_10;
	t_sample m_ctrl_39;
	t_sample m_ctrl_37;
	t_sample m_history_19;
	t_sample m_history_18;
	t_sample m_history_20;
	t_sample m_history_22;
	t_sample m_history_21;
	t_sample m_history_23;
	t_sample m_history_17;
	t_sample m_history_15;
	t_sample m_history_12;
	t_sample m_history_16;
	t_sample m_history_13;
	t_sample m_history_14;
	t_sample m_ctrl_38;
	t_sample m_history_24;
	t_sample m_history_26;
	t_sample m_button_34;
	t_sample __m_slide_97;
	t_sample m_sw_35;
	t_sample m_sw_36;
	t_sample m_history_25;
	t_sample m_ctrl_32;
	t_sample m_history_30;
	t_sample m_history_27;
	t_sample m_ctrl_31;
	t_sample m_history_28;
	t_sample m_history_29;
	t_sample m_gate_33;
	// re-initialize all member variables;
	inline void reset(t_param __sr, int __vs) {
		__exception = 0;
		vectorsize = __vs;
		samplerate = __sr;
		m_history_1 = ((int)0);
		m_history_2 = ((int)0);
		m_history_3 = ((int)0);
		m_history_4 = ((int)0);
		m_delay_5.reset("m_delay_5", ((int)192000));
		m_delay_6.reset("m_delay_6", ((int)192000));
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
		m_history_29 = ((int)0);
		m_history_30 = ((int)0);
		m_ctrl_31 = ((int)0);
		m_ctrl_32 = ((int)0);
		m_gate_33 = ((int)0);
		m_button_34 = ((int)0);
		m_sw_35 = ((int)0);
		m_sw_36 = ((int)0);
		m_ctrl_37 = ((int)0);
		m_ctrl_38 = ((int)0);
		m_ctrl_39 = ((int)0);
		m_ctrl_40 = ((int)0);
		m_ctrl_41 = ((int)0);
		__m_count_44 = 0;
		__m_count_45 = 0;
		__m_count_46 = 0;
		__m_count_47 = 0;
		__m_slide_48 = 0;
		__m_slide_51 = 0;
		__m_slide_54 = 0;
		__m_slide_57 = 0;
		__m_slide_60 = 0;
		__m_slide_63 = 0;
		__m_delta_66.reset(0);
		__m_pluseq_67.reset(0);
		__m_count_68 = 0;
		__m_latch_69 = 0;
		__m_slide_70 = 0;
		__m_slide_73 = 0;
		samples_to_seconds = (1 / samplerate);
		__m_phasor_76.reset(0);
		__m_rate_77.reset();
		__m_cycle_78.reset(samplerate, 0);
		__m_phasor_83.reset(0);
		__m_slide_85 = 0;
		__m_dcblock_88.reset();
		__m_phasor_95.reset(0);
		__m_slide_97 = 0;
		__m_dcblock_100.reset();
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
		t_sample sub_26836 = (m_sw_36 - ((int)0));
		t_sample scale_26833 = ((safepow((sub_26836 * ((t_sample)1)), ((int)1)) * ((int)2)) + ((int)1));
		t_sample scale_26414 = scale_26833;
		t_sample SW_26339 = scale_26414;
		t_sample SW_26239 = SW_26339;
		t_sample SW_26266 = SW_26339;
		t_sample choice_42 = int(SW_26266);
		t_sample SW_26228 = SW_26339;
		t_sample choice_43 = int(SW_26228);
		t_sample iup_49 = (1 / maximum(1, abs(((int)4000))));
		t_sample idown_50 = (1 / maximum(1, abs(((int)4000))));
		t_sample sub_26850 = (m_sw_35 - ((int)0));
		t_sample scale_26847 = ((safepow((sub_26850 * ((t_sample)1)), ((int)1)) * ((int)2)) + ((int)1));
		t_sample scale_26413 = scale_26847;
		t_sample SW_26197 = scale_26413;
		t_sample SW_26308 = SW_26197;
		t_sample iup_52 = (1 / maximum(1, abs(((int)4000))));
		t_sample idown_53 = (1 / maximum(1, abs(((int)4000))));
		t_sample iup_55 = (1 / maximum(1, abs(((int)4000))));
		t_sample idown_56 = (1 / maximum(1, abs(((int)4000))));
		t_sample iup_58 = (1 / maximum(1, abs(((int)4000))));
		t_sample idown_59 = (1 / maximum(1, abs(((int)4000))));
		t_sample iup_61 = (1 / maximum(1, abs(((int)4000))));
		t_sample idown_62 = (1 / maximum(1, abs(((int)4000))));
		t_sample iup_64 = (1 / maximum(1, abs(((int)3000))));
		t_sample idown_65 = (1 / maximum(1, abs(((int)3000))));
		int or_26430 = (m_gate_33 || m_button_34);
		t_sample iup_71 = (1 / maximum(1, abs(((int)4000))));
		t_sample idown_72 = (1 / maximum(1, abs(((int)4000))));
		t_sample iup_74 = (1 / maximum(1, abs(((int)3000))));
		t_sample idown_75 = (1 / maximum(1, abs(((int)3000))));
		samples_to_seconds = (1 / samplerate);
		t_sample choice_79 = int(SW_26239);
		t_sample choice_80 = int(SW_26239);
		t_sample choice_81 = int(SW_26339);
		t_sample choice_82 = int(SW_26339);
		t_sample choice_84 = int(SW_26197);
		t_sample iup_86 = (1 / maximum(1, abs(((int)3000))));
		t_sample idown_87 = (1 / maximum(1, abs(((int)3000))));
		t_sample min_89 = (-0.9);
		t_sample choice_90 = int(SW_26239);
		int min_91 = (-1);
		t_sample choice_92 = int(SW_26228);
		t_sample choice_93 = int(SW_26239);
		int min_94 = (-1);
		t_sample choice_96 = int(SW_26308);
		t_sample iup_98 = (1 / maximum(1, abs(((int)3000))));
		t_sample idown_99 = (1 / maximum(1, abs(((int)3000))));
		t_sample min_101 = (-0.9);
		t_sample choice_102 = int(SW_26339);
		int min_103 = (-1);
		t_sample choice_104 = int(SW_26266);
		t_sample choice_105 = int(SW_26339);
		int min_106 = (-1);
		// the main sample loop;
		while ((__n--)) {
			const t_sample in1 = (*(__in1++));
			const t_sample in2 = (*(__in2++));
			t_sample out7 = ((int)0);
			t_sample out8 = ((int)0);
			t_sample gate_26268 = (((choice_42 >= 1) && (choice_42 < 2)) ? in1 : 0);
			t_sample gate_26269 = (((choice_42 >= 2) && (choice_42 < 3)) ? in1 : 0);
			t_sample gate_26270 = ((choice_42 >= 3) ? in1 : 0);
			t_sample gate_26230 = (((choice_43 >= 1) && (choice_43 < 2)) ? in2 : 0);
			t_sample gate_26231 = (((choice_43 >= 2) && (choice_43 < 3)) ? in2 : 0);
			t_sample gate_26232 = ((choice_43 >= 3) ? in2 : 0);
			__m_count_44 = (((int)0) ? 0 : (fixdenorm(__m_count_44 + ((int)1))));
			int counter_26300 = __m_count_44;
			int counter_26301 = ((int)0);
			int counter_26302 = ((int)0);
			int lt_26299 = (counter_26300 < ((int)300000));
			__m_count_45 = (((int)0) ? 0 : (fixdenorm(__m_count_45 + ((int)1))));
			int counter_26288 = __m_count_45;
			int counter_26289 = ((int)0);
			int counter_26290 = ((int)0);
			int lt_26287 = (counter_26288 < ((int)300000));
			t_sample abs_26278 = fabs(in1);
			t_sample rsub_26277 = (((int)0) - abs_26278);
			t_sample switch_26286 = (lt_26287 ? ((int)0) : rsub_26277);
			t_sample out3 = switch_26286;
			__m_count_46 = (((int)0) ? 0 : (fixdenorm(__m_count_46 + ((int)1))));
			int counter_26294 = __m_count_46;
			int counter_26295 = ((int)0);
			int counter_26296 = ((int)0);
			int lt_26293 = (counter_26294 < ((int)300000));
			__m_count_47 = (((int)0) ? 0 : (fixdenorm(__m_count_47 + ((int)1))));
			int counter_26282 = __m_count_47;
			int counter_26283 = ((int)0);
			int counter_26284 = ((int)0);
			int lt_26281 = (counter_26282 < ((int)300000));
			t_sample abs_26276 = fabs(in2);
			t_sample rsub_26275 = (((int)0) - abs_26276);
			t_sample switch_26280 = (lt_26281 ? ((t_sample)-0.99) : rsub_26275);
			t_sample out4 = switch_26280;
			t_sample mix_26837 = (m_history_30 + (((t_sample)0.0019634941468452) * (m_ctrl_31 - m_history_30)));
			t_sample mix_26395 = mix_26837;
			t_sample mix_26838 = (m_history_29 + (((t_sample)0.0019634941468452) * (mix_26395 - m_history_29)));
			t_sample mix_26393 = mix_26838;
			t_sample mix_26839 = (m_history_28 + (((t_sample)0.0019634941468452) * (mix_26393 - m_history_28)));
			t_sample mix_26391 = mix_26839;
			t_sample gen_26406 = mix_26391;
			t_sample history_26396_next_26398 = fixdenorm(mix_26395);
			t_sample history_26394_next_26399 = fixdenorm(mix_26393);
			t_sample history_26392_next_26400 = fixdenorm(mix_26391);
			t_sample REGEN_26363 = gen_26406;
			__m_slide_48 = fixdenorm((__m_slide_48 + (((REGEN_26363 > __m_slide_48) ? iup_49 : idown_50) * (REGEN_26363 - __m_slide_48))));
			t_sample slide_26260 = __m_slide_48;
			t_sample mix_26840 = (m_history_27 + (((t_sample)0.0019634941468452) * (m_ctrl_40 - m_history_27)));
			t_sample mix_26462 = mix_26840;
			t_sample mix_26841 = (m_history_26 + (((t_sample)0.0019634941468452) * (mix_26462 - m_history_26)));
			t_sample mix_26459 = mix_26841;
			t_sample mix_26842 = (m_history_25 + (((t_sample)0.0019634941468452) * (mix_26459 - m_history_25)));
			t_sample mix_26457 = mix_26842;
			t_sample gen_26401 = mix_26457;
			t_sample history_26396_next_26461 = fixdenorm(mix_26462);
			t_sample history_26394_next_26460 = fixdenorm(mix_26459);
			t_sample history_26392_next_26463 = fixdenorm(mix_26457);
			t_sample THING_26358 = gen_26401;
			t_sample sub_26846 = (THING_26358 - ((int)0));
			t_sample scale_26843 = ((safepow((sub_26846 * ((t_sample)1)), ((int)1)) * ((int)50)) + ((int)0));
			t_sample scale_26357 = scale_26843;
			t_sample mix_26851 = (m_history_24 + (((t_sample)0.0019634941468452) * (m_ctrl_32 - m_history_24)));
			t_sample mix_26468 = mix_26851;
			t_sample mix_26852 = (m_history_23 + (((t_sample)0.0019634941468452) * (mix_26468 - m_history_23)));
			t_sample mix_26474 = mix_26852;
			t_sample mix_26853 = (m_history_22 + (((t_sample)0.0019634941468452) * (mix_26474 - m_history_22)));
			t_sample mix_26473 = mix_26853;
			t_sample gen_26403 = mix_26473;
			t_sample history_26396_next_26469 = fixdenorm(mix_26468);
			t_sample history_26394_next_26477 = fixdenorm(mix_26474);
			t_sample history_26392_next_26471 = fixdenorm(mix_26473);
			t_sample TIME_26379 = gen_26403;
			t_sample sub_26857 = (TIME_26379 - ((int)0));
			t_sample scale_26854 = ((safepow((sub_26857 * ((t_sample)1)), ((int)1)) * ((int)2)) + (-1));
			t_sample scale_26346 = scale_26854;
			int gte_26345 = (scale_26346 >= ((int)0));
			t_sample abs_26344 = fabs(scale_26346);
			t_sample add_26365 = (abs_26344 + ((t_sample)0.001));
			t_sample mul_26367 = (add_26365 * ((int)3));
			t_sample ceil_26366 = ceil(mul_26367);
			t_sample div_26349 = safediv(((int)1), ceil_26366);
			t_sample switch_26347 = (gte_26345 ? ceil_26366 : div_26349);
			t_sample NR_26415 = switch_26347;
			t_sample out9 = NR_26415;
			t_sample mix_26858 = (m_history_21 + (((t_sample)0.0019634941468452) * (m_ctrl_41 - m_history_21)));
			t_sample mix_26481 = mix_26858;
			t_sample mix_26859 = (m_history_20 + (((t_sample)0.0019634941468452) * (mix_26481 - m_history_20)));
			t_sample mix_26488 = mix_26859;
			t_sample mix_26860 = (m_history_19 + (((t_sample)0.0019634941468452) * (mix_26488 - m_history_19)));
			t_sample mix_26486 = mix_26860;
			t_sample gen_26405 = mix_26486;
			t_sample history_26396_next_26482 = fixdenorm(mix_26481);
			t_sample history_26394_next_26487 = fixdenorm(mix_26488);
			t_sample history_26392_next_26484 = fixdenorm(mix_26486);
			t_sample TONE_26362 = gen_26405;
			__m_slide_51 = fixdenorm((__m_slide_51 + (((TONE_26362 > __m_slide_51) ? iup_52 : idown_53) * (TONE_26362 - __m_slide_51))));
			t_sample slide_26258 = __m_slide_51;
			__m_slide_54 = fixdenorm((__m_slide_54 + (((TONE_26362 > __m_slide_54) ? iup_55 : idown_56) * (TONE_26362 - __m_slide_54))));
			t_sample slide_26222 = __m_slide_54;
			t_sample sub_26864 = (TONE_26362 - ((int)0));
			t_sample scale_26861 = ((safepow((sub_26864 * ((t_sample)1)), ((int)1)) * ((int)2)) + (-1));
			t_sample scale_26263 = scale_26861;
			t_sample sub_26868 = (scale_26263 - (-1));
			t_sample scale_26865 = ((safepow((sub_26868 * ((t_sample)1)), ((int)1)) * ((t_sample)-0.99)) + ((t_sample)0.99));
			t_sample scale_26359 = scale_26865;
			__m_slide_57 = fixdenorm((__m_slide_57 + (((scale_26359 > __m_slide_57) ? iup_58 : idown_59) * (scale_26359 - __m_slide_57))));
			t_sample slide_26259 = __m_slide_57;
			t_sample clamp_26252 = ((slide_26259 <= ((int)0)) ? ((int)0) : ((slide_26259 >= ((t_sample)0.99)) ? ((t_sample)0.99) : slide_26259));
			t_sample clamp_26373 = ((slide_26259 <= ((int)0)) ? ((int)0) : ((slide_26259 >= ((t_sample)0.99)) ? ((t_sample)0.99) : slide_26259));
			t_sample mix_26869 = (m_history_18 + (((t_sample)0.0019634941468452) * (m_ctrl_38 - m_history_18)));
			t_sample mix_26494 = mix_26869;
			t_sample mix_26870 = (m_history_17 + (((t_sample)0.0019634941468452) * (mix_26494 - m_history_17)));
			t_sample mix_26501 = mix_26870;
			t_sample mix_26871 = (m_history_16 + (((t_sample)0.0019634941468452) * (mix_26501 - m_history_16)));
			t_sample mix_26500 = mix_26871;
			t_sample gen_26407 = mix_26500;
			t_sample history_26396_next_26495 = fixdenorm(mix_26494);
			t_sample history_26394_next_26503 = fixdenorm(mix_26501);
			t_sample history_26392_next_26497 = fixdenorm(mix_26500);
			t_sample BLEND_26412 = gen_26407;
			t_sample sub_26875 = (BLEND_26412 - ((int)0));
			t_sample scale_26872 = ((safepow((sub_26875 * ((t_sample)1)), ((int)1)) * ((t_sample)0.998)) + ((t_sample)0.001));
			t_sample scale_26409 = scale_26872;
			__m_slide_60 = fixdenorm((__m_slide_60 + (((scale_26409 > __m_slide_60) ? iup_61 : idown_62) * (scale_26409 - __m_slide_60))));
			t_sample slide_26257 = __m_slide_60;
			t_sample mul_26313 = (in1 * ((int)2));
			t_sample abs_26318 = fabs(mul_26313);
			int gt_26317 = (abs_26318 > ((t_sample)0.85));
			int gt_26327 = (gt_26317 > m_history_15);
			t_sample sub_26324 = (gt_26317 - m_history_15);
			t_sample mul_26323 = (sub_26324 * ((t_sample)0.005));
			t_sample mul_26322 = (sub_26324 * ((t_sample)0.001));
			t_sample switch_26325 = (gt_26327 ? mul_26323 : mul_26322);
			t_sample add_26326 = (m_history_15 + switch_26325);
			t_sample rsub_26315 = (((int)1) - add_26326);
			t_sample mix_26876 = (add_26326 + (((int)0) * (rsub_26315 - add_26326)));
			t_sample mix_26314 = mix_26876;
			t_sample gen_26332 = mix_26314;
			t_sample history_26328_next_26330 = fixdenorm(add_26326);
			t_sample sub_26880 = (gen_26332 - ((int)0));
			t_sample scale_26877 = ((safepow((sub_26880 * ((t_sample)1)), ((int)1)) * ((int)-1)) + ((int)1));
			t_sample scale_26310 = scale_26877;
			t_sample sub_26884 = (gen_26332 - ((int)0));
			t_sample scale_26881 = ((safepow((sub_26884 * ((t_sample)1)), ((int)1)) * ((t_sample)0.7)) + ((t_sample)0.3));
			t_sample scale_26265 = scale_26881;
			t_sample mul_26201 = (in2 * ((int)2));
			t_sample abs_26206 = fabs(mul_26201);
			int gt_26205 = (abs_26206 > ((t_sample)0.85));
			int gt_26215 = (gt_26205 > m_history_14);
			t_sample sub_26212 = (gt_26205 - m_history_14);
			t_sample mul_26211 = (sub_26212 * ((t_sample)0.005));
			t_sample mul_26210 = (sub_26212 * ((t_sample)0.001));
			t_sample switch_26213 = (gt_26215 ? mul_26211 : mul_26210);
			t_sample add_26214 = (m_history_14 + switch_26213);
			t_sample rsub_26203 = (((int)1) - add_26214);
			t_sample mix_26885 = (add_26214 + (((int)0) * (rsub_26203 - add_26214)));
			t_sample mix_26202 = mix_26885;
			t_sample gen_26220 = mix_26202;
			t_sample history_26216_next_26218 = fixdenorm(add_26214);
			t_sample sub_26889 = (gen_26220 - ((int)0));
			t_sample scale_26886 = ((safepow((sub_26889 * ((t_sample)1)), ((int)1)) * ((int)-1)) + ((int)1));
			t_sample scale_26199 = scale_26886;
			t_sample sub_26893 = (gen_26220 - ((int)0));
			t_sample scale_26890 = ((safepow((sub_26893 * ((t_sample)1)), ((int)1)) * ((t_sample)0.7)) + ((t_sample)0.3));
			t_sample scale_26191 = scale_26890;
			t_sample mix_26894 = (m_history_13 + (((t_sample)0.0019634941468452) * (m_ctrl_39 - m_history_13)));
			t_sample mix_26513 = mix_26894;
			t_sample mix_26895 = (m_history_12 + (((t_sample)0.0019634941468452) * (mix_26513 - m_history_12)));
			t_sample mix_26514 = mix_26895;
			t_sample mix_26896 = (m_history_11 + (((t_sample)0.0019634941468452) * (mix_26514 - m_history_11)));
			t_sample mix_26516 = mix_26896;
			t_sample gen_26402 = mix_26516;
			t_sample history_26396_next_26507 = fixdenorm(mix_26513);
			t_sample history_26394_next_26508 = fixdenorm(mix_26514);
			t_sample history_26392_next_26512 = fixdenorm(mix_26516);
			t_sample sub_26900 = (gen_26402 - ((int)0));
			t_sample scale_26897 = ((safepow((sub_26900 * ((t_sample)1)), ((t_sample)1.5)) * ((t_sample)0.5)) + ((int)0));
			__m_slide_63 = fixdenorm((__m_slide_63 + (((scale_26897 > __m_slide_63) ? iup_64 : idown_65) * (scale_26897 - __m_slide_63))));
			t_sample slide_26352 = __m_slide_63;
			int delta_26426 = __m_delta_66(or_26430);
			int gtep_26425 = ((delta_26426 >= ((int)1)) ? delta_26426 : 0);
			t_sample plusequals_26424 = __m_pluseq_67.post(gtep_26425, m_history_10, 0);
			int eq_26422 = (plusequals_26424 == ((int)2));
			__m_count_68 = (m_history_10 ? 0 : (fixdenorm(__m_count_68 + plusequals_26424)));
			t_sample counter_26419 = __m_count_68;
			int counter_26420 = ((int)0);
			int counter_26421 = ((int)0);
			__m_latch_69 = ((eq_26422 != 0) ? counter_26419 : __m_latch_69);
			t_sample latch_26418 = __m_latch_69;
			t_sample gen_26428 = latch_26418;
			t_sample history_26423_next_26427 = fixdenorm(eq_26422);
			t_sample CLOCK_26378 = gen_26428;
			t_sample div_26368 = safediv(CLOCK_26378, switch_26347);
			__m_slide_70 = fixdenorm((__m_slide_70 + (((div_26368 > __m_slide_70) ? iup_71 : idown_72) * (div_26368 - __m_slide_70))));
			t_sample slide_26375 = __m_slide_70;
			t_sample div_26306 = (div_26368 * ((t_sample)2.0833333333333e-05));
			t_sample div_26195 = (div_26368 * ((t_sample)2.0833333333333e-05));
			t_sample mix_26901 = (m_history_9 + (((t_sample)0.0019634941468452) * (m_ctrl_37 - m_history_9)));
			t_sample mix_26520 = mix_26901;
			t_sample mix_26902 = (m_history_8 + (((t_sample)0.0019634941468452) * (mix_26520 - m_history_8)));
			t_sample mix_26528 = mix_26902;
			t_sample mix_26903 = (m_history_7 + (((t_sample)0.0019634941468452) * (mix_26528 - m_history_7)));
			t_sample mix_26525 = mix_26903;
			t_sample gen_26404 = mix_26525;
			t_sample history_26396_next_26521 = fixdenorm(mix_26520);
			t_sample history_26394_next_26522 = fixdenorm(mix_26528);
			t_sample history_26392_next_26527 = fixdenorm(mix_26525);
			t_sample MOD_26380 = gen_26404;
			t_sample sub_26907 = (MOD_26380 - ((int)0));
			t_sample scale_26904 = ((safepow((sub_26907 * ((t_sample)1)), ((int)1)) * ((t_sample)0.44)) + ((t_sample)0.55));
			t_sample scale_26382 = scale_26904;
			t_sample sub_26911 = (scale_26382 - ((t_sample)0.55));
			t_sample scale_26908 = ((safepow((sub_26911 * ((t_sample)2.2727272727273)), ((int)1)) * ((t_sample)-0.44)) + ((t_sample)0.99));
			t_sample scale_26381 = scale_26908;
			__m_slide_73 = fixdenorm((__m_slide_73 + (((scale_26381 > __m_slide_73) ? iup_74 : idown_75) * (scale_26381 - __m_slide_73))));
			t_sample slide_26361 = __m_slide_73;
			t_sample sub_26915 = (TIME_26379 - ((int)0));
			t_sample scale_26912 = ((safepow((sub_26915 * ((t_sample)1)), ((int)1)) * ((t_sample)0.499)) + ((t_sample)0.001));
			t_sample scale_26386 = scale_26912;
			t_sample phasor_26389 = __m_phasor_76(scale_26386, samples_to_seconds);
			t_sample rate_26390 = __m_rate_77.perform_off(phasor_26389, ((int)1));
			__m_cycle_78.phase(rate_26390);
			t_sample cycle_26387 = __m_cycle_78(__sinedata);
			t_sample cycleindex_26388 = __m_cycle_78.phase();
			t_sample div_26384 = (cycle_26387 * ((t_sample)0.125));
			t_sample add_26383 = (div_26384 + ((t_sample)0.5));
			t_sample mix_26916 = (add_26383 + (slide_26361 * (((int)1) - add_26383)));
			t_sample mix_26385 = mix_26916;
			t_sample modulation_26192 = mix_26385;
			t_sample modulation_26249 = modulation_26192;
			t_sample div_26250 = safediv(slide_26375, modulation_26249);
			t_sample tap_26255 = m_delay_6.read_linear(div_26250);
			t_sample mix_26917 = (tap_26255 + (clamp_26252 * (m_history_2 - tap_26255)));
			t_sample mix_26253 = mix_26917;
			t_sample mul_26247 = (mix_26253 * slide_26260);
			t_sample sub_26226 = (tap_26255 - mix_26253);
			t_sample mix_26918 = (mix_26253 + (slide_26222 * (sub_26226 - mix_26253)));
			t_sample mix_26225 = mix_26918;
			t_sample add_26920 = (gate_26230 + gate_26232);
			t_sample mix_26919 = (add_26920 + (slide_26257 * (mix_26225 - add_26920)));
			t_sample mix_26256 = mix_26919;
			t_sample gate_26236 = (((choice_79 >= 1) && (choice_79 < 2)) ? mix_26256 : 0);
			t_sample gate_26237 = (((choice_79 >= 2) && (choice_79 < 3)) ? mix_26256 : 0);
			t_sample gate_26238 = ((choice_79 >= 3) ? mix_26256 : 0);
			t_sample selector_26240 = ((choice_80 >= 3) ? gate_26238 : ((choice_80 >= 2) ? gate_26231 : ((choice_80 >= 1) ? mul_26247 : 0)));
			t_sample modulation_26370 = modulation_26192;
			t_sample div_26371 = safediv(slide_26375, modulation_26370);
			t_sample tap_26377 = m_delay_5.read_linear(div_26371);
			t_sample mix_26921 = (tap_26377 + (clamp_26373 * (m_history_1 - tap_26377)));
			t_sample mix_26374 = mix_26921;
			t_sample mul_26364 = (mix_26374 * slide_26260);
			t_sample sub_26262 = (tap_26377 - mix_26374);
			t_sample mix_26922 = (mix_26374 + (slide_26258 * (sub_26262 - mix_26374)));
			t_sample mix_26261 = mix_26922;
			t_sample add_26924 = (gate_26268 + gate_26270);
			t_sample mix_26923 = (add_26924 + (slide_26257 * (mix_26261 - add_26924)));
			t_sample mix_26411 = mix_26923;
			t_sample gate_26336 = (((choice_81 >= 1) && (choice_81 < 2)) ? mix_26411 : 0);
			t_sample gate_26337 = (((choice_81 >= 2) && (choice_81 < 3)) ? mix_26411 : 0);
			t_sample gate_26338 = ((choice_81 >= 3) ? mix_26411 : 0);
			t_sample selector_26340 = ((choice_82 >= 3) ? gate_26338 : ((choice_82 >= 2) ? gate_26269 : ((choice_82 >= 1) ? mul_26364 : 0)));
			t_sample mul_26193 = (div_26195 * modulation_26192);
			t_sample phasor_26194 = __m_phasor_83(mul_26193, samples_to_seconds);
			t_sample triangle_26196 = triangle(phasor_26194, ((t_sample)0.5));
			t_sample selector_26198 = ((choice_84 >= 3) ? scale_26191 : ((choice_84 >= 2) ? triangle_26196 : ((choice_84 >= 1) ? scale_26199 : 0)));
			t_sample clamp_26200 = ((selector_26198 <= ((t_sample)0.01)) ? ((t_sample)0.01) : ((selector_26198 >= ((int)1)) ? ((int)1) : selector_26198));
			t_sample mul_26233 = (scale_26357 * clamp_26200);
			__m_slide_85 = fixdenorm((__m_slide_85 + (((mul_26233 > __m_slide_85) ? iup_86 : idown_87) * (mul_26233 - __m_slide_85))));
			t_sample slide_26224 = __m_slide_85;
			t_sample expr_26453 = gloubiBoulga_d_d(selector_26240, slide_26224);
			t_sample clamp_26246 = ((expr_26453 <= min_89) ? min_89 : ((expr_26453 >= ((t_sample)0.9)) ? ((t_sample)0.9) : expr_26453));
			t_sample gate_26241 = (((choice_90 >= 1) && (choice_90 < 2)) ? clamp_26246 : 0);
			t_sample gate_26242 = (((choice_90 >= 2) && (choice_90 < 3)) ? clamp_26246 : 0);
			t_sample gate_26243 = ((choice_90 >= 3) ? clamp_26246 : 0);
			t_sample mix_26925 = (gate_26238 + (slide_26352 * (gate_26243 - gate_26238)));
			t_sample mul_26180 = (gate_26241 * ((t_sample)0.5));
			t_sample mul_26179 = (m_history_4 * ((t_sample)0.5));
			t_sample add_26181 = (mul_26180 + mul_26179);
			t_sample history_26182_next_26183 = fixdenorm(gate_26241);
			t_sample mix_26926 = (mul_26247 + (slide_26352 * (add_26181 - mul_26247)));
			t_sample clamp_26248 = ((mix_26926 <= min_91) ? min_91 : ((mix_26926 >= ((int)1)) ? ((int)1) : mix_26926));
			t_sample selector_26229 = ((choice_92 >= 3) ? ((int)0) : ((choice_92 >= 2) ? gate_26242 : ((choice_92 >= 1) ? ((int)0) : 0)));
			t_sample mix_26927 = (gate_26237 + (slide_26352 * (selector_26229 - gate_26237)));
			t_sample selector_26235 = ((choice_93 >= 3) ? mix_26925 : ((choice_93 >= 2) ? mix_26927 : ((choice_93 >= 1) ? gate_26236 : 0)));
			t_sample mul_26223 = (selector_26235 * ((int)1));
			t_sample clamp_26408 = ((mul_26223 <= min_94) ? min_94 : ((mul_26223 >= ((int)1)) ? ((int)1) : mul_26223));
			t_sample out2 = clamp_26408;
			t_sample abs_26272 = fabs(clamp_26408);
			t_sample rsub_26271 = (((int)0) - abs_26272);
			t_sample switch_26292 = (lt_26293 ? ((t_sample)-0.99) : rsub_26271);
			t_sample out6 = switch_26292;
			t_sample modulation_26303 = modulation_26192;
			t_sample mul_26304 = (div_26306 * modulation_26303);
			t_sample phasor_26305 = __m_phasor_95(mul_26304, samples_to_seconds);
			t_sample triangle_26307 = triangle(phasor_26305, ((t_sample)0.5));
			t_sample selector_26309 = ((choice_96 >= 3) ? scale_26265 : ((choice_96 >= 2) ? triangle_26307 : ((choice_96 >= 1) ? scale_26310 : 0)));
			t_sample clamp_26312 = ((selector_26309 <= ((t_sample)0.01)) ? ((t_sample)0.01) : ((selector_26309 >= ((int)1)) ? ((int)1) : selector_26309));
			t_sample mul_26311 = (scale_26357 * clamp_26312);
			__m_slide_97 = fixdenorm((__m_slide_97 + (((mul_26311 > __m_slide_97) ? iup_98 : idown_99) * (mul_26311 - __m_slide_97))));
			t_sample slide_26354 = __m_slide_97;
			t_sample expr_26454 = gloubiBoulga_26533_d_d(selector_26340, slide_26354);
			t_sample clamp_26356 = ((expr_26454 <= min_101) ? min_101 : ((expr_26454 >= ((t_sample)0.9)) ? ((t_sample)0.9) : expr_26454));
			t_sample gate_26341 = (((choice_102 >= 1) && (choice_102 < 2)) ? clamp_26356 : 0);
			t_sample gate_26342 = (((choice_102 >= 2) && (choice_102 < 3)) ? clamp_26356 : 0);
			t_sample gate_26343 = ((choice_102 >= 3) ? clamp_26356 : 0);
			t_sample mix_26928 = (gate_26338 + (slide_26352 * (gate_26343 - gate_26338)));
			t_sample mul_26186 = (gate_26341 * ((t_sample)0.5));
			t_sample mul_26185 = (m_history_3 * ((t_sample)0.5));
			t_sample add_26187 = (mul_26186 + mul_26185);
			t_sample history_26188_next_26189 = fixdenorm(gate_26341);
			t_sample mix_26929 = (mul_26364 + (slide_26352 * (add_26187 - mul_26364)));
			t_sample clamp_26369 = ((mix_26929 <= min_103) ? min_103 : ((mix_26929 >= ((int)1)) ? ((int)1) : mix_26929));
			t_sample selector_26267 = ((choice_104 >= 3) ? ((int)0) : ((choice_104 >= 2) ? gate_26342 : ((choice_104 >= 1) ? ((int)0) : 0)));
			t_sample mix_26930 = (gate_26337 + (slide_26352 * (selector_26267 - gate_26337)));
			t_sample selector_26335 = ((choice_105 >= 3) ? mix_26928 : ((choice_105 >= 2) ? mix_26930 : ((choice_105 >= 1) ? gate_26336 : 0)));
			t_sample mul_26360 = (selector_26335 * ((int)1));
			t_sample clamp_26410 = ((mul_26360 <= min_106) ? min_106 : ((mul_26360 >= ((int)1)) ? ((int)1) : mul_26360));
			t_sample out1 = clamp_26410;
			t_sample abs_26274 = fabs(clamp_26410);
			t_sample rsub_26273 = (((int)0) - abs_26274);
			t_sample switch_26298 = (lt_26299 ? ((t_sample)-0.99) : rsub_26273);
			t_sample out5 = switch_26298;
			t_sample history_26251_next_26534 = fixdenorm(mix_26253);
			t_sample history_26372_next_26535 = fixdenorm(mix_26374);
			m_history_30 = history_26396_next_26398;
			m_history_28 = history_26392_next_26400;
			m_history_29 = history_26394_next_26399;
			m_history_27 = history_26396_next_26461;
			m_history_25 = history_26392_next_26463;
			m_history_26 = history_26394_next_26460;
			m_history_24 = history_26396_next_26469;
			m_history_22 = history_26392_next_26471;
			m_history_23 = history_26394_next_26477;
			m_history_21 = history_26396_next_26482;
			m_history_19 = history_26392_next_26484;
			m_history_20 = history_26394_next_26487;
			m_history_18 = history_26396_next_26495;
			m_history_16 = history_26392_next_26497;
			m_history_17 = history_26394_next_26503;
			m_history_15 = history_26328_next_26330;
			m_history_14 = history_26216_next_26218;
			m_history_13 = history_26396_next_26507;
			m_history_11 = history_26392_next_26512;
			m_history_12 = history_26394_next_26508;
			m_history_10 = history_26423_next_26427;
			m_history_9 = history_26396_next_26521;
			m_history_7 = history_26392_next_26527;
			m_history_8 = history_26394_next_26522;
			m_delay_6.write((((clamp_26248 + gate_26230) + gate_26231) + gate_26232));
			m_delay_5.write((((gate_26268 + gate_26269) + gate_26270) + clamp_26369));
			m_history_4 = history_26182_next_26183;
			m_history_3 = history_26188_next_26189;
			m_history_2 = history_26251_next_26534;
			m_history_1 = history_26372_next_26535;
			m_delay_5.step();
			m_delay_6.step();
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
	inline void set_ctrl5(t_param _value) {
		m_ctrl_31 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_ctrl6(t_param _value) {
		m_ctrl_32 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_gate(t_param _value) {
		m_gate_33 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_button(t_param _value) {
		m_button_34 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw2(t_param _value) {
		m_sw_35 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw1(t_param _value) {
		m_sw_36 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_ctrl2(t_param _value) {
		m_ctrl_37 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_ctrl1(t_param _value) {
		m_ctrl_38 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_ctrl4(t_param _value) {
		m_ctrl_39 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_ctrl7(t_param _value) {
		m_ctrl_40 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_ctrl3(t_param _value) {
		m_ctrl_41 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline t_sample gloubiBoulga_d_d(t_sample xin, t_sample drive) {
		drive = ((drive < ((int)1)) ? ((int)1) : drive);
		t_sample x = ((xin * drive) * ((t_sample)0.686306));
		t_sample a = (((int)1) + exp((sqrt(fabs(x)) * (-((t_sample)0.75)))));
		t_sample y = safediv((exp(x) - exp(((-x) * a))), (exp(x) + exp((-x))));
		return __m_dcblock_88(y);
		
	};
	inline t_sample gloubiBoulga_26533_d_d(t_sample xin, t_sample drive) {
		drive = ((drive < ((int)1)) ? ((int)1) : drive);
		t_sample x = ((xin * drive) * ((t_sample)0.686306));
		t_sample a = (((int)1) + exp((sqrt(fabs(x)) * (-((t_sample)0.75)))));
		t_sample y = safediv((exp(x) - exp(((-x) * a))), (exp(x) + exp((-x))));
		return __m_dcblock_100(y);
		
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
		case 0: *value = self->m_button_34; break;
		case 1: *value = self->m_ctrl_38; break;
		case 2: *value = self->m_ctrl_37; break;
		case 3: *value = self->m_ctrl_41; break;
		case 4: *value = self->m_ctrl_39; break;
		case 5: *value = self->m_ctrl_31; break;
		case 6: *value = self->m_ctrl_32; break;
		case 7: *value = self->m_ctrl_40; break;
		case 8: *value = self->m_gate_33; break;
		case 9: *value = self->m_sw_36; break;
		case 10: *value = self->m_sw_35; break;
		
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
	// initialize parameter 0 ("m_button_34")
	pi = self->__commonstate.params + 0;
	pi->name = "button";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_button_34;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 1 ("m_ctrl_38")
	pi = self->__commonstate.params + 1;
	pi->name = "ctrl1";
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
	// initialize parameter 3 ("m_ctrl_41")
	pi = self->__commonstate.params + 3;
	pi->name = "ctrl3";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_ctrl_41;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 4 ("m_ctrl_39")
	pi = self->__commonstate.params + 4;
	pi->name = "ctrl4";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_ctrl_39;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 5 ("m_ctrl_31")
	pi = self->__commonstate.params + 5;
	pi->name = "ctrl5";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_ctrl_31;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 6 ("m_ctrl_32")
	pi = self->__commonstate.params + 6;
	pi->name = "ctrl6";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_ctrl_32;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 7 ("m_ctrl_40")
	pi = self->__commonstate.params + 7;
	pi->name = "ctrl7";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_ctrl_40;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 8 ("m_gate_33")
	pi = self->__commonstate.params + 8;
	pi->name = "gate";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_gate_33;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 9 ("m_sw_36")
	pi = self->__commonstate.params + 9;
	pi->name = "sw1";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_sw_36;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 10 ("m_sw_35")
	pi = self->__commonstate.params + 10;
	pi->name = "sw2";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_sw_35;
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
