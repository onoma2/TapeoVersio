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
	t_sample __m_count_47;
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
	t_sample m_button_37;
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
	t_sample m_ctrl_34;
	t_sample __m_slide_97;
	t_sample m_ctrl_35;
	t_sample m_gate_36;
	t_sample m_history_25;
	t_sample m_sw_32;
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
		m_sw_32 = ((int)0);
		m_sw_33 = ((int)0);
		m_ctrl_34 = ((int)0);
		m_ctrl_35 = ((int)0);
		m_gate_36 = ((int)0);
		m_button_37 = ((int)0);
		m_ctrl_38 = ((int)0);
		m_ctrl_39 = ((int)0);
		m_ctrl_40 = ((int)0);
		m_ctrl_41 = ((int)0);
		__m_count_42 = 0;
		__m_count_43 = 0;
		__m_count_44 = 0;
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
		t_sample sub_1692 = (m_sw_33 - ((int)0));
		t_sample scale_1689 = ((safepow((sub_1692 * ((t_sample)1)), ((int)1)) * ((int)2)) + ((int)1));
		t_sample scale_973 = scale_1689;
		t_sample SW_798 = scale_973;
		t_sample SW_898 = SW_798;
		t_sample SW_825 = SW_798;
		t_sample choice_45 = int(SW_825);
		t_sample SW_787 = SW_798;
		t_sample choice_46 = int(SW_787);
		t_sample iup_49 = (1 / maximum(1, abs(((int)4000))));
		t_sample idown_50 = (1 / maximum(1, abs(((int)4000))));
		t_sample sub_1706 = (m_sw_32 - ((int)0));
		t_sample scale_1703 = ((safepow((sub_1706 * ((t_sample)1)), ((int)1)) * ((int)2)) + ((int)1));
		t_sample scale_972 = scale_1703;
		t_sample SW_756 = scale_972;
		t_sample SW_867 = SW_756;
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
		int or_989 = (m_gate_36 || m_button_37);
		t_sample iup_71 = (1 / maximum(1, abs(((int)4000))));
		t_sample idown_72 = (1 / maximum(1, abs(((int)4000))));
		t_sample iup_74 = (1 / maximum(1, abs(((int)3000))));
		t_sample idown_75 = (1 / maximum(1, abs(((int)3000))));
		samples_to_seconds = (1 / samplerate);
		t_sample choice_79 = int(SW_798);
		t_sample choice_80 = int(SW_798);
		t_sample choice_81 = int(SW_898);
		t_sample choice_82 = int(SW_898);
		t_sample choice_84 = int(SW_756);
		t_sample iup_86 = (1 / maximum(1, abs(((int)3000))));
		t_sample idown_87 = (1 / maximum(1, abs(((int)3000))));
		t_sample min_89 = (-0.9);
		t_sample choice_90 = int(SW_798);
		int min_91 = (-1);
		t_sample choice_92 = int(SW_787);
		t_sample choice_93 = int(SW_798);
		int min_94 = (-1);
		t_sample choice_96 = int(SW_867);
		t_sample iup_98 = (1 / maximum(1, abs(((int)3000))));
		t_sample idown_99 = (1 / maximum(1, abs(((int)3000))));
		t_sample min_101 = (-0.9);
		t_sample choice_102 = int(SW_898);
		t_sample choice_103 = int(SW_825);
		t_sample choice_104 = int(SW_898);
		int min_105 = (-1);
		int min_106 = (-1);
		// the main sample loop;
		while ((__n--)) {
			const t_sample in1 = (*(__in1++));
			const t_sample in2 = (*(__in2++));
			t_sample out7 = ((int)0);
			t_sample out8 = ((int)0);
			__m_count_42 = (((int)0) ? 0 : (fixdenorm(__m_count_42 + ((int)1))));
			int counter_853 = __m_count_42;
			int counter_854 = ((int)0);
			int counter_855 = ((int)0);
			int lt_852 = (counter_853 < ((int)300000));
			__m_count_43 = (((int)0) ? 0 : (fixdenorm(__m_count_43 + ((int)1))));
			int counter_841 = __m_count_43;
			int counter_842 = ((int)0);
			int counter_843 = ((int)0);
			int lt_840 = (counter_841 < ((int)300000));
			__m_count_44 = (((int)0) ? 0 : (fixdenorm(__m_count_44 + ((int)1))));
			int counter_859 = __m_count_44;
			int counter_860 = ((int)0);
			int counter_861 = ((int)0);
			int lt_858 = (counter_859 < ((int)300000));
			t_sample gate_827 = (((choice_45 >= 1) && (choice_45 < 2)) ? in1 : 0);
			t_sample gate_828 = (((choice_45 >= 2) && (choice_45 < 3)) ? in1 : 0);
			t_sample gate_829 = ((choice_45 >= 3) ? in1 : 0);
			t_sample gate_789 = (((choice_46 >= 1) && (choice_46 < 2)) ? in2 : 0);
			t_sample gate_790 = (((choice_46 >= 2) && (choice_46 < 3)) ? in2 : 0);
			t_sample gate_791 = ((choice_46 >= 3) ? in2 : 0);
			t_sample abs_835 = fabs(in2);
			t_sample rsub_834 = (((int)0) - abs_835);
			t_sample switch_839 = (lt_840 ? ((t_sample)-0.99) : rsub_834);
			t_sample out4 = switch_839;
			__m_count_47 = (((int)0) ? 0 : (fixdenorm(__m_count_47 + ((int)1))));
			int counter_847 = __m_count_47;
			int counter_848 = ((int)0);
			int counter_849 = ((int)0);
			int lt_846 = (counter_847 < ((int)300000));
			t_sample abs_837 = fabs(in1);
			t_sample rsub_836 = (((int)0) - abs_837);
			t_sample switch_845 = (lt_846 ? ((int)0) : rsub_836);
			t_sample out3 = switch_845;
			t_sample mix_1693 = (m_history_30 + (((t_sample)0.0019634941468452) * (m_ctrl_40 - m_history_30)));
			t_sample mix_954 = mix_1693;
			t_sample mix_1694 = (m_history_29 + (((t_sample)0.0019634941468452) * (mix_954 - m_history_29)));
			t_sample mix_952 = mix_1694;
			t_sample mix_1695 = (m_history_28 + (((t_sample)0.0019634941468452) * (mix_952 - m_history_28)));
			t_sample mix_950 = mix_1695;
			t_sample gen_965 = mix_950;
			t_sample history_955_next_957 = fixdenorm(mix_954);
			t_sample history_953_next_958 = fixdenorm(mix_952);
			t_sample history_951_next_959 = fixdenorm(mix_950);
			t_sample REGEN_922 = gen_965;
			__m_slide_48 = fixdenorm((__m_slide_48 + (((REGEN_922 > __m_slide_48) ? iup_49 : idown_50) * (REGEN_922 - __m_slide_48))));
			t_sample slide_819 = __m_slide_48;
			t_sample mix_1696 = (m_history_27 + (((t_sample)0.0019634941468452) * (m_ctrl_41 - m_history_27)));
			t_sample mix_1015 = mix_1696;
			t_sample mix_1697 = (m_history_26 + (((t_sample)0.0019634941468452) * (mix_1015 - m_history_26)));
			t_sample mix_1014 = mix_1697;
			t_sample mix_1698 = (m_history_25 + (((t_sample)0.0019634941468452) * (mix_1014 - m_history_25)));
			t_sample mix_1018 = mix_1698;
			t_sample gen_960 = mix_1018;
			t_sample history_955_next_1017 = fixdenorm(mix_1015);
			t_sample history_953_next_1020 = fixdenorm(mix_1014);
			t_sample history_951_next_1016 = fixdenorm(mix_1018);
			t_sample THING_917 = gen_960;
			t_sample sub_1702 = (THING_917 - ((int)0));
			t_sample scale_1699 = ((safepow((sub_1702 * ((t_sample)1)), ((int)1)) * ((int)50)) + ((int)0));
			t_sample scale_916 = scale_1699;
			t_sample mix_1707 = (m_history_24 + (((t_sample)0.0019634941468452) * (m_ctrl_31 - m_history_24)));
			t_sample mix_1031 = mix_1707;
			t_sample mix_1708 = (m_history_23 + (((t_sample)0.0019634941468452) * (mix_1031 - m_history_23)));
			t_sample mix_1027 = mix_1708;
			t_sample mix_1709 = (m_history_22 + (((t_sample)0.0019634941468452) * (mix_1027 - m_history_22)));
			t_sample mix_1030 = mix_1709;
			t_sample gen_962 = mix_1030;
			t_sample history_955_next_1035 = fixdenorm(mix_1031);
			t_sample history_953_next_1033 = fixdenorm(mix_1027);
			t_sample history_951_next_1036 = fixdenorm(mix_1030);
			t_sample TIME_938 = gen_962;
			t_sample sub_1713 = (TIME_938 - ((int)0));
			t_sample scale_1710 = ((safepow((sub_1713 * ((t_sample)1)), ((int)1)) * ((int)2)) + (-1));
			t_sample scale_905 = scale_1710;
			int gte_904 = (scale_905 >= ((int)0));
			t_sample abs_903 = fabs(scale_905);
			t_sample add_924 = (abs_903 + ((t_sample)0.001));
			t_sample mul_926 = (add_924 * ((int)3));
			t_sample ceil_925 = ceil(mul_926);
			t_sample div_908 = safediv(((int)1), ceil_925);
			t_sample switch_906 = (gte_904 ? ceil_925 : div_908);
			t_sample NR_974 = switch_906;
			t_sample out9 = NR_974;
			t_sample mix_1714 = (m_history_21 + (((t_sample)0.0019634941468452) * (m_ctrl_35 - m_history_21)));
			t_sample mix_1043 = mix_1714;
			t_sample mix_1715 = (m_history_20 + (((t_sample)0.0019634941468452) * (mix_1043 - m_history_20)));
			t_sample mix_1040 = mix_1715;
			t_sample mix_1716 = (m_history_19 + (((t_sample)0.0019634941468452) * (mix_1040 - m_history_19)));
			t_sample mix_1046 = mix_1716;
			t_sample gen_964 = mix_1046;
			t_sample history_955_next_1048 = fixdenorm(mix_1043);
			t_sample history_953_next_1044 = fixdenorm(mix_1040);
			t_sample history_951_next_1047 = fixdenorm(mix_1046);
			t_sample TONE_921 = gen_964;
			t_sample sub_1720 = (TONE_921 - ((int)0));
			t_sample scale_1717 = ((safepow((sub_1720 * ((t_sample)1)), ((int)1)) * ((int)2)) + (-1));
			t_sample scale_822 = scale_1717;
			t_sample sub_1724 = (scale_822 - (-1));
			t_sample scale_1721 = ((safepow((sub_1724 * ((t_sample)1)), ((int)1)) * ((t_sample)-0.99)) + ((t_sample)0.99));
			t_sample scale_918 = scale_1721;
			__m_slide_51 = fixdenorm((__m_slide_51 + (((scale_918 > __m_slide_51) ? iup_52 : idown_53) * (scale_918 - __m_slide_51))));
			t_sample slide_818 = __m_slide_51;
			t_sample clamp_811 = ((slide_818 <= ((int)0)) ? ((int)0) : ((slide_818 >= ((t_sample)0.99)) ? ((t_sample)0.99) : slide_818));
			t_sample clamp_932 = ((slide_818 <= ((int)0)) ? ((int)0) : ((slide_818 >= ((t_sample)0.99)) ? ((t_sample)0.99) : slide_818));
			__m_slide_54 = fixdenorm((__m_slide_54 + (((TONE_921 > __m_slide_54) ? iup_55 : idown_56) * (TONE_921 - __m_slide_54))));
			t_sample slide_817 = __m_slide_54;
			__m_slide_57 = fixdenorm((__m_slide_57 + (((TONE_921 > __m_slide_57) ? iup_58 : idown_59) * (TONE_921 - __m_slide_57))));
			t_sample slide_781 = __m_slide_57;
			t_sample mix_1725 = (m_history_18 + (((t_sample)0.0019634941468452) * (m_ctrl_34 - m_history_18)));
			t_sample mix_1058 = mix_1725;
			t_sample mix_1726 = (m_history_17 + (((t_sample)0.0019634941468452) * (mix_1058 - m_history_17)));
			t_sample mix_1053 = mix_1726;
			t_sample mix_1727 = (m_history_16 + (((t_sample)0.0019634941468452) * (mix_1053 - m_history_16)));
			t_sample mix_1057 = mix_1727;
			t_sample gen_966 = mix_1057;
			t_sample history_955_next_1054 = fixdenorm(mix_1058);
			t_sample history_953_next_1059 = fixdenorm(mix_1053);
			t_sample history_951_next_1060 = fixdenorm(mix_1057);
			t_sample BLEND_971 = gen_966;
			t_sample sub_1731 = (BLEND_971 - ((int)0));
			t_sample scale_1728 = ((safepow((sub_1731 * ((t_sample)1)), ((int)1)) * ((t_sample)0.998)) + ((t_sample)0.001));
			t_sample scale_968 = scale_1728;
			__m_slide_60 = fixdenorm((__m_slide_60 + (((scale_968 > __m_slide_60) ? iup_61 : idown_62) * (scale_968 - __m_slide_60))));
			t_sample slide_816 = __m_slide_60;
			t_sample mul_872 = (in1 * ((int)2));
			t_sample abs_877 = fabs(mul_872);
			int gt_876 = (abs_877 > ((t_sample)0.85));
			int gt_886 = (gt_876 > m_history_15);
			t_sample sub_883 = (gt_876 - m_history_15);
			t_sample mul_882 = (sub_883 * ((t_sample)0.005));
			t_sample mul_881 = (sub_883 * ((t_sample)0.001));
			t_sample switch_884 = (gt_886 ? mul_882 : mul_881);
			t_sample add_885 = (m_history_15 + switch_884);
			t_sample rsub_874 = (((int)1) - add_885);
			t_sample mix_1732 = (add_885 + (((int)0) * (rsub_874 - add_885)));
			t_sample mix_873 = mix_1732;
			t_sample gen_891 = mix_873;
			t_sample history_887_next_889 = fixdenorm(add_885);
			t_sample sub_1736 = (gen_891 - ((int)0));
			t_sample scale_1733 = ((safepow((sub_1736 * ((t_sample)1)), ((int)1)) * ((int)-1)) + ((int)1));
			t_sample scale_869 = scale_1733;
			t_sample sub_1740 = (gen_891 - ((int)0));
			t_sample scale_1737 = ((safepow((sub_1740 * ((t_sample)1)), ((int)1)) * ((t_sample)0.7)) + ((t_sample)0.3));
			t_sample scale_824 = scale_1737;
			t_sample mul_760 = (in2 * ((int)2));
			t_sample abs_765 = fabs(mul_760);
			int gt_764 = (abs_765 > ((t_sample)0.85));
			int gt_774 = (gt_764 > m_history_14);
			t_sample sub_771 = (gt_764 - m_history_14);
			t_sample mul_770 = (sub_771 * ((t_sample)0.005));
			t_sample mul_769 = (sub_771 * ((t_sample)0.001));
			t_sample switch_772 = (gt_774 ? mul_770 : mul_769);
			t_sample add_773 = (m_history_14 + switch_772);
			t_sample rsub_762 = (((int)1) - add_773);
			t_sample mix_1741 = (add_773 + (((int)0) * (rsub_762 - add_773)));
			t_sample mix_761 = mix_1741;
			t_sample gen_779 = mix_761;
			t_sample history_775_next_777 = fixdenorm(add_773);
			t_sample sub_1745 = (gen_779 - ((int)0));
			t_sample scale_1742 = ((safepow((sub_1745 * ((t_sample)1)), ((int)1)) * ((int)-1)) + ((int)1));
			t_sample scale_758 = scale_1742;
			t_sample sub_1749 = (gen_779 - ((int)0));
			t_sample scale_1746 = ((safepow((sub_1749 * ((t_sample)1)), ((int)1)) * ((t_sample)0.7)) + ((t_sample)0.3));
			t_sample scale_750 = scale_1746;
			t_sample mix_1750 = (m_history_13 + (((t_sample)0.0019634941468452) * (m_ctrl_39 - m_history_13)));
			t_sample mix_1073 = mix_1750;
			t_sample mix_1751 = (m_history_12 + (((t_sample)0.0019634941468452) * (mix_1073 - m_history_12)));
			t_sample mix_1066 = mix_1751;
			t_sample mix_1752 = (m_history_11 + (((t_sample)0.0019634941468452) * (mix_1066 - m_history_11)));
			t_sample mix_1074 = mix_1752;
			t_sample gen_961 = mix_1074;
			t_sample history_955_next_1071 = fixdenorm(mix_1073);
			t_sample history_953_next_1069 = fixdenorm(mix_1066);
			t_sample history_951_next_1075 = fixdenorm(mix_1074);
			t_sample sub_1756 = (gen_961 - ((int)0));
			t_sample scale_1753 = ((safepow((sub_1756 * ((t_sample)1)), ((t_sample)1.5)) * ((t_sample)0.5)) + ((int)0));
			__m_slide_63 = fixdenorm((__m_slide_63 + (((scale_1753 > __m_slide_63) ? iup_64 : idown_65) * (scale_1753 - __m_slide_63))));
			t_sample slide_911 = __m_slide_63;
			int delta_985 = __m_delta_66(or_989);
			int gtep_984 = ((delta_985 >= ((int)1)) ? delta_985 : 0);
			t_sample plusequals_983 = __m_pluseq_67.post(gtep_984, m_history_10, 0);
			int eq_981 = (plusequals_983 == ((int)2));
			__m_count_68 = (m_history_10 ? 0 : (fixdenorm(__m_count_68 + plusequals_983)));
			t_sample counter_978 = __m_count_68;
			int counter_979 = ((int)0);
			int counter_980 = ((int)0);
			__m_latch_69 = ((eq_981 != 0) ? counter_978 : __m_latch_69);
			t_sample latch_977 = __m_latch_69;
			t_sample gen_987 = latch_977;
			t_sample history_982_next_986 = fixdenorm(eq_981);
			t_sample CLOCK_937 = gen_987;
			t_sample div_927 = safediv(CLOCK_937, switch_906);
			__m_slide_70 = fixdenorm((__m_slide_70 + (((div_927 > __m_slide_70) ? iup_71 : idown_72) * (div_927 - __m_slide_70))));
			t_sample slide_934 = __m_slide_70;
			t_sample div_865 = (div_927 * ((t_sample)2.0833333333333e-05));
			t_sample div_754 = (div_927 * ((t_sample)2.0833333333333e-05));
			t_sample mix_1757 = (m_history_9 + (((t_sample)0.0019634941468452) * (m_ctrl_38 - m_history_9)));
			t_sample mix_1087 = mix_1757;
			t_sample mix_1758 = (m_history_8 + (((t_sample)0.0019634941468452) * (mix_1087 - m_history_8)));
			t_sample mix_1079 = mix_1758;
			t_sample mix_1759 = (m_history_7 + (((t_sample)0.0019634941468452) * (mix_1079 - m_history_7)));
			t_sample mix_1086 = mix_1759;
			t_sample gen_963 = mix_1086;
			t_sample history_955_next_1084 = fixdenorm(mix_1087);
			t_sample history_953_next_1082 = fixdenorm(mix_1079);
			t_sample history_951_next_1088 = fixdenorm(mix_1086);
			t_sample MOD_939 = gen_963;
			t_sample sub_1763 = (MOD_939 - ((int)0));
			t_sample scale_1760 = ((safepow((sub_1763 * ((t_sample)1)), ((int)1)) * ((t_sample)0.44)) + ((t_sample)0.55));
			t_sample scale_941 = scale_1760;
			t_sample sub_1767 = (scale_941 - ((t_sample)0.55));
			t_sample scale_1764 = ((safepow((sub_1767 * ((t_sample)2.2727272727273)), ((int)1)) * ((t_sample)-0.44)) + ((t_sample)0.99));
			t_sample scale_940 = scale_1764;
			__m_slide_73 = fixdenorm((__m_slide_73 + (((scale_940 > __m_slide_73) ? iup_74 : idown_75) * (scale_940 - __m_slide_73))));
			t_sample slide_920 = __m_slide_73;
			t_sample sub_1771 = (TIME_938 - ((int)0));
			t_sample scale_1768 = ((safepow((sub_1771 * ((t_sample)1)), ((int)1)) * ((t_sample)0.499)) + ((t_sample)0.001));
			t_sample scale_945 = scale_1768;
			t_sample phasor_948 = __m_phasor_76(scale_945, samples_to_seconds);
			t_sample rate_949 = __m_rate_77.perform_off(phasor_948, ((int)1));
			__m_cycle_78.phase(rate_949);
			t_sample cycle_946 = __m_cycle_78(__sinedata);
			t_sample cycleindex_947 = __m_cycle_78.phase();
			t_sample div_943 = (cycle_946 * ((t_sample)0.125));
			t_sample add_942 = (div_943 + ((t_sample)0.5));
			t_sample mix_1772 = (add_942 + (slide_920 * (((int)1) - add_942)));
			t_sample mix_944 = mix_1772;
			t_sample modulation_751 = mix_944;
			t_sample modulation_808 = modulation_751;
			t_sample div_809 = safediv(slide_934, modulation_808);
			t_sample tap_814 = m_delay_6.read_linear(div_809);
			t_sample mix_1773 = (tap_814 + (clamp_811 * (m_history_2 - tap_814)));
			t_sample mix_812 = mix_1773;
			t_sample mul_806 = (mix_812 * slide_819);
			t_sample sub_785 = (tap_814 - mix_812);
			t_sample mix_1774 = (mix_812 + (slide_781 * (sub_785 - mix_812)));
			t_sample mix_784 = mix_1774;
			t_sample add_1776 = (gate_789 + gate_791);
			t_sample mix_1775 = (add_1776 + (slide_816 * (mix_784 - add_1776)));
			t_sample mix_815 = mix_1775;
			t_sample gate_795 = (((choice_79 >= 1) && (choice_79 < 2)) ? mix_815 : 0);
			t_sample gate_796 = (((choice_79 >= 2) && (choice_79 < 3)) ? mix_815 : 0);
			t_sample gate_797 = ((choice_79 >= 3) ? mix_815 : 0);
			t_sample selector_799 = ((choice_80 >= 3) ? gate_797 : ((choice_80 >= 2) ? gate_790 : ((choice_80 >= 1) ? mul_806 : 0)));
			t_sample modulation_929 = modulation_751;
			t_sample div_930 = safediv(slide_934, modulation_929);
			t_sample tap_936 = m_delay_5.read_linear(div_930);
			t_sample mix_1777 = (tap_936 + (clamp_932 * (m_history_1 - tap_936)));
			t_sample mix_933 = mix_1777;
			t_sample mul_923 = (mix_933 * slide_819);
			t_sample sub_821 = (tap_936 - mix_933);
			t_sample mix_1778 = (mix_933 + (slide_817 * (sub_821 - mix_933)));
			t_sample mix_820 = mix_1778;
			t_sample add_1780 = (gate_827 + gate_829);
			t_sample mix_1779 = (add_1780 + (slide_816 * (mix_820 - add_1780)));
			t_sample mix_970 = mix_1779;
			t_sample gate_895 = (((choice_81 >= 1) && (choice_81 < 2)) ? mix_970 : 0);
			t_sample gate_896 = (((choice_81 >= 2) && (choice_81 < 3)) ? mix_970 : 0);
			t_sample gate_897 = ((choice_81 >= 3) ? mix_970 : 0);
			t_sample selector_899 = ((choice_82 >= 3) ? gate_897 : ((choice_82 >= 2) ? gate_828 : ((choice_82 >= 1) ? mul_923 : 0)));
			t_sample mul_752 = (div_754 * modulation_751);
			t_sample phasor_753 = __m_phasor_83(mul_752, samples_to_seconds);
			t_sample triangle_755 = triangle(phasor_753, ((t_sample)0.5));
			t_sample selector_757 = ((choice_84 >= 3) ? scale_750 : ((choice_84 >= 2) ? triangle_755 : ((choice_84 >= 1) ? scale_758 : 0)));
			t_sample clamp_759 = ((selector_757 <= ((t_sample)0.01)) ? ((t_sample)0.01) : ((selector_757 >= ((int)1)) ? ((int)1) : selector_757));
			t_sample mul_792 = (scale_916 * clamp_759);
			__m_slide_85 = fixdenorm((__m_slide_85 + (((mul_792 > __m_slide_85) ? iup_86 : idown_87) * (mul_792 - __m_slide_85))));
			t_sample slide_783 = __m_slide_85;
			t_sample expr_1012 = gloubiBoulga_d_d(selector_799, slide_783);
			t_sample clamp_805 = ((expr_1012 <= min_89) ? min_89 : ((expr_1012 >= ((t_sample)0.9)) ? ((t_sample)0.9) : expr_1012));
			t_sample gate_800 = (((choice_90 >= 1) && (choice_90 < 2)) ? clamp_805 : 0);
			t_sample gate_801 = (((choice_90 >= 2) && (choice_90 < 3)) ? clamp_805 : 0);
			t_sample gate_802 = ((choice_90 >= 3) ? clamp_805 : 0);
			t_sample mix_1781 = (gate_797 + (slide_911 * (gate_802 - gate_797)));
			t_sample mul_739 = (gate_800 * ((t_sample)0.5));
			t_sample mul_738 = (m_history_4 * ((t_sample)0.5));
			t_sample add_740 = (mul_739 + mul_738);
			t_sample history_741_next_742 = fixdenorm(gate_800);
			t_sample mix_1782 = (mul_806 + (slide_911 * (add_740 - mul_806)));
			t_sample clamp_807 = ((mix_1782 <= min_91) ? min_91 : ((mix_1782 >= ((int)1)) ? ((int)1) : mix_1782));
			t_sample selector_788 = ((choice_92 >= 3) ? ((int)0) : ((choice_92 >= 2) ? gate_801 : ((choice_92 >= 1) ? ((int)0) : 0)));
			t_sample mix_1783 = (gate_796 + (slide_911 * (selector_788 - gate_796)));
			t_sample selector_794 = ((choice_93 >= 3) ? mix_1781 : ((choice_93 >= 2) ? mix_1783 : ((choice_93 >= 1) ? gate_795 : 0)));
			t_sample mul_782 = (selector_794 * ((int)1));
			t_sample clamp_967 = ((mul_782 <= min_94) ? min_94 : ((mul_782 >= ((int)1)) ? ((int)1) : mul_782));
			t_sample out2 = clamp_967;
			t_sample abs_831 = fabs(clamp_967);
			t_sample rsub_830 = (((int)0) - abs_831);
			t_sample switch_851 = (lt_852 ? ((t_sample)-0.99) : rsub_830);
			t_sample out6 = switch_851;
			t_sample modulation_862 = modulation_751;
			t_sample mul_863 = (div_865 * modulation_862);
			t_sample phasor_864 = __m_phasor_95(mul_863, samples_to_seconds);
			t_sample triangle_866 = triangle(phasor_864, ((t_sample)0.5));
			t_sample selector_868 = ((choice_96 >= 3) ? scale_824 : ((choice_96 >= 2) ? triangle_866 : ((choice_96 >= 1) ? scale_869 : 0)));
			t_sample clamp_871 = ((selector_868 <= ((t_sample)0.01)) ? ((t_sample)0.01) : ((selector_868 >= ((int)1)) ? ((int)1) : selector_868));
			t_sample mul_870 = (scale_916 * clamp_871);
			__m_slide_97 = fixdenorm((__m_slide_97 + (((mul_870 > __m_slide_97) ? iup_98 : idown_99) * (mul_870 - __m_slide_97))));
			t_sample slide_913 = __m_slide_97;
			t_sample expr_1013 = gloubiBoulga_1092_d_d(selector_899, slide_913);
			t_sample clamp_915 = ((expr_1013 <= min_101) ? min_101 : ((expr_1013 >= ((t_sample)0.9)) ? ((t_sample)0.9) : expr_1013));
			t_sample gate_900 = (((choice_102 >= 1) && (choice_102 < 2)) ? clamp_915 : 0);
			t_sample gate_901 = (((choice_102 >= 2) && (choice_102 < 3)) ? clamp_915 : 0);
			t_sample gate_902 = ((choice_102 >= 3) ? clamp_915 : 0);
			t_sample mix_1784 = (gate_897 + (slide_911 * (gate_902 - gate_897)));
			t_sample selector_826 = ((choice_103 >= 3) ? ((int)0) : ((choice_103 >= 2) ? gate_901 : ((choice_103 >= 1) ? ((int)0) : 0)));
			t_sample mix_1785 = (gate_896 + (slide_911 * (selector_826 - gate_896)));
			t_sample selector_894 = ((choice_104 >= 3) ? mix_1784 : ((choice_104 >= 2) ? mix_1785 : ((choice_104 >= 1) ? gate_895 : 0)));
			t_sample mul_919 = (selector_894 * ((int)1));
			t_sample clamp_969 = ((mul_919 <= min_105) ? min_105 : ((mul_919 >= ((int)1)) ? ((int)1) : mul_919));
			t_sample out1 = clamp_969;
			t_sample abs_833 = fabs(clamp_969);
			t_sample rsub_832 = (((int)0) - abs_833);
			t_sample switch_857 = (lt_858 ? ((t_sample)-0.99) : rsub_832);
			t_sample out5 = switch_857;
			t_sample mul_745 = (gate_900 * ((t_sample)0.5));
			t_sample mul_744 = (m_history_3 * ((t_sample)0.5));
			t_sample add_746 = (mul_745 + mul_744);
			t_sample history_747_next_748 = fixdenorm(gate_900);
			t_sample mix_1786 = (mul_923 + (slide_911 * (add_746 - mul_923)));
			t_sample clamp_928 = ((mix_1786 <= min_106) ? min_106 : ((mix_1786 >= ((int)1)) ? ((int)1) : mix_1786));
			t_sample history_810_next_1093 = fixdenorm(mix_812);
			t_sample history_931_next_1094 = fixdenorm(mix_933);
			m_history_30 = history_955_next_957;
			m_history_28 = history_951_next_959;
			m_history_29 = history_953_next_958;
			m_history_27 = history_955_next_1017;
			m_history_25 = history_951_next_1016;
			m_history_26 = history_953_next_1020;
			m_history_24 = history_955_next_1035;
			m_history_22 = history_951_next_1036;
			m_history_23 = history_953_next_1033;
			m_history_21 = history_955_next_1048;
			m_history_19 = history_951_next_1047;
			m_history_20 = history_953_next_1044;
			m_history_18 = history_955_next_1054;
			m_history_16 = history_951_next_1060;
			m_history_17 = history_953_next_1059;
			m_history_15 = history_887_next_889;
			m_history_14 = history_775_next_777;
			m_history_13 = history_955_next_1071;
			m_history_11 = history_951_next_1075;
			m_history_12 = history_953_next_1069;
			m_history_10 = history_982_next_986;
			m_history_9 = history_955_next_1084;
			m_history_7 = history_951_next_1088;
			m_history_8 = history_953_next_1082;
			m_delay_6.write((((clamp_807 + gate_789) + gate_790) + gate_791));
			m_delay_5.write((((gate_827 + gate_828) + gate_829) + clamp_928));
			m_history_4 = history_741_next_742;
			m_history_3 = history_747_next_748;
			m_history_2 = history_810_next_1093;
			m_history_1 = history_931_next_1094;
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
	inline void set_sw2(t_param _value) {
		m_sw_32 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw1(t_param _value) {
		m_sw_33 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_ctrl1(t_param _value) {
		m_ctrl_34 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_ctrl3(t_param _value) {
		m_ctrl_35 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_gate(t_param _value) {
		m_gate_36 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_button(t_param _value) {
		m_button_37 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_ctrl2(t_param _value) {
		m_ctrl_38 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_ctrl4(t_param _value) {
		m_ctrl_39 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_ctrl5(t_param _value) {
		m_ctrl_40 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_ctrl7(t_param _value) {
		m_ctrl_41 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline t_sample gloubiBoulga_d_d(t_sample xin, t_sample drive) {
		drive = ((drive < ((int)1)) ? ((int)1) : drive);
		t_sample x = ((xin * drive) * ((t_sample)0.686306));
		t_sample a = (((int)1) + exp((sqrt(fabs(x)) * (-((t_sample)0.75)))));
		t_sample y = safediv((exp(x) - exp(((-x) * a))), (exp(x) + exp((-x))));
		return __m_dcblock_88(y);
		
	};
	inline t_sample gloubiBoulga_1092_d_d(t_sample xin, t_sample drive) {
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
		case 0: *value = self->m_button_37; break;
		case 1: *value = self->m_ctrl_34; break;
		case 2: *value = self->m_ctrl_38; break;
		case 3: *value = self->m_ctrl_35; break;
		case 4: *value = self->m_ctrl_39; break;
		case 5: *value = self->m_ctrl_40; break;
		case 6: *value = self->m_ctrl_31; break;
		case 7: *value = self->m_ctrl_41; break;
		case 8: *value = self->m_gate_36; break;
		case 9: *value = self->m_sw_33; break;
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
	// initialize parameter 1 ("m_ctrl_34")
	pi = self->__commonstate.params + 1;
	pi->name = "ctrl1";
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
	// initialize parameter 2 ("m_ctrl_38")
	pi = self->__commonstate.params + 2;
	pi->name = "ctrl2";
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
	// initialize parameter 5 ("m_ctrl_40")
	pi = self->__commonstate.params + 5;
	pi->name = "ctrl5";
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
	// initialize parameter 7 ("m_ctrl_41")
	pi = self->__commonstate.params + 7;
	pi->name = "ctrl7";
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
	// initialize parameter 8 ("m_gate_36")
	pi = self->__commonstate.params + 8;
	pi->name = "gate";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_gate_36;
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
