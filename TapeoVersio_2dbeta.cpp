#include "TapeoVersio_2dbeta.h"

namespace TapeoVersio_2dbeta {

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
	Change __m_change_47;
	DCBlock __m_dcblock_72;
	Delay m_delay_3;
	Delta __m_delta_43;
	Phasor __m_phasor_67;
	Phasor __m_phasor_62;
	PlusEquals __m_pluseq_44;
	PlusEquals __m_pluseq_48;
	Rate __m_rate_63;
	SineCycle __m_cycle_64;
	SineData __sinedata;
	int __exception;
	int vectorsize;
	t_sample m_history_8;
	t_sample m_history_10;
	t_sample __m_count_41;
	t_sample m_history_7;
	t_sample __m_count_45;
	t_sample __m_latch_46;
	t_sample __m_count_40;
	t_sample __m_count_38;
	t_sample __m_count_39;
	t_sample m_ctrl_36;
	t_sample m_ctrl_37;
	t_sample m_ctrl_35;
	t_sample m_history_6;
	t_sample __m_slide_50;
	t_sample m_history_2;
	t_sample m_history_1;
	t_sample samplerate;
	t_sample m_history_5;
	t_sample m_history_4;
	t_sample __m_slide_59;
	t_sample samples_to_seconds;
	t_sample __m_slide_53;
	t_sample __m_slide_56;
	t_sample m_history_9;
	t_sample m_sw_34;
	t_sample m_button_32;
	t_sample m_history_17;
	t_sample m_history_16;
	t_sample m_history_18;
	t_sample m_history_19;
	t_sample m_history_20;
	t_sample m_history_15;
	t_sample m_history_13;
	t_sample m_history_14;
	t_sample m_history_11;
	t_sample m_history_12;
	t_sample m_ctrl_33;
	t_sample m_history_21;
	t_sample m_history_23;
	t_sample m_sw_29;
	t_sample m_ctrl_30;
	t_sample m_ctrl_31;
	t_sample m_history_22;
	t_sample __m_slide_69;
	t_sample m_history_26;
	t_sample m_gate_27;
	t_sample m_history_24;
	t_sample m_history_25;
	t_sample m_ctrl_28;
	// re-initialize all member variables;
	inline void reset(t_param __sr, int __vs) {
		__exception = 0;
		vectorsize = __vs;
		samplerate = __sr;
		m_history_1 = ((int)0);
		m_history_2 = ((int)0);
		m_delay_3.reset("m_delay_3", ((int)96000));
		m_history_4 = ((int)0);
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
		m_gate_27 = ((int)0);
		m_ctrl_28 = ((int)0);
		m_sw_29 = ((int)0);
		m_ctrl_30 = ((int)0);
		m_ctrl_31 = ((int)0);
		m_button_32 = ((int)0);
		m_ctrl_33 = ((int)0);
		m_sw_34 = ((int)0);
		m_ctrl_35 = ((int)0);
		m_ctrl_36 = ((int)0);
		m_ctrl_37 = ((int)0);
		__m_count_38 = 0;
		__m_count_39 = 0;
		__m_count_40 = 0;
		__m_count_41 = 0;
		__m_delta_43.reset(0);
		__m_pluseq_44.reset(0);
		__m_count_45 = 0;
		__m_latch_46 = 0;
		__m_change_47.reset(0);
		__m_pluseq_48.reset(0);
		__m_slide_50 = 0;
		__m_slide_53 = 0;
		__m_slide_56 = 0;
		__m_slide_59 = 0;
		samples_to_seconds = (1 / samplerate);
		__m_phasor_62.reset(0);
		__m_rate_63.reset();
		__m_cycle_64.reset(samplerate, 0);
		__m_phasor_67.reset(0);
		__m_slide_69 = 0;
		__m_dcblock_72.reset();
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
		t_sample sub_125984 = (m_sw_34 - ((int)0));
		t_sample scale_125981 = ((safepow((sub_125984 * ((t_sample)1)), ((int)1)) * ((int)2)) + ((int)1));
		t_sample choice_42 = int(scale_125981);
		int or_47504 = (m_gate_27 || m_button_32);
		t_sample sub_126005 = (m_sw_29 - ((int)0));
		t_sample scale_126002 = ((safepow((sub_126005 * ((t_sample)1)), ((int)1)) * ((int)2)) + ((int)1));
		t_sample iup_51 = (1 / maximum(1, abs(((int)4000))));
		t_sample idown_52 = (1 / maximum(1, abs(((int)4000))));
		t_sample iup_54 = (1 / maximum(1, abs(((int)4000))));
		t_sample idown_55 = (1 / maximum(1, abs(((int)4000))));
		t_sample iup_57 = (1 / maximum(1, abs(((int)3000))));
		t_sample idown_58 = (1 / maximum(1, abs(((int)3000))));
		t_sample iup_60 = (1 / maximum(1, abs(((int)3000))));
		t_sample idown_61 = (1 / maximum(1, abs(((int)3000))));
		samples_to_seconds = (1 / samplerate);
		t_sample choice_65 = int(scale_125981);
		t_sample choice_66 = int(scale_125981);
		t_sample choice_68 = int(scale_126002);
		t_sample iup_70 = (1 / maximum(1, abs(((int)3000))));
		t_sample idown_71 = (1 / maximum(1, abs(((int)3000))));
		t_sample min_73 = (-0.9);
		t_sample choice_74 = int(scale_125981);
		t_sample choice_75 = int(scale_125981);
		t_sample choice_76 = int(scale_125981);
		int min_77 = (-1);
		int min_78 = (-1);
		int min_79 = (-1);
		// the main sample loop;
		while ((__n--)) {
			const t_sample in1 = (*(__in1++));
			const t_sample in2 = (*(__in2++));
			t_sample out7 = ((int)0);
			t_sample out9 = ((int)0);
			__m_count_38 = (((int)0) ? 0 : (fixdenorm(__m_count_38 + ((int)1))));
			int counter_100732 = __m_count_38;
			int counter_100733 = ((int)0);
			int counter_100734 = ((int)0);
			int lt_100731 = (counter_100732 < ((int)300000));
			__m_count_39 = (((int)0) ? 0 : (fixdenorm(__m_count_39 + ((int)1))));
			int counter_97063 = __m_count_39;
			int counter_97064 = ((int)0);
			int counter_97065 = ((int)0);
			int lt_97062 = (counter_97063 < ((int)300000));
			__m_count_40 = (((int)0) ? 0 : (fixdenorm(__m_count_40 + ((int)1))));
			int counter_99441 = __m_count_40;
			int counter_99442 = ((int)0);
			int counter_99443 = ((int)0);
			int lt_99440 = (counter_99441 < ((int)300000));
			t_sample abs_105849 = fabs(in1);
			t_sample rsub_106983 = (((int)0) - abs_105849);
			t_sample switch_99439 = (lt_99440 ? ((int)0) : rsub_106983);
			t_sample out3 = switch_99439;
			__m_count_41 = (((int)0) ? 0 : (fixdenorm(__m_count_41 + ((int)1))));
			int counter_98125 = __m_count_41;
			int counter_98126 = ((int)0);
			int counter_98127 = ((int)0);
			int lt_98124 = (counter_98125 < ((int)300000));
			t_sample mix_125974 = (m_history_26 + (((t_sample)0.0042742627044161) * (m_ctrl_35 - m_history_26)));
			t_sample mix_4874 = mix_125974;
			t_sample mix_125975 = (m_history_25 + (((t_sample)0.0042742627044161) * (mix_4874 - m_history_25)));
			t_sample mix_4872 = mix_125975;
			t_sample mix_125976 = (m_history_24 + (((t_sample)0.0042742627044161) * (mix_4872 - m_history_24)));
			t_sample mix_4870 = mix_125976;
			t_sample gen_47478 = mix_4870;
			t_sample history_4875_next_4877 = fixdenorm(mix_4874);
			t_sample history_4873_next_4878 = fixdenorm(mix_4872);
			t_sample history_4871_next_4879 = fixdenorm(mix_4870);
			t_sample TONE_47445 = gen_47478;
			t_sample sub_125980 = (TONE_47445 - ((int)0));
			t_sample scale_125977 = ((safepow((sub_125980 * ((t_sample)1)), ((int)3)) * ((t_sample)-0.99)) + ((t_sample)0.99));
			t_sample scale_48579 = scale_125977;
			t_sample clamp_47456 = ((scale_48579 <= ((int)0)) ? ((int)0) : ((scale_48579 >= ((t_sample)0.99)) ? ((t_sample)0.99) : scale_48579));
			t_sample abs_107437 = fabs(in2);
			t_sample rsub_107436 = (((int)0) - abs_107437);
			t_sample switch_100730 = (lt_100731 ? ((t_sample)-0.99) : rsub_107436);
			t_sample out4 = switch_100730;
			t_sample gate_118783 = (((choice_42 >= 1) && (choice_42 < 2)) ? in1 : 0);
			t_sample gate_118784 = (((choice_42 >= 2) && (choice_42 < 3)) ? in1 : 0);
			t_sample gate_118785 = ((choice_42 >= 3) ? in1 : 0);
			t_sample mix_125985 = (m_history_23 + (((t_sample)0.0042742627044161) * (m_ctrl_33 - m_history_23)));
			t_sample mix_125390 = mix_125985;
			t_sample mix_125986 = (m_history_22 + (((t_sample)0.0042742627044161) * (mix_125390 - m_history_22)));
			t_sample mix_125384 = mix_125986;
			t_sample mix_125987 = (m_history_21 + (((t_sample)0.0042742627044161) * (mix_125384 - m_history_21)));
			t_sample mix_125383 = mix_125987;
			t_sample gen_47479 = mix_125383;
			t_sample history_4875_next_125389 = fixdenorm(mix_125390);
			t_sample history_4873_next_125388 = fixdenorm(mix_125384);
			t_sample history_4871_next_125387 = fixdenorm(mix_125383);
			int delta_47500 = __m_delta_43(or_47504);
			int gtep_47499 = ((delta_47500 >= ((int)1)) ? delta_47500 : 0);
			t_sample plusequals_47498 = __m_pluseq_44.post(gtep_47499, m_history_20, 0);
			int eq_47496 = (plusequals_47498 == ((int)2));
			__m_count_45 = (m_history_20 ? 0 : (fixdenorm(__m_count_45 + plusequals_47498)));
			t_sample counter_47493 = __m_count_45;
			int counter_47494 = ((int)0);
			int counter_47495 = ((int)0);
			__m_latch_46 = ((eq_47496 != 0) ? counter_47493 : __m_latch_46);
			t_sample latch_47492 = __m_latch_46;
			t_sample gen_47502 = latch_47492;
			t_sample history_47497_next_47501 = fixdenorm(eq_47496);
			t_sample CLOCK_47461 = gen_47502;
			t_sample mix_125988 = (m_history_19 + (((t_sample)0.0042742627044161) * (m_ctrl_30 - m_history_19)));
			t_sample mix_125400 = mix_125988;
			t_sample mix_125989 = (m_history_18 + (((t_sample)0.0042742627044161) * (mix_125400 - m_history_18)));
			t_sample mix_125396 = mix_125989;
			t_sample mix_125990 = (m_history_17 + (((t_sample)0.0042742627044161) * (mix_125396 - m_history_17)));
			t_sample mix_125399 = mix_125990;
			t_sample gen_47474 = mix_125399;
			t_sample history_4875_next_125402 = fixdenorm(mix_125400);
			t_sample history_4873_next_125403 = fixdenorm(mix_125396);
			t_sample history_4871_next_125404 = fixdenorm(mix_125399);
			t_sample sub_125994 = (gen_47474 - ((int)0));
			t_sample scale_125991 = ((safepow((sub_125994 * ((t_sample)1)), ((int)1)) * ((int)50)) + ((int)0));
			t_sample mix_125995 = (m_history_16 + (((t_sample)0.0042742627044161) * (m_ctrl_37 - m_history_16)));
			t_sample mix_125413 = mix_125995;
			t_sample mix_125996 = (m_history_15 + (((t_sample)0.0042742627044161) * (mix_125413 - m_history_15)));
			t_sample mix_125409 = mix_125996;
			t_sample mix_125997 = (m_history_14 + (((t_sample)0.0042742627044161) * (mix_125409 - m_history_14)));
			t_sample mix_125412 = mix_125997;
			t_sample gen_47480 = mix_125412;
			t_sample history_4875_next_125416 = fixdenorm(mix_125413);
			t_sample history_4873_next_125417 = fixdenorm(mix_125409);
			t_sample history_4871_next_125414 = fixdenorm(mix_125412);
			t_sample sub_126001 = (gen_47480 - ((int)0));
			t_sample scale_125998 = ((safepow((sub_126001 * ((t_sample)1)), ((int)1)) * ((t_sample)0.998)) + ((t_sample)0.001));
			t_sample mul_51169 = (in1 * ((int)2));
			t_sample abs_49205 = fabs(mul_51169);
			int gt_51609 = (abs_49205 > ((t_sample)0.85));
			int gt_49214 = (gt_51609 > m_history_13);
			t_sample sub_49211 = (gt_51609 - m_history_13);
			t_sample mul_49210 = (sub_49211 * ((t_sample)0.005));
			t_sample mul_49209 = (sub_49211 * ((t_sample)0.001));
			t_sample switch_49212 = (gt_49214 ? mul_49210 : mul_49209);
			t_sample add_49213 = (m_history_13 + switch_49212);
			t_sample rsub_49202 = (((int)1) - add_49213);
			t_sample mix_126006 = (add_49213 + (((int)0) * (rsub_49202 - add_49213)));
			t_sample history_49215_next_51610 = fixdenorm(add_49213);
			t_sample sub_126010 = (mix_126006 - ((int)0));
			t_sample scale_126007 = ((safepow((sub_126010 * ((t_sample)1)), ((int)1)) * ((int)-1)) + ((int)1));
			t_sample mix_126011 = (m_history_12 + (((t_sample)0.0042742627044161) * (m_ctrl_28 - m_history_12)));
			t_sample mix_125422 = mix_126011;
			t_sample mix_126012 = (m_history_11 + (((t_sample)0.0042742627044161) * (mix_125422 - m_history_11)));
			t_sample mix_125421 = mix_126012;
			t_sample mix_126013 = (m_history_10 + (((t_sample)0.0042742627044161) * (mix_125421 - m_history_10)));
			t_sample mix_125426 = mix_126013;
			t_sample gen_47476 = mix_125426;
			t_sample history_4875_next_125428 = fixdenorm(mix_125422);
			t_sample history_4873_next_125429 = fixdenorm(mix_125421);
			t_sample history_4871_next_125430 = fixdenorm(mix_125426);
			t_sample TIME_47462 = gen_47476;
			t_sample sub_126017 = (TIME_47462 - ((int)0));
			t_sample scale_126014 = ((safepow((sub_126017 * ((t_sample)1)), ((int)1)) * ((int)2)) + (-1));
			t_sample scale_47418 = scale_126014;
			int gt_47417 = (scale_47418 > ((int)0));
			t_sample abs_47416 = fabs(scale_47418);
			t_sample add_47448 = (abs_47416 + ((t_sample)0.001));
			t_sample mul_47450 = (add_47448 * ((int)7));
			t_sample ceil_47449 = ceil(mul_47450);
			t_sample div_47421 = safediv(((int)1), ceil_47449);
			t_sample switch_47419 = (gt_47417 ? ceil_47449 : div_47421);
			t_sample div_47451 = safediv(CLOCK_47461, switch_47419);
			int change_92910 = __m_change_47(div_47451);
			int abs_92909 = abs(change_92910);
			int plusequals_92908 = __m_pluseq_48.post(abs_92909, ((int)0), 0);
			t_sample mod_92907 = safemod(plusequals_92908, ((int)2));
			t_sample gen_92911 = mod_92907;
			t_sample NL_47490 = (gen_92911 + scale_48579);
			t_sample out8 = NL_47490;
			t_sample add_92904 = (gen_92911 + ((int)1));
			t_sample choice_49 = int(add_92904);
			t_sample gate_92905 = (((choice_49 >= 1) && (choice_49 < 2)) ? m_history_2 : 0);
			t_sample gate_92906 = ((choice_49 >= 2) ? m_history_2 : 0);
			__m_slide_50 = fixdenorm((__m_slide_50 + (((gate_92905 > __m_slide_50) ? iup_51 : idown_52) * (gate_92905 - __m_slide_50))));
			t_sample slide_95082 = __m_slide_50;
			__m_slide_53 = fixdenorm((__m_slide_53 + (((gate_92906 > __m_slide_53) ? iup_54 : idown_55) * (gate_92906 - __m_slide_53))));
			t_sample slide_95351 = __m_slide_53;
			t_sample mix_126018 = (m_history_9 + (((t_sample)0.0042742627044161) * (m_ctrl_36 - m_history_9)));
			t_sample mix_125435 = mix_126018;
			t_sample mix_126019 = (m_history_8 + (((t_sample)0.0042742627044161) * (mix_125435 - m_history_8)));
			t_sample mix_125434 = mix_126019;
			t_sample mix_126020 = (m_history_7 + (((t_sample)0.0042742627044161) * (mix_125434 - m_history_7)));
			t_sample mix_125442 = mix_126020;
			t_sample gen_47475 = mix_125442;
			t_sample history_4875_next_125440 = fixdenorm(mix_125435);
			t_sample history_4873_next_125441 = fixdenorm(mix_125434);
			t_sample history_4871_next_125443 = fixdenorm(mix_125442);
			t_sample sub_126024 = (gen_47475 - ((int)0));
			t_sample scale_126021 = ((safepow((sub_126024 * ((t_sample)1)), ((t_sample)1.5)) * ((t_sample)0.5)) + ((int)0));
			__m_slide_56 = fixdenorm((__m_slide_56 + (((scale_126021 > __m_slide_56) ? iup_57 : idown_58) * (scale_126021 - __m_slide_56))));
			t_sample slide_47427 = __m_slide_56;
			t_sample div_68404 = (div_47451 * ((t_sample)2.0833333333333e-05));
			t_sample mix_126025 = (m_history_6 + (((t_sample)0.0042742627044161) * (m_ctrl_31 - m_history_6)));
			t_sample mix_125449 = mix_126025;
			t_sample mix_126026 = (m_history_5 + (((t_sample)0.0042742627044161) * (mix_125449 - m_history_5)));
			t_sample mix_125447 = mix_126026;
			t_sample mix_126027 = (m_history_4 + (((t_sample)0.0042742627044161) * (mix_125447 - m_history_4)));
			t_sample mix_125456 = mix_126027;
			t_sample gen_47477 = mix_125456;
			t_sample history_4875_next_125454 = fixdenorm(mix_125449);
			t_sample history_4873_next_125455 = fixdenorm(mix_125447);
			t_sample history_4871_next_125453 = fixdenorm(mix_125456);
			t_sample MOD_47463 = gen_47477;
			t_sample sub_126031 = (MOD_47463 - ((int)0));
			t_sample scale_126028 = ((safepow((sub_126031 * ((t_sample)1)), ((int)1)) * ((t_sample)0.44)) + ((t_sample)0.55));
			t_sample scale_47465 = scale_126028;
			t_sample sub_126035 = (scale_47465 - ((t_sample)0.55));
			t_sample scale_126032 = ((safepow((sub_126035 * ((t_sample)2.2727272727273)), ((int)1)) * ((t_sample)-0.44)) + ((t_sample)0.99));
			t_sample scale_47464 = scale_126032;
			__m_slide_59 = fixdenorm((__m_slide_59 + (((scale_47464 > __m_slide_59) ? iup_60 : idown_61) * (scale_47464 - __m_slide_59))));
			t_sample slide_47437 = __m_slide_59;
			t_sample sub_126039 = (TIME_47462 - ((int)0));
			t_sample scale_126036 = ((safepow((sub_126039 * ((t_sample)1)), ((int)1)) * ((t_sample)0.499)) + ((t_sample)0.001));
			t_sample scale_47469 = scale_126036;
			t_sample phasor_47472 = __m_phasor_62(scale_47469, samples_to_seconds);
			t_sample rate_47473 = __m_rate_63.perform_off(phasor_47472, ((int)1));
			__m_cycle_64.phase(rate_47473);
			t_sample cycle_47470 = __m_cycle_64(__sinedata);
			t_sample cycleindex_47471 = __m_cycle_64.phase();
			t_sample div_47467 = (cycle_47470 * ((t_sample)0.125));
			t_sample add_47466 = (div_47467 + ((t_sample)0.5));
			t_sample mix_126040 = (add_47466 + (slide_47437 * (((int)1) - add_47466)));
			t_sample mix_47468 = mix_126040;
			t_sample modulation_78097 = mix_47468;
			t_sample modulation_47453 = modulation_78097;
			t_sample div_47454 = safediv(slide_95082, modulation_47453);
			t_sample div_93427 = safediv(slide_95351, modulation_47453);
			t_sample tap_92998 = m_delay_3.read_linear(div_47454);
			t_sample tap_92999 = m_delay_3.read_linear(div_93427);
			t_sample mix_126041 = (tap_92998 + (gen_92911 * (tap_92999 - tap_92998)));
			t_sample mix_94030 = mix_126041;
			t_sample mix_126042 = (mix_94030 + (clamp_47456 * (m_history_1 - mix_94030)));
			t_sample mix_47457 = mix_126042;
			t_sample mul_47447 = (mix_47457 * gen_47479);
			t_sample add_126044 = (gate_118783 + gate_118785);
			t_sample mix_126043 = (add_126044 + (scale_125998 * (mix_47457 - add_126044)));
			t_sample gate_47408 = (((choice_65 >= 1) && (choice_65 < 2)) ? mix_126043 : 0);
			t_sample gate_47409 = (((choice_65 >= 2) && (choice_65 < 3)) ? mix_126043 : 0);
			t_sample gate_47410 = ((choice_65 >= 3) ? mix_126043 : 0);
			t_sample selector_47412 = ((choice_66 >= 3) ? gate_47410 : ((choice_66 >= 2) ? gate_118784 : ((choice_66 >= 1) ? mul_47447 : 0)));
			t_sample mul_76506 = (div_68404 * modulation_78097);
			t_sample phasor_70971 = __m_phasor_67(mul_76506, samples_to_seconds);
			t_sample triangle_70038 = triangle(phasor_70971, ((t_sample)0.5));
			t_sample selector_56613 = ((choice_68 >= 3) ? mix_126006 : ((choice_68 >= 2) ? triangle_70038 : ((choice_68 >= 1) ? scale_126007 : 0)));
			t_sample clamp_52048 = ((selector_56613 <= ((t_sample)0.01)) ? ((t_sample)0.01) : ((selector_56613 >= ((int)1)) ? ((int)1) : selector_56613));
			t_sample mul_54180 = (scale_125991 * clamp_52048);
			__m_slide_69 = fixdenorm((__m_slide_69 + (((mul_54180 > __m_slide_69) ? iup_70 : idown_71) * (mul_54180 - __m_slide_69))));
			t_sample slide_47429 = __m_slide_69;
			t_sample expr_125381 = gloubiBoulga_d_d(selector_47412, slide_47429);
			t_sample clamp_47431 = ((expr_125381 <= min_73) ? min_73 : ((expr_125381 >= ((t_sample)0.9)) ? ((t_sample)0.9) : expr_125381));
			t_sample gate_47413 = (((choice_74 >= 1) && (choice_74 < 2)) ? clamp_47431 : 0);
			t_sample gate_47414 = (((choice_74 >= 2) && (choice_74 < 3)) ? clamp_47431 : 0);
			t_sample gate_47415 = ((choice_74 >= 3) ? clamp_47431 : 0);
			t_sample selector_119012 = ((choice_75 >= 3) ? ((int)0) : ((choice_75 >= 2) ? gate_47414 : ((choice_75 >= 1) ? ((int)0) : 0)));
			t_sample mix_126045 = (gate_47410 + (slide_47427 * (gate_47415 - gate_47410)));
			t_sample selector_47407 = ((choice_76 >= 3) ? mix_126045 : ((choice_76 >= 2) ? selector_119012 : ((choice_76 >= 1) ? gate_47408 : 0)));
			t_sample mul_124924 = (selector_47407 * ((int)1));
			t_sample clamp_47484 = ((mul_124924 <= min_77) ? min_77 : ((mul_124924 >= ((int)1)) ? ((int)1) : mul_124924));
			t_sample out1 = clamp_47484;
			t_sample abs_108343 = fabs(clamp_47484);
			t_sample rsub_108342 = (((int)0) - abs_108343);
			t_sample switch_97061 = (lt_97062 ? ((t_sample)-0.99) : rsub_108342);
			t_sample out5 = switch_97061;
			t_sample clamp_47481 = ((mul_124924 <= min_78) ? min_78 : ((mul_124924 >= ((int)1)) ? ((int)1) : mul_124924));
			t_sample out2 = clamp_47481;
			t_sample abs_108571 = fabs(clamp_47481);
			t_sample rsub_108570 = (((int)0) - abs_108571);
			t_sample switch_98123 = (lt_98124 ? ((t_sample)-0.99) : rsub_108570);
			t_sample out6 = switch_98123;
			t_sample mix_126046 = (mul_47447 + (slide_47427 * (gate_47413 - mul_47447)));
			t_sample clamp_47452 = ((mix_126046 <= min_79) ? min_79 : ((mix_126046 >= ((int)1)) ? ((int)1) : mix_126046));
			t_sample history_92903_next_125461 = fixdenorm(div_47451);
			t_sample history_47455_next_125462 = fixdenorm(mix_47457);
			m_history_26 = history_4875_next_4877;
			m_history_24 = history_4871_next_4879;
			m_history_25 = history_4873_next_4878;
			m_history_23 = history_4875_next_125389;
			m_history_21 = history_4871_next_125387;
			m_history_22 = history_4873_next_125388;
			m_history_20 = history_47497_next_47501;
			m_history_19 = history_4875_next_125402;
			m_history_17 = history_4871_next_125404;
			m_history_18 = history_4873_next_125403;
			m_history_16 = history_4875_next_125416;
			m_history_14 = history_4871_next_125414;
			m_history_15 = history_4873_next_125417;
			m_history_13 = history_49215_next_51610;
			m_history_12 = history_4875_next_125428;
			m_history_10 = history_4871_next_125430;
			m_history_11 = history_4873_next_125429;
			m_history_9 = history_4875_next_125440;
			m_history_7 = history_4871_next_125443;
			m_history_8 = history_4873_next_125441;
			m_history_6 = history_4875_next_125454;
			m_history_4 = history_4871_next_125453;
			m_history_5 = history_4873_next_125455;
			m_delay_3.write(((gate_118783 + gate_118785) + clamp_47452));
			m_history_2 = history_92903_next_125461;
			m_history_1 = history_47455_next_125462;
			m_delay_3.step();
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
	inline void set_gate(t_param _value) {
		m_gate_27 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_ctrl6(t_param _value) {
		m_ctrl_28 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw2(t_param _value) {
		m_sw_29 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_ctrl7(t_param _value) {
		m_ctrl_30 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_ctrl2(t_param _value) {
		m_ctrl_31 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_button(t_param _value) {
		m_button_32 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_ctrl5(t_param _value) {
		m_ctrl_33 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw1(t_param _value) {
		m_sw_34 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_ctrl3(t_param _value) {
		m_ctrl_35 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_ctrl4(t_param _value) {
		m_ctrl_36 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_ctrl1(t_param _value) {
		m_ctrl_37 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline t_sample gloubiBoulga_d_d(t_sample xin, t_sample drive) {
		drive = ((drive < ((int)1)) ? ((int)1) : drive);
		t_sample x = ((xin * drive) * ((t_sample)0.686306));
		t_sample a = (((int)1) + exp((sqrt(fabs(x)) * (-((t_sample)0.75)))));
		t_sample y = safediv((exp(x) - exp(((-x) * a))), (exp(x) + exp((-x))));
		return __m_dcblock_72(y);
		
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
		case 0: *value = self->m_button_32; break;
		case 1: *value = self->m_ctrl_37; break;
		case 2: *value = self->m_ctrl_31; break;
		case 3: *value = self->m_ctrl_35; break;
		case 4: *value = self->m_ctrl_36; break;
		case 5: *value = self->m_ctrl_33; break;
		case 6: *value = self->m_ctrl_28; break;
		case 7: *value = self->m_ctrl_30; break;
		case 8: *value = self->m_gate_27; break;
		case 9: *value = self->m_sw_34; break;
		case 10: *value = self->m_sw_29; break;
		
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
	// initialize parameter 0 ("m_button_32")
	pi = self->__commonstate.params + 0;
	pi->name = "button";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_button_32;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 1 ("m_ctrl_37")
	pi = self->__commonstate.params + 1;
	pi->name = "ctrl1";
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
	// initialize parameter 2 ("m_ctrl_31")
	pi = self->__commonstate.params + 2;
	pi->name = "ctrl2";
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
	// initialize parameter 3 ("m_ctrl_35")
	pi = self->__commonstate.params + 3;
	pi->name = "ctrl3";
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
	// initialize parameter 4 ("m_ctrl_36")
	pi = self->__commonstate.params + 4;
	pi->name = "ctrl4";
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
	// initialize parameter 5 ("m_ctrl_33")
	pi = self->__commonstate.params + 5;
	pi->name = "ctrl5";
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
	// initialize parameter 6 ("m_ctrl_28")
	pi = self->__commonstate.params + 6;
	pi->name = "ctrl6";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_ctrl_28;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 7 ("m_ctrl_30")
	pi = self->__commonstate.params + 7;
	pi->name = "ctrl7";
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
	// initialize parameter 8 ("m_gate_27")
	pi = self->__commonstate.params + 8;
	pi->name = "gate";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_gate_27;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 9 ("m_sw_34")
	pi = self->__commonstate.params + 9;
	pi->name = "sw1";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_sw_34;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 10 ("m_sw_29")
	pi = self->__commonstate.params + 10;
	pi->name = "sw2";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_sw_29;
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


} // TapeoVersio_2dbeta::
