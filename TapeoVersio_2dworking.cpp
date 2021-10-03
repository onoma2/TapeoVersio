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
	DCBlock __m_dcblock_63;
	DCBlock __m_dcblock_57;
	Delay m_delay_3;
	Delay m_delay_4;
	Delta __m_delta_38;
	Phasor __m_phasor_54;
	PlusEquals __m_pluseq_39;
	Rate __m_rate_55;
	SineCycle __m_cycle_56;
	SineData __sinedata;
	int __exception;
	int vectorsize;
	t_sample m_history_9;
	t_sample m_button_37;
	t_sample m_history_6;
	t_sample m_sw_36;
	t_sample m_history_5;
	t_sample m_ctrl_35;
	t_sample m_ctrl_33;
	t_sample m_gate_34;
	t_sample m_ctrl_32;
	t_sample __m_count_40;
	t_sample __m_latch_41;
	t_sample __m_slide_42;
	t_sample m_history_2;
	t_sample m_history_1;
	t_sample samplerate;
	t_sample m_ctrl_31;
	t_sample samples_to_seconds;
	t_sample __m_slide_48;
	t_sample __m_slide_51;
	t_sample __m_slide_45;
	t_sample m_history_8;
	t_sample m_sw_30;
	t_sample m_ctrl_28;
	t_sample m_history_14;
	t_sample m_history_15;
	t_sample m_history_16;
	t_sample m_history_17;
	t_sample m_history_13;
	t_sample m_history_11;
	t_sample m_history_12;
	t_sample m_history_10;
	t_sample m_ctrl_29;
	t_sample m_history_18;
	t_sample m_history_20;
	t_sample m_history_7;
	t_sample m_history_26;
	t_sample m_ctrl_27;
	t_sample m_history_19;
	t_sample m_history_24;
	t_sample m_history_22;
	t_sample m_history_23;
	t_sample m_history_21;
	t_sample m_history_25;
	// re-initialize all member variables;
	inline void reset(t_param __sr, int __vs) {
		__exception = 0;
		vectorsize = __vs;
		samplerate = __sr;
		m_history_1 = ((int)0);
		m_history_2 = ((int)0);
		m_delay_3.reset("m_delay_3", ((int)96000));
		m_delay_4.reset("m_delay_4", ((int)96000));
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
		m_ctrl_27 = ((int)0);
		m_ctrl_28 = ((int)0);
		m_ctrl_29 = ((int)0);
		m_sw_30 = ((int)0);
		m_ctrl_31 = ((int)0);
		m_ctrl_32 = ((int)0);
		m_ctrl_33 = ((int)0);
		m_gate_34 = ((int)0);
		m_ctrl_35 = ((int)0);
		m_sw_36 = ((int)0);
		m_button_37 = ((int)0);
		__m_delta_38.reset(0);
		__m_pluseq_39.reset(0);
		__m_count_40 = 0;
		__m_latch_41 = 0;
		__m_slide_42 = 0;
		__m_slide_45 = 0;
		__m_slide_48 = 0;
		__m_slide_51 = 0;
		samples_to_seconds = (1 / samplerate);
		__m_phasor_54.reset(0);
		__m_rate_55.reset();
		__m_cycle_56.reset(samplerate, 0);
		__m_dcblock_57.reset();
		__m_dcblock_63.reset();
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
		int or_5820 = (m_gate_34 || m_button_37);
		t_sample sub_36698 = (m_sw_30 - ((int)0));
		t_sample scale_36695 = ((safepow((sub_36698 * ((t_sample)1)), ((int)1)) * ((int)2)) + ((int)1));
		t_sample iup_43 = (1 / maximum(1, abs(((int)3000))));
		t_sample idown_44 = (1 / maximum(1, abs(((int)3000))));
		t_sample iup_46 = (1 / maximum(1, abs(((int)3000))));
		t_sample idown_47 = (1 / maximum(1, abs(((int)3000))));
		t_sample iup_49 = (1 / maximum(1, abs(((int)3000))));
		t_sample idown_50 = (1 / maximum(1, abs(((int)3000))));
		t_sample iup_52 = (1 / maximum(1, abs(((int)3000))));
		t_sample idown_53 = (1 / maximum(1, abs(((int)3000))));
		samples_to_seconds = (1 / samplerate);
		t_sample min_58 = (-0.5);
		int min_59 = (-1);
		int min_60 = (-1);
		t_sample choice_61 = int(scale_36695);
		t_sample choice_62 = int(scale_36695);
		t_sample min_64 = (-0.5);
		t_sample choice_65 = int(scale_36695);
		int min_66 = (-1);
		t_sample choice_67 = int(scale_36695);
		int min_68 = (-1);
		// the main sample loop;
		while ((__n--)) {
			const t_sample in1 = (*(__in1++));
			const t_sample in2 = (*(__in2++));
			t_sample out3 = ((int)0);
			t_sample out4 = ((int)0);
			t_sample out5 = ((int)0);
			t_sample out8 = ((int)0);
			int delta_5816 = __m_delta_38(or_5820);
			int gtep_5815 = ((delta_5816 >= ((int)1)) ? delta_5816 : 0);
			t_sample plusequals_5814 = __m_pluseq_39.post(gtep_5815, m_history_26, 0);
			int eq_5812 = (plusequals_5814 == ((int)2));
			__m_count_40 = (m_history_26 ? 0 : (fixdenorm(__m_count_40 + plusequals_5814)));
			t_sample counter_5809 = __m_count_40;
			int counter_5810 = ((int)0);
			int counter_5811 = ((int)0);
			__m_latch_41 = ((eq_5812 != 0) ? counter_5809 : __m_latch_41);
			t_sample latch_5808 = __m_latch_41;
			t_sample gen_5818 = latch_5808;
			t_sample history_5813_next_5817 = fixdenorm(eq_5812);
			t_sample out6 = gen_5818;
			t_sample mix_36692 = (m_history_25 + (((t_sample)0.0042742627044161) * (m_ctrl_32 - m_history_25)));
			t_sample mix_4874 = mix_36692;
			t_sample mix_36693 = (m_history_24 + (((t_sample)0.0042742627044161) * (mix_4874 - m_history_24)));
			t_sample mix_4872 = mix_36693;
			t_sample mix_36694 = (m_history_23 + (((t_sample)0.0042742627044161) * (mix_4872 - m_history_23)));
			t_sample mix_4870 = mix_36694;
			t_sample gen_5795 = mix_4870;
			t_sample history_4875_next_4877 = fixdenorm(mix_4874);
			t_sample history_4873_next_4878 = fixdenorm(mix_4872);
			t_sample history_4871_next_4879 = fixdenorm(mix_4870);
			t_sample mix_36699 = (m_history_22 + (((t_sample)0.0042742627044161) * (m_ctrl_29 - m_history_22)));
			t_sample mix_36552 = mix_36699;
			t_sample mix_36700 = (m_history_21 + (((t_sample)0.0042742627044161) * (mix_36552 - m_history_21)));
			t_sample mix_36545 = mix_36700;
			t_sample mix_36701 = (m_history_20 + (((t_sample)0.0042742627044161) * (mix_36545 - m_history_20)));
			t_sample mix_36553 = mix_36701;
			t_sample gen_5790 = mix_36553;
			t_sample history_4875_next_36549 = fixdenorm(mix_36552);
			t_sample history_4873_next_36550 = fixdenorm(mix_36545);
			t_sample history_4871_next_36551 = fixdenorm(mix_36553);
			t_sample sub_36705 = (gen_5790 - ((int)0));
			t_sample scale_36702 = ((safepow((sub_36705 * ((t_sample)1)), ((int)1)) * ((int)100)) + ((int)0));
			__m_slide_42 = fixdenorm((__m_slide_42 + (((scale_36702 > __m_slide_42) ? iup_43 : idown_44) * (scale_36702 - __m_slide_42))));
			t_sample slide_5744 = __m_slide_42;
			t_sample mix_36706 = (m_history_19 + (((t_sample)0.0042742627044161) * (m_ctrl_35 - m_history_19)));
			t_sample mix_36566 = mix_36706;
			t_sample mix_36707 = (m_history_18 + (((t_sample)0.0042742627044161) * (mix_36566 - m_history_18)));
			t_sample mix_36560 = mix_36707;
			t_sample mix_36708 = (m_history_17 + (((t_sample)0.0042742627044161) * (mix_36560 - m_history_17)));
			t_sample mix_36564 = mix_36708;
			t_sample gen_5794 = mix_36564;
			t_sample history_4875_next_36562 = fixdenorm(mix_36566);
			t_sample history_4873_next_36563 = fixdenorm(mix_36560);
			t_sample history_4871_next_36565 = fixdenorm(mix_36564);
			t_sample TONE_5761 = gen_5794;
			t_sample sub_36712 = (TONE_5761 - ((int)0));
			t_sample scale_36709 = ((safepow((sub_36712 * ((t_sample)1)), ((int)1)) * ((t_sample)0.95)) + ((int)0));
			t_sample scale_5750 = scale_36709;
			t_sample clamp_5757 = ((scale_5750 <= ((int)0)) ? ((int)0) : ((scale_5750 >= ((t_sample)0.99)) ? ((t_sample)0.99) : scale_5750));
			t_sample clamp_5772 = ((scale_5750 <= ((int)0)) ? ((int)0) : ((scale_5750 >= ((t_sample)0.99)) ? ((t_sample)0.99) : scale_5750));
			t_sample mix_36713 = (m_history_16 + (((t_sample)0.0042742627044161) * (m_ctrl_33 - m_history_16)));
			t_sample mix_36574 = mix_36713;
			t_sample mix_36714 = (m_history_15 + (((t_sample)0.0042742627044161) * (mix_36574 - m_history_15)));
			t_sample mix_36579 = mix_36714;
			t_sample mix_36715 = (m_history_14 + (((t_sample)0.0042742627044161) * (mix_36579 - m_history_14)));
			t_sample mix_36577 = mix_36715;
			t_sample gen_5792 = mix_36577;
			t_sample history_4875_next_36575 = fixdenorm(mix_36574);
			t_sample history_4873_next_36576 = fixdenorm(mix_36579);
			t_sample history_4871_next_36578 = fixdenorm(mix_36577);
			t_sample TIME_5778 = gen_5792;
			t_sample sub_36719 = (TIME_5778 - ((int)0));
			t_sample scale_36716 = ((safepow((sub_36719 * ((t_sample)1)), ((int)1)) * ((int)2)) + (-1));
			t_sample scale_19620 = scale_36716;
			int gt_19836 = (scale_19620 > ((int)0));
			t_sample abs_20689 = fabs(scale_19620);
			t_sample add_5764 = (abs_20689 + ((t_sample)0.001));
			t_sample mul_5766 = (add_5764 * ((int)7));
			t_sample ceil_5765 = ceil(mul_5766);
			t_sample div_17960 = safediv(((int)1), ceil_5765);
			t_sample switch_18998 = (gt_19836 ? ceil_5765 : div_17960);
			t_sample NR_5805 = switch_18998;
			t_sample out9 = NR_5805;
			t_sample CLOCK_5777 = gen_5818;
			t_sample div_5767 = safediv(CLOCK_5777, switch_18998);
			__m_slide_45 = fixdenorm((__m_slide_45 + (((div_5767 > __m_slide_45) ? iup_46 : idown_47) * (div_5767 - __m_slide_45))));
			t_sample slide_16282 = __m_slide_45;
			t_sample mix_36720 = (m_history_13 + (((t_sample)0.0042742627044161) * (m_ctrl_27 - m_history_13)));
			t_sample mix_36587 = mix_36720;
			t_sample mix_36721 = (m_history_12 + (((t_sample)0.0042742627044161) * (mix_36587 - m_history_12)));
			t_sample mix_36583 = mix_36721;
			t_sample mix_36722 = (m_history_11 + (((t_sample)0.0042742627044161) * (mix_36583 - m_history_11)));
			t_sample mix_36586 = mix_36722;
			t_sample gen_5796 = mix_36586;
			t_sample history_4875_next_36589 = fixdenorm(mix_36587);
			t_sample history_4873_next_36590 = fixdenorm(mix_36583);
			t_sample history_4871_next_36591 = fixdenorm(mix_36586);
			t_sample sub_36726 = (gen_5796 - ((int)0));
			t_sample scale_36723 = ((safepow((sub_36726 * ((t_sample)1)), ((int)1)) * ((t_sample)0.998)) + ((t_sample)0.001));
			t_sample mix_36727 = (m_history_10 + (((t_sample)0.0042742627044161) * (m_ctrl_31 - m_history_10)));
			t_sample mix_36600 = mix_36727;
			t_sample mix_36728 = (m_history_9 + (((t_sample)0.0042742627044161) * (mix_36600 - m_history_9)));
			t_sample mix_36596 = mix_36728;
			t_sample mix_36729 = (m_history_8 + (((t_sample)0.0042742627044161) * (mix_36596 - m_history_8)));
			t_sample mix_36599 = mix_36729;
			t_sample gen_5791 = mix_36599;
			t_sample history_4875_next_36602 = fixdenorm(mix_36600);
			t_sample history_4873_next_36603 = fixdenorm(mix_36596);
			t_sample history_4871_next_36605 = fixdenorm(mix_36599);
			t_sample sub_36733 = (gen_5791 - ((int)0));
			t_sample scale_36730 = ((safepow((sub_36733 * ((t_sample)1)), ((int)1)) * ((t_sample)0.1)) + ((int)0));
			__m_slide_48 = fixdenorm((__m_slide_48 + (((scale_36730 > __m_slide_48) ? iup_49 : idown_50) * (scale_36730 - __m_slide_48))));
			t_sample slide_5742 = __m_slide_48;
			t_sample mix_36734 = (m_history_7 + (((t_sample)0.0042742627044161) * (m_ctrl_28 - m_history_7)));
			t_sample mix_36613 = mix_36734;
			t_sample mix_36735 = (m_history_6 + (((t_sample)0.0042742627044161) * (mix_36613 - m_history_6)));
			t_sample mix_36609 = mix_36735;
			t_sample mix_36736 = (m_history_5 + (((t_sample)0.0042742627044161) * (mix_36609 - m_history_5)));
			t_sample mix_36612 = mix_36736;
			t_sample gen_5793 = mix_36612;
			t_sample history_4875_next_36615 = fixdenorm(mix_36613);
			t_sample history_4873_next_36616 = fixdenorm(mix_36609);
			t_sample history_4871_next_36618 = fixdenorm(mix_36612);
			t_sample MOD_5779 = gen_5793;
			t_sample sub_36740 = (MOD_5779 - ((int)0));
			t_sample scale_36737 = ((safepow((sub_36740 * ((t_sample)1)), ((int)1)) * ((t_sample)0.44)) + ((t_sample)0.55));
			t_sample scale_5781 = scale_36737;
			t_sample sub_36744 = (scale_5781 - ((t_sample)0.55));
			t_sample scale_36741 = ((safepow((sub_36744 * ((t_sample)2.2727272727273)), ((int)1)) * ((t_sample)-0.44)) + ((t_sample)0.99));
			t_sample scale_5780 = scale_36741;
			__m_slide_51 = fixdenorm((__m_slide_51 + (((scale_5780 > __m_slide_51) ? iup_52 : idown_53) * (scale_5780 - __m_slide_51))));
			t_sample slide_5753 = __m_slide_51;
			t_sample sub_36748 = (TIME_5778 - ((int)0));
			t_sample scale_36745 = ((safepow((sub_36748 * ((t_sample)1)), ((int)1)) * ((t_sample)0.499)) + ((t_sample)0.001));
			t_sample scale_5785 = scale_36745;
			t_sample phasor_5788 = __m_phasor_54(scale_5785, samples_to_seconds);
			t_sample rate_5789 = __m_rate_55.perform_off(phasor_5788, ((int)1));
			__m_cycle_56.phase(rate_5789);
			t_sample cycle_5786 = __m_cycle_56(__sinedata);
			t_sample cycleindex_5787 = __m_cycle_56.phase();
			t_sample div_5783 = (cycle_5786 * ((t_sample)0.125));
			t_sample add_5782 = (div_5783 + ((t_sample)0.5));
			t_sample mix_36749 = (add_5782 + (slide_5753 * (((int)1) - add_5782)));
			t_sample mix_5784 = mix_36749;
			t_sample modulation_5769 = mix_5784;
			t_sample div_5770 = safediv(slide_16282, modulation_5769);
			t_sample tap_5760 = m_delay_4.read_linear(div_5770);
			t_sample mix_36750 = (tap_5760 + (clamp_5757 * (m_history_2 - tap_5760)));
			t_sample mix_5758 = mix_36750;
			t_sample mul_5754 = (mix_5758 * gen_5795);
			t_sample expr_36542 = gloubiBoulga_d_d(mul_5754, slide_5744);
			t_sample clamp_25043 = ((expr_36542 <= min_58) ? min_58 : ((expr_36542 >= ((t_sample)0.5)) ? ((t_sample)0.5) : expr_36542));
			t_sample mix_36751 = (mul_5754 + (slide_5742 * (clamp_25043 - mul_5754)));
			t_sample clamp_5755 = ((mix_36751 <= min_59) ? min_59 : ((mix_36751 >= ((int)1)) ? ((int)1) : mix_36751));
			t_sample mix_36752 = (in2 + (scale_36723 * (mix_5758 - in2)));
			t_sample mul_5751 = (mix_36752 * ((t_sample)1.5));
			t_sample clamp_5797 = ((mul_5751 <= min_60) ? min_60 : ((mul_5751 >= ((int)1)) ? ((int)1) : mul_5751));
			t_sample out2 = clamp_5797;
			t_sample tap_5776 = m_delay_3.read_linear(div_5770);
			t_sample mix_36753 = (tap_5776 + (clamp_5772 * (m_history_1 - tap_5776)));
			t_sample mix_5773 = mix_36753;
			t_sample mul_5763 = (mix_5773 * gen_5795);
			t_sample mix_36754 = (in1 + (scale_36723 * (mix_5773 - in1)));
			t_sample gate_31684 = (((choice_61 >= 1) && (choice_61 < 2)) ? mix_36754 : 0);
			t_sample gate_31685 = (((choice_61 >= 2) && (choice_61 < 3)) ? mix_36754 : 0);
			t_sample gate_31686 = ((choice_61 >= 3) ? mix_36754 : 0);
			t_sample selector_26412 = ((choice_62 >= 3) ? gate_31686 : ((choice_62 >= 2) ? ((int)0) : ((choice_62 >= 1) ? mul_5763 : 0)));
			t_sample expr_36543 = gloubiBoulga_36624_d_d(selector_26412, slide_5744);
			t_sample clamp_24835 = ((expr_36543 <= min_64) ? min_64 : ((expr_36543 >= ((t_sample)0.5)) ? ((t_sample)0.5) : expr_36543));
			t_sample out7 = clamp_24835;
			t_sample gate_25788 = (((choice_65 >= 1) && (choice_65 < 2)) ? clamp_24835 : 0);
			t_sample gate_25789 = (((choice_65 >= 2) && (choice_65 < 3)) ? clamp_24835 : 0);
			t_sample gate_25790 = ((choice_65 >= 3) ? clamp_24835 : 0);
			t_sample mix_36755 = (mul_5763 + (slide_5742 * (gate_25788 - mul_5763)));
			t_sample clamp_5768 = ((mix_36755 <= min_66) ? min_66 : ((mix_36755 >= ((int)1)) ? ((int)1) : mix_36755));
			t_sample selector_33616 = ((choice_67 >= 3) ? gate_25790 : ((choice_67 >= 2) ? ((int)0) : ((choice_67 >= 1) ? gate_31684 : 0)));
			t_sample mul_5752 = (selector_33616 * ((t_sample)1.5));
			t_sample clamp_5800 = ((mul_5752 <= min_68) ? min_68 : ((mul_5752 >= ((int)1)) ? ((int)1) : mul_5752));
			t_sample out1 = clamp_5800;
			t_sample history_5756_next_36625 = fixdenorm(mix_5758);
			t_sample history_5771_next_36626 = fixdenorm(mix_5773);
			m_history_26 = history_5813_next_5817;
			m_history_25 = history_4875_next_4877;
			m_history_23 = history_4871_next_4879;
			m_history_24 = history_4873_next_4878;
			m_history_22 = history_4875_next_36549;
			m_history_20 = history_4871_next_36551;
			m_history_21 = history_4873_next_36550;
			m_history_19 = history_4875_next_36562;
			m_history_17 = history_4871_next_36565;
			m_history_18 = history_4873_next_36563;
			m_history_16 = history_4875_next_36575;
			m_history_14 = history_4871_next_36578;
			m_history_15 = history_4873_next_36576;
			m_history_13 = history_4875_next_36589;
			m_history_11 = history_4871_next_36591;
			m_history_12 = history_4873_next_36590;
			m_history_10 = history_4875_next_36602;
			m_history_8 = history_4871_next_36605;
			m_history_9 = history_4873_next_36603;
			m_history_7 = history_4875_next_36615;
			m_history_5 = history_4871_next_36618;
			m_history_6 = history_4873_next_36616;
			m_delay_4.write((in2 + clamp_5755));
			m_delay_3.write((clamp_5768 + in1));
			m_history_2 = history_5756_next_36625;
			m_history_1 = history_5771_next_36626;
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
	inline void set_ctrl1(t_param _value) {
		m_ctrl_27 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_ctrl2(t_param _value) {
		m_ctrl_28 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_ctrl7(t_param _value) {
		m_ctrl_29 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw1(t_param _value) {
		m_sw_30 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_ctrl4(t_param _value) {
		m_ctrl_31 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_ctrl5(t_param _value) {
		m_ctrl_32 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_ctrl6(t_param _value) {
		m_ctrl_33 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_gate(t_param _value) {
		m_gate_34 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_ctrl3(t_param _value) {
		m_ctrl_35 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw2(t_param _value) {
		m_sw_36 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_button(t_param _value) {
		m_button_37 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline t_sample gloubiBoulga_d_d(t_sample xin, t_sample drive) {
		drive = ((drive < ((int)1)) ? ((int)1) : drive);
		t_sample x = ((xin * drive) * ((t_sample)0.686306));
		t_sample a = (((int)1) + exp((sqrt(fabs(x)) * (-((t_sample)0.75)))));
		t_sample y = safediv((exp(x) - exp(((-x) * a))), (exp(x) + exp((-x))));
		return __m_dcblock_57(y);
		
	};
	inline t_sample gloubiBoulga_36624_d_d(t_sample xin, t_sample drive) {
		drive = ((drive < ((int)1)) ? ((int)1) : drive);
		t_sample x = ((xin * drive) * ((t_sample)0.686306));
		t_sample a = (((int)1) + exp((sqrt(fabs(x)) * (-((t_sample)0.75)))));
		t_sample y = safediv((exp(x) - exp(((-x) * a))), (exp(x) + exp((-x))));
		return __m_dcblock_63(y);
		
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
		case 0: *value = self->m_button_37; break;
		case 1: *value = self->m_ctrl_27; break;
		case 2: *value = self->m_ctrl_28; break;
		case 3: *value = self->m_ctrl_35; break;
		case 4: *value = self->m_ctrl_31; break;
		case 5: *value = self->m_ctrl_32; break;
		case 6: *value = self->m_ctrl_33; break;
		case 7: *value = self->m_ctrl_29; break;
		case 8: *value = self->m_gate_34; break;
		case 9: *value = self->m_sw_30; break;
		case 10: *value = self->m_sw_36; break;
		
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
	// initialize parameter 0 ("m_button_37")
	pi = self->__commonstate.params + 0;
	pi->name = "button";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_button_37;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 1 ("m_ctrl_27")
	pi = self->__commonstate.params + 1;
	pi->name = "ctrl1";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_ctrl_27;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 2 ("m_ctrl_28")
	pi = self->__commonstate.params + 2;
	pi->name = "ctrl2";
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
	// initialize parameter 4 ("m_ctrl_31")
	pi = self->__commonstate.params + 4;
	pi->name = "ctrl4";
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
	// initialize parameter 5 ("m_ctrl_32")
	pi = self->__commonstate.params + 5;
	pi->name = "ctrl5";
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
	// initialize parameter 6 ("m_ctrl_33")
	pi = self->__commonstate.params + 6;
	pi->name = "ctrl6";
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
	// initialize parameter 7 ("m_ctrl_29")
	pi = self->__commonstate.params + 7;
	pi->name = "ctrl7";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_ctrl_29;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 8 ("m_gate_34")
	pi = self->__commonstate.params + 8;
	pi->name = "gate";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_gate_34;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 9 ("m_sw_30")
	pi = self->__commonstate.params + 9;
	pi->name = "sw1";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_sw_30;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 10 ("m_sw_36")
	pi = self->__commonstate.params + 10;
	pi->name = "sw2";
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
	
	return self;
}

/// Release all resources and memory used by a State object:

void destroy(CommonState *cself) {
	State *self = (State *)cself;
	genlib_sysmem_freeptr(cself->params);
		
	delete self;
}


} // TapeoVersio_2dworking::
