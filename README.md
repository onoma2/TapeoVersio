# TapeoVersio


![](https://github.com/onoma2/TapeoVersio/blob/main/TapeoVersio.jpg)

Max/MSP gen~ tape delay emulation with fuzz for ElectroSmith Daiys and Noise Engeneering Versio Platform. It has an envelope follower controlling the fuzz inside.

Beta 0.4 (still kind of too loud, don't like the the fuzz positioning schheme, tone control requires rethinking)

Before listening to the thing **put both Fuzz and Fuzz mix to fully COUNTER-CLOCKWISE, TO THE LEFT, TO 7 O'CLOCK**, since it has a limiter but its a dinamically controlled feedback and growl machine so take care of your ears and monitors.

When you flash the Daisy it will show a code for the firmware - **Black - RED - RED - RED**, as gen~ doesnt allow to create something on the pinkish side.


Panel is arranged in Versio line of products line:



***Blend*** - dry/wet mix
***Regen*** - feedback
***Tone*** - bipolar feedback filter control with highpass filter in the line
***Tape Wobble*** - Tape Wobble Emulation that creates a little asynchronous pitch shift
***Clock Divider*** - mostly multiplies clock (1/4 to 4). Somehow clock division is not stable

***Fuzz*** - is a fuzz amount, be careful (or adventurous) when pushing it bast noot and towards **red heart** zone indicated on a panel.
***Fuzz Mix*** - its a mix of a fuzz, destination and effect depends on the top switch position and location of the fuzz *circuit* in the code.

> Top switch:
***?*** - the fuzz and delay are somehow connected (its not a pre and not a parralel, but I decided to stop there)
***loop*** - puts fuzz inside the feedback loop (the most musical and responsive to subtle modulation mode)
***post*** - delay first and then the scramble


> Bottom switch:
To emulate the character of a fuzz pedal, i've added an envelope follower that modulates waveshaping ammount in accordance with input signal aplitude change. The threshold, attack and decay are fixed but you can invert the polarity

***f+*** - positive env.follower, so the louder parts of the signal will be fuzzier
***f-*** - the quiter the signal the more it will be chewed
***tri*** - its a clock related lfo on the same duty


A nano sound demo is here: there will be more
https://www.instagram.com/p/CUi4xFRld4D/



It is loud. But cool


![]https://github.com/onoma2/TapeoVersio/blob/main/gen-tapeo.png







