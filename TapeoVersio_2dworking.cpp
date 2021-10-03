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
	Change __m_change_44;
	DCBlock __m_dcblock_76;
	DCBlock __m_dcblock_69;
	Delay m_delay_4;
	Delay m_delay_5;
	Delta __m_delta_40;
	Phasor __m_phasor_59;
	Phasor __m_phasor_64;
	PlusEquals __m_pluseq_41;
	PlusEquals __m_pluseq_45;
	Rate __m_rate_60;
	SineCycle __m_cycle_61;
	SineData __sinedata;
	int __exception;
	int vectorsize;
	t_sample __m_latch_43;
	t_sample __m_count_42;
	t_sample m_history_12;
	t_sample m_history_7;
	t_sample m_history_8;
	t_sample m_history_9;
	t_sample m_ctrl_39;
	t_sample m_history_6;
	t_sample m_sw_37;
	t_sample m_ctrl_38;
	t_sample m_ctrl_36;
	t_sample __m_slide_47;
	t_sample __m_slide_53;
	t_sample m_history_1;
	t_sample samplerate;
	t_sample __m_slide_66;
	t_sample __m_slide_50;
	t_sample m_history_2;
	t_sample samples_to_seconds;
	t_sample m_history_3;
	t_sample __m_slide_56;
	t_sample m_history_11;
	t_sample m_button_35;
	t_sample m_ctrl_33;
	t_sample m_history_18;
	t_sample m_history_19;
	t_sample m_history_20;
	t_sample m_history_21;
	t_sample m_history_17;
	t_sample m_history_15;
	t_sample m_history_16;
	t_sample m_history_13;
	t_sample m_history_14;
	t_sample m_ctrl_34;
	t_sample m_history_22;
	t_sample m_history_24;
	t_sample m_ctrl_30;
	t_sample m_sw_31;
	t_sample m_ctrl_32;
	t_sample m_history_23;
	t_sample m_gate_29;
	t_sample m_history_27;
	t_sample m_history_10;
	t_sample m_history_25;
	t_sample m_history_26;
	t_sample m_history_28;
	// re-initialize all member variables;
	inline void reset(t_param __sr, int __vs) {
		__exception = 0;
		vectorsize = __vs;
		samplerate = __sr;
		m_history_1 = ((int)0);
		m_history_2 = ((int)0);
		m_history_3 = ((int)0);
		m_delay_4.reset("m_delay_4", ((int)96000));
		m_delay_5.reset("m_delay_5", ((int)96000));
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
		m_gate_29 = ((int)0);
		m_ctrl_30 = ((int)0);
		m_sw_31 = ((int)0);
		m_ctrl_32 = ((int)0);
		m_ctrl_33 = ((int)0);
		m_ctrl_34 = ((int)0);
		m_button_35 = ((int)0);
		m_ctrl_36 = ((int)0);
		m_sw_37 = ((int)0);
		m_ctrl_38 = ((int)0);
		m_ctrl_39 = ((int)0);
		__m_delta_40.reset(0);
		__m_pluseq_41.reset(0);
		__m_count_42 = 0;
		__m_latch_43 = 0;
		__m_change_44.reset(0);
		__m_pluseq_45.reset(0);
		__m_slide_47 = 0;
		__m_slide_50 = 0;
		__m_slide_53 = 0;
		__m_slide_56 = 0;
		samples_to_seconds = (1 / samplerate);
		__m_phasor_59.reset(0);
		__m_rate_60.reset();
		__m_cycle_61.reset(samplerate, 0);
		__m_phasor_64.reset(0);
		__m_slide_66 = 0;
		__m_dcblock_69.reset();
		__m_dcblock_76.reset();
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
		t_sample sub_95540 = (m_sw_37 - ((int)0));
		t_sample scale_95537 = ((safepow((sub_95540 * ((t_sample)1)), ((int)1)) * ((int)2)) + ((int)1));
		int or_47504 = (m_gate_29 || m_button_35);
		t_sample sub_95568 = (m_sw_31 - ((int)0));
		t_sample scale_95565 = ((safepow((sub_95568 * ((t_sample)1)), ((int)1)) * ((int)2)) + ((int)1));
		t_sample iup_48 = (1 / maximum(1, abs(((int)4000))));
		t_sample idown_49 = (1 / maximum(1, abs(((int)4000))));
		t_sample iup_51 = (1 / maximum(1, abs(((int)4000))));
		t_sample idown_52 = (1 / maximum(1, abs(((int)4000))));
		t_sample iup_54 = (1 / maximum(1, abs(((int)3000))));
		t_sample idown_55 = (1 / maximum(1, abs(((int)3000))));
		t_sample iup_57 = (1 / maximum(1, abs(((int)3000))));
		t_sample idown_58 = (1 / maximum(1, abs(((int)3000))));
		samples_to_seconds = (1 / samplerate);
		t_sample choice_62 = int(scale_95537);
		t_sample choice_63 = int(scale_95537);
		t_sample choice_65 = int(scale_95565);
		t_sample iup_67 = (1 / maximum(1, abs(((int)3000))));
		t_sample idown_68 = (1 / maximum(1, abs(((int)3000))));
		t_sample min_70 = (-0.9);
		t_sample choice_71 = int(scale_95537);
		t_sample choice_72 = int(scale_95537);
		int min_73 = (-1);
		int min_74 = (-1);
		int min_75 = (-1);
		t_sample min_77 = (-0.5);
		int min_78 = (-1);
		// the main sample loop;
		while ((__n--)) {
			const t_sample in1 = (*(__in1++));
			const t_sample in2 = (*(__in2++));
			t_sample out9 = ((int)0);
			t_sample out7 = ((int)0);
			t_sample sub_95532 = (in2 - (-1));
			t_sample scale_95529 = ((safepow((sub_95532 * ((t_sample)0.5)), ((t_sample)1.5)) * ((int)-1)) + ((int)0));
			t_sample out4 = scale_95529;
			t_sample sub_95536 = (in1 - (-1));
			t_sample scale_95533 = ((safepow((sub_95536 * ((t_sample)0.5)), ((t_sample)1.5)) * ((int)-1)) + ((int)0));
			t_sample out3 = scale_95533;
			t_sample mix_95541 = (m_history_28 + (((t_sample)0.0042742627044161) * (m_ctrl_36 - m_history_28)));
			t_sample mix_4874 = mix_95541;
			t_sample mix_95542 = (m_history_27 + (((t_sample)0.0042742627044161) * (mix_4874 - m_history_27)));
			t_sample mix_4872 = mix_95542;
			t_sample mix_95543 = (m_history_26 + (((t_sample)0.0042742627044161) * (mix_4872 - m_history_26)));
			t_sample mix_4870 = mix_95543;
			t_sample gen_47479 = mix_4870;
			t_sample history_4875_next_4877 = fixdenorm(mix_4874);
			t_sample history_4873_next_4878 = fixdenorm(mix_4872);
			t_sample history_4871_next_4879 = fixdenorm(mix_4870);
			t_sample mix_95544 = (m_history_25 + (((t_sample)0.0042742627044161) * (m_ctrl_34 - m_history_25)));
			t_sample mix_95362 = mix_95544;
			t_sample mix_95545 = (m_history_24 + (((t_sample)0.0042742627044161) * (mix_95362 - m_history_24)));
			t_sample mix_95359 = mix_95545;
			t_sample mix_95546 = (m_history_23 + (((t_sample)0.0042742627044161) * (mix_95359 - m_history_23)));
			t_sample mix_95357 = mix_95546;
			t_sample gen_47478 = mix_95357;
			t_sample history_4875_next_95360 = fixdenorm(mix_95362);
			t_sample history_4873_next_95356 = fixdenorm(mix_95359);
			t_sample history_4871_next_95358 = fixdenorm(mix_95357);
			t_sample TONE_47445 = gen_47478;
			t_sample sub_95550 = (TONE_47445 - ((int)0));
			t_sample scale_95547 = ((safepow((sub_95550 * ((t_sample)1)), ((int)3)) * ((t_sample)-0.99)) + ((t_sample)0.99));
			t_sample scale_48579 = scale_95547;
			t_sample clamp_47441 = ((scale_48579 <= ((int)0)) ? ((int)0) : ((scale_48579 >= ((t_sample)0.99)) ? ((t_sample)0.99) : scale_48579));
			t_sample clamp_47456 = ((scale_48579 <= ((int)0)) ? ((int)0) : ((scale_48579 >= ((t_sample)0.99)) ? ((t_sample)0.99) : scale_48579));
			int delta_47500 = __m_delta_40(or_47504);
			int gtep_47499 = ((delta_47500 >= ((int)1)) ? delta_47500 : 0);
			t_sample plusequals_47498 = __m_pluseq_41.post(gtep_47499, m_history_22, 0);
			int eq_47496 = (plusequals_47498 == ((int)2));
			__m_count_42 = (m_history_22 ? 0 : (fixdenorm(__m_count_42 + plusequals_47498)));
			t_sample counter_47493 = __m_count_42;
			int counter_47494 = ((int)0);
			int counter_47495 = ((int)0);
			__m_latch_43 = ((eq_47496 != 0) ? counter_47493 : __m_latch_43);
			t_sample latch_47492 = __m_latch_43;
			t_sample gen_47502 = latch_47492;
			t_sample history_47497_next_47501 = fixdenorm(eq_47496);
			t_sample CLOCK_47461 = gen_47502;
			t_sample mix_95551 = (m_history_21 + (((t_sample)0.0042742627044161) * (m_ctrl_32 - m_history_21)));
			t_sample mix_95373 = mix_95551;
			t_sample mix_95552 = (m_history_20 + (((t_sample)0.0042742627044161) * (mix_95373 - m_history_20)));
			t_sample mix_95369 = mix_95552;
			t_sample mix_95553 = (m_history_19 + (((t_sample)0.0042742627044161) * (mix_95369 - m_history_19)));
			t_sample mix_95368 = mix_95553;
			t_sample gen_47474 = mix_95368;
			t_sample history_4875_next_95372 = fixdenorm(mix_95373);
			t_sample history_4873_next_95375 = fixdenorm(mix_95369);
			t_sample history_4871_next_95376 = fixdenorm(mix_95368);
			t_sample sub_95557 = (gen_47474 - ((int)0));
			t_sample scale_95554 = ((safepow((sub_95557 * ((t_sample)1)), ((int)1)) * ((int)50)) + ((int)0));
			t_sample mix_95558 = (m_history_18 + (((t_sample)0.0042742627044161) * (m_ctrl_39 - m_history_18)));
			t_sample mix_95384 = mix_95558;
			t_sample mix_95559 = (m_history_17 + (((t_sample)0.0042742627044161) * (mix_95384 - m_history_17)));
			t_sample mix_95381 = mix_95559;
			t_sample mix_95560 = (m_history_16 + (((t_sample)0.0042742627044161) * (mix_95381 - m_history_16)));
			t_sample mix_95385 = mix_95560;
			t_sample gen_47480 = mix_95385;
			t_sample history_4875_next_95386 = fixdenorm(mix_95384);
			t_sample history_4873_next_95387 = fixdenorm(mix_95381);
			t_sample history_4871_next_95388 = fixdenorm(mix_95385);
			t_sample sub_95564 = (gen_47480 - ((int)0));
			t_sample scale_95561 = ((safepow((sub_95564 * ((t_sample)1)), ((int)1)) * ((t_sample)0.998)) + ((t_sample)0.001));
			t_sample mul_51169 = (in1 * ((int)2));
			t_sample abs_49205 = fabs(mul_51169);
			int gt_51609 = (abs_49205 > ((t_sample)0.85));
			int gt_49214 = (gt_51609 > m_history_15);
			t_sample sub_49211 = (gt_51609 - m_history_15);
			t_sample mul_49210 = (sub_49211 * ((t_sample)0.005));
			t_sample mul_49209 = (sub_49211 * ((t_sample)0.001));
			t_sample switch_49212 = (gt_49214 ? mul_49210 : mul_49209);
			t_sample add_49213 = (m_history_15 + switch_49212);
			t_sample rsub_49202 = (((int)1) - add_49213);
			t_sample mix_95569 = (add_49213 + (((int)0) * (rsub_49202 - add_49213)));
			t_sample history_49215_next_51610 = fixdenorm(add_49213);
			t_sample sub_95573 = (mix_95569 - ((int)0));
			t_sample scale_95570 = ((safepow((sub_95573 * ((t_sample)1)), ((int)1)) * ((int)-1)) + ((int)1));
			t_sample mix_95574 = (m_history_14 + (((t_sample)0.0042742627044161) * (m_ctrl_30 - m_history_14)));
			t_sample mix_95398 = mix_95574;
			t_sample mix_95575 = (m_history_13 + (((t_sample)0.0042742627044161) * (mix_95398 - m_history_13)));
			t_sample mix_95394 = mix_95575;
			t_sample mix_95576 = (m_history_12 + (((t_sample)0.0042742627044161) * (mix_95394 - m_history_12)));
			t_sample mix_95397 = mix_95576;
			t_sample gen_47476 = mix_95397;
			t_sample history_4875_next_95401 = fixdenorm(mix_95398);
			t_sample history_4873_next_95399 = fixdenorm(mix_95394);
			t_sample history_4871_next_95402 = fixdenorm(mix_95397);
			t_sample TIME_47462 = gen_47476;
			t_sample sub_95580 = (TIME_47462 - ((int)0));
			t_sample scale_95577 = ((safepow((sub_95580 * ((t_sample)1)), ((int)1)) * ((int)2)) + (-1));
			t_sample scale_47418 = scale_95577;
			int gt_47417 = (scale_47418 > ((int)0));
			t_sample abs_47416 = fabs(scale_47418);
			t_sample add_47448 = (abs_47416 + ((t_sample)0.001));
			t_sample mul_47450 = (add_47448 * ((int)7));
			t_sample ceil_47449 = ceil(mul_47450);
			t_sample div_47421 = safediv(((int)1), ceil_47449);
			t_sample switch_47419 = (gt_47417 ? ceil_47449 : div_47421);
			t_sample div_47451 = safediv(CLOCK_47461, switch_47419);
			int change_92910 = __m_change_44(div_47451);
			int abs_92909 = abs(change_92910);
			int plusequals_92908 = __m_pluseq_45.post(abs_92909, ((int)0), 0);
			t_sample mod_92907 = safemod(plusequals_92908, ((int)2));
			t_sample gen_92911 = mod_92907;
			t_sample NL_47490 = (gen_92911 + scale_48579);
			t_sample out8 = NL_47490;
			t_sample add_92904 = (gen_92911 + ((int)1));
			t_sample choice_46 = int(add_92904);
			t_sample gate_92905 = (((choice_46 >= 1) && (choice_46 < 2)) ? m_history_3 : 0);
			t_sample gate_92906 = ((choice_46 >= 2) ? m_history_3 : 0);
			__m_slide_47 = fixdenorm((__m_slide_47 + (((gate_92905 > __m_slide_47) ? iup_48 : idown_49) * (gate_92905 - __m_slide_47))));
			t_sample slide_95082 = __m_slide_47;
			__m_slide_50 = fixdenorm((__m_slide_50 + (((gate_92906 > __m_slide_50) ? iup_51 : idown_52) * (gate_92906 - __m_slide_50))));
			t_sample slide_95351 = __m_slide_50;
			t_sample mix_95581 = (m_history_11 + (((t_sample)0.0042742627044161) * (m_ctrl_38 - m_history_11)));
			t_sample mix_95408 = mix_95581;
			t_sample mix_95582 = (m_history_10 + (((t_sample)0.0042742627044161) * (mix_95408 - m_history_10)));
			t_sample mix_95406 = mix_95582;
			t_sample mix_95583 = (m_history_9 + (((t_sample)0.0042742627044161) * (mix_95406 - m_history_9)));
			t_sample mix_95407 = mix_95583;
			t_sample gen_47475 = mix_95407;
			t_sample history_4875_next_95413 = fixdenorm(mix_95408);
			t_sample history_4873_next_95415 = fixdenorm(mix_95406);
			t_sample history_4871_next_95414 = fixdenorm(mix_95407);
			t_sample sub_95587 = (gen_47475 - ((int)0));
			t_sample scale_95584 = ((safepow((sub_95587 * ((t_sample)1)), ((t_sample)1.5)) * ((t_sample)0.5)) + ((int)0));
			__m_slide_53 = fixdenorm((__m_slide_53 + (((scale_95584 > __m_slide_53) ? iup_54 : idown_55) * (scale_95584 - __m_slide_53))));
			t_sample slide_47427 = __m_slide_53;
			t_sample div_68404 = (div_47451 * ((t_sample)2.0833333333333e-05));
			t_sample mix_95588 = (m_history_8 + (((t_sample)0.0042742627044161) * (m_ctrl_33 - m_history_8)));
			t_sample mix_95421 = mix_95588;
			t_sample mix_95589 = (m_history_7 + (((t_sample)0.0042742627044161) * (mix_95421 - m_history_7)));
			t_sample mix_95419 = mix_95589;
			t_sample mix_95590 = (m_history_6 + (((t_sample)0.0042742627044161) * (mix_95419 - m_history_6)));
			t_sample mix_95420 = mix_95590;
			t_sample gen_47477 = mix_95420;
			t_sample history_4875_next_95427 = fixdenorm(mix_95421);
			t_sample history_4873_next_95426 = fixdenorm(mix_95419);
			t_sample history_4871_next_95428 = fixdenorm(mix_95420);
			t_sample MOD_47463 = gen_47477;
			t_sample sub_95594 = (MOD_47463 - ((int)0));
			t_sample scale_95591 = ((safepow((sub_95594 * ((t_sample)1)), ((int)1)) * ((t_sample)0.44)) + ((t_sample)0.55));
			t_sample scale_47465 = scale_95591;
			t_sample sub_95598 = (scale_47465 - ((t_sample)0.55));
			t_sample scale_95595 = ((safepow((sub_95598 * ((t_sample)2.2727272727273)), ((int)1)) * ((t_sample)-0.44)) + ((t_sample)0.99));
			t_sample scale_47464 = scale_95595;
			__m_slide_56 = fixdenorm((__m_slide_56 + (((scale_47464 > __m_slide_56) ? iup_57 : idown_58) * (scale_47464 - __m_slide_56))));
			t_sample slide_47437 = __m_slide_56;
			t_sample sub_95602 = (TIME_47462 - ((int)0));
			t_sample scale_95599 = ((safepow((sub_95602 * ((t_sample)1)), ((int)1)) * ((t_sample)0.499)) + ((t_sample)0.001));
			t_sample scale_47469 = scale_95599;
			t_sample phasor_47472 = __m_phasor_59(scale_47469, samples_to_seconds);
			t_sample rate_47473 = __m_rate_60.perform_off(phasor_47472, ((int)1));
			__m_cycle_61.phase(rate_47473);
			t_sample cycle_47470 = __m_cycle_61(__sinedata);
			t_sample cycleindex_47471 = __m_cycle_61.phase();
			t_sample div_47467 = (cycle_47470 * ((t_sample)0.125));
			t_sample add_47466 = (div_47467 + ((t_sample)0.5));
			t_sample mix_95603 = (add_47466 + (slide_47437 * (((int)1) - add_47466)));
			t_sample mix_47468 = mix_95603;
			t_sample modulation_78097 = mix_47468;
			t_sample modulation_47453 = modulation_78097;
			t_sample div_47454 = safediv(slide_95082, modulation_47453);
			t_sample tap_47444 = m_delay_5.read_linear(div_47454);
			t_sample mix_95604 = (tap_47444 + (clamp_47441 * (m_history_2 - tap_47444)));
			t_sample mix_47442 = mix_95604;
			t_sample mul_47438 = (mix_47442 * gen_47479);
			t_sample div_93427 = safediv(slide_95351, modulation_47453);
			t_sample tap_92998 = m_delay_4.read_linear(div_47454);
			t_sample tap_92999 = m_delay_4.read_linear(div_93427);
			t_sample mix_95605 = (tap_92998 + (gen_92911 * (tap_92999 - tap_92998)));
			t_sample mix_94030 = mix_95605;
			t_sample mix_95606 = (mix_94030 + (clamp_47456 * (m_history_1 - mix_94030)));
			t_sample mix_47457 = mix_95606;
			t_sample mul_47447 = (mix_47457 * gen_47479);
			t_sample mix_95607 = (in1 + (scale_95561 * (mix_47457 - in1)));
			t_sample gate_47408 = (((choice_62 >= 1) && (choice_62 < 2)) ? mix_95607 : 0);
			t_sample gate_47409 = (((choice_62 >= 2) && (choice_62 < 3)) ? mix_95607 : 0);
			t_sample gate_47410 = ((choice_62 >= 3) ? mix_95607 : 0);
			t_sample selector_47412 = ((choice_63 >= 3) ? gate_47410 : ((choice_63 >= 2) ? ((int)0) : ((choice_63 >= 1) ? mul_47447 : 0)));
			t_sample mul_76506 = (div_68404 * modulation_78097);
			t_sample phasor_70971 = __m_phasor_64(mul_76506, samples_to_seconds);
			t_sample triangle_70038 = triangle(phasor_70971, ((t_sample)0.5));
			t_sample selector_56613 = ((choice_65 >= 3) ? mix_95569 : ((choice_65 >= 2) ? triangle_70038 : ((choice_65 >= 1) ? scale_95570 : 0)));
			t_sample clamp_52048 = ((selector_56613 <= ((t_sample)0.01)) ? ((t_sample)0.01) : ((selector_56613 >= ((int)1)) ? ((int)1) : selector_56613));
			t_sample mul_54180 = (scale_95554 * clamp_52048);
			__m_slide_66 = fixdenorm((__m_slide_66 + (((mul_54180 > __m_slide_66) ? iup_67 : idown_68) * (mul_54180 - __m_slide_66))));
			t_sample slide_47429 = __m_slide_66;
			t_sample expr_95353 = gloubiBoulga_d_d(selector_47412, slide_47429);
			t_sample clamp_47431 = ((expr_95353 <= min_70) ? min_70 : ((expr_95353 >= ((t_sample)0.9)) ? ((t_sample)0.9) : expr_95353));
			t_sample gate_47413 = (((choice_71 >= 1) && (choice_71 < 2)) ? clamp_47431 : 0);
			t_sample gate_47414 = (((choice_71 >= 2) && (choice_71 < 3)) ? clamp_47431 : 0);
			t_sample gate_47415 = ((choice_71 >= 3) ? clamp_47431 : 0);
			t_sample mix_95608 = (gate_47410 + (slide_47427 * (gate_47415 - gate_47410)));
			t_sample selector_47407 = ((choice_72 >= 3) ? mix_95608 : ((choice_72 >= 2) ? ((int)0) : ((choice_72 >= 1) ? gate_47408 : 0)));
			t_sample mul_47436 = (selector_47407 * ((t_sample)1.5));
			t_sample clamp_47484 = ((mul_47436 <= min_73) ? min_73 : ((mul_47436 >= ((int)1)) ? ((int)1) : mul_47436));
			t_sample out1 = clamp_47484;
			t_sample sub_95612 = (clamp_47484 - (-1));
			t_sample scale_95609 = ((safepow((sub_95612 * ((t_sample)0.5)), ((t_sample)1.5)) * ((int)-1)) + ((int)0));
			t_sample out5 = scale_95609;
			t_sample clamp_47481 = ((mul_47436 <= min_74) ? min_74 : ((mul_47436 >= ((int)1)) ? ((int)1) : mul_47436));
			t_sample out2 = clamp_47481;
			t_sample sub_95616 = (clamp_47481 - (-1));
			t_sample scale_95613 = ((safepow((sub_95616 * ((t_sample)0.5)), ((t_sample)1.5)) * ((int)-1)) + ((int)0));
			t_sample out6 = scale_95613;
			t_sample mix_95617 = (mul_47447 + (slide_47427 * (gate_47413 - mul_47447)));
			t_sample clamp_47452 = ((mix_95617 <= min_75) ? min_75 : ((mix_95617 >= ((int)1)) ? ((int)1) : mix_95617));
			t_sample expr_95352 = gloubiBoulga_95434_d_d(mul_47438, slide_47429);
			t_sample clamp_47422 = ((expr_95352 <= min_77) ? min_77 : ((expr_95352 >= ((t_sample)0.5)) ? ((t_sample)0.5) : expr_95352));
			t_sample mix_95618 = (mul_47438 + (slide_47427 * (clamp_47422 - mul_47438)));
			t_sample clamp_47439 = ((mix_95618 <= min_78) ? min_78 : ((mix_95618 >= ((int)1)) ? ((int)1) : mix_95618));
			t_sample history_92903_next_95435 = fixdenorm(div_47451);
			t_sample history_47440_next_95436 = fixdenorm(mix_47442);
			t_sample history_47455_next_95437 = fixdenorm(mix_47457);
			m_history_28 = history_4875_next_4877;
			m_history_26 = history_4871_next_4879;
			m_history_27 = history_4873_next_4878;
			m_history_25 = history_4875_next_95360;
			m_history_23 = history_4871_next_95358;
			m_history_24 = history_4873_next_95356;
			m_history_22 = history_47497_next_47501;
			m_history_21 = history_4875_next_95372;
			m_history_19 = history_4871_next_95376;
			m_history_20 = history_4873_next_95375;
			m_history_18 = history_4875_next_95386;
			m_history_16 = history_4871_next_95388;
			m_history_17 = history_4873_next_95387;
			m_history_15 = history_49215_next_51610;
			m_history_14 = history_4875_next_95401;
			m_history_12 = history_4871_next_95402;
			m_history_13 = history_4873_next_95399;
			m_history_11 = history_4875_next_95413;
			m_history_9 = history_4871_next_95414;
			m_history_10 = history_4873_next_95415;
			m_history_8 = history_4875_next_95427;
			m_history_6 = history_4871_next_95428;
			m_history_7 = history_4873_next_95426;
			m_delay_5.write((in2 + clamp_47439));
			m_delay_4.write((clamp_47452 + in1));
			m_history_3 = history_92903_next_95435;
			m_history_2 = history_47440_next_95436;
			m_history_1 = history_47455_next_95437;
			m_delay_4.step();
			m_delay_5.step();
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
		m_gate_29 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_ctrl6(t_param _value) {
		m_ctrl_30 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw2(t_param _value) {
		m_sw_31 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_ctrl7(t_param _value) {
		m_ctrl_32 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_ctrl2(t_param _value) {
		m_ctrl_33 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_ctrl3(t_param _value) {
		m_ctrl_34 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_button(t_param _value) {
		m_button_35 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_ctrl5(t_param _value) {
		m_ctrl_36 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw1(t_param _value) {
		m_sw_37 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_ctrl4(t_param _value) {
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
		return __m_dcblock_69(y);
		
	};
	inline t_sample gloubiBoulga_95434_d_d(t_sample xin, t_sample drive) {
		drive = ((drive < ((int)1)) ? ((int)1) : drive);
		t_sample x = ((xin * drive) * ((t_sample)0.686306));
		t_sample a = (((int)1) + exp((sqrt(fabs(x)) * (-((t_sample)0.75)))));
		t_sample y = safediv((exp(x) - exp(((-x) * a))), (exp(x) + exp((-x))));
		return __m_dcblock_76(y);
		
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
		case 2: *value = self->m_ctrl_33; break;
		case 3: *value = self->m_ctrl_34; break;
		case 4: *value = self->m_ctrl_38; break;
		case 5: *value = self->m_ctrl_36; break;
		case 6: *value = self->m_ctrl_30; break;
		case 7: *value = self->m_ctrl_32; break;
		case 8: *value = self->m_gate_29; break;
		case 9: *value = self->m_sw_37; break;
		case 10: *value = self->m_sw_31; break;
		
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
	// initialize parameter 2 ("m_ctrl_33")
	pi = self->__commonstate.params + 2;
	pi->name = "ctrl2";
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
	// initialize parameter 3 ("m_ctrl_34")
	pi = self->__commonstate.params + 3;
	pi->name = "ctrl3";
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
	// initialize parameter 4 ("m_ctrl_38")
	pi = self->__commonstate.params + 4;
	pi->name = "ctrl4";
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
	// initialize parameter 6 ("m_ctrl_30")
	pi = self->__commonstate.params + 6;
	pi->name = "ctrl6";
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
	// initialize parameter 7 ("m_ctrl_32")
	pi = self->__commonstate.params + 7;
	pi->name = "ctrl7";
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
	// initialize parameter 8 ("m_gate_29")
	pi = self->__commonstate.params + 8;
	pi->name = "gate";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_gate_29;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 9 ("m_sw_37")
	pi = self->__commonstate.params + 9;
	pi->name = "sw1";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_sw_37;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 10 ("m_sw_31")
	pi = self->__commonstate.params + 10;
	pi->name = "sw2";
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
	
	return self;
}

/// Release all resources and memory used by a State object:

void destroy(CommonState *cself) {
	State *self = (State *)cself;
	genlib_sysmem_freeptr(cself->params);
		
	delete self;
}


} // TapeoVersio_2dworking::
