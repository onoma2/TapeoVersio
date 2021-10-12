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
	t_sample m_ctrl_32;
	t_sample m_history_30;
	t_sample m_history_27;
	t_sample m_ctrl_31;
	t_sample m_history_28;
	t_sample m_history_29;
	t_sample m_sw_33;
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
		m_sw_33 = ((int)0);
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
		t_sample sub_16380 = (m_sw_33 - ((int)0));
		t_sample scale_16377 = ((safepow((sub_16380 * ((t_sample)1)), ((int)1)) * ((int)2)) + ((int)1));
		t_sample scale_15871 = scale_16377;
		t_sample SW_15685 = scale_15871;
		t_sample SW_15696 = SW_15685;
		t_sample choice_46 = int(SW_15685);
		t_sample SW_15796 = SW_15685;
		t_sample SW_15723 = SW_15685;
		t_sample choice_47 = int(SW_15723);
		t_sample iup_49 = (1 / maximum(1, abs(((int)4000))));
		t_sample idown_50 = (1 / maximum(1, abs(((int)4000))));
		t_sample sub_16394 = (m_sw_34 - ((int)0));
		t_sample scale_16391 = ((safepow((sub_16394 * ((t_sample)1)), ((int)1)) * ((int)2)) + ((int)1));
		t_sample scale_15870 = scale_16391;
		t_sample SW_15765 = scale_15870;
		t_sample SW_15654 = SW_15765;
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
		int or_15887 = (m_gate_37 || m_button_38);
		t_sample iup_71 = (1 / maximum(1, abs(((int)4000))));
		t_sample idown_72 = (1 / maximum(1, abs(((int)4000))));
		t_sample iup_74 = (1 / maximum(1, abs(((int)3000))));
		t_sample idown_75 = (1 / maximum(1, abs(((int)3000))));
		samples_to_seconds = (1 / samplerate);
		t_sample choice_79 = int(SW_15796);
		t_sample choice_80 = int(SW_15796);
		t_sample choice_81 = int(SW_15696);
		t_sample choice_82 = int(SW_15696);
		t_sample choice_84 = int(SW_15765);
		t_sample iup_86 = (1 / maximum(1, abs(((int)3000))));
		t_sample idown_87 = (1 / maximum(1, abs(((int)3000))));
		t_sample min_89 = (-0.9);
		t_sample choice_90 = int(SW_15796);
		int min_91 = (-1);
		t_sample choice_92 = int(SW_15723);
		t_sample choice_93 = int(SW_15796);
		int min_94 = (-1);
		t_sample choice_96 = int(SW_15654);
		t_sample iup_98 = (1 / maximum(1, abs(((int)3000))));
		t_sample idown_99 = (1 / maximum(1, abs(((int)3000))));
		t_sample min_101 = (-0.9);
		t_sample choice_102 = int(SW_15696);
		t_sample choice_103 = int(SW_15685);
		t_sample choice_104 = int(SW_15696);
		int min_105 = (-1);
		int min_106 = (-1);
		// the main sample loop;
		while ((__n--)) {
			const t_sample in1 = (*(__in1++));
			const t_sample in2 = (*(__in2++));
			t_sample out7 = ((int)0);
			t_sample out8 = ((int)0);
			__m_count_42 = (((int)0) ? 0 : (fixdenorm(__m_count_42 + ((int)1))));
			int counter_15745 = __m_count_42;
			int counter_15746 = ((int)0);
			int counter_15747 = ((int)0);
			int lt_15744 = (counter_15745 < ((int)300000));
			t_sample abs_15735 = fabs(in1);
			t_sample rsub_15734 = (((int)0) - abs_15735);
			t_sample switch_15743 = (lt_15744 ? ((int)0) : rsub_15734);
			t_sample out3 = switch_15743;
			__m_count_43 = (((int)0) ? 0 : (fixdenorm(__m_count_43 + ((int)1))));
			int counter_15739 = __m_count_43;
			int counter_15740 = ((int)0);
			int counter_15741 = ((int)0);
			int lt_15738 = (counter_15739 < ((int)300000));
			t_sample abs_15733 = fabs(in2);
			t_sample rsub_15732 = (((int)0) - abs_15733);
			t_sample switch_15737 = (lt_15738 ? ((t_sample)-0.99) : rsub_15732);
			t_sample out4 = switch_15737;
			__m_count_44 = (((int)0) ? 0 : (fixdenorm(__m_count_44 + ((int)1))));
			int counter_15757 = __m_count_44;
			int counter_15758 = ((int)0);
			int counter_15759 = ((int)0);
			int lt_15756 = (counter_15757 < ((int)300000));
			__m_count_45 = (((int)0) ? 0 : (fixdenorm(__m_count_45 + ((int)1))));
			int counter_15751 = __m_count_45;
			int counter_15752 = ((int)0);
			int counter_15753 = ((int)0);
			int lt_15750 = (counter_15751 < ((int)300000));
			t_sample gate_15687 = (((choice_46 >= 1) && (choice_46 < 2)) ? in2 : 0);
			t_sample gate_15688 = (((choice_46 >= 2) && (choice_46 < 3)) ? in2 : 0);
			t_sample gate_15689 = ((choice_46 >= 3) ? in2 : 0);
			t_sample gate_15725 = (((choice_47 >= 1) && (choice_47 < 2)) ? in1 : 0);
			t_sample gate_15726 = (((choice_47 >= 2) && (choice_47 < 3)) ? in1 : 0);
			t_sample gate_15727 = ((choice_47 >= 3) ? in1 : 0);
			t_sample mix_16381 = (m_history_30 + (((t_sample)0.0019634941468452) * (m_ctrl_41 - m_history_30)));
			t_sample mix_15852 = mix_16381;
			t_sample mix_16382 = (m_history_29 + (((t_sample)0.0019634941468452) * (mix_15852 - m_history_29)));
			t_sample mix_15850 = mix_16382;
			t_sample mix_16383 = (m_history_28 + (((t_sample)0.0019634941468452) * (mix_15850 - m_history_28)));
			t_sample mix_15848 = mix_16383;
			t_sample gen_15863 = mix_15848;
			t_sample history_15853_next_15855 = fixdenorm(mix_15852);
			t_sample history_15851_next_15856 = fixdenorm(mix_15850);
			t_sample history_15849_next_15857 = fixdenorm(mix_15848);
			t_sample REGEN_15820 = gen_15863;
			__m_slide_48 = fixdenorm((__m_slide_48 + (((REGEN_15820 > __m_slide_48) ? iup_49 : idown_50) * (REGEN_15820 - __m_slide_48))));
			t_sample slide_15717 = __m_slide_48;
			t_sample mix_16384 = (m_history_27 + (((t_sample)0.0019634941468452) * (m_ctrl_40 - m_history_27)));
			t_sample mix_16098 = mix_16384;
			t_sample mix_16385 = (m_history_26 + (((t_sample)0.0019634941468452) * (mix_16098 - m_history_26)));
			t_sample mix_16102 = mix_16385;
			t_sample mix_16386 = (m_history_25 + (((t_sample)0.0019634941468452) * (mix_16102 - m_history_25)));
			t_sample mix_16101 = mix_16386;
			t_sample gen_15858 = mix_16101;
			t_sample history_15853_next_16100 = fixdenorm(mix_16098);
			t_sample history_15851_next_16099 = fixdenorm(mix_16102);
			t_sample history_15849_next_16103 = fixdenorm(mix_16101);
			t_sample THING_15815 = gen_15858;
			t_sample sub_16390 = (THING_15815 - ((int)0));
			t_sample scale_16387 = ((safepow((sub_16390 * ((t_sample)1)), ((int)1)) * ((int)50)) + ((int)0));
			t_sample scale_15814 = scale_16387;
			t_sample mix_16395 = (m_history_24 + (((t_sample)0.0019634941468452) * (m_ctrl_31 - m_history_24)));
			t_sample mix_16113 = mix_16395;
			t_sample mix_16396 = (m_history_23 + (((t_sample)0.0019634941468452) * (mix_16113 - m_history_23)));
			t_sample mix_16118 = mix_16396;
			t_sample mix_16397 = (m_history_22 + (((t_sample)0.0019634941468452) * (mix_16118 - m_history_22)));
			t_sample mix_16111 = mix_16397;
			t_sample gen_15860 = mix_16111;
			t_sample history_15853_next_16117 = fixdenorm(mix_16113);
			t_sample history_15851_next_16115 = fixdenorm(mix_16118);
			t_sample history_15849_next_16114 = fixdenorm(mix_16111);
			t_sample TIME_15836 = gen_15860;
			t_sample sub_16401 = (TIME_15836 - ((int)0));
			t_sample scale_16398 = ((safepow((sub_16401 * ((t_sample)1)), ((int)1)) * ((int)2)) + (-1));
			t_sample scale_15803 = scale_16398;
			int gte_15802 = (scale_15803 >= ((int)0));
			t_sample abs_15801 = fabs(scale_15803);
			t_sample add_15822 = (abs_15801 + ((t_sample)0.001));
			t_sample mul_15824 = (add_15822 * ((int)3));
			t_sample ceil_15823 = ceil(mul_15824);
			t_sample div_15806 = safediv(((int)1), ceil_15823);
			t_sample switch_15804 = (gte_15802 ? ceil_15823 : div_15806);
			t_sample NR_15872 = switch_15804;
			t_sample out9 = NR_15872;
			t_sample mix_16402 = (m_history_21 + (((t_sample)0.0019634941468452) * (m_ctrl_36 - m_history_21)));
			t_sample mix_16129 = mix_16402;
			t_sample mix_16403 = (m_history_20 + (((t_sample)0.0019634941468452) * (mix_16129 - m_history_20)));
			t_sample mix_16126 = mix_16403;
			t_sample mix_16404 = (m_history_19 + (((t_sample)0.0019634941468452) * (mix_16126 - m_history_19)));
			t_sample mix_16124 = mix_16404;
			t_sample gen_15862 = mix_16124;
			t_sample history_15853_next_16128 = fixdenorm(mix_16129);
			t_sample history_15851_next_16131 = fixdenorm(mix_16126);
			t_sample history_15849_next_16127 = fixdenorm(mix_16124);
			t_sample TONE_15819 = gen_15862;
			__m_slide_51 = fixdenorm((__m_slide_51 + (((TONE_15819 > __m_slide_51) ? iup_52 : idown_53) * (TONE_15819 - __m_slide_51))));
			t_sample slide_15679 = __m_slide_51;
			__m_slide_54 = fixdenorm((__m_slide_54 + (((TONE_15819 > __m_slide_54) ? iup_55 : idown_56) * (TONE_15819 - __m_slide_54))));
			t_sample slide_15715 = __m_slide_54;
			t_sample sub_16408 = (TONE_15819 - ((int)0));
			t_sample scale_16405 = ((safepow((sub_16408 * ((t_sample)1)), ((int)1)) * ((int)2)) + (-1));
			t_sample scale_15720 = scale_16405;
			t_sample abs_15635 = fabs(scale_15720);
			t_sample sub_16412 = (abs_15635 - ((int)0));
			t_sample scale_16409 = ((safepow((sub_16412 * ((t_sample)1)), ((int)1)) * ((t_sample)0.99)) + ((int)0));
			t_sample scale_15816 = scale_16409;
			__m_slide_57 = fixdenorm((__m_slide_57 + (((scale_15816 > __m_slide_57) ? iup_58 : idown_59) * (scale_15816 - __m_slide_57))));
			t_sample slide_15716 = __m_slide_57;
			t_sample clamp_15830 = ((slide_15716 <= ((int)0)) ? ((int)0) : ((slide_15716 >= ((t_sample)0.99)) ? ((t_sample)0.99) : slide_15716));
			t_sample clamp_15709 = ((slide_15716 <= ((int)0)) ? ((int)0) : ((slide_15716 >= ((t_sample)0.99)) ? ((t_sample)0.99) : slide_15716));
			t_sample mix_16413 = (m_history_18 + (((t_sample)0.0019634941468452) * (m_ctrl_35 - m_history_18)));
			t_sample mix_16144 = mix_16413;
			t_sample mix_16414 = (m_history_17 + (((t_sample)0.0019634941468452) * (mix_16144 - m_history_17)));
			t_sample mix_16140 = mix_16414;
			t_sample mix_16415 = (m_history_16 + (((t_sample)0.0019634941468452) * (mix_16140 - m_history_16)));
			t_sample mix_16138 = mix_16415;
			t_sample gen_15864 = mix_16138;
			t_sample history_15853_next_16137 = fixdenorm(mix_16144);
			t_sample history_15851_next_16142 = fixdenorm(mix_16140);
			t_sample history_15849_next_16141 = fixdenorm(mix_16138);
			t_sample BLEND_15869 = gen_15864;
			t_sample sub_16419 = (BLEND_15869 - ((int)0));
			t_sample scale_16416 = ((safepow((sub_16419 * ((t_sample)1)), ((int)1)) * ((t_sample)0.998)) + ((t_sample)0.001));
			t_sample scale_15866 = scale_16416;
			__m_slide_60 = fixdenorm((__m_slide_60 + (((scale_15866 > __m_slide_60) ? iup_61 : idown_62) * (scale_15866 - __m_slide_60))));
			t_sample slide_15714 = __m_slide_60;
			t_sample mul_15658 = (in2 * ((int)2));
			t_sample abs_15663 = fabs(mul_15658);
			int gt_15662 = (abs_15663 > ((t_sample)0.85));
			int gt_15672 = (gt_15662 > m_history_15);
			t_sample sub_15669 = (gt_15662 - m_history_15);
			t_sample mul_15668 = (sub_15669 * ((t_sample)0.005));
			t_sample mul_15667 = (sub_15669 * ((t_sample)0.001));
			t_sample switch_15670 = (gt_15672 ? mul_15668 : mul_15667);
			t_sample add_15671 = (m_history_15 + switch_15670);
			t_sample rsub_15660 = (((int)1) - add_15671);
			t_sample mix_16420 = (add_15671 + (((int)0) * (rsub_15660 - add_15671)));
			t_sample mix_15659 = mix_16420;
			t_sample gen_15677 = mix_15659;
			t_sample history_15673_next_15675 = fixdenorm(add_15671);
			t_sample sub_16424 = (gen_15677 - ((int)0));
			t_sample scale_16421 = ((safepow((sub_16424 * ((t_sample)1)), ((int)1)) * ((int)-1)) + ((int)1));
			t_sample scale_15656 = scale_16421;
			t_sample sub_16428 = (gen_15677 - ((int)0));
			t_sample scale_16425 = ((safepow((sub_16428 * ((t_sample)1)), ((int)1)) * ((t_sample)0.7)) + ((t_sample)0.3));
			t_sample scale_15648 = scale_16425;
			t_sample mul_15770 = (in1 * ((int)2));
			t_sample abs_15775 = fabs(mul_15770);
			int gt_15774 = (abs_15775 > ((t_sample)0.85));
			int gt_15784 = (gt_15774 > m_history_14);
			t_sample sub_15781 = (gt_15774 - m_history_14);
			t_sample mul_15780 = (sub_15781 * ((t_sample)0.005));
			t_sample mul_15779 = (sub_15781 * ((t_sample)0.001));
			t_sample switch_15782 = (gt_15784 ? mul_15780 : mul_15779);
			t_sample add_15783 = (m_history_14 + switch_15782);
			t_sample rsub_15772 = (((int)1) - add_15783);
			t_sample mix_16429 = (add_15783 + (((int)0) * (rsub_15772 - add_15783)));
			t_sample mix_15771 = mix_16429;
			t_sample gen_15789 = mix_15771;
			t_sample history_15785_next_15787 = fixdenorm(add_15783);
			t_sample sub_16433 = (gen_15789 - ((int)0));
			t_sample scale_16430 = ((safepow((sub_16433 * ((t_sample)1)), ((int)1)) * ((int)-1)) + ((int)1));
			t_sample scale_15767 = scale_16430;
			t_sample sub_16437 = (gen_15789 - ((int)0));
			t_sample scale_16434 = ((safepow((sub_16437 * ((t_sample)1)), ((int)1)) * ((t_sample)0.7)) + ((t_sample)0.3));
			t_sample scale_15722 = scale_16434;
			t_sample mix_16438 = (m_history_13 + (((t_sample)0.0019634941468452) * (m_ctrl_32 - m_history_13)));
			t_sample mix_16153 = mix_16438;
			t_sample mix_16439 = (m_history_12 + (((t_sample)0.0019634941468452) * (mix_16153 - m_history_12)));
			t_sample mix_16157 = mix_16439;
			t_sample mix_16440 = (m_history_11 + (((t_sample)0.0019634941468452) * (mix_16157 - m_history_11)));
			t_sample mix_16151 = mix_16440;
			t_sample gen_15859 = mix_16151;
			t_sample history_15853_next_16148 = fixdenorm(mix_16153);
			t_sample history_15851_next_16150 = fixdenorm(mix_16157);
			t_sample history_15849_next_16155 = fixdenorm(mix_16151);
			t_sample sub_16444 = (gen_15859 - ((int)0));
			t_sample scale_16441 = ((safepow((sub_16444 * ((t_sample)1)), ((t_sample)1.5)) * ((t_sample)0.5)) + ((int)0));
			__m_slide_63 = fixdenorm((__m_slide_63 + (((scale_16441 > __m_slide_63) ? iup_64 : idown_65) * (scale_16441 - __m_slide_63))));
			t_sample slide_15809 = __m_slide_63;
			int delta_15883 = __m_delta_66(or_15887);
			int gtep_15882 = ((delta_15883 >= ((int)1)) ? delta_15883 : 0);
			t_sample plusequals_15881 = __m_pluseq_67.post(gtep_15882, m_history_10, 0);
			int eq_15879 = (plusequals_15881 == ((int)2));
			__m_count_68 = (m_history_10 ? 0 : (fixdenorm(__m_count_68 + plusequals_15881)));
			t_sample counter_15876 = __m_count_68;
			int counter_15877 = ((int)0);
			int counter_15878 = ((int)0);
			__m_latch_69 = ((eq_15879 != 0) ? counter_15876 : __m_latch_69);
			t_sample latch_15875 = __m_latch_69;
			t_sample gen_15885 = latch_15875;
			t_sample history_15880_next_15884 = fixdenorm(eq_15879);
			t_sample CLOCK_15835 = gen_15885;
			t_sample div_15825 = safediv(CLOCK_15835, switch_15804);
			__m_slide_70 = fixdenorm((__m_slide_70 + (((div_15825 > __m_slide_70) ? iup_71 : idown_72) * (div_15825 - __m_slide_70))));
			t_sample slide_15832 = __m_slide_70;
			t_sample div_15652 = (div_15825 * ((t_sample)2.0833333333333e-05));
			t_sample div_15763 = (div_15825 * ((t_sample)2.0833333333333e-05));
			t_sample mix_16445 = (m_history_9 + (((t_sample)0.0019634941468452) * (m_ctrl_39 - m_history_9)));
			t_sample mix_16167 = mix_16445;
			t_sample mix_16446 = (m_history_8 + (((t_sample)0.0019634941468452) * (mix_16167 - m_history_8)));
			t_sample mix_16170 = mix_16446;
			t_sample mix_16447 = (m_history_7 + (((t_sample)0.0019634941468452) * (mix_16170 - m_history_7)));
			t_sample mix_16164 = mix_16447;
			t_sample gen_15861 = mix_16164;
			t_sample history_15853_next_16161 = fixdenorm(mix_16167);
			t_sample history_15851_next_16163 = fixdenorm(mix_16170);
			t_sample history_15849_next_16168 = fixdenorm(mix_16164);
			t_sample MOD_15837 = gen_15861;
			t_sample sub_16451 = (MOD_15837 - ((int)0));
			t_sample scale_16448 = ((safepow((sub_16451 * ((t_sample)1)), ((int)1)) * ((t_sample)0.44)) + ((t_sample)0.55));
			t_sample scale_15839 = scale_16448;
			t_sample sub_16455 = (scale_15839 - ((t_sample)0.55));
			t_sample scale_16452 = ((safepow((sub_16455 * ((t_sample)2.2727272727273)), ((int)1)) * ((t_sample)-0.44)) + ((t_sample)0.99));
			t_sample scale_15838 = scale_16452;
			__m_slide_73 = fixdenorm((__m_slide_73 + (((scale_15838 > __m_slide_73) ? iup_74 : idown_75) * (scale_15838 - __m_slide_73))));
			t_sample slide_15818 = __m_slide_73;
			t_sample sub_16459 = (TIME_15836 - ((int)0));
			t_sample scale_16456 = ((safepow((sub_16459 * ((t_sample)1)), ((int)1)) * ((t_sample)0.499)) + ((t_sample)0.001));
			t_sample scale_15843 = scale_16456;
			t_sample phasor_15846 = __m_phasor_76(scale_15843, samples_to_seconds);
			t_sample rate_15847 = __m_rate_77.perform_off(phasor_15846, ((int)1));
			__m_cycle_78.phase(rate_15847);
			t_sample cycle_15844 = __m_cycle_78(__sinedata);
			t_sample cycleindex_15845 = __m_cycle_78.phase();
			t_sample div_15841 = (cycle_15844 * ((t_sample)0.125));
			t_sample add_15840 = (div_15841 + ((t_sample)0.5));
			t_sample mix_16460 = (add_15840 + (slide_15818 * (((int)1) - add_15840)));
			t_sample mix_15842 = mix_16460;
			t_sample modulation_15760 = mix_15842;
			t_sample modulation_15827 = modulation_15760;
			t_sample div_15828 = safediv(slide_15832, modulation_15827);
			t_sample tap_15834 = m_delay_6.read_linear(div_15828);
			t_sample mix_16461 = (tap_15834 + (clamp_15830 * (m_history_2 - tap_15834)));
			t_sample mix_15831 = mix_16461;
			t_sample mul_15821 = (mix_15831 * slide_15717);
			t_sample sub_15719 = (tap_15834 - mix_15831);
			t_sample mix_16462 = (mix_15831 + (slide_15715 * (sub_15719 - mix_15831)));
			t_sample mix_15718 = mix_16462;
			t_sample add_16464 = (gate_15725 + gate_15727);
			t_sample mix_16463 = (add_16464 + (slide_15714 * (mix_15718 - add_16464)));
			t_sample mix_15868 = mix_16463;
			t_sample gate_15793 = (((choice_79 >= 1) && (choice_79 < 2)) ? mix_15868 : 0);
			t_sample gate_15794 = (((choice_79 >= 2) && (choice_79 < 3)) ? mix_15868 : 0);
			t_sample gate_15795 = ((choice_79 >= 3) ? mix_15868 : 0);
			t_sample selector_15797 = ((choice_80 >= 3) ? gate_15795 : ((choice_80 >= 2) ? gate_15726 : ((choice_80 >= 1) ? mul_15821 : 0)));
			t_sample modulation_15706 = modulation_15760;
			t_sample div_15707 = safediv(slide_15832, modulation_15706);
			t_sample tap_15712 = m_delay_5.read_linear(div_15707);
			t_sample mix_16465 = (tap_15712 + (clamp_15709 * (m_history_1 - tap_15712)));
			t_sample mix_15710 = mix_16465;
			t_sample mul_15704 = (mix_15710 * slide_15717);
			t_sample sub_15683 = (tap_15712 - mix_15710);
			t_sample mix_16466 = (mix_15710 + (slide_15679 * (sub_15683 - mix_15710)));
			t_sample mix_15682 = mix_16466;
			t_sample add_16468 = (gate_15687 + gate_15689);
			t_sample mix_16467 = (add_16468 + (slide_15714 * (mix_15682 - add_16468)));
			t_sample mix_15713 = mix_16467;
			t_sample gate_15693 = (((choice_81 >= 1) && (choice_81 < 2)) ? mix_15713 : 0);
			t_sample gate_15694 = (((choice_81 >= 2) && (choice_81 < 3)) ? mix_15713 : 0);
			t_sample gate_15695 = ((choice_81 >= 3) ? mix_15713 : 0);
			t_sample selector_15697 = ((choice_82 >= 3) ? gate_15695 : ((choice_82 >= 2) ? gate_15688 : ((choice_82 >= 1) ? mul_15704 : 0)));
			t_sample mul_15761 = (div_15763 * modulation_15760);
			t_sample phasor_15762 = __m_phasor_83(mul_15761, samples_to_seconds);
			t_sample triangle_15764 = triangle(phasor_15762, ((t_sample)0.5));
			t_sample selector_15766 = ((choice_84 >= 3) ? scale_15722 : ((choice_84 >= 2) ? triangle_15764 : ((choice_84 >= 1) ? scale_15767 : 0)));
			t_sample clamp_15769 = ((selector_15766 <= ((t_sample)0.01)) ? ((t_sample)0.01) : ((selector_15766 >= ((int)1)) ? ((int)1) : selector_15766));
			t_sample mul_15768 = (scale_15814 * clamp_15769);
			__m_slide_85 = fixdenorm((__m_slide_85 + (((mul_15768 > __m_slide_85) ? iup_86 : idown_87) * (mul_15768 - __m_slide_85))));
			t_sample slide_15811 = __m_slide_85;
			t_sample expr_16095 = gloubiBoulga_d_d(selector_15797, slide_15811);
			t_sample clamp_15813 = ((expr_16095 <= min_89) ? min_89 : ((expr_16095 >= ((t_sample)0.9)) ? ((t_sample)0.9) : expr_16095));
			t_sample gate_15798 = (((choice_90 >= 1) && (choice_90 < 2)) ? clamp_15813 : 0);
			t_sample gate_15799 = (((choice_90 >= 2) && (choice_90 < 3)) ? clamp_15813 : 0);
			t_sample gate_15800 = ((choice_90 >= 3) ? clamp_15813 : 0);
			t_sample mix_16469 = (gate_15795 + (slide_15809 * (gate_15800 - gate_15795)));
			t_sample mul_15643 = (gate_15798 * ((t_sample)0.5));
			t_sample mul_15642 = (m_history_4 * ((t_sample)0.5));
			t_sample add_15644 = (mul_15643 + mul_15642);
			t_sample history_15645_next_15646 = fixdenorm(gate_15798);
			t_sample mix_16470 = (mul_15821 + (slide_15809 * (add_15644 - mul_15821)));
			t_sample clamp_15826 = ((mix_16470 <= min_91) ? min_91 : ((mix_16470 >= ((int)1)) ? ((int)1) : mix_16470));
			t_sample selector_15724 = ((choice_92 >= 3) ? ((int)0) : ((choice_92 >= 2) ? gate_15799 : ((choice_92 >= 1) ? ((int)0) : 0)));
			t_sample mix_16471 = (gate_15794 + (slide_15809 * (selector_15724 - gate_15794)));
			t_sample selector_15792 = ((choice_93 >= 3) ? mix_16469 : ((choice_93 >= 2) ? mix_16471 : ((choice_93 >= 1) ? gate_15793 : 0)));
			t_sample mul_15817 = (selector_15792 * ((int)1));
			t_sample clamp_15867 = ((mul_15817 <= min_94) ? min_94 : ((mul_15817 >= ((int)1)) ? ((int)1) : mul_15817));
			t_sample out1 = clamp_15867;
			t_sample abs_15731 = fabs(clamp_15867);
			t_sample rsub_15730 = (((int)0) - abs_15731);
			t_sample switch_15755 = (lt_15756 ? ((t_sample)-0.99) : rsub_15730);
			t_sample out5 = switch_15755;
			t_sample modulation_15649 = modulation_15760;
			t_sample mul_15650 = (div_15652 * modulation_15649);
			t_sample phasor_15651 = __m_phasor_95(mul_15650, samples_to_seconds);
			t_sample triangle_15653 = triangle(phasor_15651, ((t_sample)0.5));
			t_sample selector_15655 = ((choice_96 >= 3) ? scale_15648 : ((choice_96 >= 2) ? triangle_15653 : ((choice_96 >= 1) ? scale_15656 : 0)));
			t_sample clamp_15657 = ((selector_15655 <= ((t_sample)0.01)) ? ((t_sample)0.01) : ((selector_15655 >= ((int)1)) ? ((int)1) : selector_15655));
			t_sample mul_15690 = (scale_15814 * clamp_15657);
			__m_slide_97 = fixdenorm((__m_slide_97 + (((mul_15690 > __m_slide_97) ? iup_98 : idown_99) * (mul_15690 - __m_slide_97))));
			t_sample slide_15681 = __m_slide_97;
			t_sample expr_16094 = gloubiBoulga_16176_d_d(selector_15697, slide_15681);
			t_sample clamp_15703 = ((expr_16094 <= min_101) ? min_101 : ((expr_16094 >= ((t_sample)0.9)) ? ((t_sample)0.9) : expr_16094));
			t_sample gate_15698 = (((choice_102 >= 1) && (choice_102 < 2)) ? clamp_15703 : 0);
			t_sample gate_15699 = (((choice_102 >= 2) && (choice_102 < 3)) ? clamp_15703 : 0);
			t_sample gate_15700 = ((choice_102 >= 3) ? clamp_15703 : 0);
			t_sample mix_16472 = (gate_15695 + (slide_15809 * (gate_15700 - gate_15695)));
			t_sample selector_15686 = ((choice_103 >= 3) ? ((int)0) : ((choice_103 >= 2) ? gate_15699 : ((choice_103 >= 1) ? ((int)0) : 0)));
			t_sample mix_16473 = (gate_15694 + (slide_15809 * (selector_15686 - gate_15694)));
			t_sample selector_15692 = ((choice_104 >= 3) ? mix_16472 : ((choice_104 >= 2) ? mix_16473 : ((choice_104 >= 1) ? gate_15693 : 0)));
			t_sample mul_15680 = (selector_15692 * ((int)1));
			t_sample clamp_15865 = ((mul_15680 <= min_105) ? min_105 : ((mul_15680 >= ((int)1)) ? ((int)1) : mul_15680));
			t_sample out2 = clamp_15865;
			t_sample abs_15729 = fabs(clamp_15865);
			t_sample rsub_15728 = (((int)0) - abs_15729);
			t_sample switch_15749 = (lt_15750 ? ((t_sample)-0.99) : rsub_15728);
			t_sample out6 = switch_15749;
			t_sample mul_15637 = (gate_15698 * ((t_sample)0.5));
			t_sample mul_15636 = (m_history_3 * ((t_sample)0.5));
			t_sample add_15638 = (mul_15637 + mul_15636);
			t_sample history_15639_next_15640 = fixdenorm(gate_15698);
			t_sample mix_16474 = (mul_15704 + (slide_15809 * (add_15638 - mul_15704)));
			t_sample clamp_15705 = ((mix_16474 <= min_106) ? min_106 : ((mix_16474 >= ((int)1)) ? ((int)1) : mix_16474));
			t_sample history_15829_next_16177 = fixdenorm(mix_15831);
			t_sample history_15708_next_16178 = fixdenorm(mix_15710);
			m_history_30 = history_15853_next_15855;
			m_history_28 = history_15849_next_15857;
			m_history_29 = history_15851_next_15856;
			m_history_27 = history_15853_next_16100;
			m_history_25 = history_15849_next_16103;
			m_history_26 = history_15851_next_16099;
			m_history_24 = history_15853_next_16117;
			m_history_22 = history_15849_next_16114;
			m_history_23 = history_15851_next_16115;
			m_history_21 = history_15853_next_16128;
			m_history_19 = history_15849_next_16127;
			m_history_20 = history_15851_next_16131;
			m_history_18 = history_15853_next_16137;
			m_history_16 = history_15849_next_16141;
			m_history_17 = history_15851_next_16142;
			m_history_15 = history_15673_next_15675;
			m_history_14 = history_15785_next_15787;
			m_history_13 = history_15853_next_16148;
			m_history_11 = history_15849_next_16155;
			m_history_12 = history_15851_next_16150;
			m_history_10 = history_15880_next_15884;
			m_history_9 = history_15853_next_16161;
			m_history_7 = history_15849_next_16168;
			m_history_8 = history_15851_next_16163;
			m_delay_6.write((((gate_15725 + gate_15726) + gate_15727) + clamp_15826));
			m_delay_5.write((((clamp_15705 + gate_15687) + gate_15688) + gate_15689));
			m_history_4 = history_15645_next_15646;
			m_history_3 = history_15639_next_15640;
			m_history_2 = history_15829_next_16177;
			m_history_1 = history_15708_next_16178;
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
	inline void set_ctrl4(t_param _value) {
		m_ctrl_32 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw1(t_param _value) {
		m_sw_33 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw2(t_param _value) {
		m_sw_34 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_ctrl1(t_param _value) {
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
	inline void set_ctrl2(t_param _value) {
		m_ctrl_39 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_ctrl7(t_param _value) {
		m_ctrl_40 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_ctrl5(t_param _value) {
		m_ctrl_41 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline t_sample gloubiBoulga_d_d(t_sample xin, t_sample drive) {
		drive = ((drive < ((int)1)) ? ((int)1) : drive);
		t_sample x = ((xin * drive) * ((t_sample)0.686306));
		t_sample a = (((int)1) + exp((sqrt(fabs(x)) * (-((t_sample)0.75)))));
		t_sample y = safediv((exp(x) - exp(((-x) * a))), (exp(x) + exp((-x))));
		return __m_dcblock_88(y);
		
	};
	inline t_sample gloubiBoulga_16176_d_d(t_sample xin, t_sample drive) {
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
		case 1: *value = self->m_ctrl_35; break;
		case 2: *value = self->m_ctrl_39; break;
		case 3: *value = self->m_ctrl_36; break;
		case 4: *value = self->m_ctrl_32; break;
		case 5: *value = self->m_ctrl_41; break;
		case 6: *value = self->m_ctrl_31; break;
		case 7: *value = self->m_ctrl_40; break;
		case 8: *value = self->m_gate_37; break;
		case 9: *value = self->m_sw_33; break;
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
	// initialize parameter 1 ("m_ctrl_35")
	pi = self->__commonstate.params + 1;
	pi->name = "ctrl1";
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
	// initialize parameter 2 ("m_ctrl_39")
	pi = self->__commonstate.params + 2;
	pi->name = "ctrl2";
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
	// initialize parameter 4 ("m_ctrl_32")
	pi = self->__commonstate.params + 4;
	pi->name = "ctrl4";
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
	// initialize parameter 5 ("m_ctrl_41")
	pi = self->__commonstate.params + 5;
	pi->name = "ctrl5";
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
	// initialize parameter 9 ("m_sw_33")
	pi = self->__commonstate.params + 9;
	pi->name = "sw1";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_sw_33;
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
