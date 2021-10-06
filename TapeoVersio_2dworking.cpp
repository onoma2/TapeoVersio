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
	t_sample __m_count_44;
	t_sample m_ctrl_41;
	t_sample __m_count_45;
	t_sample __m_count_42;
	t_sample __m_count_43;
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
	t_sample m_gate_37;
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
	t_sample m_button_38;
	t_sample m_history_24;
	t_sample m_history_26;
	t_sample m_sw_34;
	t_sample __m_slide_97;
	t_sample m_ctrl_35;
	t_sample m_ctrl_36;
	t_sample m_history_25;
	t_sample m_sw_32;
	t_sample m_history_30;
	t_sample m_history_27;
	t_sample m_ctrl_31;
	t_sample m_history_28;
	t_sample m_history_29;
	t_sample m_ctrl_33;
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
		m_sw_32 = ((int)0);
		m_ctrl_33 = ((int)0);
		m_sw_34 = ((int)0);
		m_ctrl_35 = ((int)0);
		m_ctrl_36 = ((int)0);
		m_gate_37 = ((int)0);
		m_button_38 = ((int)0);
		m_ctrl_39 = ((int)0);
		m_ctrl_40 = ((int)0);
		m_ctrl_41 = ((int)0);
		__m_count_42 = 0;
		__m_count_43 = 0;
		__m_count_44 = 0;
		__m_count_45 = 0;
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
		t_sample sub_10600 = (m_sw_32 - ((int)0));
		t_sample scale_10597 = ((safepow((sub_10600 * ((t_sample)1)), ((int)1)) * ((int)2)) + ((int)1));
		t_sample scale_224 = scale_10597;
		t_sample SW_149 = scale_224;
		t_sample SW_49 = SW_149;
		t_sample SW_38 = SW_149;
		t_sample choice_46 = int(SW_38);
		t_sample SW_76 = SW_149;
		t_sample choice_47 = int(SW_76);
		t_sample iup_49 = (1 / maximum(1, abs(((int)4000))));
		t_sample idown_50 = (1 / maximum(1, abs(((int)4000))));
		t_sample sub_10621 = (m_sw_34 - ((int)0));
		t_sample scale_10618 = ((safepow((sub_10621 * ((t_sample)1)), ((int)1)) * ((int)2)) + ((int)1));
		t_sample scale_223 = scale_10618;
		t_sample SW_118 = scale_223;
		t_sample SW_7 = SW_118;
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
		int or_240 = (m_gate_37 || m_button_38);
		t_sample iup_71 = (1 / maximum(1, abs(((int)4000))));
		t_sample idown_72 = (1 / maximum(1, abs(((int)4000))));
		t_sample iup_74 = (1 / maximum(1, abs(((int)3000))));
		t_sample idown_75 = (1 / maximum(1, abs(((int)3000))));
		samples_to_seconds = (1 / samplerate);
		t_sample choice_79 = int(SW_149);
		t_sample choice_80 = int(SW_149);
		t_sample choice_81 = int(SW_49);
		t_sample choice_82 = int(SW_49);
		t_sample choice_84 = int(SW_7);
		t_sample iup_86 = (1 / maximum(1, abs(((int)3000))));
		t_sample idown_87 = (1 / maximum(1, abs(((int)3000))));
		t_sample min_89 = (-0.9);
		t_sample choice_90 = int(SW_49);
		t_sample choice_91 = int(SW_38);
		t_sample choice_92 = int(SW_49);
		int min_93 = (-1);
		int min_94 = (-1);
		t_sample choice_96 = int(SW_118);
		t_sample iup_98 = (1 / maximum(1, abs(((int)3000))));
		t_sample idown_99 = (1 / maximum(1, abs(((int)3000))));
		t_sample min_101 = (-0.9);
		t_sample choice_102 = int(SW_149);
		t_sample choice_103 = int(SW_76);
		t_sample choice_104 = int(SW_149);
		int min_105 = (-1);
		int min_106 = (-1);
		// the main sample loop;
		while ((__n--)) {
			const t_sample in1 = (*(__in1++));
			const t_sample in2 = (*(__in2++));
			t_sample out7 = ((int)0);
			t_sample out8 = ((int)0);
			__m_count_42 = (((int)0) ? 0 : (fixdenorm(__m_count_42 + ((int)1))));
			int counter_98 = __m_count_42;
			int counter_99 = ((int)0);
			int counter_100 = ((int)0);
			int lt_97 = (counter_98 < ((int)300000));
			__m_count_43 = (((int)0) ? 0 : (fixdenorm(__m_count_43 + ((int)1))));
			int counter_92 = __m_count_43;
			int counter_93 = ((int)0);
			int counter_94 = ((int)0);
			int lt_91 = (counter_92 < ((int)300000));
			__m_count_44 = (((int)0) ? 0 : (fixdenorm(__m_count_44 + ((int)1))));
			int counter_110 = __m_count_44;
			int counter_111 = ((int)0);
			int counter_112 = ((int)0);
			int lt_109 = (counter_110 < ((int)300000));
			__m_count_45 = (((int)0) ? 0 : (fixdenorm(__m_count_45 + ((int)1))));
			int counter_104 = __m_count_45;
			int counter_105 = ((int)0);
			int counter_106 = ((int)0);
			int lt_103 = (counter_104 < ((int)300000));
			t_sample abs_86 = fabs(in2);
			t_sample rsub_85 = (((int)0) - abs_86);
			t_sample switch_90 = (lt_91 ? ((t_sample)-0.99) : rsub_85);
			t_sample out4 = switch_90;
			t_sample gate_40 = (((choice_46 >= 1) && (choice_46 < 2)) ? in2 : 0);
			t_sample gate_41 = (((choice_46 >= 2) && (choice_46 < 3)) ? in2 : 0);
			t_sample gate_42 = ((choice_46 >= 3) ? in2 : 0);
			t_sample gate_78 = (((choice_47 >= 1) && (choice_47 < 2)) ? in1 : 0);
			t_sample gate_79 = (((choice_47 >= 2) && (choice_47 < 3)) ? in1 : 0);
			t_sample gate_80 = ((choice_47 >= 3) ? in1 : 0);
			t_sample abs_88 = fabs(in1);
			t_sample rsub_87 = (((int)0) - abs_88);
			t_sample switch_96 = (lt_97 ? ((int)0) : rsub_87);
			t_sample out3 = switch_96;
			t_sample mix_10601 = (m_history_30 + (((t_sample)0.0042742627044161) * (m_ctrl_39 - m_history_30)));
			t_sample mix_205 = mix_10601;
			t_sample mix_10602 = (m_history_29 + (((t_sample)0.0042742627044161) * (mix_205 - m_history_29)));
			t_sample mix_203 = mix_10602;
			t_sample mix_10603 = (m_history_28 + (((t_sample)0.0042742627044161) * (mix_203 - m_history_28)));
			t_sample mix_201 = mix_10603;
			t_sample gen_216 = mix_201;
			t_sample history_206_next_208 = fixdenorm(mix_205);
			t_sample history_204_next_209 = fixdenorm(mix_203);
			t_sample history_202_next_210 = fixdenorm(mix_201);
			t_sample REGEN_173 = gen_216;
			__m_slide_48 = fixdenorm((__m_slide_48 + (((REGEN_173 > __m_slide_48) ? iup_49 : idown_50) * (REGEN_173 - __m_slide_48))));
			t_sample slide_70 = __m_slide_48;
			t_sample mix_10604 = (m_history_27 + (((t_sample)0.0042742627044161) * (m_ctrl_35 - m_history_27)));
			t_sample mix_10320 = mix_10604;
			t_sample mix_10605 = (m_history_26 + (((t_sample)0.0042742627044161) * (mix_10320 - m_history_26)));
			t_sample mix_10319 = mix_10605;
			t_sample mix_10606 = (m_history_25 + (((t_sample)0.0042742627044161) * (mix_10319 - m_history_25)));
			t_sample mix_10324 = mix_10606;
			t_sample gen_211 = mix_10324;
			t_sample history_206_next_10325 = fixdenorm(mix_10320);
			t_sample history_204_next_10317 = fixdenorm(mix_10319);
			t_sample history_202_next_10316 = fixdenorm(mix_10324);
			t_sample THING_168 = gen_211;
			t_sample sub_10610 = (THING_168 - ((int)0));
			t_sample scale_10607 = ((safepow((sub_10610 * ((t_sample)1)), ((int)1)) * ((int)50)) + ((int)0));
			t_sample scale_167 = scale_10607;
			t_sample mix_10611 = (m_history_24 + (((t_sample)0.0042742627044161) * (m_ctrl_31 - m_history_24)));
			t_sample mix_10338 = mix_10611;
			t_sample mix_10612 = (m_history_23 + (((t_sample)0.0042742627044161) * (mix_10338 - m_history_23)));
			t_sample mix_10333 = mix_10612;
			t_sample mix_10613 = (m_history_22 + (((t_sample)0.0042742627044161) * (mix_10333 - m_history_22)));
			t_sample mix_10331 = mix_10613;
			t_sample gen_213 = mix_10331;
			t_sample history_206_next_10332 = fixdenorm(mix_10338);
			t_sample history_204_next_10335 = fixdenorm(mix_10333);
			t_sample history_202_next_10337 = fixdenorm(mix_10331);
			t_sample TIME_189 = gen_213;
			t_sample sub_10617 = (TIME_189 - ((int)0));
			t_sample scale_10614 = ((safepow((sub_10617 * ((t_sample)1)), ((int)1)) * ((int)2)) + (-1));
			t_sample scale_156 = scale_10614;
			int gte_155 = (scale_156 >= ((int)0));
			t_sample abs_154 = fabs(scale_156);
			t_sample add_175 = (abs_154 + ((t_sample)0.001));
			t_sample mul_177 = (add_175 * ((int)3));
			t_sample ceil_176 = ceil(mul_177);
			t_sample div_159 = safediv(((int)1), ceil_176);
			t_sample switch_157 = (gte_155 ? ceil_176 : div_159);
			t_sample NR_225 = switch_157;
			t_sample out9 = NR_225;
			t_sample mix_10622 = (m_history_21 + (((t_sample)0.0042742627044161) * (m_ctrl_36 - m_history_21)));
			t_sample mix_10349 = mix_10622;
			t_sample mix_10623 = (m_history_20 + (((t_sample)0.0042742627044161) * (mix_10349 - m_history_20)));
			t_sample mix_10346 = mix_10623;
			t_sample mix_10624 = (m_history_19 + (((t_sample)0.0042742627044161) * (mix_10346 - m_history_19)));
			t_sample mix_10344 = mix_10624;
			t_sample gen_215 = mix_10344;
			t_sample history_206_next_10345 = fixdenorm(mix_10349);
			t_sample history_204_next_10347 = fixdenorm(mix_10346);
			t_sample history_202_next_10350 = fixdenorm(mix_10344);
			t_sample TONE_172 = gen_215;
			t_sample sub_10628 = (TONE_172 - ((int)0));
			t_sample scale_10625 = ((safepow((sub_10628 * ((t_sample)1)), ((int)1)) * ((int)2)) + (-1));
			t_sample scale_73 = scale_10625;
			t_sample sub_10632 = (scale_73 - (-1));
			t_sample scale_10629 = ((safepow((sub_10632 * ((t_sample)1)), ((int)1)) * ((t_sample)-0.99)) + ((t_sample)0.99));
			t_sample scale_169 = scale_10629;
			__m_slide_51 = fixdenorm((__m_slide_51 + (((scale_169 > __m_slide_51) ? iup_52 : idown_53) * (scale_169 - __m_slide_51))));
			t_sample slide_69 = __m_slide_51;
			t_sample clamp_183 = ((slide_69 <= ((int)0)) ? ((int)0) : ((slide_69 >= ((t_sample)0.99)) ? ((t_sample)0.99) : slide_69));
			t_sample clamp_62 = ((slide_69 <= ((int)0)) ? ((int)0) : ((slide_69 >= ((t_sample)0.99)) ? ((t_sample)0.99) : slide_69));
			__m_slide_54 = fixdenorm((__m_slide_54 + (((TONE_172 > __m_slide_54) ? iup_55 : idown_56) * (TONE_172 - __m_slide_54))));
			t_sample slide_32 = __m_slide_54;
			__m_slide_57 = fixdenorm((__m_slide_57 + (((TONE_172 > __m_slide_57) ? iup_58 : idown_59) * (TONE_172 - __m_slide_57))));
			t_sample slide_68 = __m_slide_57;
			t_sample mix_10633 = (m_history_18 + (((t_sample)0.0042742627044161) * (m_ctrl_41 - m_history_18)));
			t_sample mix_10364 = mix_10633;
			t_sample mix_10634 = (m_history_17 + (((t_sample)0.0042742627044161) * (mix_10364 - m_history_17)));
			t_sample mix_10362 = mix_10634;
			t_sample mix_10635 = (m_history_16 + (((t_sample)0.0042742627044161) * (mix_10362 - m_history_16)));
			t_sample mix_10357 = mix_10635;
			t_sample gen_217 = mix_10357;
			t_sample history_206_next_10358 = fixdenorm(mix_10364);
			t_sample history_204_next_10359 = fixdenorm(mix_10362);
			t_sample history_202_next_10361 = fixdenorm(mix_10357);
			t_sample BLEND_222 = gen_217;
			t_sample sub_10639 = (BLEND_222 - ((int)0));
			t_sample scale_10636 = ((safepow((sub_10639 * ((t_sample)1)), ((int)1)) * ((t_sample)0.998)) + ((t_sample)0.001));
			t_sample scale_219 = scale_10636;
			__m_slide_60 = fixdenorm((__m_slide_60 + (((scale_219 > __m_slide_60) ? iup_61 : idown_62) * (scale_219 - __m_slide_60))));
			t_sample slide_67 = __m_slide_60;
			t_sample mul_11 = (in2 * ((int)2));
			t_sample abs_16 = fabs(mul_11);
			int gt_15 = (abs_16 > ((t_sample)0.85));
			int gt_25 = (gt_15 > m_history_15);
			t_sample sub_22 = (gt_15 - m_history_15);
			t_sample mul_21 = (sub_22 * ((t_sample)0.005));
			t_sample mul_20 = (sub_22 * ((t_sample)0.001));
			t_sample switch_23 = (gt_25 ? mul_21 : mul_20);
			t_sample add_24 = (m_history_15 + switch_23);
			t_sample rsub_13 = (((int)1) - add_24);
			t_sample mix_10640 = (add_24 + (((int)0) * (rsub_13 - add_24)));
			t_sample mix_12 = mix_10640;
			t_sample gen_30 = mix_12;
			t_sample history_26_next_28 = fixdenorm(add_24);
			t_sample sub_10644 = (gen_30 - ((int)0));
			t_sample scale_10641 = ((safepow((sub_10644 * ((t_sample)1)), ((int)1)) * ((int)-1)) + ((int)1));
			t_sample scale_9 = scale_10641;
			t_sample sub_10648 = (gen_30 - ((int)0));
			t_sample scale_10645 = ((safepow((sub_10648 * ((t_sample)1)), ((int)1)) * ((t_sample)0.7)) + ((t_sample)0.3));
			t_sample scale_1 = scale_10645;
			t_sample mul_123 = (in1 * ((int)2));
			t_sample abs_128 = fabs(mul_123);
			int gt_127 = (abs_128 > ((t_sample)0.85));
			int gt_137 = (gt_127 > m_history_14);
			t_sample sub_134 = (gt_127 - m_history_14);
			t_sample mul_133 = (sub_134 * ((t_sample)0.005));
			t_sample mul_132 = (sub_134 * ((t_sample)0.001));
			t_sample switch_135 = (gt_137 ? mul_133 : mul_132);
			t_sample add_136 = (m_history_14 + switch_135);
			t_sample rsub_125 = (((int)1) - add_136);
			t_sample mix_10649 = (add_136 + (((int)0) * (rsub_125 - add_136)));
			t_sample mix_124 = mix_10649;
			t_sample gen_142 = mix_124;
			t_sample history_138_next_140 = fixdenorm(add_136);
			t_sample sub_10653 = (gen_142 - ((int)0));
			t_sample scale_10650 = ((safepow((sub_10653 * ((t_sample)1)), ((int)1)) * ((int)-1)) + ((int)1));
			t_sample scale_120 = scale_10650;
			t_sample sub_10657 = (gen_142 - ((int)0));
			t_sample scale_10654 = ((safepow((sub_10657 * ((t_sample)1)), ((int)1)) * ((t_sample)0.7)) + ((t_sample)0.3));
			t_sample scale_75 = scale_10654;
			t_sample mix_10658 = (m_history_13 + (((t_sample)0.0042742627044161) * (m_ctrl_33 - m_history_13)));
			t_sample mix_10372 = mix_10658;
			t_sample mix_10659 = (m_history_12 + (((t_sample)0.0042742627044161) * (mix_10372 - m_history_12)));
			t_sample mix_10374 = mix_10659;
			t_sample mix_10660 = (m_history_11 + (((t_sample)0.0042742627044161) * (mix_10374 - m_history_11)));
			t_sample mix_10369 = mix_10660;
			t_sample gen_212 = mix_10369;
			t_sample history_206_next_10370 = fixdenorm(mix_10372);
			t_sample history_204_next_10371 = fixdenorm(mix_10374);
			t_sample history_202_next_10375 = fixdenorm(mix_10369);
			t_sample sub_10664 = (gen_212 - ((int)0));
			t_sample scale_10661 = ((safepow((sub_10664 * ((t_sample)1)), ((t_sample)1.5)) * ((t_sample)0.5)) + ((int)0));
			__m_slide_63 = fixdenorm((__m_slide_63 + (((scale_10661 > __m_slide_63) ? iup_64 : idown_65) * (scale_10661 - __m_slide_63))));
			t_sample slide_162 = __m_slide_63;
			int delta_236 = __m_delta_66(or_240);
			int gtep_235 = ((delta_236 >= ((int)1)) ? delta_236 : 0);
			t_sample plusequals_234 = __m_pluseq_67.post(gtep_235, m_history_10, 0);
			int eq_232 = (plusequals_234 == ((int)2));
			__m_count_68 = (m_history_10 ? 0 : (fixdenorm(__m_count_68 + plusequals_234)));
			t_sample counter_229 = __m_count_68;
			int counter_230 = ((int)0);
			int counter_231 = ((int)0);
			__m_latch_69 = ((eq_232 != 0) ? counter_229 : __m_latch_69);
			t_sample latch_228 = __m_latch_69;
			t_sample gen_238 = latch_228;
			t_sample history_233_next_237 = fixdenorm(eq_232);
			t_sample CLOCK_188 = gen_238;
			t_sample div_178 = safediv(CLOCK_188, switch_157);
			__m_slide_70 = fixdenorm((__m_slide_70 + (((div_178 > __m_slide_70) ? iup_71 : idown_72) * (div_178 - __m_slide_70))));
			t_sample slide_185 = __m_slide_70;
			t_sample div_5 = (div_178 * ((t_sample)2.0833333333333e-05));
			t_sample div_116 = (div_178 * ((t_sample)2.0833333333333e-05));
			t_sample mix_10665 = (m_history_9 + (((t_sample)0.0042742627044161) * (m_ctrl_40 - m_history_9)));
			t_sample mix_10387 = mix_10665;
			t_sample mix_10666 = (m_history_8 + (((t_sample)0.0042742627044161) * (mix_10387 - m_history_8)));
			t_sample mix_10388 = mix_10666;
			t_sample mix_10667 = (m_history_7 + (((t_sample)0.0042742627044161) * (mix_10388 - m_history_7)));
			t_sample mix_10382 = mix_10667;
			t_sample gen_214 = mix_10382;
			t_sample history_206_next_10383 = fixdenorm(mix_10387);
			t_sample history_204_next_10384 = fixdenorm(mix_10388);
			t_sample history_202_next_10389 = fixdenorm(mix_10382);
			t_sample MOD_190 = gen_214;
			t_sample sub_10671 = (MOD_190 - ((int)0));
			t_sample scale_10668 = ((safepow((sub_10671 * ((t_sample)1)), ((int)1)) * ((t_sample)0.44)) + ((t_sample)0.55));
			t_sample scale_192 = scale_10668;
			t_sample sub_10675 = (scale_192 - ((t_sample)0.55));
			t_sample scale_10672 = ((safepow((sub_10675 * ((t_sample)2.2727272727273)), ((int)1)) * ((t_sample)-0.44)) + ((t_sample)0.99));
			t_sample scale_191 = scale_10672;
			__m_slide_73 = fixdenorm((__m_slide_73 + (((scale_191 > __m_slide_73) ? iup_74 : idown_75) * (scale_191 - __m_slide_73))));
			t_sample slide_171 = __m_slide_73;
			t_sample sub_10679 = (TIME_189 - ((int)0));
			t_sample scale_10676 = ((safepow((sub_10679 * ((t_sample)1)), ((int)1)) * ((t_sample)0.499)) + ((t_sample)0.001));
			t_sample scale_196 = scale_10676;
			t_sample phasor_199 = __m_phasor_76(scale_196, samples_to_seconds);
			t_sample rate_200 = __m_rate_77.perform_off(phasor_199, ((int)1));
			__m_cycle_78.phase(rate_200);
			t_sample cycle_197 = __m_cycle_78(__sinedata);
			t_sample cycleindex_198 = __m_cycle_78.phase();
			t_sample div_194 = (cycle_197 * ((t_sample)0.125));
			t_sample add_193 = (div_194 + ((t_sample)0.5));
			t_sample mix_10680 = (add_193 + (slide_171 * (((int)1) - add_193)));
			t_sample mix_195 = mix_10680;
			t_sample modulation_2 = mix_195;
			t_sample modulation_180 = modulation_2;
			t_sample div_181 = safediv(slide_185, modulation_180);
			t_sample tap_187 = m_delay_6.read_linear(div_181);
			t_sample mix_10681 = (tap_187 + (clamp_183 * (m_history_2 - tap_187)));
			t_sample mix_184 = mix_10681;
			t_sample mul_174 = (mix_184 * slide_70);
			t_sample sub_72 = (tap_187 - mix_184);
			t_sample mix_10682 = (mix_184 + (slide_68 * (sub_72 - mix_184)));
			t_sample mix_71 = mix_10682;
			t_sample add_10684 = (gate_78 + gate_80);
			t_sample mix_10683 = (add_10684 + (slide_67 * (mix_71 - add_10684)));
			t_sample mix_221 = mix_10683;
			t_sample gate_146 = (((choice_79 >= 1) && (choice_79 < 2)) ? mix_221 : 0);
			t_sample gate_147 = (((choice_79 >= 2) && (choice_79 < 3)) ? mix_221 : 0);
			t_sample gate_148 = ((choice_79 >= 3) ? mix_221 : 0);
			t_sample selector_150 = ((choice_80 >= 3) ? gate_148 : ((choice_80 >= 2) ? gate_79 : ((choice_80 >= 1) ? mul_174 : 0)));
			t_sample modulation_59 = modulation_2;
			t_sample div_60 = safediv(slide_185, modulation_59);
			t_sample tap_65 = m_delay_5.read_linear(div_60);
			t_sample mix_10685 = (tap_65 + (clamp_62 * (m_history_1 - tap_65)));
			t_sample mix_63 = mix_10685;
			t_sample mul_57 = (mix_63 * slide_70);
			t_sample sub_36 = (tap_65 - mix_63);
			t_sample mix_10686 = (mix_63 + (slide_32 * (sub_36 - mix_63)));
			t_sample mix_35 = mix_10686;
			t_sample add_10688 = (gate_40 + gate_42);
			t_sample mix_10687 = (add_10688 + (slide_67 * (mix_35 - add_10688)));
			t_sample mix_66 = mix_10687;
			t_sample gate_46 = (((choice_81 >= 1) && (choice_81 < 2)) ? mix_66 : 0);
			t_sample gate_47 = (((choice_81 >= 2) && (choice_81 < 3)) ? mix_66 : 0);
			t_sample gate_48 = ((choice_81 >= 3) ? mix_66 : 0);
			t_sample selector_50 = ((choice_82 >= 3) ? gate_48 : ((choice_82 >= 2) ? gate_41 : ((choice_82 >= 1) ? mul_57 : 0)));
			t_sample mul_3 = (div_5 * modulation_2);
			t_sample phasor_4 = __m_phasor_83(mul_3, samples_to_seconds);
			t_sample triangle_6 = triangle(phasor_4, ((t_sample)0.5));
			t_sample selector_8 = ((choice_84 >= 3) ? scale_1 : ((choice_84 >= 2) ? triangle_6 : ((choice_84 >= 1) ? scale_9 : 0)));
			t_sample clamp_10 = ((selector_8 <= ((t_sample)0.01)) ? ((t_sample)0.01) : ((selector_8 >= ((int)1)) ? ((int)1) : selector_8));
			t_sample mul_43 = (scale_167 * clamp_10);
			__m_slide_85 = fixdenorm((__m_slide_85 + (((mul_43 > __m_slide_85) ? iup_86 : idown_87) * (mul_43 - __m_slide_85))));
			t_sample slide_34 = __m_slide_85;
			t_sample expr_10314 = gloubiBoulga_d_d(selector_50, slide_34);
			t_sample clamp_56 = ((expr_10314 <= min_89) ? min_89 : ((expr_10314 >= ((t_sample)0.9)) ? ((t_sample)0.9) : expr_10314));
			t_sample gate_51 = (((choice_90 >= 1) && (choice_90 < 2)) ? clamp_56 : 0);
			t_sample gate_52 = (((choice_90 >= 2) && (choice_90 < 3)) ? clamp_56 : 0);
			t_sample gate_53 = ((choice_90 >= 3) ? clamp_56 : 0);
			t_sample mix_10689 = (gate_48 + (slide_162 * (gate_53 - gate_48)));
			t_sample selector_39 = ((choice_91 >= 3) ? ((int)0) : ((choice_91 >= 2) ? gate_52 : ((choice_91 >= 1) ? ((int)0) : 0)));
			t_sample mix_10690 = (gate_47 + (slide_162 * (selector_39 - gate_47)));
			t_sample selector_45 = ((choice_92 >= 3) ? mix_10689 : ((choice_92 >= 2) ? mix_10690 : ((choice_92 >= 1) ? gate_46 : 0)));
			t_sample mul_33 = (selector_45 * ((int)1));
			t_sample clamp_218 = ((mul_33 <= min_93) ? min_93 : ((mul_33 >= ((int)1)) ? ((int)1) : mul_33));
			t_sample out2 = clamp_218;
			t_sample abs_82 = fabs(clamp_218);
			t_sample rsub_81 = (((int)0) - abs_82);
			t_sample switch_102 = (lt_103 ? ((t_sample)-0.99) : rsub_81);
			t_sample out6 = switch_102;
			t_sample mul_10125 = (gate_51 * ((t_sample)0.5));
			t_sample mul_10124 = (m_history_4 * ((t_sample)0.5));
			t_sample add_10126 = (mul_10125 + mul_10124);
			t_sample history_10127_next_10128 = fixdenorm(gate_51);
			t_sample mix_10691 = (mul_57 + (slide_162 * (add_10126 - mul_57)));
			t_sample clamp_58 = ((mix_10691 <= min_94) ? min_94 : ((mix_10691 >= ((int)1)) ? ((int)1) : mix_10691));
			t_sample modulation_113 = modulation_2;
			t_sample mul_114 = (div_116 * modulation_113);
			t_sample phasor_115 = __m_phasor_95(mul_114, samples_to_seconds);
			t_sample triangle_117 = triangle(phasor_115, ((t_sample)0.5));
			t_sample selector_119 = ((choice_96 >= 3) ? scale_75 : ((choice_96 >= 2) ? triangle_117 : ((choice_96 >= 1) ? scale_120 : 0)));
			t_sample clamp_122 = ((selector_119 <= ((t_sample)0.01)) ? ((t_sample)0.01) : ((selector_119 >= ((int)1)) ? ((int)1) : selector_119));
			t_sample mul_121 = (scale_167 * clamp_122);
			__m_slide_97 = fixdenorm((__m_slide_97 + (((mul_121 > __m_slide_97) ? iup_98 : idown_99) * (mul_121 - __m_slide_97))));
			t_sample slide_164 = __m_slide_97;
			t_sample expr_10315 = gloubiBoulga_10396_d_d(selector_150, slide_164);
			t_sample clamp_166 = ((expr_10315 <= min_101) ? min_101 : ((expr_10315 >= ((t_sample)0.9)) ? ((t_sample)0.9) : expr_10315));
			t_sample gate_151 = (((choice_102 >= 1) && (choice_102 < 2)) ? clamp_166 : 0);
			t_sample gate_152 = (((choice_102 >= 2) && (choice_102 < 3)) ? clamp_166 : 0);
			t_sample gate_153 = ((choice_102 >= 3) ? clamp_166 : 0);
			t_sample mix_10692 = (gate_148 + (slide_162 * (gate_153 - gate_148)));
			t_sample selector_77 = ((choice_103 >= 3) ? ((int)0) : ((choice_103 >= 2) ? gate_152 : ((choice_103 >= 1) ? ((int)0) : 0)));
			t_sample mix_10693 = (gate_147 + (slide_162 * (selector_77 - gate_147)));
			t_sample selector_145 = ((choice_104 >= 3) ? mix_10692 : ((choice_104 >= 2) ? mix_10693 : ((choice_104 >= 1) ? gate_146 : 0)));
			t_sample mul_170 = (selector_145 * ((int)1));
			t_sample clamp_220 = ((mul_170 <= min_105) ? min_105 : ((mul_170 >= ((int)1)) ? ((int)1) : mul_170));
			t_sample out1 = clamp_220;
			t_sample abs_84 = fabs(clamp_220);
			t_sample rsub_83 = (((int)0) - abs_84);
			t_sample switch_108 = (lt_109 ? ((t_sample)-0.99) : rsub_83);
			t_sample out5 = switch_108;
			t_sample mul_8636 = (gate_151 * ((t_sample)0.5));
			t_sample mul_9381 = (m_history_3 * ((t_sample)0.5));
			t_sample add_7890 = (mul_8636 + mul_9381);
			t_sample history_7518_next_9754 = fixdenorm(gate_151);
			t_sample mix_10694 = (mul_174 + (slide_162 * (add_7890 - mul_174)));
			t_sample clamp_179 = ((mix_10694 <= min_106) ? min_106 : ((mix_10694 >= ((int)1)) ? ((int)1) : mix_10694));
			t_sample history_182_next_10397 = fixdenorm(mix_184);
			t_sample history_61_next_10398 = fixdenorm(mix_63);
			m_history_30 = history_206_next_208;
			m_history_28 = history_202_next_210;
			m_history_29 = history_204_next_209;
			m_history_27 = history_206_next_10325;
			m_history_25 = history_202_next_10316;
			m_history_26 = history_204_next_10317;
			m_history_24 = history_206_next_10332;
			m_history_22 = history_202_next_10337;
			m_history_23 = history_204_next_10335;
			m_history_21 = history_206_next_10345;
			m_history_19 = history_202_next_10350;
			m_history_20 = history_204_next_10347;
			m_history_18 = history_206_next_10358;
			m_history_16 = history_202_next_10361;
			m_history_17 = history_204_next_10359;
			m_history_15 = history_26_next_28;
			m_history_14 = history_138_next_140;
			m_history_13 = history_206_next_10370;
			m_history_11 = history_202_next_10375;
			m_history_12 = history_204_next_10371;
			m_history_10 = history_233_next_237;
			m_history_9 = history_206_next_10383;
			m_history_7 = history_202_next_10389;
			m_history_8 = history_204_next_10384;
			m_delay_6.write((((gate_78 + gate_79) + gate_80) + clamp_179));
			m_delay_5.write((((clamp_58 + gate_40) + gate_41) + gate_42));
			m_history_4 = history_10127_next_10128;
			m_history_3 = history_7518_next_9754;
			m_history_2 = history_182_next_10397;
			m_history_1 = history_61_next_10398;
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
	inline void set_ctrl6(t_param _value) {
		m_ctrl_31 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw1(t_param _value) {
		m_sw_32 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_ctrl4(t_param _value) {
		m_ctrl_33 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw2(t_param _value) {
		m_sw_34 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_ctrl7(t_param _value) {
		m_ctrl_35 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_ctrl3(t_param _value) {
		m_ctrl_36 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_gate(t_param _value) {
		m_gate_37 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_button(t_param _value) {
		m_button_38 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_ctrl5(t_param _value) {
		m_ctrl_39 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_ctrl2(t_param _value) {
		m_ctrl_40 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_ctrl1(t_param _value) {
		m_ctrl_41 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline t_sample gloubiBoulga_d_d(t_sample xin, t_sample drive) {
		drive = ((drive < ((int)1)) ? ((int)1) : drive);
		t_sample x = ((xin * drive) * ((t_sample)0.686306));
		t_sample a = (((int)1) + exp((sqrt(fabs(x)) * (-((t_sample)0.75)))));
		t_sample y = safediv((exp(x) - exp(((-x) * a))), (exp(x) + exp((-x))));
		return __m_dcblock_88(y);
		
	};
	inline t_sample gloubiBoulga_10396_d_d(t_sample xin, t_sample drive) {
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
		case 0: *value = self->m_button_38; break;
		case 1: *value = self->m_ctrl_41; break;
		case 2: *value = self->m_ctrl_40; break;
		case 3: *value = self->m_ctrl_36; break;
		case 4: *value = self->m_ctrl_33; break;
		case 5: *value = self->m_ctrl_39; break;
		case 6: *value = self->m_ctrl_31; break;
		case 7: *value = self->m_ctrl_35; break;
		case 8: *value = self->m_gate_37; break;
		case 9: *value = self->m_sw_32; break;
		case 10: *value = self->m_sw_34; break;
		
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
	// initialize parameter 0 ("m_button_38")
	pi = self->__commonstate.params + 0;
	pi->name = "button";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_button_38;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 1 ("m_ctrl_41")
	pi = self->__commonstate.params + 1;
	pi->name = "ctrl1";
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
	// initialize parameter 2 ("m_ctrl_40")
	pi = self->__commonstate.params + 2;
	pi->name = "ctrl2";
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
	// initialize parameter 3 ("m_ctrl_36")
	pi = self->__commonstate.params + 3;
	pi->name = "ctrl3";
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
	// initialize parameter 4 ("m_ctrl_33")
	pi = self->__commonstate.params + 4;
	pi->name = "ctrl4";
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
	// initialize parameter 5 ("m_ctrl_39")
	pi = self->__commonstate.params + 5;
	pi->name = "ctrl5";
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
	// initialize parameter 8 ("m_gate_37")
	pi = self->__commonstate.params + 8;
	pi->name = "gate";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_gate_37;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 9 ("m_sw_32")
	pi = self->__commonstate.params + 9;
	pi->name = "sw1";
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
	// initialize parameter 10 ("m_sw_34")
	pi = self->__commonstate.params + 10;
	pi->name = "sw2";
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
	
	return self;
}

/// Release all resources and memory used by a State object:

void destroy(CommonState *cself) {
	State *self = (State *)cself;
	genlib_sysmem_freeptr(cself->params);
		
	delete self;
}


} // TapeoVersio_2dworking::
