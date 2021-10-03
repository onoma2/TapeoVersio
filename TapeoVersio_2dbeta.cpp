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
	t_sample __m_count_43;
	t_sample __m_count_40;
	t_sample m_history_9;
	t_sample __m_count_41;
	t_sample __m_count_42;
	t_sample m_history_8;
	t_sample __m_count_66;
	t_sample __m_latch_67;
	t_sample m_history_1;
	t_sample m_history_2;
	t_sample __m_slide_83;
	t_sample samplerate;
	t_sample m_ctrl_39;
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
	t_sample m_button_35;
	t_sample m_history_24;
	t_sample m_ctrl_31;
	t_sample m_sw_29;
	t_sample m_history_26;
	t_sample m_gate_30;
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
		m_sw_29 = ((int)0);
		m_gate_30 = ((int)0);
		m_ctrl_31 = ((int)0);
		m_sw_32 = ((int)0);
		m_ctrl_33 = ((int)0);
		m_ctrl_34 = ((int)0);
		m_button_35 = ((int)0);
		m_ctrl_36 = ((int)0);
		m_ctrl_37 = ((int)0);
		m_ctrl_38 = ((int)0);
		m_ctrl_39 = ((int)0);
		__m_count_40 = 0;
		__m_count_41 = 0;
		__m_count_42 = 0;
		__m_count_43 = 0;
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
		t_sample sub_183267 = (m_sw_29 - ((int)0));
		t_sample scale_183264 = ((safepow((sub_183267 * ((t_sample)1)), ((int)1)) * ((int)2)) + ((int)1));
		t_sample choice_44 = int(scale_183264);
		t_sample choice_45 = int(scale_183264);
		t_sample iup_47 = (1 / maximum(1, abs(((int)4000))));
		t_sample idown_48 = (1 / maximum(1, abs(((int)4000))));
		t_sample sub_183288 = (m_sw_32 - ((int)0));
		t_sample scale_183285 = ((safepow((sub_183288 * ((t_sample)1)), ((int)1)) * ((int)2)) + ((int)1));
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
		int or_47504 = (m_gate_30 || m_button_35);
		t_sample iup_69 = (1 / maximum(1, abs(((int)4000))));
		t_sample idown_70 = (1 / maximum(1, abs(((int)4000))));
		t_sample iup_72 = (1 / maximum(1, abs(((int)3000))));
		t_sample idown_73 = (1 / maximum(1, abs(((int)3000))));
		samples_to_seconds = (1 / samplerate);
		t_sample choice_77 = int(scale_183264);
		t_sample choice_78 = int(scale_183264);
		t_sample choice_79 = int(scale_183264);
		t_sample choice_80 = int(scale_183264);
		t_sample choice_82 = int(scale_183285);
		t_sample iup_84 = (1 / maximum(1, abs(((int)3000))));
		t_sample idown_85 = (1 / maximum(1, abs(((int)3000))));
		t_sample min_87 = (-0.9);
		t_sample choice_88 = int(scale_183264);
		int min_89 = (-1);
		t_sample choice_90 = int(scale_183264);
		t_sample choice_91 = int(scale_183264);
		int min_92 = (-1);
		t_sample choice_94 = int(scale_183285);
		t_sample iup_96 = (1 / maximum(1, abs(((int)3000))));
		t_sample idown_97 = (1 / maximum(1, abs(((int)3000))));
		t_sample min_99 = (-0.9);
		t_sample choice_100 = int(scale_183264);
		int min_101 = (-1);
		t_sample choice_102 = int(scale_183264);
		t_sample choice_103 = int(scale_183264);
		int min_104 = (-1);
		// the main sample loop;
		while ((__n--)) {
			const t_sample in1 = (*(__in1++));
			const t_sample in2 = (*(__in2++));
			t_sample out8 = ((int)0);
			t_sample out7 = ((int)0);
			__m_count_40 = (((int)0) ? 0 : (fixdenorm(__m_count_40 + ((int)1))));
			int counter_100732 = __m_count_40;
			int counter_100733 = ((int)0);
			int counter_100734 = ((int)0);
			int lt_100731 = (counter_100732 < ((int)300000));
			__m_count_41 = (((int)0) ? 0 : (fixdenorm(__m_count_41 + ((int)1))));
			int counter_97063 = __m_count_41;
			int counter_97064 = ((int)0);
			int counter_97065 = ((int)0);
			int lt_97062 = (counter_97063 < ((int)300000));
			t_sample abs_107437 = fabs(in2);
			t_sample rsub_107436 = (((int)0) - abs_107437);
			t_sample switch_100730 = (lt_100731 ? ((t_sample)-0.99) : rsub_107436);
			t_sample out4 = switch_100730;
			__m_count_42 = (((int)0) ? 0 : (fixdenorm(__m_count_42 + ((int)1))));
			int counter_99441 = __m_count_42;
			int counter_99442 = ((int)0);
			int counter_99443 = ((int)0);
			int lt_99440 = (counter_99441 < ((int)300000));
			t_sample abs_105849 = fabs(in1);
			t_sample rsub_106983 = (((int)0) - abs_105849);
			t_sample switch_99439 = (lt_99440 ? ((int)0) : rsub_106983);
			t_sample out3 = switch_99439;
			__m_count_43 = (((int)0) ? 0 : (fixdenorm(__m_count_43 + ((int)1))));
			int counter_98125 = __m_count_43;
			int counter_98126 = ((int)0);
			int counter_98127 = ((int)0);
			int lt_98124 = (counter_98125 < ((int)300000));
			t_sample gate_118783 = (((choice_44 >= 1) && (choice_44 < 2)) ? in1 : 0);
			t_sample gate_118784 = (((choice_44 >= 2) && (choice_44 < 3)) ? in1 : 0);
			t_sample gate_118785 = ((choice_44 >= 3) ? in1 : 0);
			t_sample gate_160588 = (((choice_45 >= 1) && (choice_45 < 2)) ? in2 : 0);
			t_sample gate_160589 = (((choice_45 >= 2) && (choice_45 < 3)) ? in2 : 0);
			t_sample gate_160590 = ((choice_45 >= 3) ? in2 : 0);
			t_sample mix_183268 = (m_history_28 + (((t_sample)0.0042742627044161) * (m_ctrl_36 - m_history_28)));
			t_sample mix_4874 = mix_183268;
			t_sample mix_183269 = (m_history_27 + (((t_sample)0.0042742627044161) * (mix_4874 - m_history_27)));
			t_sample mix_4872 = mix_183269;
			t_sample mix_183270 = (m_history_26 + (((t_sample)0.0042742627044161) * (mix_4872 - m_history_26)));
			t_sample mix_4870 = mix_183270;
			t_sample gen_47479 = mix_4870;
			t_sample history_4875_next_4877 = fixdenorm(mix_4874);
			t_sample history_4873_next_4878 = fixdenorm(mix_4872);
			t_sample history_4871_next_4879 = fixdenorm(mix_4870);
			__m_slide_46 = fixdenorm((__m_slide_46 + (((gen_47479 > __m_slide_46) ? iup_47 : idown_48) * (gen_47479 - __m_slide_46))));
			t_sample slide_159533 = __m_slide_46;
			t_sample mix_183271 = (m_history_25 + (((t_sample)0.0042742627044161) * (m_ctrl_33 - m_history_25)));
			t_sample mix_182695 = mix_183271;
			t_sample mix_183272 = (m_history_24 + (((t_sample)0.0042742627044161) * (mix_182695 - m_history_24)));
			t_sample mix_182691 = mix_183272;
			t_sample mix_183273 = (m_history_23 + (((t_sample)0.0042742627044161) * (mix_182691 - m_history_23)));
			t_sample mix_182689 = mix_183273;
			t_sample gen_47474 = mix_182689;
			t_sample history_4875_next_182692 = fixdenorm(mix_182695);
			t_sample history_4873_next_182690 = fixdenorm(mix_182691);
			t_sample history_4871_next_182688 = fixdenorm(mix_182689);
			t_sample sub_183277 = (gen_47474 - ((int)0));
			t_sample scale_183274 = ((safepow((sub_183277 * ((t_sample)1)), ((int)1)) * ((int)50)) + ((int)0));
			t_sample mix_183278 = (m_history_22 + (((t_sample)0.0042742627044161) * (m_ctrl_31 - m_history_22)));
			t_sample mix_182704 = mix_183278;
			t_sample mix_183279 = (m_history_21 + (((t_sample)0.0042742627044161) * (mix_182704 - m_history_21)));
			t_sample mix_182701 = mix_183279;
			t_sample mix_183280 = (m_history_20 + (((t_sample)0.0042742627044161) * (mix_182701 - m_history_20)));
			t_sample mix_182703 = mix_183280;
			t_sample gen_47476 = mix_182703;
			t_sample history_4875_next_182706 = fixdenorm(mix_182704);
			t_sample history_4873_next_182707 = fixdenorm(mix_182701);
			t_sample history_4871_next_182708 = fixdenorm(mix_182703);
			t_sample TIME_47462 = gen_47476;
			t_sample sub_183284 = (TIME_47462 - ((int)0));
			t_sample scale_183281 = ((safepow((sub_183284 * ((t_sample)1)), ((int)1)) * ((int)2)) + (-1));
			t_sample scale_47418 = scale_183281;
			int gte_182115 = (scale_47418 >= ((int)0));
			t_sample abs_47416 = fabs(scale_47418);
			t_sample add_47448 = (abs_47416 + ((t_sample)0.001));
			t_sample mul_177752 = (add_47448 * ((int)3));
			t_sample ceil_47449 = ceil(mul_177752);
			t_sample div_47421 = safediv(((int)1), ceil_47449);
			t_sample switch_47419 = (gte_182115 ? ceil_47449 : div_47421);
			t_sample NR_47489 = switch_47419;
			t_sample out9 = NR_47489;
			t_sample mix_183289 = (m_history_19 + (((t_sample)0.0042742627044161) * (m_ctrl_38 - m_history_19)));
			t_sample mix_182718 = mix_183289;
			t_sample mix_183290 = (m_history_18 + (((t_sample)0.0042742627044161) * (mix_182718 - m_history_18)));
			t_sample mix_182714 = mix_183290;
			t_sample mix_183291 = (m_history_17 + (((t_sample)0.0042742627044161) * (mix_182714 - m_history_17)));
			t_sample mix_182717 = mix_183291;
			t_sample gen_47478 = mix_182717;
			t_sample history_4875_next_182720 = fixdenorm(mix_182718);
			t_sample history_4873_next_182721 = fixdenorm(mix_182714);
			t_sample history_4871_next_182719 = fixdenorm(mix_182717);
			t_sample TONE_47445 = gen_47478;
			t_sample sub_183295 = (TONE_47445 - ((int)0));
			t_sample scale_183292 = ((safepow((sub_183295 * ((t_sample)1)), ((int)1)) * ((int)2)) + (-1));
			t_sample scale_155684 = scale_183292;
			t_sample sub_183299 = (scale_155684 - (-1));
			t_sample scale_183296 = ((safepow((sub_183299 * ((t_sample)1)), ((int)1)) * ((t_sample)-0.99)) + ((t_sample)0.99));
			t_sample scale_156917 = scale_183296;
			__m_slide_49 = fixdenorm((__m_slide_49 + (((scale_156917 > __m_slide_49) ? iup_50 : idown_51) * (scale_156917 - __m_slide_49))));
			t_sample slide_159698 = __m_slide_49;
			t_sample clamp_160612 = ((slide_159698 <= ((int)0)) ? ((int)0) : ((slide_159698 >= ((t_sample)0.99)) ? ((t_sample)0.99) : slide_159698));
			t_sample clamp_47456 = ((slide_159698 <= ((int)0)) ? ((int)0) : ((slide_159698 >= ((t_sample)0.99)) ? ((t_sample)0.99) : slide_159698));
			__m_slide_52 = fixdenorm((__m_slide_52 + (((TONE_47445 > __m_slide_52) ? iup_53 : idown_54) * (TONE_47445 - __m_slide_52))));
			t_sample slide_164343 = __m_slide_52;
			__m_slide_55 = fixdenorm((__m_slide_55 + (((TONE_47445 > __m_slide_55) ? iup_56 : idown_57) * (TONE_47445 - __m_slide_55))));
			t_sample slide_159863 = __m_slide_55;
			t_sample mix_183300 = (m_history_16 + (((t_sample)0.0042742627044161) * (m_ctrl_39 - m_history_16)));
			t_sample mix_182732 = mix_183300;
			t_sample mix_183301 = (m_history_15 + (((t_sample)0.0042742627044161) * (mix_182732 - m_history_15)));
			t_sample mix_182727 = mix_183301;
			t_sample mix_183302 = (m_history_14 + (((t_sample)0.0042742627044161) * (mix_182727 - m_history_14)));
			t_sample mix_182731 = mix_183302;
			t_sample gen_47480 = mix_182731;
			t_sample history_4875_next_182733 = fixdenorm(mix_182732);
			t_sample history_4873_next_182734 = fixdenorm(mix_182727);
			t_sample history_4871_next_182730 = fixdenorm(mix_182731);
			t_sample sub_183306 = (gen_47480 - ((int)0));
			t_sample scale_183303 = ((safepow((sub_183306 * ((t_sample)1)), ((int)1)) * ((t_sample)0.998)) + ((t_sample)0.001));
			__m_slide_58 = fixdenorm((__m_slide_58 + (((scale_183303 > __m_slide_58) ? iup_59 : idown_60) * (scale_183303 - __m_slide_58))));
			t_sample slide_160333 = __m_slide_58;
			t_sample mul_166216 = (in2 * ((int)2));
			t_sample abs_166221 = fabs(mul_166216);
			int gt_166220 = (abs_166221 > ((t_sample)0.85));
			int gt_166230 = (gt_166220 > m_history_13);
			t_sample sub_166227 = (gt_166220 - m_history_13);
			t_sample mul_166226 = (sub_166227 * ((t_sample)0.005));
			t_sample mul_166225 = (sub_166227 * ((t_sample)0.001));
			t_sample switch_166228 = (gt_166230 ? mul_166226 : mul_166225);
			t_sample add_166229 = (m_history_13 + switch_166228);
			t_sample rsub_166218 = (((int)1) - add_166229);
			t_sample mix_183307 = (add_166229 + (((int)0) * (rsub_166218 - add_166229)));
			t_sample history_166231_next_166233 = fixdenorm(add_166229);
			t_sample sub_183311 = (mix_183307 - ((int)0));
			t_sample scale_183308 = ((safepow((sub_183311 * ((t_sample)1)), ((int)1)) * ((int)-1)) + ((int)1));
			t_sample sub_183315 = (mix_183307 - ((int)0));
			t_sample scale_183312 = ((safepow((sub_183315 * ((t_sample)1)), ((int)1)) * ((t_sample)0.7)) + ((t_sample)0.3));
			t_sample mul_51169 = (in1 * ((int)2));
			t_sample abs_49205 = fabs(mul_51169);
			int gt_51609 = (abs_49205 > ((t_sample)0.85));
			int gt_49214 = (gt_51609 > m_history_12);
			t_sample sub_49211 = (gt_51609 - m_history_12);
			t_sample mul_49210 = (sub_49211 * ((t_sample)0.005));
			t_sample mul_49209 = (sub_49211 * ((t_sample)0.001));
			t_sample switch_49212 = (gt_49214 ? mul_49210 : mul_49209);
			t_sample add_49213 = (m_history_12 + switch_49212);
			t_sample rsub_49202 = (((int)1) - add_49213);
			t_sample mix_183316 = (add_49213 + (((int)0) * (rsub_49202 - add_49213)));
			t_sample history_49215_next_51610 = fixdenorm(add_49213);
			t_sample sub_183320 = (mix_183316 - ((int)0));
			t_sample scale_183317 = ((safepow((sub_183320 * ((t_sample)1)), ((int)1)) * ((int)-1)) + ((int)1));
			t_sample sub_183324 = (mix_183316 - ((int)0));
			t_sample scale_183321 = ((safepow((sub_183324 * ((t_sample)1)), ((int)1)) * ((t_sample)0.7)) + ((t_sample)0.3));
			t_sample mix_183325 = (m_history_11 + (((t_sample)0.0042742627044161) * (m_ctrl_37 - m_history_11)));
			t_sample mix_182741 = mix_183325;
			t_sample mix_183326 = (m_history_10 + (((t_sample)0.0042742627044161) * (mix_182741 - m_history_10)));
			t_sample mix_182739 = mix_183326;
			t_sample mix_183327 = (m_history_9 + (((t_sample)0.0042742627044161) * (mix_182739 - m_history_9)));
			t_sample mix_182740 = mix_183327;
			t_sample gen_47475 = mix_182740;
			t_sample history_4875_next_182746 = fixdenorm(mix_182741);
			t_sample history_4873_next_182747 = fixdenorm(mix_182739);
			t_sample history_4871_next_182748 = fixdenorm(mix_182740);
			t_sample sub_183331 = (gen_47475 - ((int)0));
			t_sample scale_183328 = ((safepow((sub_183331 * ((t_sample)1)), ((t_sample)1.5)) * ((t_sample)0.5)) + ((int)0));
			__m_slide_61 = fixdenorm((__m_slide_61 + (((scale_183328 > __m_slide_61) ? iup_62 : idown_63) * (scale_183328 - __m_slide_61))));
			t_sample slide_47427 = __m_slide_61;
			int delta_47500 = __m_delta_64(or_47504);
			int gtep_47499 = ((delta_47500 >= ((int)1)) ? delta_47500 : 0);
			t_sample plusequals_47498 = __m_pluseq_65.post(gtep_47499, m_history_8, 0);
			int eq_47496 = (plusequals_47498 == ((int)2));
			__m_count_66 = (m_history_8 ? 0 : (fixdenorm(__m_count_66 + plusequals_47498)));
			t_sample counter_47493 = __m_count_66;
			int counter_47494 = ((int)0);
			int counter_47495 = ((int)0);
			__m_latch_67 = ((eq_47496 != 0) ? counter_47493 : __m_latch_67);
			t_sample latch_47492 = __m_latch_67;
			t_sample gen_47502 = latch_47492;
			t_sample history_47497_next_47501 = fixdenorm(eq_47496);
			t_sample CLOCK_47461 = gen_47502;
			t_sample div_47451 = safediv(CLOCK_47461, switch_47419);
			__m_slide_68 = fixdenorm((__m_slide_68 + (((div_47451 > __m_slide_68) ? iup_69 : idown_70) * (div_47451 - __m_slide_68))));
			t_sample slide_95082 = __m_slide_68;
			t_sample div_166210 = (div_47451 * ((t_sample)2.0833333333333e-05));
			t_sample div_68404 = (div_47451 * ((t_sample)2.0833333333333e-05));
			t_sample mix_183332 = (m_history_7 + (((t_sample)0.0042742627044161) * (m_ctrl_34 - m_history_7)));
			t_sample mix_182754 = mix_183332;
			t_sample mix_183333 = (m_history_6 + (((t_sample)0.0042742627044161) * (mix_182754 - m_history_6)));
			t_sample mix_182752 = mix_183333;
			t_sample mix_183334 = (m_history_5 + (((t_sample)0.0042742627044161) * (mix_182752 - m_history_5)));
			t_sample mix_182753 = mix_183334;
			t_sample gen_47477 = mix_182753;
			t_sample history_4875_next_182759 = fixdenorm(mix_182754);
			t_sample history_4873_next_182760 = fixdenorm(mix_182752);
			t_sample history_4871_next_182761 = fixdenorm(mix_182753);
			t_sample MOD_47463 = gen_47477;
			t_sample sub_183338 = (MOD_47463 - ((int)0));
			t_sample scale_183335 = ((safepow((sub_183338 * ((t_sample)1)), ((int)1)) * ((t_sample)0.44)) + ((t_sample)0.55));
			t_sample scale_47465 = scale_183335;
			t_sample sub_183342 = (scale_47465 - ((t_sample)0.55));
			t_sample scale_183339 = ((safepow((sub_183342 * ((t_sample)2.2727272727273)), ((int)1)) * ((t_sample)-0.44)) + ((t_sample)0.99));
			t_sample scale_47464 = scale_183339;
			__m_slide_71 = fixdenorm((__m_slide_71 + (((scale_47464 > __m_slide_71) ? iup_72 : idown_73) * (scale_47464 - __m_slide_71))));
			t_sample slide_47437 = __m_slide_71;
			t_sample sub_183346 = (TIME_47462 - ((int)0));
			t_sample scale_183343 = ((safepow((sub_183346 * ((t_sample)1)), ((int)1)) * ((t_sample)0.499)) + ((t_sample)0.001));
			t_sample scale_47469 = scale_183343;
			t_sample phasor_47472 = __m_phasor_74(scale_47469, samples_to_seconds);
			t_sample rate_47473 = __m_rate_75.perform_off(phasor_47472, ((int)1));
			__m_cycle_76.phase(rate_47473);
			t_sample cycle_47470 = __m_cycle_76(__sinedata);
			t_sample cycleindex_47471 = __m_cycle_76.phase();
			t_sample div_47467 = (cycle_47470 * ((t_sample)0.125));
			t_sample add_47466 = (div_47467 + ((t_sample)0.5));
			t_sample mix_183347 = (add_47466 + (slide_47437 * (((int)1) - add_47466)));
			t_sample mix_47468 = mix_183347;
			t_sample modulation_166207 = mix_47468;
			t_sample modulation_160609 = modulation_166207;
			t_sample div_160610 = safediv(slide_95082, modulation_160609);
			t_sample tap_182598 = m_delay_4.read_linear(div_160610);
			t_sample mix_183348 = (tap_182598 + (clamp_160612 * (m_history_2 - tap_182598)));
			t_sample mix_160613 = mix_183348;
			t_sample mul_160607 = (mix_160613 * slide_159533);
			t_sample sub_160584 = (tap_182598 - mix_160613);
			t_sample mix_183349 = (mix_160613 + (slide_164343 * (sub_160584 - mix_160613)));
			t_sample add_183351 = (gate_160590 + gate_160588);
			t_sample mix_183350 = (add_183351 + (slide_160333 * (mix_183349 - add_183351)));
			t_sample gate_160596 = (((choice_77 >= 1) && (choice_77 < 2)) ? mix_183350 : 0);
			t_sample gate_160597 = (((choice_77 >= 2) && (choice_77 < 3)) ? mix_183350 : 0);
			t_sample gate_160598 = ((choice_77 >= 3) ? mix_183350 : 0);
			t_sample selector_160600 = ((choice_78 >= 3) ? gate_160598 : ((choice_78 >= 2) ? gate_160589 : ((choice_78 >= 1) ? mul_160607 : 0)));
			t_sample modulation_47453 = modulation_166207;
			t_sample div_47454 = safediv(slide_95082, modulation_47453);
			t_sample tap_182684 = m_delay_3.read_linear(div_47454);
			t_sample mix_183352 = (tap_182684 + (clamp_47456 * (m_history_1 - tap_182684)));
			t_sample mix_47457 = mix_183352;
			t_sample mul_47447 = (mix_47457 * slide_159533);
			t_sample sub_157164 = (tap_182684 - mix_47457);
			t_sample mix_183353 = (mix_47457 + (slide_159863 * (sub_157164 - mix_47457)));
			t_sample add_183355 = (gate_118783 + gate_118785);
			t_sample mix_183354 = (add_183355 + (slide_160333 * (mix_183353 - add_183355)));
			t_sample gate_47408 = (((choice_79 >= 1) && (choice_79 < 2)) ? mix_183354 : 0);
			t_sample gate_47409 = (((choice_79 >= 2) && (choice_79 < 3)) ? mix_183354 : 0);
			t_sample gate_47410 = ((choice_79 >= 3) ? mix_183354 : 0);
			t_sample selector_47412 = ((choice_80 >= 3) ? gate_47410 : ((choice_80 >= 2) ? gate_118784 : ((choice_80 >= 1) ? mul_47447 : 0)));
			t_sample mul_166208 = (div_166210 * modulation_166207);
			t_sample phasor_166209 = __m_phasor_81(mul_166208, samples_to_seconds);
			t_sample triangle_166211 = triangle(phasor_166209, ((t_sample)0.5));
			t_sample selector_166213 = ((choice_82 >= 3) ? scale_183312 : ((choice_82 >= 2) ? triangle_166211 : ((choice_82 >= 1) ? scale_183308 : 0)));
			t_sample clamp_166215 = ((selector_166213 <= ((t_sample)0.01)) ? ((t_sample)0.01) : ((selector_166213 >= ((int)1)) ? ((int)1) : selector_166213));
			t_sample mul_160593 = (scale_183274 * clamp_166215);
			__m_slide_83 = fixdenorm((__m_slide_83 + (((mul_160593 > __m_slide_83) ? iup_84 : idown_85) * (mul_160593 - __m_slide_83))));
			t_sample slide_161149 = __m_slide_83;
			t_sample expr_182686 = gloubiBoulga_d_d(selector_160600, slide_161149);
			t_sample clamp_160606 = ((expr_182686 <= min_87) ? min_87 : ((expr_182686 >= ((t_sample)0.9)) ? ((t_sample)0.9) : expr_182686));
			t_sample gate_160601 = (((choice_88 >= 1) && (choice_88 < 2)) ? clamp_160606 : 0);
			t_sample gate_160602 = (((choice_88 >= 2) && (choice_88 < 3)) ? clamp_160606 : 0);
			t_sample gate_160603 = ((choice_88 >= 3) ? clamp_160606 : 0);
			t_sample mix_183356 = (mul_160607 + (slide_47427 * (gate_160601 - mul_160607)));
			t_sample clamp_160608 = ((mix_183356 <= min_89) ? min_89 : ((mix_183356 >= ((int)1)) ? ((int)1) : mix_183356));
			t_sample mix_183357 = (gate_160598 + (slide_47427 * (gate_160603 - gate_160598)));
			t_sample selector_160587 = ((choice_90 >= 3) ? ((int)0) : ((choice_90 >= 2) ? gate_160602 : ((choice_90 >= 1) ? ((int)0) : 0)));
			t_sample mix_183358 = (gate_160597 + (slide_47427 * (selector_160587 - gate_160597)));
			t_sample selector_160595 = ((choice_91 >= 3) ? mix_183357 : ((choice_91 >= 2) ? mix_183358 : ((choice_91 >= 1) ? gate_160596 : 0)));
			t_sample mul_161948 = (selector_160595 * ((int)1));
			t_sample clamp_47481 = ((mul_161948 <= min_92) ? min_92 : ((mul_161948 >= ((int)1)) ? ((int)1) : mul_161948));
			t_sample out2 = clamp_47481;
			t_sample abs_108571 = fabs(clamp_47481);
			t_sample rsub_108570 = (((int)0) - abs_108571);
			t_sample switch_98123 = (lt_98124 ? ((t_sample)-0.99) : rsub_108570);
			t_sample out6 = switch_98123;
			t_sample mul_76506 = (div_68404 * modulation_166207);
			t_sample phasor_70971 = __m_phasor_93(mul_76506, samples_to_seconds);
			t_sample triangle_70038 = triangle(phasor_70971, ((t_sample)0.5));
			t_sample selector_56613 = ((choice_94 >= 3) ? scale_183321 : ((choice_94 >= 2) ? triangle_70038 : ((choice_94 >= 1) ? scale_183317 : 0)));
			t_sample clamp_52048 = ((selector_56613 <= ((t_sample)0.01)) ? ((t_sample)0.01) : ((selector_56613 >= ((int)1)) ? ((int)1) : selector_56613));
			t_sample mul_54180 = (scale_183274 * clamp_52048);
			__m_slide_95 = fixdenorm((__m_slide_95 + (((mul_54180 > __m_slide_95) ? iup_96 : idown_97) * (mul_54180 - __m_slide_95))));
			t_sample slide_47429 = __m_slide_95;
			t_sample expr_182685 = gloubiBoulga_182766_d_d(selector_47412, slide_47429);
			t_sample clamp_47431 = ((expr_182685 <= min_99) ? min_99 : ((expr_182685 >= ((t_sample)0.9)) ? ((t_sample)0.9) : expr_182685));
			t_sample gate_47413 = (((choice_100 >= 1) && (choice_100 < 2)) ? clamp_47431 : 0);
			t_sample gate_47414 = (((choice_100 >= 2) && (choice_100 < 3)) ? clamp_47431 : 0);
			t_sample gate_47415 = ((choice_100 >= 3) ? clamp_47431 : 0);
			t_sample mix_183359 = (gate_47410 + (slide_47427 * (gate_47415 - gate_47410)));
			t_sample mix_183360 = (mul_47447 + (slide_47427 * (gate_47413 - mul_47447)));
			t_sample clamp_47452 = ((mix_183360 <= min_101) ? min_101 : ((mix_183360 >= ((int)1)) ? ((int)1) : mix_183360));
			t_sample selector_119012 = ((choice_102 >= 3) ? ((int)0) : ((choice_102 >= 2) ? gate_47414 : ((choice_102 >= 1) ? ((int)0) : 0)));
			t_sample mix_183361 = (gate_47409 + (slide_47427 * (selector_119012 - gate_47409)));
			t_sample selector_47407 = ((choice_103 >= 3) ? mix_183359 : ((choice_103 >= 2) ? mix_183361 : ((choice_103 >= 1) ? gate_47408 : 0)));
			t_sample mul_124924 = (selector_47407 * ((int)1));
			t_sample clamp_47484 = ((mul_124924 <= min_104) ? min_104 : ((mul_124924 >= ((int)1)) ? ((int)1) : mul_124924));
			t_sample out1 = clamp_47484;
			t_sample abs_108343 = fabs(clamp_47484);
			t_sample rsub_108342 = (((int)0) - abs_108343);
			t_sample switch_97061 = (lt_97062 ? ((t_sample)-0.99) : rsub_108342);
			t_sample out5 = switch_97061;
			t_sample history_160611_next_182767 = fixdenorm(mix_160613);
			t_sample history_47455_next_182768 = fixdenorm(mix_47457);
			m_history_28 = history_4875_next_4877;
			m_history_26 = history_4871_next_4879;
			m_history_27 = history_4873_next_4878;
			m_history_25 = history_4875_next_182692;
			m_history_23 = history_4871_next_182688;
			m_history_24 = history_4873_next_182690;
			m_history_22 = history_4875_next_182706;
			m_history_20 = history_4871_next_182708;
			m_history_21 = history_4873_next_182707;
			m_history_19 = history_4875_next_182720;
			m_history_17 = history_4871_next_182719;
			m_history_18 = history_4873_next_182721;
			m_history_16 = history_4875_next_182733;
			m_history_14 = history_4871_next_182730;
			m_history_15 = history_4873_next_182734;
			m_history_13 = history_166231_next_166233;
			m_history_12 = history_49215_next_51610;
			m_history_11 = history_4875_next_182746;
			m_history_9 = history_4871_next_182748;
			m_history_10 = history_4873_next_182747;
			m_history_8 = history_47497_next_47501;
			m_history_7 = history_4875_next_182759;
			m_history_5 = history_4871_next_182761;
			m_history_6 = history_4873_next_182760;
			m_delay_4.write((((gate_160589 + gate_160588) + gate_160590) + clamp_160608));
			m_delay_3.write((((clamp_47452 + gate_118785) + gate_118783) + gate_118784));
			m_history_2 = history_160611_next_182767;
			m_history_1 = history_47455_next_182768;
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
	inline void set_sw1(t_param _value) {
		m_sw_29 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_gate(t_param _value) {
		m_gate_30 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_ctrl6(t_param _value) {
		m_ctrl_31 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw2(t_param _value) {
		m_sw_32 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_ctrl7(t_param _value) {
		m_ctrl_33 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_ctrl2(t_param _value) {
		m_ctrl_34 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_button(t_param _value) {
		m_button_35 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_ctrl5(t_param _value) {
		m_ctrl_36 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_ctrl4(t_param _value) {
		m_ctrl_37 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_ctrl3(t_param _value) {
		m_ctrl_38 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_ctrl1(t_param _value) {
		m_ctrl_39 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline t_sample gloubiBoulga_d_d(t_sample xin, t_sample drive) {
		drive = ((drive < ((int)1)) ? ((int)1) : drive);
		t_sample x = ((xin * drive) * ((t_sample)0.686306));
		t_sample a = (((int)1) + exp((sqrt(fabs(x)) * (-((t_sample)0.75)))));
		t_sample y = safediv((exp(x) - exp(((-x) * a))), (exp(x) + exp((-x))));
		return __m_dcblock_86(y);
		
	};
	inline t_sample gloubiBoulga_182766_d_d(t_sample xin, t_sample drive) {
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
		case 0: *value = self->m_button_35; break;
		case 1: *value = self->m_ctrl_39; break;
		case 2: *value = self->m_ctrl_34; break;
		case 3: *value = self->m_ctrl_38; break;
		case 4: *value = self->m_ctrl_37; break;
		case 5: *value = self->m_ctrl_36; break;
		case 6: *value = self->m_ctrl_31; break;
		case 7: *value = self->m_ctrl_33; break;
		case 8: *value = self->m_gate_30; break;
		case 9: *value = self->m_sw_29; break;
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
	// initialize parameter 0 ("m_button_35")
	pi = self->__commonstate.params + 0;
	pi->name = "button";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_button_35;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 1 ("m_ctrl_39")
	pi = self->__commonstate.params + 1;
	pi->name = "ctrl1";
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
	// initialize parameter 2 ("m_ctrl_34")
	pi = self->__commonstate.params + 2;
	pi->name = "ctrl2";
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
	// initialize parameter 4 ("m_ctrl_37")
	pi = self->__commonstate.params + 4;
	pi->name = "ctrl4";
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
	// initialize parameter 5 ("m_ctrl_36")
	pi = self->__commonstate.params + 5;
	pi->name = "ctrl5";
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
	// initialize parameter 6 ("m_ctrl_31")
	pi = self->__commonstate.params + 6;
	pi->name = "ctrl6";
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
	// initialize parameter 7 ("m_ctrl_33")
	pi = self->__commonstate.params + 7;
	pi->name = "ctrl7";
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
	// initialize parameter 8 ("m_gate_30")
	pi = self->__commonstate.params + 8;
	pi->name = "gate";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_gate_30;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 9 ("m_sw_29")
	pi = self->__commonstate.params + 9;
	pi->name = "sw1";
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


} // TapeoVersio_2dbeta::
